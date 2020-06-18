#include <stdio.h>

int main(int argv, char *argc[])
{
	int i = 123456;
	int &j = i; //j是i的别名：引用

	int *p = &i;//一个存在地址的指针，保存了i的地址

	printf("val: i=%d, j=%d, *p=%d\n", i, j, *p);
	printf("addr: i=%p, j=%p, p=%p, %p\n", &i, &j, p, &p);

	return 0;
}

