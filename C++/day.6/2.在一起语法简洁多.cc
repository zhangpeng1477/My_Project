#include <iostream>
using namespace std;

#include <assert.h>

#define MAX1 3
#define MAX2 3

template <typename T1=char, typename T2=int, int max1=MAX1, int max2=MAX2>
class Demo{
public:
	Demo(const T1 val1, const T2 val2){
		for(int i = 0; i < max1; i++){
			arr1[i] = val1;
		}

		for(int i = 0; i < max2; i++){
			arr2[i] = val2;
		}
	}
	Demo(const Demo &obj){
		for(int i = 0; i < max1; i++){
			arr1[i] = obj.arr1[i];
		}

		for(int i = 0; i < max2; i++){
			arr2[i] =obj.arr2[i];
		}
	}
	~Demo(){
	}

public:
	T1 getval1(const int id)const{
		return arr1[id];
	}

	T2 getval2(const int id)const{
		return arr2[id];
	}

	static void setval1(Demo &obj, const int id, const T1 val){
		obj.arr1[id] = val;
	}

	friend void setval2(Demo &obj, const int id, const T2 val){
		obj.arr2[id] = val;
	}

private:
	T1 arr1[max1];
	T2 arr2[max2];	
};

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
}


