#include "Pipe.h"
#include <iostream>

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

void Pipe::setLength(double length) {
	this->length = length;
}

void Pipe::setDiametr(double diametr) {
	this->diametr = diametr;
}

void Pipe::setInRepair(bool inRepair) {
	this->inRepair = inRepair;
}
