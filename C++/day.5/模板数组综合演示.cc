#include <iostream>
using namespace std;

#include <assert.h>

template <typename T=int, int max=1024>
class Array{
public:
	Array():addr(new T[max]){
		assert(NULL != addr);
	}

	Array(const T &obj):addr(new T[max])
	{
		assert(NULL != addr);
		for(int i = 0; i < max; i++){
			addr[i] = obj;
		}
	}

	Array(const Array<T, max> &obj):addr(new T[max])
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

private:
	T* const addr;
};

int main()
{
#define MAX 3
	Array<char, MAX> a('a');

	Array<char, MAX>::Iterator p = a.begin();

	for(int i = 0; i < MAX; i++){
		cout << "a[" << i << "] = " << *p << endl;
		p++;
	}

	p = a.begin();
	for(int i = 0; i < MAX; i++){
		*p = 'a'+i;
		p++;
	}

	--p;
	for(int i = 0; i < MAX; i++){
		cout << "a[" << i << "] = " << *p << endl;
		p--;
	}
	cout << "--------done-------\n";
}


