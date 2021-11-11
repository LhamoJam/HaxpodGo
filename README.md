# HaxpodGo
本项目使用Golang语言驱动六足机器人,功能如下:
1. 基于websocket的全端遥控
2. webcam模块
3. jetson nano GPIO驱动
4. 舵机控制协议

## webCam
### gocv简介
gocv是golang中对opencv库封装。
### gocv安装
+ gocv网址: https://gocv.io/
+ 安装OpenCV: http://c.biancheng.net/view/1104.html
+ 下载 `go get -u -d gocv.io/x/gocv`
+ 编译 