#include <iostream>
using namespace std;

class man{
public:
	man(const int val = 0){
		cout << "-------" << __func__ << "------------" << endl;
		ival = val;
	}

	~man(){
		cout << "-------" << __func__ << "------------" << endl;
	}

	void prnmanmsg(){
		cout << "---ival = " << ival << "------------" << endl;
	}

private:
	int ival;
};

class wolf{
public:
	wolf(const char ch){
		cout << "-------" << __func__ << "------------" << endl;
		this->ch = ch;
	}

	~wolf(){
		cout << "-------" << __func__ << "------------" << endl;
	}

	void prnwolfmsg(){
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


