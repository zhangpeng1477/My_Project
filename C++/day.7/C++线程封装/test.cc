#include <iostream>
using namespace std;

#include <unistd.h>
#include <stdio.h>
#include "thread.h"

class MyThread1 : public Thread{
public:
	MyThread1(const int val=0){
		i = val;
	}

	void run(){
		cout << "NO." << i++ << ": hello world" << endl;
		::sleep(1);
	}

private:
	int i;
};

class MyThread2 : public Thread{
public:
	MyThread2(const int val=1){
		i = val;
	}

	void run(){
		cout << "NO." << i++ << ": aaaaaaaaaaaaaaaaaaaaaaa" << endl;
		::sleep(1);
	}

private:
	int i;
};

int main()
{
	MyThread1 thr1;
	MyThread2 thr2;

	thr1.start();

	::sleep(1);

	thr2.start();

	while(1){
		getchar();
		thr1.stop();
		thr2.stop();
	}
}


