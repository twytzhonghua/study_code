
#include "Time.hpp"
#include <iostream>

using namespace std;

Time AddTime(Time& time1, Time& time2)
{
	int hour, second, minute =0;
	
	second = time1.m_nSecond + time2.m_nSecond;
	if(second > 60){
			second -=60;
			minute ++;
	}
	
	minute += time1.m_nMinute + time2.m_nMinute;
	if(minute > 60){
			minute -=60;
			hour ++;
	}
	
	hour += time1.m_nHour + time2.m_nHour;
	
	Time time(hour, minute, second);
	
	return time;
}

#if 0
Time operator+(Time& time1, Time& time2)
{
	int hour, second, minute =0;
	
	second = time1.m_nSecond + time2.m_nSecond;
	if(second > 60){
			second -=60;
			minute ++;
	}
	
	minute += time1.m_nMinute + time2.m_nMinute;
	if(minute > 60){
			minute -=60;
			hour ++;
	}
	
	hour += time1.m_nHour + time2.m_nHour;
	
	Time time(hour, minute, second);
	
	return time;
}
#endif



int main()
{

	Time time1(10,22,10);
	Time time2(10,52,55);

	Time time3 = AddTime(time1, time2);
	//Time time4 = time1 + time2; //默认调用Time operator+(Time& time1, Time& time2)
	Time time5 = time1 + time2;
	
	time3.displayTime();
	//time4.displayTime();
	time5.displayTime();
	
	return 0;
}
