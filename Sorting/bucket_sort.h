#ifndef B_SORT_H
#define B_SORT_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class BucketSort {
public:
	BucketSort();
	~BucketSort();
	void run(int list[], const int& legnth);
	void write(const string&);

private:
	int** bucket_arr;
	int* sorted_arr;
	string output;
};

BucketSort::BucketSort() {
	bucket_arr = new int*[10];

	sorted_arr = nullptr;
	output = "";
}

BucketSort::~BucketSort() {
	int i = 0;
	while(bucket_arr[i]) {
		delete[] bucket_arr[i];
		bucket_arr[i] = nullptr;
		i++;
	}
	delete[] bucket_arr;
	bucket_arr = nullptr;

	delete[] sorted_arr;
	sorted_arr = nullptr;
}

void BucketSort::run(int list[], const int& legnth) { //uses insertionsort in the buckets
	int bucket_size = (legnth == 1000) ? 1000 : ((legnth == 10000) ? 10000 : 1000000);
	for(int i = 0; i < 100; i++) {
		bucket_arr[i] = new int[bucket_size];
	}

	int index0, index1, index2, index3, index4, index5, index6, index7, index8, index9;
	index0 = index1 = index2 = index3 = index4 = index5 = index6 = index7 = index8 = index9 = 0;

	int divider = (legnth == 1000) ? 100 : ((legnth == 10000) ? 1000 : 100000);
	for(int i = 0; i < legnth; i++) {
		int bucket = i/divider;
		if(bucket >= 0 && bucket < 10) {
			bucket_arr[0][index0] = list[i];

			index0++;
		} else if(bucket >= 10 && bucket < 20) {
			bucket_arr[1][index1] = list[i];

			index1++;
		} else if(bucket >= 20 && bucket < 30) {
			bucket_arr[2][index2] = list[i];

			index2++;
		} else if(bucket >= 30 && bucket < 40) {
			bucket_arr[3][index3] = list[i];

			index3++;
		} else if(bucket >= 40 && bucket < 50) {
			bucket_arr[4][index4] = list[i];

			index4++;
		} else if(bucket >= 50 && bucket < 60) {
			bucket_arr[5][index5] = list[i];

			index5++;
		} else if(bucket >= 60 && bucket < 70) {
			bucket_arr[6][index6] = list[i];

			index6++;
		} else if(bucket >= 70 && bucket < 80) {
			bucket_arr[7][index7] = list[i];

			index7++;
		} else if(bucket >= 80 && bucket < 90) {
			bucket_arr[8][index8] = list[i];

			index8++;
		} else if(bucket >= 90 && bucket < 100) {
			bucket_arr[9][index9] = list[i];

			index9++;
		}
	}

	for(int i = 0; i < 10; i++) { //output
		int* indexptr = 0;
		switch(i) {
			case 0: indexptr = &index0; break;
			case 1: indexptr = &index1; break;
			case 2: indexptr = &index2; break;
			case 3: indexptr = &index3; break;
			case 4: indexptr = &index4; break;
			case 5: indexptr = &index5; break;
			case 6: indexptr = &index6; break;
			case 7: indexptr = &index7; break;
			case 8: indexptr = &index8; break;
			case 9: indexptr = &index9; break;
		};

		output += "Bucket" + to_string(i) + " ";
		for(int j = 0; j < *indexptr; j++) {
			output += "[" + to_string(bucket_arr[i][j]) + "]";
		}
	}
	output += "\n\n";

	for(int k = 0; k < 10; k++) {
		int value = 0;
		int hole = 0;
		int old_hole = 0;

		int* indexptr = 0;
		switch(k) {
			case 0: indexptr = &index0; break;
			case 1: indexptr = &index1; break;
			case 2: indexptr = &index2; break;
			case 3: indexptr = &index3; break;
			case 4: indexptr = &index4; break;
			case 5: indexptr = &index5; break;
			case 6: indexptr = &index6; break;
			case 7: indexptr = &index7; break;
			case 8: indexptr = &index8; break;
			case 9: indexptr = &index9; break;
		};

		for(int i = 1; i < *indexptr; i++) {
			value  = bucket_arr[k][i];
			hole = old_hole = i;

			while((hole > 0) && (bucket_arr[k][hole - 1] > value)) {
				bucket_arr[k][hole] = bucket_arr[k][hole - 1];
				hole -= 1;
			}

			bucket_arr[k][hole] = value;
			output += to_string(value) + " is moved from " + to_string(old_hole) + to_string(hole) + ".\n";
		}

		output += "Sorted Array:\t";
		for(int i = 0; i < *indexptr; i++) {
			output += "[" + to_string(bucket_arr[k][i]) + "]";
		}
	}

	for(int i = 0; i < legnth; i++) {
		int bucket = i/divider;
		if(bucket >= 0 && bucket < 10) {
			while(index1 != 0) {
				list[i] = bucket_arr[0][index0];

				index0--;
			}
		} else if(bucket >= 10 && bucket < 20) {
			while(index1 != 0) {
				list[i] = bucket_arr[1][index1];
				
				index1--;
			}
		} else if(bucket >= 20 && bucket < 30) {
			while(index1 != 0) {
				list[i] = bucket_arr[2][index2];
				
				index2--;
			}
		} else if(bucket >= 30 && bucket < 40) {
			while(index1 != 0) {
				list[i] = bucket_arr[3][index3];
				
				index3--;
			}
		} else if(bucket >= 40 && bucket < 50) {
			while(index1 != 0) {
				list[i] = bucket_arr[4][index4];
				
				index4--;
			}
		} else if(bucket >= 50 && bucket < 60) {
			while(index1 != 0) {
				list[i] = bucket_arr[5][index5];
				
				index5--;
			}
		} else if(bucket >= 60 && bucket < 70) {
			while(index1 != 0) {
				list[i] = bucket_arr[6][index6];
				
				index6--;
			}
		} else if(bucket >= 70 && bucket < 80) {
			while(index1 != 0) {
				list[i] = bucket_arr[7][index7];
				
				index7--;
			}
		} else if(bucket >= 80 && bucket < 90) {
			while(index1 != 0) {
				list[i] = bucket_arr[8][index8];
				
				index8--;
			}
		} else if(bucket >= 90 && bucket < 100) {
			while(index1 != 0) {
				list[i] = bucket_arr[9][index9];
				
				index9--;
			}
		}
	}
}

void BucketSort::write(const string& filename) {
	ofstream fout;
	fout.open(filename);

	fout << output << endl;

	fout.close();
}

#endif