#include "City.h"
#include "Flight.h"
#include "Airport.h"

// Kunle new addition (git reintroduction) v3

int main()
{
	string filename;
	cout << "Type in a file with flights labeled in such order per line: \"DepartureCity ArrivalCity Mileage Cost\" " << endl;
	cout << "Filename: ";
	getline(cin, filename);
	ifstream file(filename.c_str());
	graphAirport Reagan;
	Reagan.createGraph(file);
	string city;
	cout << "Type in the city from which you would like to peform a depth first traversal from. " << endl;
	cout << "City: ";
	getline(cin, city);
	Reagan.depthFirstTraversal(city);
	cout << endl;
	return 0;
}