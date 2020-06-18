#include <iostream>
#include <memory>
using namespace std;

class Demo{
public:
	Demo(){
		cout << this << "----------normal-------------\n";
	}

	Demo(const Demo &obj){
		cout << this << "----------copy-------------\n";
	}

	~Demo(){
		cout << this << "---------- ~ -------------\n";
	}

	void prnmsg()const {
		cout << "---------- prnmsg -------------\n";
	}
};

//指针智能：模板+运算符重载
template<typename T>
class Pointer{
public:
	Pointer(const T *p):
		ptr(const_cast<T*>(p))
	{
	}

	Pointer(const T &){
		cout << "----------------------" << endl;
	}

	~Pointer(){
		delete ptr;
	}

	T* operator -> ()const{
		return ptr;
	}

	T& operator * () const{
		return *ptr;
	}

private:
	T* const ptr;
};

int main()
{
	Pointer<Demo> p(new Demo);
	//Pointer<Demo> pp=p;
	//Pointer<Demo> pp(p);

	p->prnmsg();
	(*p).prnmsg();
	

	return 0;
}


