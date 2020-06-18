#ifndef ARRAY_H
#define ARRAY_H

#define T int

class Array{
public:
	Array(const int len = 1024);
	Array(const Array &);
	~Array();
	
public:
	T& at(const int id);
	int length()const;

#if 1
	friend Array append(const Array &, const Array &);
#else
	static Array append(const Array &, const Array &);
#endif

private:
	T* const addr;
	const int size;
};

#endif

