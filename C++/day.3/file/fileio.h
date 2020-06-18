#ifndef FILEIO_H
#define FILEIO_H

class FileIO{
public:
	FileIO(const char *filename="i.txt");
	FileIO(const FileIO &);
	~FileIO();

public:
	size_t read(void *buf, size_t size);
	size_t write(const void *buf, size_t size);

private:
	int fd;
};

#endif
