#ifndef BASEIO_H
#define BASEIO_H

#include "array.h"

typedef Array<char> ByteArray;

class BaseIO{
protected:
	BaseIO();

public:
	size_t read(void* buf, size_t count);
	bool write(const void* buf, size_t count);

	size_t read(ByteArray &);
	bool write(const ByteArray &);

	off_t seek(off_t offset, int whence);

	bool close();

protected:
	int fd;
};

#endif

