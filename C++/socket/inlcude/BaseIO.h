#ifndef BASEIO_H
#define BASEIO_H

#include "Array.h"

typedef Array<char> ByteArray;

class BaseIO{
public:
	virtual bool open(int flag)=0;
	virtual bool close();

	size_t read(void* buf, size_t count);
	bool write(const void* buf, size_t count);

	size_t read(ByteArray &);
	bool write(const ByteArray &);

	virtual off_t seek(off_t offset, int whence);

protected:
	int fd;
};

#endif

