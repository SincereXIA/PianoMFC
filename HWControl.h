#pragma once

#include "StdAfx.h"
#include "QTH9054fun.h"
#include "QTH9054ioctl.h"

#define P8254A 0x00
#define P8254B 0x01
#define P8254C 0x02
#define P8254MODE 0x03

#define BASEFREQ 32680 //
extern BOOL isLocalSound;
extern BOOL init8254();
extern void set_freq_dividing_ratio(int ratio,int time);
extern void delay(int nms);
extern int freq_list[8];
extern float flag;
extern int get_div_ratio(int freqnum,float flag);
extern void play_music(int music_num);
extern void play_one_tone(int freq,float flag);
extern void play_one_toneL(char c);
extern void setBeat(float b);
extern void setRhythm(bool rhythm);