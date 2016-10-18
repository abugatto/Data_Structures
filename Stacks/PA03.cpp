#ifndef PA03_CPP
#define PA03_CPP

#include <iostream>
#include <fstream>
#include <string>
#include "FlightMap.h"

using namespace std;

string** get_requests(int& request_num);

int main() {
	int request_num = 0;
	string** requests = get_requests(request_num);

	//**********************************************************************************

	FLIGHTMAP1 map("cityFile.txt", "flightFile.txt");

	for(int i = 0; i < request_num; i++) {
		if(map.find_path(requests[i][0], requests[i][1])) {
			cout << "You can fly from " << requests[i][0] << " to " << requests[i][1] << "." << endl;
		} else {
			cout << "" << requests[i][0] << " to " << requests[i][1] << "" << endl;
		}
	}

	//**********************************************************************************

	FLIGHTMAP2 map2("cityFile.txt", "flightFile.txt");

	for(int i = 0; i < request_num; i++) {
		if(map.find_path(requests[i][0], requests[i][1])) {
			cout << "You can fly from " << requests[i][0] << " to " << requests[i][1] << "." << endl;
		} else {
			cout << "" << requests[i][0] << " to " << requests[i][1] << "" << endl;
		}
	}

	//**********************************************************************************

	FLIGHTMAP3 map3("cityFile.txt", "flightFile.txt");

	for(int i = 0; i < request_num; i++) {
		if(map.find_path(requests[i][0], requests[i][1])) {
			cout << "You can fly from " << requests[i][0] << " to " << requests[i][1]
				 << " for" << "" << endl;
		} else {
			cout << "" << requests[i][0] << " to " << requests[i][1] << "" << endl;
		}
	}

	//**********************************************************************************

	while(request_num >= 0) {
		delete[] requests[request_num];
		request_num--;
	}
	delete[] requests;

	return 0;
}

string** get_requests(int& request_num) {
	fstream fin;
	fin.open("requestFile.txt");

	int i = 0;
	string OG, DN;
	string** temp = new string*[100];
	for(int p = 0; p < 100; p++) {
		temp[p] = new string[2];
	}

	while(fin >> OG >> DN) {
		OG.erase(OG.length() - 1, OG.length()); //erasing comma

		for(int p = 0; p < 2; p++) {
			if(p == 0) {
				temp[i][p] = OG;
			} else {
				temp[i][p] = DN;
			}
		}

		i++;
	}

	string** requests = new string*[i];
	for(int j = 0; j < i; j++) {
		requests[j] = new string[2];

		for(int k = 0; k < 2; k++) {
			requests[j][k] = temp[j][k];
		}
	}

	int c = i;
	while(c >= 0) {
		delete[] temp[c];
		c--;
	}
	delete[] temp;

	fin.close();

	return requests;
}


#endif