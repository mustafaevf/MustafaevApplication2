#include <string>
#include "Station.h"
#include <fstream>


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

void Station::setEfficiency(double efficiency) {
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

void Station::saveFile(std::ofstream& fout)
{
	fout << name;
	fout << countWorkshop;
	fout << countActiveWorkshop;
	fout << efficiency;
}

double Station::getEfficiency() const {
	return this->efficiency;
}

void Station::updateWorkshop(int newCount)
{
	this->countActiveWorkshop = countActiveWorkshop + newCount;
}
