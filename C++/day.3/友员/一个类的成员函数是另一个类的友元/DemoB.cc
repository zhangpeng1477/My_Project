#include "DemoA.h"
#include "DemoB.h"

DemoB::DemoB()
{
}

int DemoB::getval(const DemoA &obj)
{
	return obj.ival;
}
