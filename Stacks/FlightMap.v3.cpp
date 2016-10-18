#ifndef FLIGHTMAP3_CPP
#define FLIGHTMAP3_CPP

#include <iostream>
#include <string>
#include <fstream>
#include "list.h"
#include "stack.cpp"
#include "destinationNode.h"

using namespace std;

class FLIGHTMAP3 {
	FLIGHTMAP3();
	FLIGHTMAP3(const string& filename);
	~FLIGHTMAP3();
	void import_map();
	void clear();

private:
	ADJLIST<SMARTDESTINATION> map;
	STACK flight_path;
};

#endif