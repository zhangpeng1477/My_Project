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
	myspace::prnmsg();	//��ʾ�������ֿռ�myspace�е�prnmsg
	prnmsg();	//û���������ֿռ䣬ȫ�ֵ�
	::prnmsg(); //û�����֣�ȫ��
}


