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
*按照官网教程,需要关闭gomodule*
+ 使用命令查看go mod的功能是否开启： `go env `
  + 默认情况下可以看到`GO111MODULE=""`，即`GO111MODULE=auto`要想`go get`下载源代
  码到src下，设置关闭go mod功能既可以了：
  + windows下： `go env -w GO111MODULE=off`
  + Linux下： `export GO111MODULE=off`
+ gocv网址: https://gocv.io/
+ 由于国内网络环境,建议在win_build_opencv.cmd加上`pause`,运行后暂停来查看输出

**如果运行要提示安装包,要打开`GO111MODULE=on`**