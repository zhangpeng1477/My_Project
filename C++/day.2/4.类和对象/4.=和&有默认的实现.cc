#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class IntArray{
public:
	IntArray(const int len){
		arr = new int[len];
		if(arr){
			for(int i = 0; i < size; i++)
				arr[i] = obj.arr[i];
			size = len;
		}else{
			size = 0;
		}
	}
	IntArray(const IntArray &obj){
		size = obj.size;

		arr = new int[size];
		if(arr){
			for(int i = 0; i < size; i++)
				arr[i] = obj.arr[i];
		}else{
			size = 0;
		}		
	}

	int& at(const int id){
		if( (0 <= id) && (id < size) )
			return arr[id];
		//�д����
		//�쳣����
	}

	int *addr(){
		return arr;
	}

private:
	int *arr;
	size_t size;
};

int main()
{
#define MAX 12
	IntArray a(MAX);
	IntArray b = a;
	cout << "a: addr: " << a.addr() << endl;
	cout << "b: addr: " << b.addr() << endl;

	b = a; //û��"="��������أ��������������һ��Ĭ�ϵģ�������ǳ������������

	Demo *p = &a; //ȡ����ĵ�ַ�����û������&�����������Ĭ�����ɵ�
}


