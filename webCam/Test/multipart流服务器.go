package main

import (
	"crypto/md5"
	"fmt"
	"image/color"
	"net/http"
	"time"

	brain "path/to/image/generator/module"
)

func init() {
	RouteHandler{
		function: func(w http.ResponseWriter, r *http.Request) {
			w.Header().Set("Content-Type", "multipart/x-mixed-replace; boundary=frame")
			w.Header().Set("Cache-Control", "no-cache") // <- Just in case
			w.WriteHeader(200)

			// If the request contains a token and the token maps to a valid "brain", start consuming frames from
			// the brain and returning them to the client
			params := r.URL.Query()
			if val, ok := params["token"]; ok && len(val) > 0 {
				if b, ok := SharedMemory["brains"].(map[string]*brain.Brain)[val[0]]; ok && !b.CheckHasExit() {
					// Keep a checksum of the previous frame to avoid sending frames which haven't changed. Frames cannot
					// be compared directly (at least efficiently) as they are slices not arrays
					previousFrameChecksum := [16]byte{}

					for {
						if !b.CheckHasExit() {
							frame, err := b.GetNextFrame(SharedMemory["conf"].(map[string]interface{})["DISPLAY_COL"].(color.Color))
							if err == nil && md5.Sum(frame) != previousFrameChecksum {
								// Only write the frame if we succesfully read it and it's different to the previous
								_, err = w.Write([]byte(fmt.Sprintf("--frame\r\nContent-Type: image/png\r\nContent-Size: %d\r\n\r\n%s\r\n", len(frame), frame)))
								if err != nil {
									// The client most likely disconnected, so we should end the stream. As the brain still exists, the
									// user can re-connect at any time
									return
								}
								// Update the checksum to this frame
								previousFrameChecksum = md5.Sum(frame)
								// If possible, flush the buffer to make sure the frame is sent ASAP
								if flusher, ok := w.(http.Flusher); ok {
									flusher.Flush()
								}
							}
							// Limit the framerate to reduce CPU usage
							<-time.After(time.Duration(SharedMemory["conf"].(map[string]interface{})["FPS_LIMITER_INTERVAL"].(int)) * time.Millisecond)
						} else {
							// The brain has exit so there is no more we can do - we are braindead :P
							return
						}
					}
				}
			}
		},
	}.Register("/stream", "/stream.png")
}

func main(){
	init()
}

