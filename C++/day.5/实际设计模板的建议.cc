#include <iostream>
using namespace std;

//����������һ��
//��Ϊ��ģ��û��ʹ��ʵ������û�д���������ʴ˲��ܵ�������ɿ�
//һ����Ƶ�ͷ�ļ���
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


