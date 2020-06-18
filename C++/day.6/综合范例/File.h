#ifndef FILE_H
#define FILE_H

//#include <limits.h>
#include <string>
using namespace std;

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "BaseIO.h"

#define F_RD O_RDONLY
#define F_WR O_WRONLY
#define F_RW O_RDWR

class File: public BaseIO{
public:
	File(const char *filname);
	File(const string &f);

	bool open(int flags);
	off_t lseek(off_t offset, int whence);

private:
	//char filname[NAME_MAX];
	string filname;
};

#endif

