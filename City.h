#pragma once
#ifndef CITY_H
#define CITY_H
#include <string>
#include <vector>
#include "Flight.h"
using namespace std;


class City {
public:
	City(string city) : myCity(city) {};

	void addflight(City* end, int mile, int price) {
		Flight toPlace(this, end, mile, price);
		outflights.push_back(toPlace);
		end->inflights.push_back(toPlace);
	}
	int sizeOut() { return outflights.size(); }

	string getReturn(int i) {
		return (outflights[i].getDestination()->getCityName());
	}
	string getCityName() { return myCity; };
private:
	string myCity;
	vector<Flight> inflights;
	vector<Flight> outflights;
};

#endif
