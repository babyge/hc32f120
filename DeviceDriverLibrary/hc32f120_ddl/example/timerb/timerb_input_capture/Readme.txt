﻿================================================================================
                                样例使用说明
================================================================================
版本历史
日期        版本    负责人         IAR     MDK     GCC     描述
2019-03-26  1.0     Hongjh         7.70    5.16    8.3.1   first version
================================================================================
平台说明
================================================================================
GCC工程，由Eclipse IDE外挂GNU-ARM Toolchain，再结合pyOCD GDB Server实现工程的编译、
链接和调试。在用Eclipse导入工程后，请将xxxx_PyOCDDebug中pyocd-gdbserver和SVD文件
设置为正确的路径；请将xxxx_PyOCDDownload中pyocd设置为正确的路径。注意，这些路径不
能包含非英文字符。


功能描述
================================================================================
本样例展示Timera模块输入捕获功能。

说明：
1、本样例设置TimerB为锯齿波、向上计数模式，启动条件为外部中断事件
2、TimerB单元3使能输出比较功能，比较匹配和TimerB单元3使能输出比较功能，比较匹配和
周期匹配翻转输出极性，比较匹配TIMB_3_PWM1产生下降沿；
3、TimerB单元1和2使能输入捕获功能，TimerB单元1和2在TIMB_3_PWM1下降沿时，捕获输入。

================================================================================
测试环境
================================================================================
测试用板:
---------------------
STK_HC32F120_LQFP44_080_V11

辅助工具:
---------------------
无

辅助软件:
---------------------
无

================================================================================
使用步骤
================================================================================
1）将P146(TIMB_1_PWM1)、P16(TIMB_2_PWM1)、P17(TIMB_3_PWM1)相连
2）打开工程并重新编译
3）启动IDE的下载和调试功能全速运行
4）按下SW2按键
5）绿色LED灯点亮，表示产生外部中断事件
6）通过IDE的Live Watch功能，查看捕获输入缓存变量m_stcEvenUnitCmpBuf、
   m_stcOddUnitCmpBuf为TimerB单元3 TMRB_CMPAR值加1

================================================================================
注意
================================================================================
无

================================================================================
