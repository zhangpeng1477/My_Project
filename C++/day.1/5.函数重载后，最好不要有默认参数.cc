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
	//ȷ�ϵ�һ���汾int add(int x=0, int y=0),��Ϊ�ð汾���Բ����ݲ�����
	//x=0,y=0
	printf("%d\n", add());

	//��������ѡ�汾��������壬�������޷����б�д
	//�ʴ˺���������ò�Ҫ��Ĭ�ϲ���
	printf("%d\n", add(1));
	return 0;
}

