#include <unistd.h>
#include "BaseIO.h"

BaseIO::BaseIO()
{

}

size_t BaseIO::read(void *buf, size_t count)
{
	return ::read(fd, buf, count);
}


size_t BaseIO::write(const void *buf, size_t count)
{
	return ::write(fd, buf, count);
}

size_t BaseIO::read(BYTEARR &obj)
{
	size_t len = obj.length();
	void *p = obj.data();
	return ::read(fd, p, len);
}

bool BaseIO::write(const BYTEARR &obj)
{
	size_t len = obj.length();
	void *p = obj.data();
	return (len == ::write(fd, p, len)) ? true : false;
}

bool BaseIO::close()
{
	return (-1 != ::close(fd)) ?  true : false;
}
