#include <stdio.h>

int i=1;
void prnmsg()
{
	printf("g: i = %d\n", i);
}


namespace myspace {
	int i=2;
	void prnmsg()
	{
		printf("myspace: i = %d\n", i);
	}
}

int main()
{
	myspace::prnmsg();	//显示调用名字空间myspace中的prnmsg
	prnmsg();	//没有声明名字空间，全局的
	::prnmsg(); //没有名字，全局
}


