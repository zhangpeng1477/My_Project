#include <stdio.h>

int main(int argv, char *argc[])
{
	int i = 123456;
	int &j = i; //j��i�ı���������

	int *p = &i;//һ�����ڵ�ַ��ָ�룬������i�ĵ�ַ

	printf("val: i=%d, j=%d, *p=%d\n", i, j, *p);
	printf("addr: i=%p, j=%p, p=%p, %p\n", &i, &j, p, &p);

	return 0;
}

