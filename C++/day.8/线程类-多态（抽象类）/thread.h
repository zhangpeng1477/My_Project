#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>

class Thread{
protected:
	Thread(){
		::pthread_mutex_init(&mutex, NULL);
		::pthread_cond_init (&cont, NULL);
	}
	
	virtual ~Thread(){
		::pthread_mutex_destroy(&mutex);
		::pthread_cond_destroy(&cont);
	}

public:
	bool start(bool isSuspend = false){
		this->isSuspend = isSuspend;
		int ret = ::pthread_create(&tid, NULL, routine, (void *)this);

		return !ret ? true : false; 
	}

	bool stop(){
		::pthread_mutex_lock(&mutex);
		if(isSuspend){
			isSuspend = false;
			::pthread_mutex_unlock(&mutex);
			resume();
		}else{
			::pthread_mutex_unlock(&mutex);
		}

		int ret = ::pthread_cancel(tid);
		return !ret ? true : false;
	}

	bool wait(){
		int ret = ::pthread_join(tid, NULL);
		return !ret ? true : false;
	}

	bool suspend(){
		::pthread_mutex_lock(&mutex);
		if(!isSuspend){
			isSuspend = true;
		}
		::pthread_mutex_unlock(&mutex);
	}
	
	bool resume(){
		::pthread_mutex_lock(&mutex);
		if(isSuspend){
			isSuspend = false;
			::pthread_mutex_unlock(&mutex);
			::pthread_cond_signal(&cont);
		}else{
			::pthread_mutex_unlock(&mutex);
		}
	}

	virtual void run() = 0;
	
protected:
	static void *routine(void *arg)
	{
		Thread* thr = (Thread*)arg;

		::pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
		//pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
		::pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
		
		do{
			::pthread_mutex_lock(&thr->mutex);
			if(thr->isSuspend){
				::pthread_cond_wait (&thr->cont, &thr->mutex);
			}
			::pthread_mutex_unlock(&thr->mutex);

			thr->run();
		}while(1);
	}

private:
	pthread_t tid;
	pthread_mutex_t mutex;
	pthread_cond_t cont;

	bool isSuspend;
};
#endif
