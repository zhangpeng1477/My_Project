#include <stdio.h>

//函数的参数允许有默认值
int add(int x=1, int y=2)
{
	return x+y;
}
#if 0
//OK，左边可以没有默认参数
int add(int x, int y=2)
{
	return x+y;
}

//错误，必须：右边不能没有默认参数
int add(int x=1, int y)
{
	return x+y;
}

//错误，必须：不能两边有默认参数
int add(int x=1, int y， int z=0)
{
	return x+y+z;
}

#endif
int main(int argv, char *argc[])
{
	printf("%d\n", add()); //x没有传参，则默认1；y没有传参，则默认2
	printf("%d\n", add(3)); //x传参，是3；y没有传参，则默认2
	printf("%d\n", add(4,5));//x传参，是4；y传参，是5

	return 0;
}

