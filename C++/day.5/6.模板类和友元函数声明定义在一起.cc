#include <iostream>
using namespace std;

template<typename T>
class Data{
public:
	Data(const T a){
		val = a;
	}
	Data(const Data &obj){
		val = obj.val;
	}

	//因为声明定义都在类体内，故此不需要单独声明自己的模板的类型参数
	friend void setval(Data<T> &obj, const T& val){
		obj.val = val;
	}

	friend T getval(Data<T> &obj){
		return obj.val;
	}

private:
	T val;
};

int main()
{
#define MAX 3
	Data<char> a('a');

	//因为友元函数模板类型参数没有单独声明，那么类使用声明，自己解析为友元函数的类型
	setval(a, '1');
	//setval<int>(a, '1'); error

	cout << "val = " << getval(a) << endl;
}


