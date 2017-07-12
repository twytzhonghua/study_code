#include "Time.hpp"


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