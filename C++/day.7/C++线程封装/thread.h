#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>

class Thread{
protected:
	Thread(){
		isRun = false;
	}
	~Thread(){
	}

public:
	bool start(){
		int ret = ::pthread_create(&tid, NULL, routine, (void *)this);
		if(!ret){
			isRun = true;
		}else{
			isRun = false;
		}

		return isRun;
	}

	bool stop(){
		if(isRun){
			isRun = false;
		}
	}

	void wait(){
		::pthread_join(this->tid, NULL);
	}

	virtual void run() = 0;
	
protected:
	static void *routine(void *arg)
	{
		Thread* p = (Thread *)arg;
		while(p->isRun){
			p->run();
		}

		return (void *)0;
	}

private:
	pthread_t tid;
	bool isRun;
};
#endif
