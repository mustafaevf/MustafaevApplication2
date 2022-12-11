#include <fstream>
#include "Pipe.h"
#include <math.h>
#include "Utils.h"

int Pipe::IDp = 0;

Pipe::Pipe() {
	Pipe::IDp++;
	this->id = IDp;
}

// get
int Pipe::getId() const { return this->id; } 

double Pipe::getLength() const { return this->length; }
bool Pipe::getRepair() const { return this->repair; }
double Pipe::getDiametr() const { return this->diametr; }
std::string Pipe::getName() const { return this->name; }
int Pipe::getInputStation() const { return this->inputStation; }
int Pipe::getOutputStation() const { return this->outputStation; }
double Pipe::getEfficiency() const { return this->efficiency; }

// set
void Pipe::setName(std::string _name) { this->name = _name; }
void Pipe::Edit()
{
	int action = getNumber("1) �������������\n2) ����������\n- ", 1, 2);
	if (action == 1)
		this->updateRepair();
}
void Pipe::setLength(double _length) { this->length = _length; }
void Pipe::setDiametr(double _diametr) { this->diametr = _diametr; }
void Pipe::setRepair(bool _repair) { this->repair = _repair; }
void Pipe::setInputStation(int id) { this->inputStation = id; }
void Pipe::setOutputStation(int id) { this->outputStation = id; }
void Pipe::setEfficiency(double efficiency) { this->efficiency = efficiency; }


void Pipe::updateRepair() { this->repair = !this->repair; }

void Pipe::Save(std::ofstream& fout) {
	fout << name << std::endl;
	fout << length << std::endl;
	fout << diametr << std::endl;
	fout << repair << std::endl;
	fout << inputStation << std::endl;
	fout << outputStation << std::endl;
}

void Pipe::Load(std::ifstream& fin) {
	fin >> name;
	fin >> length;
	fin >> diametr;
	fin >> repair;
	fin >> inputStation;
	fin >> outputStation;
	double result = sqrt(pow(diametr / 1000, 5) / length) * 100;
	efficiency = result;
	
}

std::ostream& operator << (std::ostream& out, Pipe& pipe) {
	out << "����� (" << pipe.id << ")" << std::endl;
	out << "��������: " << pipe.name << std::endl;
	out << "�����: " << pipe.length << std::endl;
	out << "�������: " << pipe.diametr << std::endl;
	out << "������� �������: " << pipe.getInputStation() << std::endl;
	out << "�������� �������: " << pipe.getOutputStation() << std::endl;
	out << "�������������: " << pipe.getEfficiency() << std::endl;
	out << (pipe.repair ? "in repair" : "in work") << std::endl;
	return out;
}

std::istream& operator >> (std::istream& in, Pipe& pipe) {
	pipe.setName(getText("������� �������� �����: "));
	pipe.setLength((double)getNumber("������� ����� �����: ", 0.0, 1000.0));
	std::cout << "�������� ������� �����\n" <<
		"1) 500 �� \n" <<
		"2) 700 ��\n" <<
		"3) 1400 ��\n";
	switch (getNumber("��������: ", 1, 3))
	{
	case 1:
		pipe.setDiametr(500);
		break;
	case 2:
		pipe.setDiametr(700);
		break;
	case 3:
		pipe.setDiametr(1400);
		break;
	}
	pipe.setRepair(0);
	double result = sqrt(pow(pipe.getDiametr() / 1000, 5) / pipe.getLength()) * 100;
	pipe.setEfficiency(result);
	return in;
}