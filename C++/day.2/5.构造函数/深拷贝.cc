#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class IntArray{
public:
	IntArray(const int len){
		arr = new int[len];
		size = len;
	}
	//默认的拷贝构造是浅拷贝：即仅仅是对应的数据成员赋值
	//这个示例需要深拷贝
	IntArray(const IntArray &obj){
		size = obj.size;
		//分配自己的堆区
		arr = new int[size];

		//对象的堆数据内容拷贝
		for(int i = 0; i < size; i++)
			arr[i] = obj.arr[i];
	}

	//返回值是引用
	//因为at()运行完成，arr是成员数据，不会消失，那么就可以返回arr的别名，实质是返回arr
	//外部就可以直接操作arr,但是是通过公共接口得到的别名来完成的。
	int& at(const int id){
		return arr[id];
	}

private:
	int *arr;
	size_t size;
};

int main()
{
#define MAX 12
	IntArray a(MAX);
	for(int i = 0; i < MAX; i++){
		a.at(i) = i; //at()返回的是arr的别名，故此作为左值是可以的
				//实质是给arr赋值
	}

	IntArray b = a;

	for(int i = 0; i < MAX; i++){
		cout << "a[" <<i << "]=" << a.at(i) << endl;
	}

	for(int i = 0; i < MAX; i++){
		cout << "b[" <<i << "]=" << b.at(i) << endl;
	}
}


