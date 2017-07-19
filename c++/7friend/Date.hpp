#ifndef _DATE_H_
#define _DATE_H_
class Time;  //类的前置声明
class CDate
{
public:
	CDate(int year, int month, int day);
	
	void display(Time& time);
private:
	int m_nYear;
	int m_nMonth;
	int m_nDay;
	
};



#endif
