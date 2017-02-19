### Topics(目標)
- 介紹 ARM mbed 的 Analog 介面
- 撰寫程式直接更改 ARM mbed 的類比電壓
- [Lab3連結](http://www1.ee.nthu.edu.tw/ee240500/mbed-lab-3-analog-input.html#id7)

#### 學會用 Analog 的訊號作為 Input
要產生的三種功能：
1. 使用 AnalogOut 控制 LED 燈(要產生以下波形)
![](http://www1.ee.nthu.edu.tw/ee240500/notes/mbed3/img/3_1_6.png)
2. 使用 PWMout 控制LED 燈(要產生以下波形)
![](http://www1.ee.nthu.edu.tw/ee240500/notes/mbed3/img/3_2_3_2.png)
![](http://www1.ee.nthu.edu.tw/ee240500/notes/mbed3/img/3_2_4.png)
3. 把量測到的東西顯示在電腦螢幕上
4. 測量取樣數不足時造成的問題

##### **記得他的 Input 會傳到Port A Output 會傳到 AWS**
![](http://www1.ee.nthu.edu.tw/ee240500/notes/mbed3/img/3_1_4.jpg)
#### 任務
1. Know how to read the analog input.
2. Know how to obtain K64F outputs from terminal.

#### **Questions about the topic or our lab**
1. 要如何能夠找出 Nyquist Frequency？
2. 可以直接使用三用電錶去測量這些值嗎？

* **Related parts of our lab**

[ARM embed 官方 API 介紹](https://developer.mbed.org/handbook/AnalogIn)
