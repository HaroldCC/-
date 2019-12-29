/*************************************************************************
    > File Name       : tv.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-09 10:51:19
 ************************************************************************/
#include<iostream>
#include "tv.h"

bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown() 
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::chanup()
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;
}

void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;
}

void Tv::settings() const
{
	using std::cout;
	using std::endl;
	cout << "TV is " << (state == Off ? "Off" : "On") << endl;
	if (state == On)
	{
		cout << "Volume setting = " << volume << endl;
		cout << "Channel setting = " << channel << endl;
		cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
		cout << "Input = " << (input == TV ? "TV" : "DVD") << endl;
	}
}

bool Tv::ChangeRemoteMode(Remote& r)
{
	if (ison())
	{
		r.N_INmode = (r.N_INmode == Remote::Normal) ? Remote::Interactive : Remote::Normal;
		return true;
	}
	else 
		return false;
}


void Remote::displayMode() const
{
	using std::cout;
	using std::endl;
	cout << "control mode = " << (mode == Tv::TV ? "TV" : "DVD") << endl;
	cout << "inter mode = " << (N_INmode == Normal ? "normal" : "interactive") << endl;
}
