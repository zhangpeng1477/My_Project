#include <iostream>
using namespace std;

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <string.h>

#include "String.h"
#include "File.h"

int main()
{
	String fname = "1.txt";
	char filname[] = "1.txt";

	File f(fname);

	if(f.creat(0666)){
		if(f.open(O_RDWR)){
			char buf[] = "123";
			if(f.write(buf, ::strlen(buf))){
				f.seek(0, SEEK_SET);

				ByteArray arr(1024);
				int num = f.read(arr);
				if(num >= 0){
					cout << "context: \n";
					for(int i= 0; i < num; i++){
						cout << arr[i];
					}

					cout << "\n";
				}
			}
		}
	}
}


