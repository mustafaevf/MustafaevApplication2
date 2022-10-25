#include "Station.h"

unsigned int Station::IDcs = 0;


int Station::getId() const
{
	return this->id;
}

std::string Station::getName() const
{
	return this->name;
}

int Station::getCountWorkshop() const
{
	return this->countWorkshop;
}

int Station::getCountActiveWorkshop() const
{
	return this->countActiveWorkshop;
}

double Station::getEfficiency() const
{
	return this->efficiency;
}

void Station::setName(std::string name)
{
	this->name = name;
}


void Station::setCountWorkshop(int countWorkshop)
{
	this->countWorkshop = countWorkshop;
}

void Station::setCountActiveWorkshop(int countActiveWorkshop)
{
	this->countActiveWorkshop = countActiveWorkshop;
}

void Station::setEfficiency(double efficiency)
{
	this->efficiency = efficiency;
}

void Station::setId(int id)
{
	this->id = id;
}

