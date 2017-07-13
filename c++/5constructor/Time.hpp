#ifndef STIME_H_
#define STIME_H_

class Time
{
public:
	Time();
	Time(int hour, int minute, int second);

	~Time();
	
	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);
	
	int getHour();
	int getMinute();
	int getSecond();	
	
private:
	int m_nHour;
	int m_nMinute;
	int m_nSecond;
};

#endif