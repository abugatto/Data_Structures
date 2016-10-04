#include <iostream>
#include <fstream>
#include "ksmall_class.h"

int main() {

	//Declerations (insert as needed)
	KSmall algorithm; 		//object declaration
	int kSmall_pos = 0;		//For User Input
	int kSmall_val = 0;		//Populate using your algorithm implementation

	//User Input DO NOT MODIFY
	cout << "Please enter required kth smallest value:";
	cin >> kSmall_pos;


	//File Read code (insert) - This code should be able to parse the data in a text file similar to the provided one and store values in an array for processing.

	int legnth = algorithm.parse("data2.txt");

	//kmsall algorithm implementation or function call (insert) - implement using recursion as indicated

	kSmall_val = algorithm.find(kSmall_pos, 0, legnth - 1, legnth);

	//Log file output (insert) - preferred in .txt format acoording to instructions posted on assignment page

	cout << "The trace log file is called:\t" << "trace.txt" << endl;

	//Output DO NOT MODIFY
	cout << "kth smallest value = " << kSmall_val << endl;

	return 0;
}
