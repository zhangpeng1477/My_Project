#ifndef STRING_H
#define STRING_H

class String{
public:
	String(const char *str = NULL);
	String(const char &);
	String(const String &);

	~String();

public:
	char& at(const int id) const;
	char& operator[](const int id) const;

	String& operator=(const String &);
	String& operator=(const char *);

	char* data()const;
	size_t length()const;

private:
	char *addr;
	size_t size;
};

#endif
