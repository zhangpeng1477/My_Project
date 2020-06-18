#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class IntArray{
public:
	IntArray(const int len){
		arr = new int[len];
		size = len;
		cout << "============normal============" << endl;
	}
	IntArray(const IntArray &obj){
		size = obj.size;

		arr = new int[size];
		for(int i = 0; i < size; i++)
			arr[i] = obj.arr[i];
		cout << "============copy============" << endl;
	}

	//析构函数：对象销毁时自动被调用，如果对象存在，也可以显示调用
	//作用：负责回收构造分配的资源
	~IntArray(){
		if(arr)
			delete [] arr;

		cout << "============end============" << endl;
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

///IntArray a(MAX);

void test()
{
#if 1
	//static IntArray c(MAX);
	//IntArray a(MAX);
	//IntArray b = a;

	IntArray *p = new IntArray(MAX);
	//p->~IntArray();
	//delete p;
#endif
}

int main()
{
	cout << "-------main 1-------\n";
	test();
	test();
	cout << "-------main 2-------\n";
}


