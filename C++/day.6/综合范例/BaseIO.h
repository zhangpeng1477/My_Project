#ifndef BASEIO_H
#define BASEIO_H

#include "array.h"

typedef Array<char> BYTEARR;

class BaseIO{
protected:
	BaseIO();

public:
	size_t read(void *buf, size_t count);
	size_t write(const void *buf, size_t count);

	size_t read(BYTEARR &);
	bool write(const BYTEARR &);

	bool close();

protected:
	int fd;
};

#endif
