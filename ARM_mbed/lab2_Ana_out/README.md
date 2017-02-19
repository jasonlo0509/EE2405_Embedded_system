### Topics(目標)
- 介紹 ARM mbed 的 Analog 介面
- 撰寫程式直接更改 ARM mbed 的類比電壓
- [Lab2連結](http://www1.ee.nthu.edu.tw/ee240500/mbed-lab-2-analog-output.html)

#### 學會使用工具 Picoscope 2204A
* **Introduction**：可以同時顯示該條線的類比和數位訊號
1. 學會在 Linux 上安裝他


#### 更改 ARM mbed 的一個 pin 腳並且更動它的值 
* **Introduction**：
1. 在 ARM mbed 板上預設不會有類比的輸出，所以一定要自己處理
2. 記得是量哪一個 pin 腳
![picture1](http://www1.ee.nthu.edu.tw/ee240500/notes/mbed2/img/2_1_6.png)
3. 按照下圖接！
![picture2](http://www1.ee.nthu.edu.tw/ee240500/notes/mbed2/img/k64f_aout.png)


##### 要產生的三種訊號：
1. 三個 Voltage 電壓之間彼此 Switch
2. 等差級數的電壓上升
3. Sin 波

#### 產生 PWM (週期性方波)：
1. 要做出這個功能，要記得選取支援 PWM 函式的 pin 腳
![](http://www1.ee.nthu.edu.tw/ee240500/notes/mbed2/img/2_4_4.png)
2. 按照下圖接！
![](http://www1.ee.nthu.edu.tw/ee240500/notes/mbed2/img/2_4_1.jpg)



#### 任務
1. You need to know how to use Picoscope 2204A
2. You need to know how to control the analog output.
3. You need to know how to control the PWM output.
4. Can you output a PWM signal from a DAC output pin?

#### **Questions about the topic or our lab**
1. 是否能夠產生連續的 Output ，在上面的研究中都只有看到接近連續的 Sin 波？？

* **Related parts of our lab**

