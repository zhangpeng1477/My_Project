#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>
using namespace std;

#include <assert.h>

template <typename T=int>
class Array{
public:
	Array(const int size) throw(bad_alloc):
		addr(new T[size]),
		max(size_t(size))
	{
	}

	Array(const Array<T> &obj) throw(bad_alloc):
		addr(new T[obj.max]),
		max(obj.max)
	{
		for(int i = 0; i < max; i++){
			addr[i] = obj.addr[i];
		}
	}

	~Array(){
		delete [] addr;
	}

public:
	class Iterator{
	public:
		Iterator(const Iterator &obj){
			ptr = obj.ptr;
			size= obj.size;
			pos = obj.pos;
		}
	private:
		Iterator(T* p, const int len){
			ptr = p;
			size= size_t(len);
			pos = 0;
		}
	
		friend Iterator Array::begin() const;

	public:
		T& operator *() const throw(overflow_error, underflow_error)
		{
			if(pos < 0){
				throw underflow_error("pos is too small");
			}else if(pos >= size){
				throw overflow_error("pos is too big");
			}

			return *ptr;
		}

		T* operator ->()const throw(overflow_error, underflow_error)
		{
			if(pos < 0){
				throw underflow_error("pos is too small");
			}else if(pos >= size){
				throw overflow_error("pos is too big");
			}
			return ptr;
		}

		T* operator++()throw(overflow_error)
		{
			if(size_t(pos) >= (size-1)){
				throw overflow_error("pos is too big");
			}

			++ptr;
			++pos;
			return ptr;
		}

		T* operator++(int)throw(overflow_error)
		{
			if(size_t(pos) >= size){
				throw overflow_error("pos is too big");
			}

			T* p = ptr;
			ptr++;
			pos++;
			return p;
		}

		T* operator--()throw(underflow_error)
		{
			if(pos <= 0){
				throw underflow_error("pos is too small");
			}

			--ptr;
			--pos;
			return ptr;
		}

		T* operator--(int)throw(underflow_error)
		{
			if(pos < 0){
				throw underflow_error("pos is too small");
			}

			T* p = ptr;
			ptr--;
			pos--;
			return p;
		}

	private:
		T* ptr;
		int pos;
		size_t size;
	};

public:
	T& at(const int id) const throw(overflow_error, underflow_error)
	{
		if(id < 0){
			throw underflow_error("id is too small");
		}else if(size_t(id) >= max){
			throw overflow_error("id is too big");
		}
		
		return addr[id];
	}

	T& operator[](const int id) const throw(overflow_error, underflow_error)
	{
		if(id < 0){
			throw underflow_error("id is too small");
		}else if(size_t(id) >= max){
			throw overflow_error("id is too big");
		}

		return addr[id];
	}

	Iterator begin() const{
		Iterator p(addr, max);
		return p;
	}

	T* data() const{
		return addr;
	}

	size_t length() const{
		return max;
	}

private:
	T* const addr;
	size_t max;
};

#endif
