#include <iostream>
using namespace std;

#include <assert.h>

class Array{
public:
	Array(const int len=1024);
	Array(const Array &);

	~Array();

public:
	int& at(const int id)const;		//�õ�����һ����Ա������ȫ����Ϊid����Խ�磩
	int& operator[](const int id)const;	//������õ�����һ����Ա������ȫ����Ϊid����Խ�磩

	class Pointer{ //Pointer�����Array�����÷�Χ���Ƕ�������
	public:
		Pointer(int *p, int len);
	
		int* operator++();	//ָ�򻺴��ַ+1��ǰ++
		int* operator++(int);	//ָ�򻺴��ַ+1����++

		int *operator->() const{//�õ����û����һ����Ա��ַ
			return ptr;
		}

		int& operator*() const{ //�õ�ָ�򻺴��һ����Ա
			return *ptr;
		}

	private:
		int *ptr;	//��ǰָ��
		int pos;	//���浱ǰָ��λ��
		const int size; //���滺�泤��
	};

	Pointer begin(){ //�õ�һ��������
		//���ڵ����������в�������Ҫ�Ǵ��ݻ�����׵�ַ�ͳ���
		//�û�����Ҳ���ܳ������⣬��ô��װ��ʹ�ú����Ͱ�ȫ��
		Pointer tmp(addr, size);
		return tmp;
	}	
	
private:
	int *const addr;	//��������ڲ����������׵�ַ
	const size_t size;	//��������ڲ��������鳤��
};

Array::Pointer::Pointer(int *p, const int len):
	size(len)
{
	ptr = p;
	pos = 0;
}

int* Array::Pointer::operator++()
{
	if(pos < (size-1)){
		++ptr;
		++pos;
		return ptr;
	}

	return NULL;
}

int* Array::Pointer::operator++(int)
{
	int *p = ptr;

	if(pos < size){
		ptr++;
		pos++;
		return ptr;
	}

	return NULL;
}

Array::Array(const int len):
	addr(new int[len]),
	size(len)
{
	assert(NULL != addr);
	cout << "-------normal---------\n";
}

Array::Array(const Array &obj):
	addr(new int[obj.size]),
	size(obj.size)
{
	assert(NULL != addr);
	for(int i = 0; i < size; i++){
		addr[i] = obj.addr[i];
	}
	cout << "-------copy---------\n";
}

Array::~Array()
{
	delete [] addr;
}

int& Array::at(const int id)const
{
	assert((0<=id) && (id < size));
	return addr[id];
}

int& Array::operator[](const int id)const
{
	//assert((0<=id) && (id < size));
	return addr[id];
}


int main()
{
#define MAX 6
	Array arr(MAX);

	Array::Pointer p = arr.begin();

	int i;
	for(i = 0; i < 2*MAX; i++){
		*p = 'a';
		if(NULL == ++p)
			break;
	}

	cout << "i = " << i << endl;
}


