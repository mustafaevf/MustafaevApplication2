#include "Pipe.h"
#include "Utils.h"

unsigned int Pipe::IDp = 0;

int Pipe::getId() const
{
	return this->id;
}

double Pipe::getLength() const
{
	return this->length;
}

bool Pipe::getRepair() const
{
	return this->repair;
}

double Pipe::getDiametr() const
{
	return this->diametr;
}

void Pipe::setLength(double length)
{
	this->length = length;
}

void Pipe::setDiametr(double diametr)
{
	this->diametr = diametr;
}

void Pipe::setRepair(bool repair)
{
	this->repair = repair;
}

void Pipe::setId(int id)
{
	this->id = id;
}
void Pipe::updateRepair() {
	this->repair = !this->repair;
}
