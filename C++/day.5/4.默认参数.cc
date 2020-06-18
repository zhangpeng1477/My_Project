#include <iostream>
using namespace std;

template <typename T=int> //默认类型参数为int，用户不明确指定类型，则T类型为int
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
#if 0
Demo<int> a(1);
--->
class Demo{
public:
	Demo(const int val);

	void setval(const int val);
	int getval()const;

private:
	int val;
}; 
#endif

	Demo<> a(1); //ok,使用默认类型int
	//Demo a(1);//error

	cout << "val = " << a.getval() << endl;

	Demo<char> b('a');
	cout << "val = " << b.getval() << endl;

}


