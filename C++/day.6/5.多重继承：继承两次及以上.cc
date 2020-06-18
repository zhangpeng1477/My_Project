#include <iostream>
using namespace std;

class sw{
public:
	sw(){
		cout << "-------" << __func__ << "------------" << endl;
	}

	~sw(){
		cout << "-------" << __func__ << "------------" << endl;
	}

	void prnswmsg(){
		cout << "-------" << __func__ << "------------" << endl;
	}
};

class man : public sw{
public:
	man(const int val = 0){
		cout << "-------" << __func__ << "------------" << endl;
		ival = val;
	}

	~man(){
		cout << "-------" << __func__ << "------------" << endl;
	}

	void prnmanmsg(){
		prnswmsg(); //�����ǵ���wolf��Ψһ��ȷ����sw��prnswmsg()��Ա������û������
		cout << "---ival = " << ival << "------------" << endl;
	}

private:
	int ival;
};

class wolf : public sw{
public:
	wolf(const char ch){
		cout << "-------" << __func__ << "------------" << endl;
		this->ch = ch;
	}

	~wolf(){
		cout << "-------" << __func__ << "------------" << endl;
	}

	void prnwolfmsg(){
		prnswmsg(); //�����ǵ���wolf��Ψһ��ȷ����sw��prnswmsg()��Ա������û������
		cout << "---ch = " << ch << "------------" << endl;
	}

private:
	char ch;
};


class wolfman : public man, public wolf{ 
public:
	wolfman(const int val=0, char ch='a'):
		man(val), wolf(ch)
	{
		cout << "-------" << __func__ << "------------" << endl;
	}

	~wolfman(){
		cout << "-------" << __func__ << "------------" << endl;
	}

	void prnwolfmanmsg(){
		prnswmsg(); //���������壺man��wolf��ͨ�õĻ���sw����prnswmsg��sw�ĳ�Ա
			//��ô��wolfman��������sw�Ĵ��룬��������prnswmsg����
			//ͨ�������޷�ȷ�ϵ����ĸ�����
		cout << "-------" << __func__ << "------------" << endl;
	}
};



int main()
{
	wolfman a;

	a.prnmanmsg();
	a.prnwolfmsg();
	a.prnwolfmanmsg();
}


