#include <iostream>
using namespace std;

#include <assert.h>

class Array{
public:
	Array(const int len=1024);
	Array(const Array &);

	~Array();

public:
	int& at(const int id)const;		//得到数组一个成员（不安全，因为id可能越界）
	int& operator[](const int id)const;	//运算符得到数组一个成员（不安全，因为id可能越界）

	class Pointer{ //Pointer类的在Array的作用范围，是独立的类
	public:
		Pointer(int *p, int len);
	
		int* operator++();	//指向缓存地址+1，前++
		int* operator++(int);	//指向缓存地址+1，后++

		int *operator->() const{//得到引用缓存的一个成员地址
			return ptr;
		}

		int& operator*() const{ //得到指向缓存的一个成员
			return *ptr;
		}

	private:
		int *ptr;	//当前指针
		int pos;	//保存当前指针位置
		const int size; //保存缓存长度
	};

	Pointer begin(){ //得到一个迭代器
		//由于迭代器构造有参数，主要是传递缓存的首地址和长度
		//用户传参也可能出现问题，那么封装成使用函数就安全了
		Pointer tmp(addr, size);
		return tmp;
	}	
	
private:
	int *const addr;	//数组类的内部整型数组首地址
	const size_t size;	//数组类的内部整型数组长度
};

Array::Pointer::Pointer(int *p, const int len):
	size(len)
{
	ptr = p;
	pos = 0;
}

int* Array::Pointer::operator++()
{
	if(pos < (size-1)){
		++ptr;
		++pos;
		return ptr;
	}

	return NULL;
}

int* Array::Pointer::operator++(int)
{
	int *p = ptr;

	if(pos < size){
		ptr++;
		pos++;
		return ptr;
	}

	return NULL;
}

Array::Array(const int len):
	addr(new int[len]),
	size(len)
{
	assert(NULL != addr);
	cout << "-------normal---------\n";
}

Array::Array(const Array &obj):
	addr(new int[obj.size]),
	size(obj.size)
{
	assert(NULL != addr);
	for(int i = 0; i < size; i++){
		addr[i] = obj.addr[i];
	}
	cout << "-------copy---------\n";
}

Array::~Array()
{
	delete [] addr;
}

int& Array::at(const int id)const
{
	assert((0<=id) && (id < size));
	return addr[id];
}

int& Array::operator[](const int id)const
{
	//assert((0<=id) && (id < size));
	return addr[id];
}


int main()
{
#define MAX 6
	Array arr(MAX);

	Array::Pointer p = arr.begin();

	int i;
	for(i = 0; i < 2*MAX; i++){
		*p = 'a';
		if(NULL == ++p)
			break;
	}

	cout << "i = " << i << endl;
}


