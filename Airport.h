#pragma once
#ifndef AIRPORT_H
#define AIRPORT_H
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "Flight.h"
using namespace std;

class City;
class Flight;

class graphAirport {
private:
	vector<City*> airlist;
	bool *visited;

	void dft(int ind, bool* visit) {
		visit[ind] = true;
		cout << airlist[ind]->getCityName() << " ";

		for (int i = 0; i < airlist[ind]->sizeOut(); i++) {
			int place = find(airlist[ind]->getReturn(i));
			if (!visited[place])
				dft(place, visit);
		}
	}

public:
	graphAirport() {};

	int find(string City) {
		for (int i = 0; i < airlist.size(); i++) {
			if (airlist[i]->getCityName().compare(City) == 0)
			return i;
		}
		exit(1);
	}
	
	bool isEmpty() {
		return (airlist.size() == 0);
	}

	//Departure Arrival Mile Cost
	void createGraph(ifstream &file) {
		string departure;
		string arrival; 
		City* holder;
		int mile = 0;
		int cost = 0;
		string ss;

		while (getline(file, ss)) {
			stringstream(ss) >> departure;
			bool found = false;
			for (int i = 0; i < airlist.size(); i++) {
				if (airlist[i]->getCityName().compare(departure) == 0) {
					i = airlist.size();
					found = true;
				}
			}
			if (!found) {
				airlist.push_back(new City(departure));
			}
			else continue;
		}
		file.clear();
		file.seekg(0, ios::beg);

		while (getline(file, ss)){
			bool found = false;
			stringstream(ss) >> departure >> arrival;
			for (int i = 0; i < airlist.size(); i++) {
				if (airlist[i]->getCityName().compare(arrival) == 0) {
					i = airlist.size();
					found = true;
				}
			}
			if (!found) {
				airlist.push_back(new City(arrival));
			}
			else continue;
		}
		file.clear();
		file.seekg(0, ios::beg);

		while (getline(file, ss)) {
			stringstream(ss) >> departure >> arrival >> mile >> cost;

			for (int i = 0; i < airlist.size(); i++) {
				if (airlist[i]->getCityName().compare(departure) == 0) {

					for (int j = 0; j < airlist.size(); j++) {
						if (airlist[j]->getCityName().compare(arrival) == 0) {
							airlist[i]->addflight(airlist[j], mile, cost);
							break;
						}
					}
					break;
				}
			}
		}

	}
	
	void clearGraph() {
		airlist.clear();
	}

	void depthFirstTraversal(string City) {
		visited = new bool[airlist.size()];

		for (int ind = 0; ind < airlist.size(); ind++)
			visited[ind] = false;

		dft(find(City), visited);
		}
	};

#endif
