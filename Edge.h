
#ifndef edge_class
#define edge_class

struct edge{
	int v1;
	int v2;
	double weight;

	bool operator < (edge & rhs){
		if(weight < rhs.weight)
			return true;
		else 
			return false;
	};
	bool operator > (edge & rhs){
		if(weight > rhs.weight)
			return true;
		else 
			return false;
	};
	bool operator == (edge & rhs){
		if(v1 == rhs.v1 && v2 == rhs.v2)
			return true;
		else if(v1 == rhs.v2 && v2 == rhs.v1)
			return true;
		else 
			return false;
	};

	edge & operator = (edge & rhs){
		v1 = rhs.v1;
		v2 = rhs.v2;
		weight = rhs.weight;
		return *this;

	};
	
};

#endif