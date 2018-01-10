#include <iostream>
#include "Time.hpp"
#include "CurrentTime.hpp"


using namespace std;


int main()
{
	CCurrentTime curTime;
	curTime.init();
	
	curTime.displayTime();
	
	return 0;
}
