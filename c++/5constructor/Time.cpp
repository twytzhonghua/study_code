#include "Time.hpp"
#include <iostream>

Time::~Time()
{
	std::cout<<"~CTime"<<std::endl;
}



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
	m_nHour = hour;	
}

void Time::setMinute(int Minute)
{
	m_nMinute = Minute;	
}

void Time::setSecond(int second)
{
	m_nSecond = second;	
}

