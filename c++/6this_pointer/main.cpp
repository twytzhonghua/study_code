
#include "Time.hpp"
#include <iostream>

using namespace std;

void func(Time time)
{
	cout<<time.getHour()<<endl;
}

Time& func1(Time& time)
{
	cout<<time.getHour()<<endl;
	return time;
}


int main()
{
	Time time1(10, 12, 12);
	Time time2;

	Time time3(time1);
	
	func(time2);
	
	cout<<"get current NuM"<<Time::getNum()<<endl;
	
	Time time4 = func1(time3);
	
	cout<<time1.getHour()<<":"<<time1.getMinute()<<":"<<time1.getSecond()<<endl;
	cout<<time2.getHour()<<":"<<time2.getMinute()<<":"<<time2.getSecond()<<endl;
	cout<<time3.getHour()<<":"<<time3.getMinute()<<":"<<time3.getSecond()<<endl;
	cout<<time4.getHour()<<":"<<time4.getMinute()<<":"<<time4.getSecond()<<endl;
}