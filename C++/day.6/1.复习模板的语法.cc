#include <iostream>
using namespace std;

#include <assert.h>

#define MAX1 3
#define MAX2 3

template <typename T1=char, typename T2=int, int max1=MAX1, int max2=MAX2>
class Demo{
public:
	Demo(const T1 val1, const T2 val2);
	Demo(const Demo &);
	~Demo();

public:
	T1 getval1(const int id)const;
	T2 getval2(const int id)const;

	static void setval1(Demo &, const int id, const T1 val);

	template <typename C1, typename C2, int max11, int max22>
	friend void setval2(Demo<C1, C2, max11, max22> &obj, const int id, const C2 val);

private:
	T1 arr1[max1];
	T2 arr2[max2];	
};

template <typename T1, typename T2, int max1, int max2>
Demo<T1,T2,max1,max2>::Demo(const T1 val1, const T2 val2)
{
	for(int i = 0; i < max1; i++){
		arr1[i] = val1;
	}

	for(int i = 0; i < max2; i++){
		arr2[i] = val2;
	}
}

template <typename T1, typename T2, int max1, int max2>
Demo<T1,T2,max1,max2>::Demo(const Demo &obj)
{
	for(int i = 0; i < max1; i++){
		arr1[i] = obj.arr1[i];
	}

	for(int i = 0; i < max2; i++){
		arr2[i] =obj.arr2[i];
	}
}

template <typename T1, typename T2, int max1, int max2>
Demo<T1,T2,max1,max2>::~Demo()
{

}

template <typename T1, typename T2, int max1, int max2>
T1 Demo<T1,T2,max1,max2>::getval1(const int id)const
{
	return arr1[id];
}

template <typename T1, typename T2, int max1, int max2>
T2 Demo<T1,T2,max1,max2>::getval2(const int id)const
{
	return arr2[id];
}

template <typename T1, typename T2, int max1, int max2>
void Demo<T1,T2,max1,max2>::setval1(Demo &obj, const int id, const T1 val)
{
	obj.arr1[id] = val;
}

template <typename C1, typename C2, int max11, int max22>
void setval2(Demo<C1, C2, max11, max22> &obj, const int id, const C2 val)
{
	obj.arr2[id] = val;
}

int main()
{
	Demo<> a('a', 1);
	
	for(int i = 0; i < MAX1; i++){
		cout << "arr1[" << i << "] = " << a.getval1(i) << endl;
	}

	for(int i = 0; i < MAX2; i++){
		cout << "arr2[" << i << "] = " << a.getval2(i) << endl;		
	}

#define MAX11 6
	Demo<double, char, MAX11> b(1.1, 'a');	
	for(int i = 0; i < MAX11; i++){
		double db = i+1.1;
		Demo<double, char, 6>::setval1(b, i, db);
	}
	for(int i = 0; i < MAX2; i++){
		char ch = i+'a';
		setval2(b, i, ch);
	}

	for(int i = 0; i < MAX11; i++){
		cout << "arr1[" << i << "] = " << b.getval1(i) << endl;
	}

	for(int i = 0; i < MAX2; i++){
		cout << "arr2[" << i << "] = " << b.getval2(i) << endl;		
	}

	
	//setval2(a,);
}


