#ifndef ARRAY_H
#define ARRAY_H

template <typename T=int, int max=1024>
class Array{
public:
	Array(){
	}

	Array(const T val){
		for(int i = 0; i < max; i++){
			arr[i] = val;
		}
	}

	Array(const Array &obj){
		for(int i = 0; i < max; i++){
			arr[i] = obj.arr[i];
		}
	}

	~Array(){
	}

public:
	T& at(const int id){
		return arr[id];
	}

	T& operator[](const int id){
		return arr[id];
	}

private:
	T arr[max];
};

#endif
