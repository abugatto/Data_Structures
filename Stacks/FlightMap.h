#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include <fstream>
#include "stack.h"
#include "destinationNode.h"

using namespace std;

class FLIGHTMAP1 {
public:
	FLIGHTMAP1() { size = 0; }
	FLIGHTMAP1(const string& citylist, const string& flightfile);
	~FLIGHTMAP1();
	void concat_output(const string& str);
	void reset();
	bool find_path(const string& origin, const string& destination);
	bool output_to_file();

private:
	int size;
	City** map;
	Stack<City*> path;
	string output;
};

//***************************************************************************

FLIGHTMAP1::FLIGHTMAP1(const string& citylist, const string& flightfile) {
	ifstream fin;
	fin.open(citylist); //for list

	string* city_name = new string[200];
	while(fin >> city_name[size]) {
		size++;
	}

	cout << endl;

	map = new City*[size];
	for(int j = 0; j < size; j++) {
		map[j] = new City(city_name[j]);

		output = output + "[" + to_string(j) + "->" + city_name[j] + "]";
	}

	cout << endl;

	delete[] city_name;
	city_name = NULL;

	fin.close();
	fin.open(flightfile); //for adjacencies

	string c1, c2; 
	int flight_number, cost;
	for(int j = 0; j < size; j++) {
		fin >> c1 >> c2 >> flight_number >> cost;

		c1.erase(c1.length() - 1, c1.length()); //erasing comma

		int k = 0;
		while(map[k]->get_name() != c1) { //going to the correct city 
			k++;
		}

		int q = 0;
		while(map[q]->get_name() != c2) { //inputting destination into adjacency list
			map[k]->input_adjacency(map[q]);
		}
	}

	fin.close(); 
}

FLIGHTMAP1::~FLIGHTMAP1() {
	while(size >= 0) {
		delete[] map[size];
		size--;
	}
	delete[] map;
	map = nullptr;
}

void FLIGHTMAP1::concat_output(const string& str) {

}

void FLIGHTMAP1::reset() {
	for(int i = 0; i < size; i++) {
		map[i]->reset_visited();
	}
}

bool FLIGHTMAP1::find_path(const string& origin, const string& destination) {
	int i = 0;
	while(map[i]->get_name() != origin) { //finds the origin city
		i++;
	}

	City* Optr = map[i];
	map[i]->set_visited();
	path.push(Optr); //for beginning of search

	i = 0;
	while(map[i]->get_name() != destination) { //finds the destination city
		i++;
	}
	City* Dptr = map[i];

	City* ptr = nullptr;
	bool path_found, no_path;
	path_found = no_path = false;

	int next = i;
	while(!path_found || !no_path) {
		ptr = map[next]->get_next_unvisited();
		if(!ptr) {
			no_path = true;
		}

		ptr->set_visited();
		path.push(ptr);

		if(ptr == Dptr) {
			path_found = true;
		} else {
			City* temp = map[next]->get_next_unvisited();
			if(ptr->adjecency_empty() || !temp) {
				if(ptr == Optr) {
					no_path = true;
				}

				temp = nullptr;
				path.pop(temp);
				while(temp->adjecency_empty() || temp == Optr) { //keeps popping off 
					path.pop(temp);
				}
				ptr = temp;
			}
		}
	}

	Optr = Dptr = nullptr;

	return path_found && !no_path;
}

bool FLIGHTMAP1::output_to_file() {
	ofstream fout;
	fout.open("HPAir.log.txt");



	fout.close();
}

//***************************************************************************

class FLIGHTMAP2 {
public:
	FLIGHTMAP2() { size = 0; }
	FLIGHTMAP2(const string& citylist, const string& flightfile);
	~FLIGHTMAP2();
	bool output_to_file();
	void concat_output(const string& str);
	void reset();
	bool find_path(const string& origin, const string& destination);

private:
	int size;
	City** map;
	Stack<City*> path;
	string output;
};

//***************************************************************************

FLIGHTMAP2::FLIGHTMAP2(const string& citylist, const string& flightfile) {
	ifstream fin;
	fin.open(citylist); //for list

	string* city_name = new string[200];
	while(fin >> city_name[size]) {
		size++;
	}

	cout << endl;

	map = new City*[size];
	for(int j = 0; j < size; j++) {
		map[j] = new City(city_name[j]);

		output = output + "[" + to_string(j) + "->" + city_name[j] + "]";
	}

	cout << endl;

	delete[] city_name;
	city_name = NULL;

	fin.close();
	fin.open(flightfile); //for adjacencies

	string c1, c2; 
	int flight_number, cost;
	for(int j = 0; j < size; j++) {
		fin >> c1 >> c2 >> flight_number >> cost;

		c1.erase(c1.length() - 1, c1.length()); //erasing comma

		int k = 0;
		while(map[k]->get_name() != c1) { //going to the correct city 
			k++;
		}

		int q = 0;
		while(map[q]->get_name() != c2) { //inputting destination into adjacency list
			map[k]->input_adjacency(map[q]);
		}
	}

	fin.close(); 
}

