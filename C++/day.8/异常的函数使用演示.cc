#include <iostream>
#include <stdexcept>
using namespace std;

#include <unistd.h>
#include <stdio.h>
#include "thread.h"

int mydiv(const int x, const int y)
throw(invalid_argument) //�����ú���֧��invalid_argument�쳣
{
	if(0 != y)
		return x/y;

#if 0
	//�����쳣�����乹�캯���Ĳ������Ǵ�����Ϣ
	invalid_argument tmp("ERROR!!! y is zero."); 
	throw tmp;//throw�׳��쳣��ʵ����ԭ��ַ��ת�����������catch��
#else
	//û��ȡ����������ʱ����
	throw invalid_argument("ERROR!!! y is zero.");;
#endif
}

int main()
{
#if 0
	try{ //֧���쳣�ĺ����������try�飬���ܱ������쳣
		cout << "1/2 = " << mydiv(1, 2) << endl;
		cout << "1/0 = " << mydiv(1, 0) << endl;
	}catch(const invalid_argument &err){ //catch�飺���ڲ����쳣
		cout << "DEMO: " << err.what() << endl;
	}

	cout << "----------------------------" << endl;
#else
	mydiv(1, 0);//û��try��catch�飬�쳣�׳��󣬽�������
#endif

	return 0;
}


