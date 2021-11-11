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
+ 由于国内网络环境,建议在win_build_opencv.cmd加上`pause`,运行后暂停来查看输出