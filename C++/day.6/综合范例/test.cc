#include <iostream>
using namespace std;

#include <string.h>

#include "File.h"

int main()
{
	File f("1.txt");

	if(f.open(F_RW)){
		char buf[] = "hello world";
		if(f.write(buf, strlen(buf))){
			f.lseek(0, SEEK_SET);
			BYTEARR arr(1024);

			int num = f.read(arr);
			if(num > 0){
				for(int i= 0; i < num; i++){
					cout << "arr[" << i << "] = " << arr[i] << endl;
				}	

			}else{
				cout << "read fail from 1.txt.\n";
			}
		}else{
			cout << "write fail to 1.txt.\n";
		}
	}else{
		cout << "1.txt open fail.\n";
	}
}


