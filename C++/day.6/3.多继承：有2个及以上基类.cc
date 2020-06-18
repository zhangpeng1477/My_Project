#include <iostream>
using namespace std;

class man{
public:
	man(){
		cout << "-------" << __func__ << "------------" << endl;
	}

	~man(){
		cout << "-------" << __func__ << "------------" << endl;
	}

	void prnmanmsg(){
		cout << "-------" << __func__ << "------------" << endl;
	}
};

class wolf{
public:
	wolf(){
		cout << "-------" << __func__ << "------------" << endl;
	}

	~wolf(){
		cout << "-------" << __func__ << "------------" << endl;
	}

	void prnwolfmsg(){
		cout << "-------" << __func__ << "------------" << endl;
	}
};

class wolfman : public man, public wolf{
public:
	wolfman(){
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


