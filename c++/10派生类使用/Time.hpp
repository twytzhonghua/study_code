#ifndef STIME_H_
#define STIME_H_

class Time;
class Time
{
public:
	Time();
	Time(int hour, int minute, int second);
	//Time(Time& time);
	
	~Time();
	
	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);
	
	int getHour();
	int getMinute();
	int getSecond();	
	
	void displayTime();
	Time operator+(Time& time);
	
	friend Time AddTime(Time& time1, Time& time2);
	//friend Time operator+(Time& time1, Time& time2);
private:
	int m_nHour;
	int m_nMinute;
	int m_nSecond;
	
	static int m_nNum;
};

#endif

