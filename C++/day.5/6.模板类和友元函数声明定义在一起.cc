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

	//��Ϊ�������嶼�������ڣ��ʴ˲���Ҫ���������Լ���ģ������Ͳ���
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

	//��Ϊ��Ԫ����ģ�����Ͳ���û�е�����������ô��ʹ���������Լ�����Ϊ��Ԫ����������
	setval(a, '1');
	//setval<int>(a, '1'); error

	cout << "val = " << getval(a) << endl;
}


