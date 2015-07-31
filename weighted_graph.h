/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  uwuserid @uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  (Winter|Spring|Fall) 201N
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of uWaterloo User IDs of those students
 * I had discussions with in preparing this project:
 *    -
 *
 * The following is a list of uWaterloo User IDs of those students
 * who helped me with this project (describe their help; e.g., debugging):
 *    -
 *****************************************/

#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#ifndef nullptr
#define nullptr 0
#endif

#include <iostream>
#include <limits>
#include "Set.h"
#include "Heap.h"
#include "Edge.h"
//#include "Exception.h"

class Weighted_graph {
	private:
		static const double INF;
		int size;
		set s;
		Heap<edge> h;

		// Do not implement these functions!
		// By making these private and not implementing them, any attempt
		// to make copies or assignments will result in errors
		Weighted_graph( Weighted_graph const & );
		Weighted_graph &operator=( Weighted_graph );

		// your choice

	public:
		Weighted_graph( int = 10 );
		~Weighted_graph();

		int degree( int ) const;
		int edge_count() const;
		std::pair<double, int> minimum_spanning_tree();

		bool insert_edge( int, int, double );
		bool erase_edge( int, int );
		void clear_edges();

	// Friends

	friend std::ostream &operator<<( std::ostream &, Weighted_graph const & );
};

const double Weighted_graph::INF = std::numeric_limits<double>::infinity();

Weighted_graph::Weighted_graph( int n ) {
	size = n;
	h.setsize(n*n);
	s.setsize(n);
}

Weighted_graph::~Weighted_graph() {
}
int Weighted_graph::degree( int n ) const{
	return 0;
}
int Weighted_graph::edge_count() const{
	return 0;
}

bool Weighted_graph::insert_edge( int i, int j, double d ) {
	//if(i < 0)
	//	//throw illegal_argument();
	//if(j < 0)
	//	//throw illegal_argument();
	//if(i > size)
	//	throw illegal_argument();
	//if(j > size)
	//	throw illegal_argument();

	
	edge temp = {i,j,d};

	if(i == j)
		return false;
	if(h.contains(temp))
		h.find(temp) = temp;
	else 
		h.insert(temp);
		
	return true;
	
}

std::pair<double, int> Weighted_graph::minimum_spanning_tree(){
	int weight = 0;
	int edges = 0;

	while(edges < size - 1){
		edge e = h.deletemin();

		if(s.find(e.v1) != s.find(e.v2)){
			s.unite(e.v1, e.v2);
			weight += e.weight;
			edges++;
		}
	}

	cout << weight;
	cout << endl << edges;
	return std::pair<double, int>( weight, edges );
};

std::ostream &operator<<( std::ostream &out, Weighted_graph const &graph ) {
	// Your implementation

	return out;
}

#endif