#ifndef FLIGHTMAP1_CPP
#define FLIGHTMAP1_CPP

#include <iostream>
#include <string>
#include <fstream>
#include "list.h"
#include "stack.cpp"
#include "destinationNode.h"

using namespace std;

class FLIGHTMAP1 {
public:
	FLIGHTMAP1() { size = 0; }
	FLIGHTMAP1(const string& citylist, const string& flightfile);
	~FLIGHTMAP1();
	void reset();
	bool find_path(const string& origin, const string& destination);

private:
	int size;
	City* map;
	STACK<City*> path;
};

FLIGHTMAP1::FLIGHTMAP1(const string& citylist, const string& flightfile) {
	ifstream fin;
	fin.open(citylist); //for list

	string* city_name = new string(200);
	while(fin >> city_name[size]) {
		size++;
	}

	map = new City(size);
	for(int j = 0; j < size; j++) {
		map[j] = new City(city_name[j]);
	}

	delete[] city_name;
	city_name = NULL;

	fin.close();
	fin.open(flightfile); //for adjacencies

	string c1, c2; 
	int flight_number, cost;
	for(int j = 0; j < size; j++) {
		fin >> c1 >> c2 >> flight_number, cost;

		c1.erase(c1.length() - 1, c1.length()); //erasing comma

		int k = 0;
		while(map[k]->get_name() != c1) { //going to the correct city 
			k++;
		}

		int q;
		while(map[q]->get_name() != c2) { //inputting destination into adjacency list
			map[k]->input_adjacency(map[q]);
		}
	}

	fin.close(); 
}

FLIGHTMAP1::~FLIGHTMAP1() {
	while(size != 0) {
		delete[] map[size];
		size--;
	}
	delete[] map;
}

void FLIGHTMAP1::reset() {
	for(int i = 0; i < size; i++) {
		map[i]->reset_visited();
	}
}

bool FLIGHTMAP1::find_path(const string& origin, const string& destination) {
	int i = 0;
	while(map[i]->get_name() == origin) { //finds the origin city
		i++;
	}

	City* Optr = map[i];
	map[i]->set_visited();
	path.push(Optr); //for beginning of search

	i = 0;
	while(map[i]->get_name() == destination) { //finds the destination city
		i++;
	}
	City* Dptr = map[i];

	City* ptr = nullptr;
	bool path_found, no_path;
	int next = i;
	while(!path_found || !nopath) {
		ptr = map[next].get_next_unvisited();
		if(!ptr) {
			no_path = true;
		}

		ptr->set_visited();
		path.push(ptr);

		if(ptr == Dptr) {
			path_found = true;
		} else {
			if(ptr->adjacency_empty()) {
				if(ptr == Optr) {
					nopath = true;
				}

				City* temp = nullptr;
				path.pop(temp);
				while(temp->adjacency_empty() || temp == Optr) {
					path.pop(temp);
				}
				ptr = temp;
			}
		}
	}

	Optr = Dptr = nullptr;

	return path_found && !no_path;
}


#endif