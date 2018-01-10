#include "CurrentTime.hpp"
#include <ctime>
#include <iostream>

CCurrentTime::CCurrentTime()
{
	std::cout<<"CurrentTime constructor~"<<std::endl;
}


CCurrentTime::~CCurrentTime()
{
	std::cout<<"CurrentTime destructor~"<<std::endl;
}


void CCurrentTime::init()
{
	time_t t = time(0);
	tm tt = *localtime(&t);
	
	setHour(tt.tm_hour);
	setMinute(tt.tm_min);
	setSecond(tt.tm_sec);
}

int CCurrentTime::getHour()
{
	int nHour = Time::getHour(); //需要指定基类的类名, 防止重复调用
	if (nHour > 12){
		nHour -= 12;
	}
	
	return nHour;
}
