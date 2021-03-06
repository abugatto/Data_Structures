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

	int str_num = 0;
	string OG, DN;
	OG = DN = "";
	string** temp = new string*[100];
	for(int p = 0; p < 100; p++) {
		temp[p] = new string[2];
	}

	char ctemp;
	while(fin.good()) {
		OG = DN = "";

		ctemp = fin.get();
		while(ctemp != ',') {
			OG += ctemp;
			ctemp = fin.get();

			//cout << ctemp;
		}

		ctemp = fin.get();
		while(ctemp != '\n' && fin.good()) {
			DN += ctemp;
			ctemp = fin.get();

			//cout << ctemp;
		}

		cout << OG << "->" << DN << endl;

		for(int cities = 0; cities < 2; cities++) {
			if(cities == 0) {
				temp[str_num][cities] = OG;
			} else {
				temp[str_num][cities] = DN;
			}
		}

		str_num++;
	}

	for(int i = 0; i < str_num; i++) {
		
	}

	string** requests = new string*[str_num];
	for(int request = 0; request < str_num; request++) {
		requests[request] = new string[2];

		for(int cities = 0; cities < 2; cities++) {
			requests[request][cities] = temp[request][cities];
			cout << requests[request][cities] << " ";
		}
	}

	int counter = str_num;
	while(counter >= 0) {
		delete[] temp[counter];
		counter--;
	}
	delete[] temp;
	temp = nullptr;

	fin.close();

	return requests;
}


#endif