#ifndef M_SORT_H
#define M_SORT_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class MergeSort {
public:
	MergeSort();
	~MergeSort();
	int* sort(int list1[], int list2[], const int& legnth);
	int* run(int list[], const int& legnth);
	void write(const string&);

private:
	int* sorted_arr;
	string output;
};

MergeSort::MergeSort() {
	sorted_arr = nullptr;
	output = "";
}

MergeSort::~MergeSort() {
	delete[] sorted_arr;
	sorted_arr = nullptr;
}

int* MergeSort::sort(int list1[], int list2[], const int& legnth) {
	int* output_arr = new int[legnth];

	int legnth1, legnth2, i;
	i = 0;
	legnth1 = legnth2 = legnth/2;
	while(legnth1 >= 1 && legnth2 >= 1) {
		if(legnth1 >= 1 && legnth2 >= 1) {
			if(list1[0] > list2[0]) {
				output_arr[i] = list2[0];

				int counter = legnth2;
				while(counter != 0) {
					list2[0] = list2[1];
				}
				legnth2--;
			} else {
				output_arr[i] = list1[0];

				int counter = legnth1;
				while(counter != 0) {
					list1[0] = list1[1];
				}
				legnth1--;
			}
		}
		i++;
	}

	while(legnth1 >=1) {
		output_arr[i] = list1[0];

		int counter = legnth1;
		while(counter != 0) {
			list1[0] = list1[1];
			counter--;
		}
		legnth1--;
		i++;
	}

	while(legnth2 >=1) {
		output_arr[i] = list2[0];

		int counter = legnth1;
		while(counter != 0) {
			list2[0] = list2[1];
			counter--;
		}
		legnth1--;
		i++;
	}

	return output_arr;
}

int* MergeSort::run(int list[], const int& legnth) {
	if(legnth != 1) {
		int* list1 = new int[legnth/2];
		int* list2 = new int[legnth/2];

		for(int i = 0; i < legnth; i++) {
			if(i < legnth/2) {
				list1[i] = list[i];
			} else {
				list2[i] = list[i];
			}
		}

		list1 = run(list1, legnth/2);
		list2 = run(list2, legnth/2);

		list = sort(list1, list2, legnth);

		delete[] list1;
		delete[] list2;
		list1 = list2 = nullptr;
	}

	for(int i = 0; i < legnth; i++) {
		output += "[" + to_string(list[i]) + "]";
	}
	output += " -> ";

	return list;
}

void MergeSort::write(const string& filename) {
ofstream fout;
	fout.open(filename);

	fout << output << endl;

	fout.close();
}

#endif