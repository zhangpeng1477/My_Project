/*
 * 线程封装演示-C版本
 * write by panzhh
 * 2011.12.24
 */
#include <stdio.h>
#include <stdlib.h>
#include "mythr.h"

#define TRACE(str) printf("%s:%s:%s:%d\n", str, __FILE__, __FUNCTION__, __LINE__); 

static void *routine(void *arg)
{
	PMYTHR pthr=(PMYTHR)arg;
	
	printf("tid = 0x%.8x\n", pthr->tid);

	pthread_mutex_init(&pthr->mutex, NULL);
	pthread_cond_init (&pthr->cont, NULL); 

	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	//pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

	do{
		pthread_mutex_lock(&pthr->mutex);
		if(pthr->bthrsusend){
			if(0 != pthread_cond_wait (&pthr->cont, &pthr->mutex)){
				perror("work:pthread_cond_wait");
				break;
			}
		}
		pthread_mutex_unlock(&pthr->mutex);

		//执行线程
		if(0 > pthr->run(pthr->arg))
			break;
	}while(pthr->bthrun);

	pthread_cond_destroy(&pthr->cont);
	pthread_mutex_destroy(&pthr->mutex);

	return (void *)0;
}

int thr_start(PMYTHR pthr)
{
	if(NULL != pthr->run){
		return pthread_create(&pthr->tid, NULL, routine, (void *)pthr);
	}

	return -1;
}

int thr_wait(PMYTHR pthr)
{
	if(NULL != pthr->run){
		return pthread_join(pthr->tid, NULL);
	}

	return -1;
}

int thr_cancel(PMYTHR pthr)
{
	if(NULL != pthr->run){
		pthread_cancel(pthr->tid);

		pthread_cond_destroy(&pthr->cont);
		pthread_mutex_destroy(&pthr->mutex);
		return 0;
	}

	return -1;
}

void thr_exit(PMYTHR pthr)
{
	if(NULL != pthr->run){
		pthread_mutex_lock(&pthr->mutex);
		pthr->bthrun = false;
		pthread_mutex_unlock(&pthr->mutex);
	}
}

void thr_suspend(PMYTHR pthr)
{
	pthread_mutex_lock(&pthr->mutex);
	if(!pthr->bthrsusend){
		pthr->bthrsusend = true;
	}
	pthread_mutex_unlock(&pthr->mutex);
}

void thr_resume(PMYTHR pthr)
{
	pthread_mutex_lock(&pthr->mutex); 
	if(pthr->bthrsusend){
		pthr->bthrsusend = false;
		pthread_cond_signal(&pthr->cont);
	} 
	pthread_mutex_unlock (&pthr->mutex);
}

int getthrstatus(PMYTHR pthr)
{
	return (pthr->bthrsusend ? S_SUSPEND : S_RUNNING);
}
