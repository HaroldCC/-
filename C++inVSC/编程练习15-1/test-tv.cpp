/*************************************************************************
    > File Name       : test-tv.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-09 13:30:06
 ************************************************************************/
#include<iostream>
#include "tv.h"


int main(int argc,char *argv[])
{
	using std::cout;
	Tv s42;
	cout << "初始化for42\"TV:\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\n调整42\"TV的设置：\n";
	s42.chanup();
	cout << "\n调整42\"TV的设置：\n";
	s42.settings();

	Remote grey;

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n使用遥控器后的42\"TV:\n";
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\ns58\"settings:\n";
	s58.settings();

	grey.displayMode();
	s58.ChangeRemoteMode(grey);
	cout << "TV s58 change remote's mode:\n";
	grey.displayMode();
     
    return 0;
}

