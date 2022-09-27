#include "Pipe.h"
#include <iostream>

Pipe::Pipe()
{
	this->diametr = 0;
	this->length = 0;
	this->inRepair = 0;
}

int Pipe::getLength() const {
	return this->length;
}

int Pipe::getDiametr() const {
	return this->diametr;
}

bool Pipe::getInRepair() const {
	return this->inRepair;
}

void Pipe::setLength(int length) {
	this->length = length;
}

void Pipe::setDiametr(int diametr) {
	this->diametr = diametr;
}

void Pipe::setInRepair(bool inRepair) {
	this->inRepair = inRepair;
}
