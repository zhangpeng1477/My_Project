#include <stdio.h>

//�Զ������ͣ����û�ж��������������û���κοռ����
struct demo{
	int x;
	int y;
	int (*add)(struct demo *);
};

int func(struct demo *p)
{
	return p->x+p->y;
}

#if 0
struct demo a = {
	x : 1,		//��ȷ��ʼ���Ǹ���Ա
	y : 1,
	add: func,
};
struct demo a = {
	.x = 1,		//��ȷ��ʼ���Ǹ���Ա
	.y = 1,
	.add = func,
};

#else
struct demo a = {1,1,func}; //���������ʼ��
#endif

int main(int argv, char *argc[])
{
	//���ṹ���Ա��ֵ������
	a.x = 1;
	a.y = 1;
	a.add = func;

	a.add(&a);

	return 0;
}

