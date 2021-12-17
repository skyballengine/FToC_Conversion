#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {



	// instantiating objects for reading from and writing to files
	ifstream inFS;
	// temp variables for storing data
	string cityName = " ";
	int cityTemp = 0;
	// variable for storing converted Celsius temp
	int cityTempCelsius = 0;

	ofstream outFS;
	cout << "Hello?\n" << endl;

	// read data in using ifstream object
	inFS.open("FahrenheitTemperature.txt");

	// open input stream to receive data from text file
	if (inFS.is_open()) {
		cout << "File to read is open!!\n" << endl;

	}
	else {
		cout << "File not open.\n" << endl;
		return -1;
	}

	// open output stream to write data to empty file
	outFS.open("FahrenheitToCelsius.txt");

	if (outFS.is_open()) {
		cout << "File to write is open!!\n" << endl;
	}

	else {
		cout << "File not open.\n" << endl;
	}

	// Begin input stream of cities and temps in F
	inFS >> cityName;
	// initiate while loop to check for fails
	while (!inFS.fail()) {
		inFS >> cityTemp;
		cout << "Received: " << cityName << " " << cityTemp << endl;
		cityTempCelsius = (cityTemp - 32) * 5 / 9;
		
		// write to converted temp file
		outFS << cityName << " " << cityTempCelsius << endl;
		if (outFS.fail()) {
			return -1;
		}
		else {
			cout << "Wrote " << cityName << " & " << cityTemp << endl;
		}
		cout << endl;
		inFS >> cityName;
	}

	inFS.close();
	outFS.close();

	inFS.open("FahrenheitToCelsius.txt");

	inFS >> cityName;
	while (!inFS.fail()) {
		inFS >> cityTemp;
		cout << "Received: " << cityName << " " << cityTemp << endl;

		inFS >> cityName;
	}
	cout << endl;

	inFS.close();


	


	return 0;
}