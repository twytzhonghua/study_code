#include "Date.hpp"
#include "Time.hpp"
#include <iostream>


CDate::CDate(int year, int month, int day)
	:m_nYear(year), m_nMonth(month), m_nDay(day)
{
}

void CDate::display(Time& time)
{
	std::cout<<m_nYear<<"-"<<m_nMonth<<"-"<<m_nDay<<std::endl;
	std::cout<<time.m_nHour<<"-"<<time.m_nMinute<<"-"<<time.m_nSecond<<std::endl;
}	
