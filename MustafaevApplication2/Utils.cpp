#include "Utils.h"


void PrintMenu() {
	std::cout << "1) �������� �����" << std::endl
		<< "2) �������� ������������� �������" << std::endl
		<< "3) �������� ��� �������" << std::endl
		<< "4) ��������� � ����" << std::endl
		<< "5) ��������� �� �����" << std::endl
		<< "6) ����� �����" << std::endl
		<< "7) ����� ������������� �������" << std::endl
		<< "8) ������� �����" << std::endl
		<< "9) ������� ������������� �������" << std::endl
		<< "10) �������� �������" << std::endl
		<< "11) �������� ���������������� ����" << std::endl
		<< "12) ������� ���������������� ����" << std::endl
		<< "13) �������������� ����������" << std::endl
		<< "14) ������������ �����" << std::endl
		<< "15) ����������� ���� ����� �������������� ���������" << std::endl
		<< "16) ������� ���������������� ����" << std::endl;
}

std::string getText(std::string message) {
	std::string text;
	std::cout << message;
	std::cin.ignore();
	getline(std::cin, text);
	return text;
}

bool FilterGetByNamePipe(Pipe& pipe, std::string name) {
	std::string ame = pipe.getName();
	if (size_t(ame.find(name)) != std::string::npos)
		return true;
}

bool FilterGetByNameStation(Station& station, std::string name) {
	std::string ame = station.getName();
	std::cout << size_t(ame.find(name));
	if (size_t(ame.find(name)) != std::string::npos)
		return true;
}

bool FilterGetByRepairPipe(Pipe& pipe, bool repair) {
	return pipe.getRepair() == repair;
}

bool FilterGetByEfficiencyStation(Station& station, double efficiency) {
	return station.getEfficiency() == efficiency;
}


bool FilterGetByDiametrPipe(Pipe& pipe, double diametr) {
	return pipe.getDiametr() == diametr;
}