# PianoMFC
西电微机原理课设项目，键盘电子乐器演奏程序设计（电子琴），MFC 

需要连接西电微机原理实验室提供的 QTH9054 微机试验箱，使用其蜂鸣器发声，若不连接，程序会直接播放 mp3 文件模拟钢琴声。

请在 release 处下载编译好的 exe 文件运行，如需计算机喇叭发声，请选择声卡输出，并保证 sound 文件夹与 piano.exe 在同一目录下。

## 功能设计

**基础功能**

1. 能够演奏 C 调包含高、中、低音的不同节拍的乐曲，音调与频率的对应关系如下： 

   微机键盘与电子琴键盘的对应关系为：高音依次为 Q,W,E,R,T,Y,U，中音依次为A,S,D,F,G,H,J，低音依次为 Z,X,C,V,B,N,M。

**附加功能**

1. 增加自动演奏乐曲功能。当按下 P 键后，自动播放一首乐曲，曲长大于 20 秒。 
2. 增加琴键图形显示功能。屏幕上显示 21 个琴键（高中低音），当按下某键后屏幕上的对应琴键有所反映。 
3. 增加一个音调 D，当从 C 调改为 D 调后，演奏音按照 D 调(比 C 高一个调)发音。  

**进阶功能**

1. 实现键位切换功能：除了基础功能要求的按键映射关系外，额外增加可以选择 按键A~Z 对应于音调的最低音到最高音
2. 实现声卡输出功能：在脱离了微机实验箱的情况下，程序仍然能够使用计算机内置的声卡，通过计算机喇叭或者耳机进行声音的输出 

## 环境要求

- 开发环境：
  - 开发工具：实验室给定的 Visual C++ 6.0 
  - 操作系统：实验室给定的 Windows XP
- 软件执行环境
  - 执行程序需要在 WIndows 平台上运行，在 Windows10、Windows 7 、Windows XP 上通过兼容性测试
  - QTH9054 微机试验箱 （可选）

### 为什么用 vc6.0

因为实验室的电脑上面只有 vc6.0

## 硬件设计方案及硬件连线图

硬件部分使用8254定时器，控制音调的高低，为了使蜂鸣器发出声音，使用高频时钟脉冲信号（32.768KHz），向8254写入方式三控制字，之后通过改变计数值值来获得期望得到的脉冲信号，将可听频率内的脉冲信号直接接入蜂鸣喇叭，获得声音输出。

**硬件连线**：

- 总线 LD0-LD7 接8254的 D0-D7 ，
- LA0和LA1接8254的A0和A1，
- IOWR和IORD接8254的WR和RD，
- 地址0000H接8254的CS
- 8254的GATE0接VCC
- CLK0接初始的时钟频率32.768KHZ
- OUT0接蜂鸣器输入

![](http://media.sumblog.cn/img/20190327200132.png-min_pic)

### 硬件驱动部分设计

使蜂鸣喇叭发出声音的核心是 `set_freq_dividing_ratio()` 函数，其参数 `ratio` 设定了计数值，`time` 定义了声音发出的时长。

开始时，先写入 8254 的方式控制字，使其工作在方式 3，之后写入计数值。该方式输出的是方波。如果初始计数值是N， 那么方波的频率是输入时钟的N分之一。该方式的特点是方波占空比约为1比1 

```c++
void set_freq_dividing_ratio(int ratio,int time)
{
	if(ratio!=0){
		IO8bWrite(P8254MODE,0x14);//0x03
		char input = (char)(ratio);
		IO8bWrite(P8254A,input);
	}
	Sleep(time);
	IO8bWrite(P8254MODE,0x10);
}
```

而计数值则由`play_one_tone()` 函数通过查表并计算得出

```c++
void play_one_tone(int freqnum,float flag)
{
	//printf("\b%c%c\n",tone_list[freqnum-1][0],tone_list[freqnum-1][1]);
	int div_ratio = get_div_ratio(freqnum, flag);
	if (isLocalSound){
		if(flag < 1) flag = 0;
		play_one_toneL('a'+freqnum-1 + flag*7);
	}else{
		set_freq_dividing_ratio(div_ratio,beat);
	}
}
```



## 测试结果与功能展示

执行编译好的 Piano.exe 文件，完成硬件驱动检测后，即会弹出电子乐器演奏程序的主界面

![](http://media.sumblog.cn/img/20190327200955.png-min_pic)

界面中部为模拟的电子琴界面，界面下部为设置界面。

单击右下角的帮助按钮，弹出帮助窗口，对程序功能进行说明

![](http://media.sumblog.cn/img/20190327201423.png-min_pic)

按下键盘按键，微机试验箱上的蜂鸣器就会发出指定音调的声音。

可以通过点击按钮来设定 C/D 调 以及声音长度（节拍）。如果选择声卡输出，则会使用计算机的内置声卡进行钢琴音的模拟

![](http://media.sumblog.cn/img/20190327202039.png-min_pic)

点击右下角的歌曲按钮，会自动播放内置的音频

![](http://media.sumblog.cn/img/20190327202125.png-min_pic)

工作中的微机试验箱：

![](http://media.sumblog.cn/img/20190327202248.jpg-min_pic)