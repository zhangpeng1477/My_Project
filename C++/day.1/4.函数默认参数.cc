#include <stdio.h>

//�����Ĳ���������Ĭ��ֵ
int add(int x=1, int y=2)
{
	return x+y;
}
#if 0
//OK����߿���û��Ĭ�ϲ���
int add(int x, int y=2)
{
	return x+y;
}

//���󣬱��룺�ұ߲���û��Ĭ�ϲ���
int add(int x=1, int y)
{
	return x+y;
}

//���󣬱��룺����������Ĭ�ϲ���
int add(int x=1, int y�� int z=0)
{
	return x+y+z;
}

#endif
int main(int argv, char *argc[])
{
	printf("%d\n", add()); //xû�д��Σ���Ĭ��1��yû�д��Σ���Ĭ��2
	printf("%d\n", add(3)); //x���Σ���3��yû�д��Σ���Ĭ��2
	printf("%d\n", add(4,5));//x���Σ���4��y���Σ���5

	return 0;
}

