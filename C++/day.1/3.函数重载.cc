#include <stdio.h>
/*
 *�������أ�������һ����������һ�������������ͣ�����
 *ʲôӦ�����أ���Ϊ���ƣ����⺯�������� 
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

