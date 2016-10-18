#ifndef DESTINATIONNODE_CPP
#define DESTINATIONNODE_CPP

#include <iostream>
#include <string>
#include "list.h"

using namespace std;

class City {
public:
	City();
	City(const string& n);
	~City() {}
	void set_name(const string&);
	string get_name() const;
	void set_visited();
	void reset_visited();
	bool has_been_visited() const;
	void input_adjacency(City* Dptr);
	bool adjecency_empty() const;
	City* get_next_unvisited();

private:
	string name;
	bool visited;
	ListNode<City*> adjacencies;
};

//***************************************************************************

City::City() {
	visited = false;
}

City::City(const string& n) {
	name = n;
	visited = false;
}

void City::input_adjacency(City* Dptr) {
	adjacencies.insertAfter(Dptr);
}

bool City::adjecency_empty() const {
	return adjacencies.isEmpty();
}

void City::set_visited() {
	visited = true;
}

void City::reset_visited() {
	visited = false;
}

void City::set_name(const string& n) {
	name = n;
}

string City::get_name() const {
	return name;
}

bool City::has_been_visited() const {
	return visited;
}

City* City::get_next_unvisited() {
	City* temp = nullptr;
	adjacencies.get(temp); 

	while(temp->has_been_visited()) {
		adjacencies.goToNext();
		adjacencies.get(temp); 
	}

	if(temp) {
		return temp;
	} else {
		return nullptr;
	}
}

#endif