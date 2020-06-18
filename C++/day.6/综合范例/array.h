#ifndef ARRAY_H
#define ARRAY_H

#include <assert.h>

template <typename T=int>
class Array{
public:
	Array(const int size):max(size),addr(new T[size]){
		assert(NULL != addr);
	}

	Array(const Array<T> &obj):
		addr(new T[obj.max]),
		max(obj.max)
	{
		assert(NULL != addr);
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
			size= len;
			pos = 0;
		}
	
		friend Iterator Array::begin() const;

	public:
		T& operator *() const{
			assert((0<=pos) && (pos < size));
			return *ptr;			
		}

		T* operator ->()const {
			assert((0<=pos) && (pos < size));
			return ptr;
		}

		T* operator++(){
			assert(pos < (size-1));

			++ptr;
			++pos;
			return ptr;
		}

		T* operator++(int){
			assert(pos < size);

			T* p = ptr;
			ptr++;
			pos++;
			return p;
		}

		T* operator--(){
			assert(0 < pos);

			--ptr;
			--pos;
			return ptr;
		}

		T* operator--(int){
			assert(0 <= pos);

			T* p = ptr;
			ptr--;
			pos--;
			return p;
		}

	private:
		T* ptr;
		int pos;
		int size;
	};

public:
	T& at(const int id) const{
		assert((0<=id) && (id<max));
		return addr[id];
	}

	T& operator[](const int id) const{
		assert((0<=id) && (id<max));
		return addr[id];
	}

	Iterator begin() const{
		Iterator a(addr, max);
		return a;
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
