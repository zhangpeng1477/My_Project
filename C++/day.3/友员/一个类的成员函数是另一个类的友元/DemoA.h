#ifndef DEMOA_H
#define DEMOA_H

#include "DemoB.h"

class DemoA{
public:
	DemoA(const int val=0);

private:
	friend int DemoB::getval(const DemoA &);
	int ival;
};

#endif

