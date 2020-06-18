#include <iostream>
using namespace std;

//声明模板类，T是一个类型参数，让用户指定
template <typename T>
class Demo{
public:
	Demo(const T val);

	void setval(const T val);
	T getval()const;

private:
	T val;
}; 

template <typename T>
Demo<T>::Demo(const T val)
{
	this->val = val;
}

template <typename T>
void Demo<T>::setval(const T val)
{
	this->val = val;
}

template <typename T>
T Demo<T>::getval()const
{
	return val;
}


int main()
{
	//类的实际类必须显式说明
	Demo<int> a(1);

	cout << "val = " << a.getval() << endl;

	Demo<char> b('a');
	cout << "val = " << b.getval() << endl;

}


