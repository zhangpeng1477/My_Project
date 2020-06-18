#include <iostream>
using namespace std;

//����ģ���࣬T��һ�����Ͳ��������û�ָ��
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
	//���ʵ���������ʽ˵��
	Demo<int> a(1);

	cout << "val = " << a.getval() << endl;

	Demo<char> b('a');
	cout << "val = " << b.getval() << endl;

}


