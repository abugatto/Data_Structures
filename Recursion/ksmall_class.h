#ifndef KSMALL_H
#define KSMALL_H

#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

//************************************************************************************************

class KSmall {
public:
	KSmall();
	~KSmall();
	int parse(const string& filename);
	void trace(const int& pivot, const int& first, const int& legnth);
	int partition(const int& first, const int& last);
	int find(const int& k, const int& first, const int& last, const int& legnth);
private:
	int* list;
	int k;
	string log;
};

//************************************************************************************************

KSmall::KSmall() {
	remove("trace.txt");

	log = "Test output of code:\n\n";

	k = 0;
	list = nullptr;
}

KSmall::~KSmall() {
	delete[] list;
	list = nullptr;
}

int KSmall::parse(const string& filename) {
	ifstream fin;

	fin.open(filename);

	int* temp = new int[1000];
	int legnth = 0;

	int i = 0;
	while(fin >> temp[i]) { //counts the number of elements in the document
		legnth++;
		i++;
	}

	list = new int[legnth]; //makes an array as long as the legnth

	for(int j = 0; j < legnth; j++) {
		list[j] = temp[j];
	}
	
	/*
	for(int a = 0; a < legnth; a++) { //TEST CODE
		cout << "[" << list[a] << "]";
	}
	*/

	delete[] temp;
	temp = nullptr;

	fin.close();

	return legnth;
}

void KSmall::trace(const int& pivot, const int& first, const int& legnth) { //NEEDS PIVOT
	ifstream fin;
	ofstream fout;

	for(int cntr = 0; cntr < legnth; cntr++) {
		if(cntr == pivot) {
			log = log + "<[" + to_string(list[cntr]) + "]>";
		} else {
			log = log + "[" + to_string(list[cntr]) + "]";
		}
	}
	log = log + "\n";

	if(k == pivot - first + 1) {
		log = log + "\n\nThe kth smallest number is:\t" + to_string(list[pivot]);

		fout.open("trace.txt");

		fout << log << endl;

		fout.close();
	}
}

int KSmall::partition(const int& first, const int& last) {
	int pivot = first;
	for(int i = first; i < last; i++) {
		if(list[i] < list[last]) {
			int temp = list[pivot]; //swap
			list[pivot] = list[i];
			list[i] = temp;

			pivot++;
		}
	}
	int temp = list[pivot]; //swap
	list[pivot] = list[last];
	list[last] = temp;

	return pivot;
}

int KSmall::find(const int& knum, const int& first, const int& last, const int& legnth) {
	k = knum;

	if((k > 0) && (k < legnth - first + 1)) {
		int pivot = partition(first, last);

	/*
		for(int i = 0; i < legnth; i++) { //TEST CODE
			if(i == pivot) {
				cout << " <[" << list[i] << "]> ";
			} else if(i == last){
				cout << " ^[" << list[i] << "]^ ";
			} else {
				cout << "[" << list[i] << "]";
			}
		} cout << endl;
	*/

		trace(pivot, first, legnth);

		if(k < pivot - first + 1) {
			return find(k, first, pivot - 1, legnth);
		} else if(k == pivot - first + 1) {
			return list[pivot];
		} else {
			return find(k - (pivot - first + 1), pivot + 1, last, legnth);
		}
	}

	return -1;
}

#endif