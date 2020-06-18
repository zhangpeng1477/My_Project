#include <iostream>
using namespace std;

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "File.h"

File::File(const char*f):
	filname(f)
{
	//filname = f;
}

File::File(const String &f):
	filname(f)
{
	//filname = f;
}

bool File::open(int flag)
{
	const char *f = filname.data();
	fd = ::open(f, flag);
	return (-1 != fd) ? true : false;
}

bool File::creat(mode_t mode)
{
	const char *f = filname.data();
	return (-1 != ::creat(f, mode)) ? true : false;
}
