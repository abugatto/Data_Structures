#ifndef KSMALL_H
#define KSMALL_H

#include <iostream> 
#include <fstream>

using namespace std;

//************************************************************************************************

class KSmall {
public:
	KSmall();
	~KSmall();
	int parse(const string& filename);
	void trace() const;
	int find(const int& k, const int& first, const int& last);
private:
	int* list;
	int* p;
	int k, pivot;
};

//************************************************************************************************

KSmall::kSmall() {
	k = pivot = 0;

	list = nullptr;
	p = nullptr; 
}

KSmall::~kSmall() {
	delete[] list;
	list = nullptr;

	delete p;
	p = nullptr;
}

int KSmall::parse(const string& filename) {
	fstream fin;

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
		list[i] = temp[i];
	}

	delete[] temp;
	temp = nullptr;

	fin.close();

	return legnth;
}

void KSmall::trace() const { //NEEDS PIVOT
	fstream fout;

	fout.open("trace.txt");

	fout << counter << ":\t";

	int cntr = 0;
	while(cntr <= legnth) {
		if(cntr == pivot) {
			fout << " <[" << list[cntr] << "]> ";
		} else {
			fout << "[" << list[cntr] << "]";
		}
	}
	fout << endl;

	fout.close();
}

int KSmall::find(const int& k, const int& first, const int& last) {
	
	//Partition code:
	pivot = last;

	for(int i = 0;; i++) {
		if(list[pivot - i + 1] < list[i]) { //compare [pivot-1] and [1]
			int temp = list[pivot - i + 1];

			list[pivot - i + 1] = list[i];
			list[i] = temp; //smaller value being repositioned
		}


	}


	//trace();

	if(k < (pivot - first + 1)) {
		return find(k, first, pivot - 1);
	} else if(k == (pivot - first + 1)) {
		return *p;
	} else {
		return find(k - (pivot - first + 1), pivot + 1, last);
	}
}

#endif