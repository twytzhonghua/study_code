#include "Time.hpp"
#include <iostream>

Time::~Time()
{

}

#if 0
//把老的对象传递给新的对象时会调用
// 把对象传给函数的形参， 也会调用复制构造函数
Time::Time(Time& time)
{
	m_nHour = time.m_nHour;
	m_nMinute = time.m_nMinute;
	m_nSecond = time.m_nSecond;
	std::cout<<"copy constructor"<<std::endl;
	m_nNum++;
	std::cout<<"CTime num="<<m_nNum<<std::endl;
}
#endif

Time::Time()
{
	m_nHour = 1;
	m_nMinute = 1;
	m_nSecond = 1;
}


Time::Time(int hour, int minute, int second)
{
	m_nHour = hour;
	m_nMinute = minute;
	m_nSecond = second;
}

int Time::getHour()
{
	return m_nHour;
}

int Time::getMinute()
{
	return m_nMinute;
}

int Time::getSecond()
{
	return m_nSecond;
}


void Time::setHour(int hour)
{
	this->m_nHour = hour;	
}

void Time::setMinute(int Minute)
{
	m_nMinute = Minute;	
}

void Time::setSecond(int second)
{
	m_nSecond = second;	
}


void Time::displayTime()
{
	std::cout<<this->getHour()<<"-"<<this->m_nMinute<<"-"<<this->m_nSecond<<std::endl;
}


Time Time::operator+(Time& time)
{
	int hour, second, minute =0;
	
	second = this->m_nSecond + time.m_nSecond;
	if(second > 60){
			second -=60;
			minute ++;
	}
	
	minute += this->m_nMinute + time.m_nMinute;
	if(minute > 60){
			minute -=60;
			hour ++;
	}
	
	hour += this->m_nHour + time.m_nHour;
	
	return Time(hour, minute, second);
}


