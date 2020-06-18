#include <iostream>
using namespace std;

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>

#include "String.h"
#include "Socket.h"

int main()
{
	TcpSocket s;
	if(s.connect("127.0.0.1", 59999)){
		while(1){
			cout << "wait for input ..." << endl;	
		#define MAX 1024
			char buf[MAX];
			memset(buf, 0, MAX);
			if(NULL != fgets(buf, MAX, stdin)){
				int num = strlen(buf);
				buf[num-1] = 0;
		
				if(s.write(buf, num)){
					cout << "Snd " << num << "bytes : \"" << buf << "\" done" << endl; 
				}else{
					break;
				}
			}else{
				break;
			}
		}
	}else{
		cout << "connect fail" << endl;
	}
}


