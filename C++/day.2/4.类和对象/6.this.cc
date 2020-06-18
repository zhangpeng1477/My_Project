#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class IntArray{
public:
	IntArray(const int len){
		arr = new int[len];
		size = len;
		cout << this << "============normal============" << endl;
	}
	IntArray(const IntArray &obj){
		size = obj.size;

		arr = new int[size];
		for(int i = 0; i < size; i++)
			arr[i] = obj.arr[i];
		cout << this << "============copy============" << endl;
	}

	~IntArray(){
		if(arr){
			delete [] arr;
			arr = NULL;
		}

		cout << this << "============end============" << endl;
	}

	int& at(const int id){
		return arr[id];
	}

	int *addr(){
		return arr;
	}

private:
	int *arr;
	size_t size;
};

#define MAX 12

IntArray a(MAX);

void test()
{

	static IntArray c(MAX);
	IntArray b(MAX);

//a.this ;

	IntArray *p = new IntArray(MAX);

	cout << "globel: " << &a << endl;
	cout << "static: " << &c << endl;
	cout << "local: " << &b << endl;
	cout << "heap: " << p << endl;
}

int main()
{
	cout << "-------main 1-------\n";
	test();
	test();
	cout << "-------main 2-------\n";
}


