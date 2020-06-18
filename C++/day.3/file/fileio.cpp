#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#include "fileio.h"

//���������ʱ��ϵͳ�Զ����ù��캯��
//Ҫ��ֻ����ɶ���ĳ�ʼ�����ܹ�����ʼ���Ľ��������ݳ�Ա��
//����дҲ����Ĭ�ϣ����������ɣ�
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

//����������Ҫ����������������
//��������ʱ��ϵͳ�Զ���������
//��������������ʽ���ã�����ʹ�ã�
//����дҲ����Ĭ�ϣ����������ɣ�
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
