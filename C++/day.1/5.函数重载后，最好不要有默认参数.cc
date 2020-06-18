#include <stdio.h>

int add(int x=0, int y=0)
{
	return x+y;
}

int add(int x)
{
	return x+x;
}

int main(int argv, char *argc[])
{
	//确认第一个版本int add(int x=0, int y=0),因为该版本可以不传递参数，
	//x=0,y=0
	printf("%d\n", add());

	//有两个备选版本，造成歧义，编译器无法进行编写
	//故此函数重载最好不要有默认参数
	printf("%d\n", add(1));
	return 0;
}

