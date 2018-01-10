
#include "Time.hpp"
#include <iostream>
#include "Date.hpp"
using namespace std;

void func()
{
	Time time1(10, 12, 12);
	time1.m_nHour = 3;
	cout<<"hour = "<<time1.m_nHour<<endl;
	cout<<time1.getHour()<<":"<<time1.getMinute()<<":"<<time1.getSecond()<<endl;
}



int main()
{
	//func();
	Time time2(10,22,10);
	
	CDate date(2017,7,17);
	date.display( time2 );
	
	return 0;
}
