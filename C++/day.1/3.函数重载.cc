#include <stdio.h>
/*
 *函数重载：函数名一样，参数不一样（数量，类型，次序）
 *什么应该重载：行为相似，避免函数名过多 
 */
int add(int x, int y)
{
	return x+y;
}

char add(char x, char y, char z)
{
	return x+y+z;
}

int main(int argv, char *argc[])
{
	printf("%d\n", add(1,2));
	printf("%c\n", add('a', 1, 2));

	return 0;
}

