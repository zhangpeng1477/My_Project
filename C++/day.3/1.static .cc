#include <iostream>
using namespace std;

#if 0
��̬��Ա:��Ա���ݺͳ�Ա����
1�����÷�Χ����ķ�Χ
2���������κ��������û�ж����У���Ψһ��һ��
#endif
class Demo{
public:
	Demo(int val = 0){
		ival = val;
	}

	void setval(int val);
	static int getval(); //������̬��Ա����

private:
	static int ival;	//������̬��Ա����
};

int Demo::ival;		//���徲̬��Ա����
//int Demo::ival = 0;	//���徲̬��Ա���ݣ�����ʼ��

void Demo::setval(int val)
{
	ival = val;//��Ϊ��̬��Ա�������������Թ��캯�����Է���

	//����::��̬��Ա
	Demo::ival = val;//��ȷ��̬��Ա����ival�����÷�ΧҲ����
}

int Demo::getval()
{
	return ival;
}

int main()
{

}


