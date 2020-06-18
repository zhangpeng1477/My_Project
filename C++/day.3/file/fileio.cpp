#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#include "fileio.h"

//当对象产生时，系统自动调用构造函数
//要求：只能完成对象的初始化（能够被初始化的仅仅是数据成员）
//不编写也会有默认（编译器生成）
FileIO::FileIO(const char *filename)
{
	fd = ::open(filename, O_RDWR);
	if(0 > fd){
		perror("open");
	}
}

FileIO::FileIO(const FileIO &obj)
{
	fd = obj.fd;
}

//析构函数：要求，做回收清理工作，
//对象销毁时，系统自动调用析构
//析构函数可以显式调用（避免使用）
//不编写也会有默认（编译器生成）
FileIO::~FileIO()
{
	if(-1 != fd){
		::close(fd);
	}
}

size_t FileIO::read(void *buf, size_t size)
{
	return ::read(fd, buf, size);
}

size_t FileIO::write(const void *buf, size_t size)
{
	return ::write(fd, buf, size);
}
