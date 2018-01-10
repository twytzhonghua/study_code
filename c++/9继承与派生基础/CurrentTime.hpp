#ifndef CURRENT_H_
#define CURRENT_H_
#include "Time.hpp"


class CCurrentTime : public Time
{
public:
	CCurrentTime();
	~CCurrentTime();

public:
	void init();	
};


#endif
