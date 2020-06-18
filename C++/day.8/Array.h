#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>
using namespace std;

template<typename _T>
class Array{
public:
	class Iterator{
	public:
		Iterator(){		//无参数构造函数
			ptr = NULL;
			len = 0;
			counter = 0;		 
		}

		Iterator(const Iterator &p){ //拷贝构造函数
			ptr = p.ptr;
			len = p.len;
			counter = p.counter;		 
		}

		friend Iterator Array::begin()const; //友员

	private:
		Iterator(const _T *p, int size){ //限制构造函数
			ptr = const_cast<_T*>(p);
			len = size;
			counter = 0;		 
		}
	
	public:
		_T* operator-> () const{
			if((0 <= counter) && (counter < len))
				return ptr;
			throw out_of_range("operator-> : out of range.");
		}

		_T& operator* () const{
			if((0 <= counter) && (counter < len))
				return *ptr;
			throw out_of_range("operator* : out of range.");
		}

		_T& operator[] (const int id) const throw(out_of_range){
			if((0 <= id) && (id < len))
				return ptr[id];
			throw out_of_range("operator[] : id is out of range.");
		}

		_T* operator++ () throw(out_of_range){
			if((len-1) > counter){
				++counter;
				return ++ptr;
			}
			--counter;
			throw out_of_range("operator++ : out of range.");
		}

		_T* operator++ (int) throw(out_of_range){
			_T* p = ptr;
			if((len-1) >= counter){
				counter++;
				ptr++;
				return p;
			}
			throw out_of_range("operator++ : out of range.");
		}

		_T* operator-- () throw(out_of_range){
			if(counter > 0){
				--counter;
				return --ptr;
			}
			throw out_of_range("operator-- : out of range.");
		}

		_T* operator-- (int) throw(out_of_range){
			_T* p = ptr;
			if(counter >= 0){
				counter--;
				ptr--;
				return p;
			}
			throw out_of_range("operator-- : out of range.");
		}

	private:
		_T* ptr;
		int len;
		int counter;
	};
public:
	Array(const int size) :
		len(size),
		addr(new _T[size])
	{
	}

	Array(const _T val, int size) :
		len(size),
		addr(new _T[size])
	{
		for(int i = 0; i < len; i++){
			addr[i] = val;
		}
	}

	Array(const Array &arr) :
		len(arr.len),
		addr(new _T[arr.len])
	{
		for(int i = 0; i < len; i++){
			addr[i] = arr.addr[i];
		}
	}

	~Array()
	{
		delete [] addr;
	}

public:
	_T& at(const int id) const{
		return addr[id];
	}

	_T& operator[](const int id)const{
		return addr[id];
	}

	const int size() const{
		return len;
	}

	Iterator begin()const{		
		return Iterator(addr, len);
	}

private:
	_T* const addr;
	const int len;
};

#endif