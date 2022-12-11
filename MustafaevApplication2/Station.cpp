#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Utils.h"
#include "Station.h"

int Station::IDcs = 0;

Station::Station() {
	Station::IDcs++;
	this->id = IDcs;
}

int Station::getId() const { return id; }
std::string Station::getName() const { return this->name; }
int Station::getCountWorkshop() const { return this->countWorkshop; }
int Station::getCountActiveWorkshop() const { return this->countActiveWorkshop; }
double Station::getEfficiency() const { return this->efficiency; }

void Station::setName(std::string _name) { this->name = _name; }
void Station::setCountWorkshop(int _countWorkshop) { this->countWorkshop = _countWorkshop; }
void Station::setCountActiveWorkshop(int _countActiveWorkshop) { this->countActiveWorkshop = _countActiveWorkshop; }
void Station::setEfficiency(double _efficiency) { this->efficiency = _efficiency; }

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

std::ostream& operator << (std::ostream& out, Station& station) {
	out << "������� (" << station.id << ")" << std::endl;
	out << "��������: " << station.name << std::endl;
	out << "�����: " << station.countWorkshop << std::endl;
	out << "������� �����: " << station.countActiveWorkshop << std::endl;
	out << "�������������: " << station.efficiency << std::endl;
	return out;
}

std::istream& operator >> (std::istream& in, Station& station) {
	int countWorkshop = getNumber("������� ���������� �����: ", 1, 1000);
	int countActiveWorkshop = getNumber("������� ���������� ������� �����: ", 1, countWorkshop);
	double efficiency = getNumber("������� ������������� ������������� �������: ", 1.0, 100.0);
	in.ignore();
	std::string name;
	std::cout << "������� �������� �������: ";
	getline(in, name);
	station.setCountWorkshop(countWorkshop);
	station.setCountActiveWorkshop(countActiveWorkshop);
	station.setEfficiency(efficiency);
	station.setName(name);
	return in;
}
