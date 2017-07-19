#ifndef STIME_H_
#define STIME_H_
class CDate;
class Time
{
public:
	Time();
	Time(int hour, int minute, int second);
	Time(Time &time);
	
	~Time();
	
	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);
	
	int getHour();
	int getMinute();
	int getSecond();	
	static int getNum();
	
	friend void func(); //这个声明可以放在任何地方, 友元函数
	friend CDate;		//声明 Time是 CDate的 友元类
private:
	int m_nHour;
	int m_nMinute;
	int m_nSecond;
	
	static int m_nNum;
};

#endif
