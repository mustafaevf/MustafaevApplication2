#include "Pipe.h"
#include <fstream>

Pipe::Pipe()
{
	this->diametr = 0.0;
	this->length = 0;
	this->inRepair = 0;
}

double Pipe::getLength() const {
	return this->length;
}

double Pipe::getDiametr() const {
	return this->diametr;
}

bool Pipe::getInRepair() const {
	return this->inRepair;
}

void Pipe::setName(std::string name)
{
	this->name = name;
}

std::string Pipe::getName()
{
	return this->name;
}

void Pipe::setLength(double length) {
	this->length = length;
}

void Pipe::setDiametr(double diametr) {
	this->diametr = diametr;
}

void Pipe::setInRepair(bool inRepair) {
	this->inRepair = inRepair;
}
void Pipe::saveFile(std::ofstream& fout)
{
	fout << length;
	fout << diametr;
	fout << inRepair;
}
bool Pipe::check() {
	if (this->length == 0) return false;
	else return true;
}

void Pipe::updateInRepair()
{
	this->inRepair = !this->inRepair;
}
