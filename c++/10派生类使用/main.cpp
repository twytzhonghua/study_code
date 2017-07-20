#include <iostream>
#include "Time.hpp"
#include "CurrentTime.hpp"
#include "DateTime.hpp"

using namespace std;


int main()
{
	CCurrentTime curTime;
	curTime.init();
	
	curTime.displayTime();
	
	cout<<curTime.getHour()<<endl;
		
	Time time = curTime;
	time.displayTime();
	
	Time* pTime = &curTime;
	pTime->getHour(); //基类的指针只能调用基类的方法, 不能调用派生类的方法
		
	CDateTime dateTime(2017, 7, 20, 10, 55, 50);	
	dateTime.Display();
		
	return 0;
}
