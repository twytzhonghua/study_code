#ifndef CURRENT_H_
#define CURRENT_H_
#include "Time.hpp"


class CCurrentTime : public Time
{
public:
	CCurrentTime();
	~CCurrentTime();
	
	int getHour();

public:
	void init();	
};


#endif
