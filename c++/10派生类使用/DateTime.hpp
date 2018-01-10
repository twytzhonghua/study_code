#ifndef _DATE_TIME_H_
#define _DATE_TIME_H_

#include "Time.hpp"

class CDateTime
{
public:
	CDateTime();
	CDateTime(int year, int month, int day, int hour, int minute, int second);
	
	~CDateTime();
	
	void Display();

private:
	int m_nYear;
	int m_nMonth;
	int m_nDay;
	
	Time m_time;	//作为 CDateTime的内部类,  has -a 关系
};

#endif
