#include <string>
using namespace std;

#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "File.h"

File::File(const char *f):
	filname(f)
{
}

File::File(const string &f)
{
	filname = f;
}

bool File::open(int flags)
{
	char *p = (char *)filname.data();
	fd = ::open(p, flags);

	return (-1 != fd) ? true : false;
}

off_t File::lseek(off_t offset, int whence)
{
	return ::lseek(fd, offset, whence);
}
