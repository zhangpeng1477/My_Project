#include <iostream>
#include <stdexcept>
using namespace std;

#include <unistd.h>
#include <stdio.h>
#include "thread.h"

int mydiv(const int x, const int y)
throw(invalid_argument) //声明该函数支持invalid_argument异常
{
	if(0 != y)
		return x/y;

#if 0
	//构造异常对象，其构造函数的参数就是错误信息
	invalid_argument tmp("ERROR!!! y is zero."); 
	throw tmp;//throw抛出异常，实质是原地址跳转：添到函数外的catch段
#else
	//没有取对象名的临时对象
	throw invalid_argument("ERROR!!! y is zero.");;
#endif
}

int main()
{
#if 0
	try{ //支持异常的函数必须放在try块，才能被捕获异常
		cout << "1/2 = " << mydiv(1, 2) << endl;
		cout << "1/0 = " << mydiv(1, 0) << endl;
	}catch(const invalid_argument &err){ //catch块：用于捕获异常
		cout << "DEMO: " << err.what() << endl;
	}

	cout << "----------------------------" << endl;
#else
	mydiv(1, 0);//没有try及catch块，异常抛出后，进程跳出
#endif

	return 0;
}


