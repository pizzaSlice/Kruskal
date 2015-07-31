#ifndef SET_CLASS
#define SET_CLASS

class set{
private:
	int * s;
	int size;
public:
	set(){
	};
	void setsize(int n){
		size = n; 
		s = new int[size];
	}
	int find(int x) const{
		if(s[x] < 0 )
			return x;
		else
			return s[x] = find(s[x]);
	};
	void unite(int x1, int x2){
		if(s[x1] < s[x2])
			s[x1] = x2;
		else{
			if(s[x1] == s[x2])
				--s[x1];
			s[x2] = x1;
		}
	};
	~set(){
		delete [] s;
	};
};

#endif