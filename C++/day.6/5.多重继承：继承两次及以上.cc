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
		prnswmsg(); //这里是调用wolf的唯一明确基类sw的prnswmsg()成员函数，没有歧义
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
		prnswmsg(); //这里是调用wolf的唯一明确基类sw的prnswmsg()成员函数，没有歧义
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
		prnswmsg(); //这里有歧义：man和wolf有通用的基类sw，且prnswmsg是sw的成员
			//那么在wolfman中有两份sw的代码，即有两个prnswmsg函数
			//通过名字无法确认调用哪个函数
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


