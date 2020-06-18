#include <iostream>
using namespace std;

template<typename T>
class Data{
public:
	Data(const T a);
	Data(const Data &);

	//��Ϊ����ģ�壬��Ԫ���Է������˽�����ݣ��ʴ���Ԫ��������Ҳ��ģ��
	//�����Ԫ����������������������ô�õ��������Լ���ģ�����Ͳ���
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


