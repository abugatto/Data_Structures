#ifndef FLIGHTMAP2_CPP
#define FLIGHTMAP2_CPP

#include <iostream>
#include <string>
#include <fstream>
#include "list.h"
#include "stack.cpp"
#include "destinationNode.h"

using namespace std;

class FLIGHTMAP2 {
public:
	FLIGHTMAP2();
	FLIGHTMAP2(const string& filename);
	~FLIGHTMAP2();
	void import_map();
	void clear();

private:
	DESTINATION* map;
	int cursor;
	STACK path;
};

#endif