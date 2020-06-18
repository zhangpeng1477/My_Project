#include <iostream>
using namespace std;

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "BaseIO.h"

size_t BaseIO::read(void* buf, size_t count)
{
	return ::read(fd, buf, count);
}

bool BaseIO::write(const void* buf, size_t count)
{
	return (-1 != ::write(fd, buf, count)) ? true : false;
}

size_t BaseIO::read(ByteArray &arr)
{
	char *p = arr.data();
	int len = arr.length();

	return ::read(fd, p, len);
}

bool BaseIO::close()
{
	return (-1 != ::close(fd)) ? true : false;
}

bool BaseIO::write(const ByteArray &arr)
{
	const char *p = arr.data();
	int len = arr.length();

	return (len == ::write(fd, p, len)) ? true : false;
}

off_t BaseIO::seek(off_t offset, int whence)
{
	return ::lseek(fd, offset, whence);
}
