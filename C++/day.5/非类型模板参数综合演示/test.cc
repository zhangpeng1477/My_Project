#include <iostream>
using namespace std;

#include "array.h"

#if 0
Array<int, MAX>--->
class Array1{
public:
	Array(const int val);
	Array(const Array &);
	~Array();

public:
	int& at(const int id)const{
		return arr[id];
	}

	int& operator[](const int id)const{
		return arr[id];
	}

private:
	int arr[6];
};

Array<int, 2*MAX>--->
class Array2{
public:
	Array(const int val);
	Array(const Array &);
	~Array();

public:
	int& at(const int id)const{
		return arr[id];
	}

	int& operator[](const int id)const{
		return arr[id];
	}

private:
	int arr[12];
};

Array2 a = 1;
#endif

int main()
{
#if 0
#define MAX 3
	Array<int, MAX> a(0); //����һ�����󣬹�����������int arr[MAX]

	for(int i= 0; i < MAX; i++){
		cout << "a[" << i << "] = " << a[i] << endl;
	}

	//����һ����������������Array<int, MAX> arr[2*MAX];
	//Array<int, MAX>������õĹ��캯����û�в������캯��
	Array<Array<int, MAX>, 2*MAX> b(a);

	for(int i= 0; i < 2*MAX; i++){
		for(int j = 0; j < MAX; j++){
			//b[i].at(j) = 1+i+j; 
			//��һ��[]ȡ��һ������
			//�ڶ���[]���ж��������[]�õ������������������һ����Ա
			b[i][j] = 1+i+j;
		}
	}

	for(int i= 0; i < 2*MAX; i++){
		for(int j = 0; j < MAX; j++){
			cout << "a[" << i << "] = " << b[i][j] << endl;
		}
	}
#else
	//����һ���������飬ÿ�����������������int arr[MAX];

������	//ÿ������Ĺ��캯������һ�������İ汾	Array(int val)
	Array<int, MAX> a[MAX](0); //����һ�����󣬹�����������int arr[MAX]
������	//ÿ������Ĺ��캯������û�в����İ汾	Array()
	Array<int, MAX> a[MAX]; //����һ�����󣬹�����������int arr[MAX]
#endif
}


