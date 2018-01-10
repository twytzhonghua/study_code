#include "Time.hpp"
#include <iostream>

Time::~Time()
{
	m_nNum--;
	std::cout<<"~CTime num="<<m_nNum<<std::endl;
}


//把老的对象传递给新的对象时会调用
// 把对象传给函数的形参， 也会调用复制构造函数
Time::Time(Time &time)
{
	m_nHour = time.m_nHour;
	m_nMinute = time.m_nMinute;
	m_nSecond = time.m_nSecond;
	std::cout<<"copy constructor"<<std::endl;
	m_nNum++;
	std::cout<<"CTime num="<<m_nNum<<std::endl;
}

Time::Time()
{
	m_nHour = 1;
	m_nMinute = 1;
	m_nSecond = 1;
	m_nNum++;
	std::cout<<"CTime num="<<m_nNum<<std::endl;
}


Time::Time(int hour, int minute, int second)
{
	m_nHour = hour;
	m_nMinute = minute;
	m_nSecond = second;
	m_nNum++;
	std::cout<<"CTime num="<<m_nNum<<std::endl;
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

int Time::m_nNum =0;

int Time::getNum()
{
	return m_nNum;
}
