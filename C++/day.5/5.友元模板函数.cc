#include <iostream>
using namespace std;

template<typename T>
class Data{
public:
	Data(const T a);
	Data(const Data &);

	//因为类是模板，友元可以访问类的私有数据，故此友元函数往往也是模板
	//如果友元函数仅仅是在类声明，那么得单独声明自己的模板类型参数
	template<typename C>
	friend void setval(Data<C> &, const T&);

	template<typename C>
	friend C getval(Data<C> &);

private:
	T val;
};

template<typename C>
Data<C>::Data(const C val)
{
	this->val = val;
}

template<typename T>
Data<T>::Data(const Data &obj)
{
	this->val = obj.val;
}

template<typename T>
void setval(Data<T> &obj, const T& val)
{
	obj.val = val;
}

template<typename C>
C getval(Data<C> &obj)
{
	return obj.val;
}


int main()
{
#define MAX 3
	Data<char> a('a');

	setval<int>(a, '1');

	cout << "val = " << getval<char>(a) << endl;
}


