#include <string>
#include "Station.h"
#include <iostream>

Station::Station()
{
	setName("");
	setCountWorkshop(0);
	setCountActiveWorkshop(0);
	setEfficiency(0);
}

void Station::setName(std::string name) {
	this->name = name;
}

void Station::setCountWorkshop(int countWorkshop) {
	this->countWorkshop = countWorkshop;
}

void Station::setCountActiveWorkshop(int countActiveWorkshop) {
	this->countActiveWorkshop = countActiveWorkshop;
}

void Station::setEfficiency(int efficiency) {
	this->efficiency = efficiency;
}

std::string Station::getName() const {
	return this->name;
}

int Station::getCountWorkshop() const {
	return this->countWorkshop;
}

int Station::getCountActiveWorkshop() const {
	return this->countActiveWorkshop;
}

int Station::getEfficiency() const {
	return this->efficiency;
}