#include "Pipe.h"
#include <fstream>

int Pipe::IDp = 0;

// get
int Pipe::getId() const { return id; } 
double Pipe::getLength() const { return length; }
bool Pipe::getRepair() const { return repair; }
double Pipe::getDiametr() const { return diametr; }
std::string Pipe::getName() const { return name; }

// set
void Pipe::setName(std::string _name) { name = _name; }
void Pipe::setLength(double _length) { length = _length; }
void Pipe::setDiametr(double _diametr) { diametr = _diametr; }
void Pipe::setRepair(bool _repair) { repair = _repair; }
void Pipe::setId(int _id) { id = _id; }

void Pipe::updateRepair() { repair = !repair; }

void Pipe::Save(std::ofstream& fout) {
	fout << name << std::endl;
	fout << length << std::endl;
	fout << diametr << std::endl;
	fout << repair << std::endl;
}

void Pipe::Load(std::ifstream& fin) {
	fin >> name;
	fin >> length;
	fin >> diametr;
	fin >> repair;
}

//std::ostream& operator << (std::ostream& out, Pipe& pipe) {
//	out << "����� (" << pipe.id << ")" << std::endl;
//	out << "��������: " << pipe.name << std::endl;
//	out << "�����: " << pipe.length << std::endl;
//	out << "�������: " << pipe.diametr << std::endl;
//	out << (pipe.repair ? "� �������" : "� ������") << std::endl;
//	return out;
//}

//std::istream& operator >> (std::istream& in, Pipe& pipe) {
//	pipe.setId(++Pipe::IDp);
//	double length = getNumber("������� ������ �����: ", 1, 1000);
//	double diametr = getNumber("������� ������� �����: ", 1, 1000);
//	bool repair = getNumber("� �������: ", 0, 1);
//	pipe.setLength(length);
//	pipe.setDiametr(diametr);
//	pipe.setRepair(repair);
//	return in;
//}