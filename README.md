# 此仓库为我们制作的网球机器人的下位机嵌入式部分

### 此下位机基于STM32F407ZGT6，独立设计制作PCB，将外设集成在一起

**外设：**

+ 基于A4950的电机驱动
+ hc-05蓝牙模块
+ 航模遥控器接收机
+ jy901姿态解算器

**此项目只要使用stm32的定时器的pwm输出与输入捕获，串口通信等功能，基于PID算法控制机器人底盘移动，与上位机通信方式为串口通信。**