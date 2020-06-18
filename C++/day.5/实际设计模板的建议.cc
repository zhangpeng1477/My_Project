#include <iostream>
using namespace std;

//声明定义在一起
//因为：模板没有使用实例，则没有代码产生，故此不能单独编译成库
//一般设计到头文件中
template <typename T=int>
class Demo{
public:
	Demo(const T val){
		this->val = val;
	}

	void setval(const T val){
		this->val = val;
	}

	T getval()const{
		return val;
	}


private:
	T val;
}; 

int main()
{
	Demo<> a(1);
	//Demo a(1); error

	cout << "val = " << a.getval() << endl;

	Demo<char> b('a');
	cout << "val = " << b.getval() << endl;

}


