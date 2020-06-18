#ifndef FILE_H
#define FILE_H

#include "String.h"
#include "BaseIO.h"

class File : public BaseIO{
public:
	File(const char*);
	File(const String &);

public:
	bool open(int flag);
	bool creat(mode_t mode);

private:
	String filname;
};

#endif
