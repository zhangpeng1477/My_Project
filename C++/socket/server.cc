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
	TcpServer s;
	if(s.listen("127.0.0.1", 59999)){
		cout << "wait for a client ..." << endl;
		TcpSocket rws;
		if(s.wait(rws)){
			while(1){
				ByteArray arr(1024);
				int num = rws.read(arr);
				cout << "RECV[" << num << "] : ";
				for(int i = 0; i < num; i++){
					cout << arr[i];
				}
				cout << endl;
			}
		}else{
			perror("wait");
		}
	}else{
		perror("listen");
	}
}


