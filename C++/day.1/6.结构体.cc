#include <stdio.h>

//自定义类型：如果没有定义变量，概念上没有任何空间分配
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
	x : 1,		//明确初始化那个成员
	y : 1,
	add: func,
};
struct demo a = {
	.x = 1,		//明确初始化那个成员
	.y = 1,
	.add = func,
};

#else
struct demo a = {1,1,func}; //声明定义初始化
#endif

int main(int argv, char *argc[])
{
	//给结构体成员赋值：代码
	a.x = 1;
	a.y = 1;
	a.add = func;

	a.add(&a);

	return 0;
}

