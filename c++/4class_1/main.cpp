
#include "Time.hpp"
#include <iostream>

using namespace std;

int main()
{
	Time time;
	time.setHour(10);
	time.setMinute(50);
	time.setSecond(20);
	
	cout<<time.getHour()<<":"<<time.getMinute()<<":"<<time.getSecond()<<endl;
	
}