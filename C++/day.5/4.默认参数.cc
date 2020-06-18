#include <iostream>
using namespace std;

template <typename T=int> //Ĭ�����Ͳ���Ϊint���û�����ȷָ�����ͣ���T����Ϊint
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

	Demo<> a(1); //ok,ʹ��Ĭ������int
	//Demo a(1);//error

	cout << "val = " << a.getval() << endl;

	Demo<char> b('a');
	cout << "val = " << b.getval() << endl;

}


