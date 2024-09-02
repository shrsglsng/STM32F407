By default the internal clock for the MCU is set as HSI(High Spped Internal) MCO pin. This code aims to change the clock source to HSI and route it to gpio A pin 8. The output is captured by the logic analyzer.

![](HSE%20configuration%20logic%20analyzer%20output.png)

clock frequency of 8MHz with prescaler = 4 is measured by the logic analyzer in pulseview
