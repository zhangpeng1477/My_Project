#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class IntArray{
public:
	IntArray(const int len){
		arr = new int[len];
		size = len;
	}
	//Ĭ�ϵĿ���������ǳ�������������Ƕ�Ӧ�����ݳ�Ա��ֵ
	//���ʾ����Ҫ���
	IntArray(const IntArray &obj){
		size = obj.size;
		//�����Լ��Ķ���
		arr = new int[size];

		//����Ķ��������ݿ���
		for(int i = 0; i < size; i++)
			arr[i] = obj.arr[i];
	}

	//����ֵ������
	//��Ϊat()������ɣ�arr�ǳ�Ա���ݣ�������ʧ����ô�Ϳ��Է���arr�ı�����ʵ���Ƿ���arr
	//�ⲿ�Ϳ���ֱ�Ӳ���arr,������ͨ�������ӿڵõ��ı�������ɵġ�
	int& at(const int id){
		return arr[id];
	}

private:
	int *arr;
	size_t size;
};

int main()
{
#define MAX 12
	IntArray a(MAX);
	for(int i = 0; i < MAX; i++){
		a.at(i) = i; //at()���ص���arr�ı������ʴ���Ϊ��ֵ�ǿ��Ե�
				//ʵ���Ǹ�arr��ֵ
	}

	IntArray b = a;

	for(int i = 0; i < MAX; i++){
		cout << "a[" <<i << "]=" << a.at(i) << endl;
	}

	for(int i = 0; i < MAX; i++){
		cout << "b[" <<i << "]=" << b.at(i) << endl;
	}
}


