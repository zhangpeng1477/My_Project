#include <iostream>
using namespace std;

int main()
{
	int i;
	double db;
	char c;

	//输入的实际是字符串，要被转换成对应的数据类型，存在位宽不足及缓存越界的问题
	//只要输入出现数据宽度不足，后续数据解析都不对
	cin >> i;		
	cin >> db >> c;	//多次输入，空格或回车分隔数据

	cout << "i = " << i << endl;
	cout << "db= " << db << endl;
	cout << "c = " << c << endl;
}


