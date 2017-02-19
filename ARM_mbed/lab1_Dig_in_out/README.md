cs(目標)
- 介紹 ARM mbed 的 I/O 介面
- 撰寫 3 個程式分別觀測 LED 燈, 七段顯示器, 以及按鈕
- [Lab1連結](http://www1.ee.nthu.edu.tw/ee240500/mbed-lab-1-digital-output-and-input.html#id5)

#### LED 燈
* **Introduction**：在 ARM mbed 版上有三個 LED 燈，分別顯示紅、藍、綠


#### 七段顯示器
* **Introduction**：
1. 在 ARM mbed 板上並沒有七段顯示器，但可用電路外接到麵包板顯示之
2. 七段顯示器所對應的16 bit 表
![Picture1](http://www1.ee.nthu.edu.tw/ee240500/notes/mbed1/img/mbed_1_7seg_table.png)
3. 板子上的連結按照(MSB) dp g f e d c b a (LSB) 來排列，***需注意方向***！！
![Picture2](http://www1.ee.nthu.edu.tw/ee240500/notes/mbed1/img/mbed_1_7seg_pin.png)

#### Digital Input(按鈕)
* **Introduction**：
1. 在 ARM mbed 板上除了 reset 按鈕之外，還有另外一顆按鈕
![picture3](http://www1.ee.nthu.edu.tw/ee240500/notes/mbed1/img/K64F_SW2.png)

#### 任務
1. know how to control the digital output.
2. know how to read the digital input.
3. Please write a program to display 0, 1, 2, 3 in order on a seven-segment display when the button is pressed sequentially.

#### **Questions about the topic or our lab**
1. 要如何才能維持在不同的 State，以顯示0 1 2 3？ 
2. 要如何外接到不同的 output 裝置(不單單是七段顯示器)

* **Related parts of our lab**
)
