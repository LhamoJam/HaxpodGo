// What it does:
//
// This example opens a video capture device, then streams MJPEG from it.
// Once running point your browser to the hostname/port you passed in the
// command line (for example http://localhost:8080) and you should see
// the live video stream.
//
// How to run:
//
// mjpeg-streamer [camera ID] [host:port]
//
//		go get -u github.com/hybridgroup/mjpeg
// 		go run ./cmd/mjpeg-streamer/main.go 1 0.0.0.0:8080
//

package main

import (
	"fmt"
	"image"
	"image/color"
	"log"
	"net/http"
	"os"

	_ "net/http/pprof"

	"github.com/hybridgroup/mjpeg"
	"gocv.io/x/gocv"
)

var (
	deviceID int
	err      error
	webcam   *gocv.VideoCapture
	stream   *mjpeg.Stream
)

func main() {
	if len(os.Args) < 3 {
		fmt.Println("How to run:\n\tmjpeg-streamer [camera ID] [host:port]")
		return
	}

	// parse args
	deviceID := os.Args[1]
	host := os.Args[2]

	// open webcam
	webcam, err = gocv.OpenVideoCapture(deviceID)
	if err != nil {
		fmt.Printf("Error opening capture device: %v\n", deviceID)
		return
	}
	defer webcam.Close()

	// create the mjpeg stream
	stream = mjpeg.NewStream()

	// start capturing
	go mjpegCapture()

	fmt.Println("Capturing. Point your browser to " + host)

	// start http server
	http.Handle("/", stream)
	log.Fatal(http.ListenAndServe(host, nil))
}

func mjpegCapture() {
	img := gocv.NewMat()
	defer img.Close()
	//fmt.Println("draw...")
	for {
		if ok := webcam.Read(&img); !ok {
			fmt.Printf("Device closed: %v\n", deviceID)
			return
		}
		if img.Empty() {
			continue
		}
		// 设定颜色值
		blue := color.RGBA{0, 0, 255, 0}
		size := gocv.GetTextSize("ARTScript-HaxpodGo", gocv.FontHersheyPlain, 1, 2)
		pos := image.Pt(size.X/4,0+size.Y + 5)
		// 把字绘制在图片上
		gocv.PutText(&img, "ARTScript-HaxpodGo", pos, gocv.FontHersheyPlain, 1, blue, 2)
		buf, _ := gocv.IMEncode(".jpg", img)
		stream.UpdateJPEG(buf.GetBytes())
		buf.Close()
	}
}