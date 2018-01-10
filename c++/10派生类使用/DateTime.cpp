#include "DateTime.hpp"
#include <iostream>
using namespace std;


CDateTime::CDateTime()
{
	
}

CDateTime::~CDateTime()
{
	
}

CDateTime::CDateTime(int year, int month, int day, int hour, int minute, int second)
{
	m_nYear = year;
	m_nMonth = month;
	m_nDay = day;
	
	m_time.setHour(hour);
	m_time.setMinute(minute);
	m_time.setSecond(second);
	
	
}

void CDateTime::Display()
{
	cout<<m_nYear<<"_"<<m_nMonth<<"-"<<m_nDay<<"-"<<m_time.getHour()<<"-"<<m_time.getMinute()<<"-"<<m_time.getSecond()<<endl;
}
