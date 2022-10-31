#include "Station.h"
#include <fstream>

int Station::IDcs = 0;

int Station::getId() const { return id; }
std::string Station::getName() const { return name; }
int Station::getCountWorkshop() const { return countWorkshop; }
int Station::getCountActiveWorkshop() const { return countActiveWorkshop; }
double Station::getEfficiency() const { return efficiency; }

void Station::setName(std::string _name) { name = _name; }
void Station::setCountWorkshop(int _countWorkshop) { countWorkshop = _countWorkshop; }
void Station::setCountActiveWorkshop(int _countActiveWorkshop) { countActiveWorkshop = _countActiveWorkshop; }
void Station::setEfficiency(double _efficiency) { efficiency = _efficiency; }
void Station::setId(int _id) { id = _id; }

void Station::Save(std::ofstream& fout) {
	fout << name << std::endl;
	fout << countWorkshop << std::endl;
	fout << countActiveWorkshop << std::endl;
	fout << efficiency << std::endl;
}

void Station::Load(std::ifstream& fin) {
	fin >> name;
	fin >> countWorkshop;
	fin >> countActiveWorkshop;
	fin >> efficiency;
}