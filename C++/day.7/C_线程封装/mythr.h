/*
 * 线程封装演示-C版本
 * write by panzhh
 * 2011.12.24
 */

#ifndef MYTHR_H
#define MYTHR_H

#include <pthread.h>

#define true  1
#define false 0

typedef unsigned int bool;

typedef int (*RUN)(void *arg);

typedef struct __mythr{
	RUN  run;
	void *arg;
	bool bthrun;
	bool bthrsusend;

	/*private item*/
	pthread_t tid;
	pthread_mutex_t mutex;
	pthread_cond_t cont;
}MYTHR, *PMYTHR;

int thr_start(PMYTHR pthr);
int thr_wait(PMYTHR pthr);
int thr_cancel(PMYTHR pthr);
void thr_exit(PMYTHR pthr);

void thr_suspend(PMYTHR pthr);
void thr_resume(PMYTHR pthr);

#define S_SUSPEND	0
#define S_RUNNING	1

int getthrstatus(PMYTHR pthr);

#endif
