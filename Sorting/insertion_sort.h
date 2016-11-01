#ifndef I_SORT_H
#define I_SORT_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class InsertionSort {
public:
	InsertionSort();
	~InsertionSort();
	void run(int list[], const int& legnth);
	void write(const string&);

private:
	int* sorted_arr;
	string output;
};

InsertionSort::InsertionSort() {
	sorted_arr = nullptr;
	output = "";
}

InsertionSort::~InsertionSort() {
	delete[] sorted_arr;
	sorted_arr = nullptr;
}

void InsertionSort::run(int list[], const int& legnth) {
	int value = 0;
	int hole = 0;
	int old_hole = 0;

	for(int i = 1; i < legnth; i++) {
		value  = list[i];
		hole = old_hole = i;

		while((hole > 0) && (list[hole - 1] > value)) {
			list[hole] = list[hole - 1];
			hole -= 1;
		}

		list[hole] = value;
		output += to_string(value) + " is moved from " + to_string(old_hole) + to_string(hole) + ".\n";
	}

	output += "Sorted Array:\t";
	for(int i = 0; i < legnth; i++) {
		output += "[" + to_string(list[i]) + "]";
	}
}

void InsertionSort::write(const string& filename) {
	ofstream fout;
	fout.open(filename);

	fout << output << endl;

	fout.close();
}

#endif
