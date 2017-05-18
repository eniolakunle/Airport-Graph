#pragma once
#ifndef FLIGHT_H
#define FLIGHT_H

class City;

class Flight {
private:
	City* bcity;
	City* ecity;
	int mileage;
	int cost;

public:
	Flight(City *x, City *y, int mile, int price) {
		bcity = x;
		ecity = y;
		mileage = mile;
		cost = price;
	};
	City* getDestination() const { return ecity; };
	int getMileage() { return mileage; };
};

#endif
