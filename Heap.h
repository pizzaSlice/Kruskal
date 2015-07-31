#ifndef heap_class
#define heap_class

#include <iostream>
using namespace std;

template <class t>
class Heap{
	t * array;
	int size;
	int arrsize;

public: 
	Heap(){
	};
	void setsize(int n){
		size = 0;
		arrsize = n;
		array = new t [arrsize];
	};
	void insert(t value){
		if(size == arrsize){
			t * oldarray = array;
			array = new t[arrsize * 2];
			for(int i = 0; i < size + 1;i++){
				arrsize = arrsize * 2;
				array[i] = oldarray[i];
				//cout << array[i];
			}
		}

		int hole = ++ size;
		t copy = value;

		array[0] = std::move(copy);
		for(; value < array[hole / 2]; hole /= 2)
			array[hole] = std::move(array[hole / 2]);
		array[hole] = std::move(array[0]);
	};

	t deletemin(){
		t returnvalue;
		//if(size == 0)
			//throw exception();
		returnvalue = array[1];
		array[1] = std::move(array[size --]);
		
		percolateDown(1);

		return returnvalue;
	};

	t & find(t value){
		// linear search for now
		for(int i = 1; i < size; i ++){
			if(array[i] == value)
				return array[i];
		}
	};

	bool contains(t value){
		// linear search for now
		for(int i = 1; i < size; i ++){
			if(array[i] == value)
				return true;
		}
		return false;
	};

	void percolateDown(int hole){
		int child;
		t tmp = std::move(array[hole]);
		for(;hole * 2 <= size; hole = child){
			child = hole * 2;
			if(child != size && array[child + 1] < array[child])
				++child;
			if(array[child] < tmp)
				array[hole] = std::move(array[child]);
			else
				break;
		}
		array[hole] = std::move(tmp);
	};

	~Heap(){
		delete [] array;
	};
};

#endif