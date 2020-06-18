#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class IntArray{
public:
	IntArray(const int len){
		arr = new int[len];
		if(arr){
			for(int i = 0; i < size; i++)
				arr[i] = obj.arr[i];
			size = len;
		}else{
			size = 0;
		}
	}
	IntArray(const IntArray &obj){
		size = obj.size;

		arr = new int[size];
		if(arr){
			for(int i = 0; i < size; i++)
				arr[i] = obj.arr[i];
		}else{
			size = 0;
		}		
	}

	int& at(const int id){
		if( (0 <= id) && (id < size) )
			return arr[id];
		//有待解决
		//异常处理
	}

	int *addr(){
		return arr;
	}

private:
	int *arr;
	size_t size;
};

int main()
{
#define MAX 12
	IntArray a(MAX);
	IntArray b = a;
	cout << "a: addr: " << a.addr() << endl;
	cout << "b: addr: " << b.addr() << endl;

	b = a; //没有"="运算符重载，则编译器会生成一个默认的，这里是浅拷贝，不合理

	Demo *p = &a; //取对象的地址，如果没有重载&，则编译器会默认生成的
}


