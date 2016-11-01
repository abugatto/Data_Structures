#include <iostream>
#include <string>
#include <cstdlib>
#include "insertion_sort.h"
#include "merge_sort.h"
#include "bucket_sort.h"

using namespace std;

int main() {

	int *small, *medium, *large;
	small = new int[1000];
	medium = new int[10000];
	large = new int[100000];

	srand(1000000); //sets random number between 1-1000000
	for(int i = 0; i < 3; i++) { //load random values into the arrays
		int p = (i == 2) ? 100 : ((i == 1) ? 10 : 1);
		int* aptr = (i == 2) ? large : ((i == 1) ? medium : small);

		for(int j = 0; j < (1000 * p); j++) {
			aptr[j] = rand();
		}

		delete[] aptr;
		aptr = nullptr;
	}

	//run sorting algorithms

	InsertionSort i_small_sort, i_medium_sort, i_large_sort;
	MergeSort m_small_sort, m_medium_sort, m_large_sort;
	BucketSort b_small_sort, b_medium_sort, b_large_sort;

	for(int i = 0; i < 10; i++) { //small
		i_small_sort.run(small, 1000); /*
		m_small_sort.run(small, 1000);
		b_small_sort.run(small, 1000); */
	}

	for(int i = 0; i < 10; i++) { //medium
		i_medium_sort.run(medium, 10000); /*
		m_medium_sort.run(medium, 10000);
		b_medium_sort.run(medium, 10000); */
	}

	for(int i = 0; i < 10; i++) { //large
		i_large_sort.run(large, 100000); /*
		m_large_sort.run(large, 100000);
		b_large_sort.run(large, 100000); */
	}

	i_small_sort.write("data.txt"); //stores all data in strings until
	i_medium_sort.write("data.txt");
	i_large_sort.write("data.txt"); /*
	m_small_sort.write("data.txt");
	m_medium_sort.write("data.txt");
	m_large_sort.write("data.txt");
	b_small_sort.write("data.txt");
	b_medium_sort.write("data.txt");
	b_large_sort.write("data.txt");
*/
	//deallocate arrays

	delete[] small;
	delete[] medium;
	delete[] large;
	small = medium = large = nullptr; 

	return 0;
}