FLIGHTMAP2::~FLIGHTMAP2() {
	while(size >= 0) {
		delete[] map[size];
		size--;
	}
	delete[] map;
	map = nullptr;
}

void FLIGHTMAP2::concat_output(const string& str) {

}

void FLIGHTMAP2::reset() {
	for(int i = 0; i < size; i++) {
		map[i]->reset_visited();
	}
}

bool FLIGHTMAP2::find_path(const string& origin, const string& destination) {
	int i = 0;
	while(map[i]->get_name() != origin) { //finds the origin city
		i++;
	}

	City* Optr = map[i];
	map[i]->set_visited();
	path.push(Optr); //for beginning of search

	i = 0;
	while(map[i]->get_name() != destination) { //finds the destination city
		i++;
	}
	City* Dptr = map[i];

	City* ptr = nullptr;
	bool path_found, no_path;
	path_found = no_path = false;

	int next = i;
	while(!path_found || !no_path) {
		ptr = map[next]->get_next_unvisited();
		if(!ptr) {
			no_path = true;
		}

		ptr->set_visited();
		path.push(ptr);

		if(ptr == Dptr) {
			path_found = true;
		} else {
			City* temp = map[next]->get_next_unvisited();
			if(ptr->adjecency_empty() || !temp) {
				if(ptr == Optr) {
					no_path = true;
				}

				temp = nullptr;
				path.pop(temp);
				while(temp->adjecency_empty() || temp == Optr) { //keeps popping off 
					path.pop(temp);
				}
				ptr = temp;
			}
		}
	}

	Optr = Dptr = nullptr;

	return path_found && !no_path;
}

bool FLIGHTMAP2::output_to_file() {
	ofstream fout;
	fout.open("HPAir.log.txt");



	fout.close();
}


//***************************************************************************

class FLIGHTMAP3 {
public:
	FLIGHTMAP3() { size = 0; }
	FLIGHTMAP3(const string& citylist, const string& flightfile);
	~FLIGHTMAP3();
	bool output_to_file();
	void concat_output(const string& str);
	void reset();
	bool find_path(const string& origin, const string& destination);

private:
	int size;
	City** map;
	Stack<City*> path;
	string output;
};

//***************************************************************************

FLIGHTMAP3::FLIGHTMAP3(const string& citylist, const string& flightfile) {
	ifstream fin;
	fin.open(citylist); //for list

	string* city_name = new string[200];
	while(fin >> city_name[size]) {
		size++;
	}

	cout << endl;

	map = new City*[size];
	for(int j = 0; j < size; j++) {
		map[j] = new City(city_name[j]);

		output = output + "[" + to_string(j) + "->" + city_name[j] + "]";
	}

	cout << endl;

	delete[] city_name;
	city_name = NULL;

	fin.close();
	fin.open(flightfile); //for adjacencies

	string c1, c2; 
	int flight_number, cost;
	for(int j = 0; j < size; j++) {
		fin >> c1 >> c2 >> flight_number >> cost;

		c1.erase(c1.length() - 1, c1.length()); //erasing comma

		int k = 0;
		while(map[k]->get_name() != c1) { //going to the correct city 
			k++;
		}

		int q = 0;
		while(map[q]->get_name() != c2) { //inputting destination into adjacency list
			map[k]->input_adjacency(map[q]);
		}
	}

	fin.close(); 
}

FLIGHTMAP3::~FLIGHTMAP3() {
	while(size >= 0) {
		delete[] map[size];
		size--;
	}
	delete[] map;
	map = nullptr;
}

void FLIGHTMAP3::concat_output(const string& str) {

}

void FLIGHTMAP3::reset() {
	for(int i = 0; i < size; i++) {
		map[i]->reset_visited();
	}
}

bool FLIGHTMAP3::find_path(const string& origin, const string& destination) {
	int i = 0;
	while(map[i]->get_name() != origin) { //finds the origin city
		i++;
	}

	City* Optr = map[i];
	map[i]->set_visited();
	path.push(Optr); //for beginning of search

	i = 0;
	while(map[i]->get_name() != destination) { //finds the destination city
		i++;
	}
	City* Dptr = map[i];

	City* ptr = nullptr;
	bool path_found, no_path;
	path_found = no_path = false;

	int next = i;
	while(!path_found || !no_path) {
		ptr = map[next]->get_next_unvisited();
		if(!ptr) {
			no_path = true;
		}

		ptr->set_visited();
		path.push(ptr);

		if(ptr == Dptr) {
			path_found = true;
		} else {
			City* temp = map[next]->get_next_unvisited();
			if(ptr->adjecency_empty() || !temp) {
				if(ptr == Optr) {
					no_path = true;
				}

				temp = nullptr;
				path.pop(temp);
				while(temp->adjecency_empty() || temp == Optr) { //keeps popping off 
					path.pop(temp);
				}
				ptr = temp;
			}
		}
	}

	Optr = Dptr = nullptr;

	return path_found && !no_path;
}

bool FLIGHTMAP3::output_to_file() {
	ofstream fout;
	fout.open("HPAir.log.txt");



	fout.close();
}

#endif