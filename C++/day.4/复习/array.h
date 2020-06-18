#ifndef ARRAY_H
#define ARRAY_H

#define T double

class Array{
public:
	Array(const int len = 1024);
	Array(const Array &);

	~Array();

public:
	T& at(const int id)const;
	
	friend Array append(const Array &a, const Array &b);
	static bool compare(const Array &a, const Array &b);

private:
	T * const addr;
	const size_t size;
};

Array append(const Array &a, const Array &b);

#endif

