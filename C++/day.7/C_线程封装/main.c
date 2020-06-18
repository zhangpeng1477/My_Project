/*
 * 线程封装演示-C版本
 * write by panzhh
 * 2011.12.24
 */
#include <stdio.h>
#include <stdlib.h>

#include "mythr.h"

#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <unistd.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */

pid_t gettid(void)
{
	return syscall(SYS_gettid);
}

int demo_one(void *arg)
{
	char *str = (char *)arg;
	printf("0x%.8x: Thread running: %s\r\n", gettid(), str);
	sleep(1);

	return 0;
}
MYTHR thr_one={
	.run = demo_one,
	.arg = "hello",
	.bthrun = true,
	.bthrsusend = false
};

int demo_two(void *arg)
{
	char *str = (char *)arg;
	printf("0x%.8x: Thread running: %s\r\n", gettid(), str);
	sleep(1);

	return 0;
}
MYTHR thr_two={
	.run = demo_two,
	.arg = "world",
	.bthrun = true,
	.bthrsusend = false
};
int main(int argc, char **argv)
{
	thr_start(&thr_one);
	thr_start(&thr_two);

	while(1){
		char ch = getchar();
		switch(ch){
		case 'r':
			thr_resume(&thr_one);
			break;
		case 'R':
			thr_resume(&thr_two);
			break;

		case 's':
			thr_suspend(&thr_one);
			break;

		case 'S':
			thr_suspend(&thr_two);
			break;

		case 'c':
		case 'C':
			thr_cancel(&thr_one);
			thr_cancel(&thr_two);
			goto NEXT_STEP;

		case 'e':
		case 'E':
			thr_resume(&thr_one);
			thr_resume(&thr_two);
			thr_exit(&thr_one);
			thr_exit(&thr_two);
			goto NEXT_STEP;
		};
	}

NEXT_STEP:
	thr_wait(&thr_one);
	thr_wait(&thr_two);

	return 0;
}
