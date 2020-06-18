#include <iostream>
using namespace std;

#include <unistd.h>
#include <stdio.h>
#include "thread.h"

class MyThread : public Thread{
public:
	MyThread(const int val=0){
		i = val;
	}

	void run(){
		cout << this << ", NO." << i++ << ": hello world" << endl;
		::sleep(1);
	}

private:
	int i;
};

int main()
{
	MyThread thr1(1);
	MyThread thr2;

	thr1.start(true);
	thr2.start();

	while(1){
		char c;

		cin >> c;

		switch(c){
		case 's':
			thr1.suspend();
			break;
		case 'S':
			thr2.suspend();
			break;
		case 'r':
			thr1.resume();
			break;
		case 'R':
			thr2.resume();
			break;

		case 'q':
		case 'Q':
			thr1.stop();
			thr2.stop();
			return 0;
		};
	}

	return 0;
}


