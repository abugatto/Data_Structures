#include <iostream> 
#include <fstream>

using namespace std;

class kSmall {
public:
	kSmall();
	~kSmall();
	void parse(const string& filename);
	void trace(const int& size, const int& pivot) const;
	int find_kSmall(const int& k) const;
private:
	int k;
	int* list;
	int counter;
	int num;
};

kSmall::kSmall() {
	k = counter = num = 0;
}

kSmall::~kSmall() {

}

void kSmall::parse(const string& filename) {
	fstream fin;

	fin.open(filename);

	int i = 0;
	while(fin >> i) { //counts the number of elements in the document
		num++;
		i = 0;
	}

	list = new int[num]; //makes an array as long as the 



	fin.close();
}

void kSmall::trace(const int& size, const int& pivot) const { //NEEDS PIVOT
	fstream fin;

	fin.open("trace.txt");

	fin << counter << ":\t";

	int cntr = 0;
	while(cntr <= size) {
		fin << "[" << list[cntr] << "]";
	}
	fin << endl;

	fin.close();
}

int kSmall::find_kSmall(const int& k) const {

}