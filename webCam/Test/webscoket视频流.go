package main

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"github.com/gorilla/websocket"
	"image"
	"image/color"
	"net/http"
	_ "net/http/pprof"
	"time"

	"github.com/hybridgroup/mjpeg"
	"gocv.io/x/gocv"
)
// 视频
var (
	deviceID int
	err      error
	webcam   *gocv.VideoCapture
	stream   *mjpeg.Stream
)

//var upGrader = websocket.Upgrader{
//	CheckOrigin: func(r *http.Request) bool {
//		return true
//	},
//}
//
////webSocket请求ping 返回pong
//func ping(c *gin.Context) {
//	//升级get请求为webSocket协议
//	ws, err := upGrader.Upgrade(c.Writer, c.Request, nil)
//	if err != nil {
//		return
//	}
//	defer ws.Close()
//	for {
//		//写入ws数据
//		err = ws.WriteMessage([]byte ,stream)
//		if err != nil {
//			break
//		}
//	}
//}

var wsupgrader = websocket.Upgrader{
	ReadBufferSize:   1024,
	WriteBufferSize:  1024,
	HandshakeTimeout: 5 * time.Second,
	// 取消ws跨域校验
	CheckOrigin: func(r *http.Request) bool {
		return true
	},
}

// 处理ws请求
func WsHandler(w http.ResponseWriter, r *http.Request) {
	var conn *websocket.Conn
	var err error
	conn, err = wsupgrader.Upgrade(w, r, nil)
	if err != nil {
		fmt.Println("Failed to set websocket upgrade: %+v", err)
		return
	}

	// 必须死循环，gin通过协程调用该handler函数，一旦退出函数，ws会被主动销毁
	for {
		// recieve
		//t, reply, err := conn.ReadMessage()
		//if err != nil {
		//	break
		//}
		// todo：业务操作
		err = conn.WriteMessage(websocket.TextMessage,stream)
		if err != nil {
			break
		}
	}
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

func main() {
	// parse args
	deviceID := 0
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

	bindAddress := "localhost:8080"
	r := gin.Default()
	r.GET("/socketServer", WsHandler)
	r.Run(bindAddress)



}
