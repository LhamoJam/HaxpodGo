# PowerPod serial mode command set
+ 参考网站: https://www.robotshop.com/community/forum/t/powerpod-serial-mode-command-set/18151
```
I copied this from KM6VV.

[code]L1 tile floor
04 FF FB 80 80 80 80 0D

(start) Knee Shift
08 F7 FF 80 80 80 80 0D

(Triangle) button
10 FF EF 80 80 80 80 0D

L2 default
01 FF FE 80 80 80 80 0D

(Circle) button
20 FF DF 80 80 80 80 0D

(Square) Button
80 FF 7F 80 80 80 80 0D

(Cross) Button
40 FF BF 80 80 80 80 0D

R2 Body Low
02 FF FD 80 80 80 80 0D

(select) Lock Legs
01 FE FF 80 80 80 80 0D

R1 tall grass
08 FF F7 80 80 80 80 0D

L3 Cycle Button
02 FD FF 00 00 00 00 0D

UP Button
10 EF FF 80 80 80 80 0D

Down Button
40 BF FF 80 80 80 80 0D

Right Button
20 DF FF 80 80 80 80 0D

Left Button
80 7F FF 80 80 80 80 0D

height down
E8 FF FF 80 80 80 68 0D

Y Speed - 84
A8 FF FF 28 80 80 80 0D

steer right
20 FF FF 80 80 A0 80 0D

steer left
E7 FF F8 80 80 60 80 0D

height up
15 FF FF 80 80 80 95 0D

X Speed - 84
A8 FF FF 80 28 80 80 0D

Y Speed + 36
28 FF FF A8 80 80 80 0D

Neutral 80
00 FF FF 80 80 80 80 0D

R3 (horn) Button
04 FB FF 80 80 80 80 0D

X Speed + 36
28 FF FF 80 A8 80 80 0D

XY speed +
00 FF FF A8 A8 80 80 0D

XY Speed -
00 FF FF 28 28 80 80 0D

XY speed ±
80 FF FF A8 28 80 80 0D

XY Speed -+
80 FF FF 28 A8 80 80 0D

X Speed max
7C FF FF 80 FC 80 80 0D

Y Speed max
7C FF FF FC 80 80 80 0D
[/code]****
```