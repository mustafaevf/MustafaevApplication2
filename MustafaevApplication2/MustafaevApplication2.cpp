#include <iostream>
#include <string>
#include "Pipe.h"
#include "Station.h"
#include <vector>
#include "File.h"
#include "Utils.h"


using namespace std;
 
static int id = 1;


void SaveToFile(string path, const Pipe& pipe, const Station& station) {
	ofstream fout;
	bool pipeEx = false, stationEx = false;
	fout.open(path + ".txt", ofstream::trunc);
	if (fout.is_open()) {
		if (pipe.getLength() != 0)
			pipeEx = 1;
		if (station.getName() != "")
			stationEx = 1;
		fout << pipeEx << endl;
		fout << stationEx << endl;
		if (pipe.getLength() != 0) {
			fout << pipe.getLength() << endl;
			fout << pipe.getDiametr() << endl;
			fout << pipe.getInRepair() << endl;
			cout << "Труба сохранена " << endl;
		}
		if (station.getName() != "") {
			fout << station.getName() << endl;
			fout << station.getCountWorkshop() << endl;
			fout << station.getCountActiveWorkshop() << endl;
			fout << station.getEfficiency() << endl;
			cout << "Станция сохранена " << endl;
		}
		else {
			cout << "Добавте все объекты" << endl;

		}
	}
	else {
		cout << "Ошибка открытия файла" << endl;
	}
	fout.close();

}

void LoadFromFile(string path, Pipe& pipe, Station& station) {
	ifstream fin;
	bool pipeEx = false, stationEx = false;
	fin.open(path + ".txt");
	if (fin.is_open()) {
		fin >> pipeEx;
		fin >> stationEx;
		if (pipeEx && stationEx) {
			string name;
			double length, diametr;
			int countWorkshop, countActiveWorkshop;
			double efficiency;
			bool inRepair;
			fin >> length;
			fin >> diametr;
			fin >> inRepair;
			fin >> ws;
			getline(fin, name);
			fin >> countWorkshop;
			fin >> countActiveWorkshop;
			fin >> efficiency;

			pipe.setLength(length);
			pipe.setDiametr(diametr);
			pipe.setInRepair(inRepair);
			station.setName(name);
			station.setCountWorkshop(countWorkshop);
			station.setCountActiveWorkshop(countActiveWorkshop);
			station.setEfficiency(efficiency);

		}
		if (stationEx) {
			int countWorkshop, countActiveWorkshop;
			double efficiency;
			string name;
			fin >> ws;
			getline(fin, name);
			fin >> countWorkshop;
			fin >> countActiveWorkshop;
			fin >> efficiency;


			station.setName(name);
			station.setCountWorkshop(countWorkshop);
			station.setCountActiveWorkshop(countActiveWorkshop);
			station.setEfficiency(efficiency);


		}
		if (pipeEx) {
			double length, diametr;
			bool inRepair;
			fin >> length;
			fin >> diametr;
			fin >> inRepair;

			pipe.setLength(length);
			pipe.setDiametr(diametr);
			pipe.setInRepair(inRepair);

		}



		if (pipe.getLength() != 0 && pipe.getDiametr() != 0) {
			cout << "Труба загружена" << endl;
		}
		if (station.getName() != "" && station.getCountWorkshop() != 0 && station.getEfficiency() != 0) {
			cout << "Станция загружена" << endl;
		}
		else
		{
			cout << "объекты не загружены" << endl;
		}
	}
	else {
		cout << "Ошибка открытия файла" << endl;
	}
	fin.close();

}


void InputStation(vector<Station>& stations, Station& station) {
	string name;
	int countWorkshop, countActiveWorkshop;
	double efficiency; 
	
	countWorkshop = getInt("Введите количество цехов: ", 0, 1000);
	countActiveWorkshop = getInt("Введите количество рабочих цехов: ", 0, countWorkshop);
	efficiency = getInt("Введите показатель эффективности: ", 0, 100);

	do {
		cout << "Введите название станции: ";
		cin.ignore();
		getline(cin, name);

	} while (cin.fail());
	
	station.id = id++;
	station.setName(name);
	station.setCountWorkshop(countWorkshop);
	station.setCountActiveWorkshop(countActiveWorkshop);
	station.setEfficiency(efficiency);
	stations.push_back(station);
}

void InputPipe(Pipe& pipe, vector<Pipe>& pipes) {
	double length, diametr;
	bool inrepair;
	string name;
	
	length = getInt("Введите длину: ", 0, 1000);
	diametr = getInt("Введите диаметр: ", 0, 1000);
	inrepair = getInt("В работе: ", 0, 1);

	pipe.id = id++;
	pipe.setDiametr(diametr);
	pipe.setLength(length);
	pipe.setInRepair(inrepair);
	pipes.push_back(pipe);
}




bool ValidStation(vector<Station>& stations, int id) {
	if (stations.size() != 0) {
		for (int i = 0; i < stations.size(); i++) {
			if (stations[i].id == id) {
				return true;
			}
		}
	}
}

bool ValidPipe(vector<Pipe>& pipes, int id) {
	if (pipes.size() != 0) {
		for (int i = 0; i < pipes.size(); i++) {
			if(pipes[i].id == id) {
				return true;
			}
		}
	}
}

void DeletePipe(vector<Pipe>& pipes, int id) {
	if (!ValidPipe(pipes, id)) {
		cout << "Труба не найдена" << endl;
		return;
	}
	int position = pipes.size() - id;
	pipes.erase(pipes.begin() + position);
}

void DeleteStation(vector<Station>& stations, int id) {
	if (!ValidStation(stations, id)) {
		cout << "Станция не найдена" << endl;
		return;
	}
	stations.erase(stations.begin() + id);
}

void PrintStation(vector<Station>& stations, int id) {
	if (!ValidStation(stations, id)) {
		std::cout << "Станция не найдена" << std::endl;
		return;
	}
	cout << "Станция (" << id << ")" << endl;
	cout << "Название: " << stations[id].getName() << endl;
	cout << "Цехов: " << stations[id].getCountWorkshop() << endl;
	cout << "Рабочих цехов: " << stations[id].getCountActiveWorkshop() << endl;
	cout << "Эффективность: " << stations[id].getEfficiency() << endl;
}

void PrintPipe(vector<Pipe>& pipes, int id) {
	if (!ValidPipe(pipes, id)) {
		std::cout << "Труба не найдена" << std::endl;
		return;
	}
	cout << "Труба (" << id << ")" << endl;
	cout << "Длина: " << pipes[id].getLength() << endl;
	cout << "Диаметр: " << pipes[id].getDiametr() << endl;
	cout << "В ремонте: " << pipes[id].getInRepair() << endl;
}

void PrintPipes(vector<Pipe>& pipes) {
	if (pipes.size() == 0) {
		cout << "Трубы не найдены" << endl;
		return;
	}
	for (int i = 0; i < pipes.size(); i++) {
		cout << "Труба (" << pipes[i].id << ")" << endl;
		cout << "Длина: " << pipes[i].getLength() << endl;
		cout << "Диаметр: " << pipes[i].getDiametr() << endl;
		cout << "В ремонте: " << pipes[i].getInRepair() << endl;
	}
}

void PrintStations(vector<Station>& stations) {
	if (stations.size() == 0) {
		cout << "Станции не найдены" << endl;
		return;
	}
	for (int i = 0; i < stations.size(); i++) {
		cout << "Станция (" << stations[i].id << ")" << endl;
		cout << "Название: " << stations[i].getName() << endl;
		cout << "Цехов: " << stations[i].getCountWorkshop() << endl;
		cout << "Рабочих цехов: " << stations[i].getCountActiveWorkshop() << endl;
		cout << "Эффективность: " << stations[i].getEfficiency() << endl;
	}
}

//void InputFilterPipes(vector<Pipe>& pipes) {
//	int query;
//	bool params;
//	string name;
//	cout << "1. По признаку в ремонте\n2. По названию" << endl;
//	query = getInt("Выберите по какому параметру фильтровать: ", 1, 2);
//	vector<int> findedPipes;
//	if (query == 2) {
//		cout << "Введите название трубы: ";
//		cin.ignore();
//		getline(cin, name);
//		findedPipes = searchByFilterPipe(pipes, name);
//	}
//	else {
//		params = getInt("Введите параметр поиска: ", 0, 1);
//		findedPipes = searchByFilterPipe(pipes, params);
//	}
//
//	if (findedPipes.size() != 0) {
//		for (int i = 0; i < findedPipes.size(); i++) {
//			cout << "Труба (" << findedPipes[i] << ")\nId: " << pipes[findedPipes[i]].id << "\nДлина: " << pipes[findedPipes[i]].getLength() << "\nДиаметр: " << pipes[findedPipes[i]].getDiametr() << "\nВ ремонте: " << pipes[findedPipes[i]].getInRepair() << endl;
//		}
//	}
//	else {
//		cout << "Объекты не найдены" << endl;
//	}
//	
//}

void InputFilterStations(vector<Station>& stations) {
	int query;
	bool params;
	string name;
	cout << "1. По проценту незадействованных\n2. По названию" << endl;
	query = getInt("Выберите по какому параметру фильтровать: ", 1, 2);
	vector<int> findedStations;
	if (query == 2) {
		cout << "Введите название станции: ";
		cin.ignore();
		getline(cin, name);
		findedStations = searchByFilterStation(stations, name);
	}
	else {
		params = getInt("Введите процент поиска: ", 0, 100);
		findedStations = searchByFilterStation(stations, params);
	}

	if (findedStations.size() != 0) {
		for (int i = 0; i < findedStations.size(); i++) {
			cout << "Станция (" << findedStations[i] << ")\nНазвание: " << stations[findedStations[i]].getName() << "\nЦехов: " << stations[findedStations[i]].getCountWorkshop() << "\nРабочих цехов: " << stations[findedStations[i]].getCountActiveWorkshop() << "\nЭффективность: " << stations[findedStations[i]].getEfficiency() << endl;
		}
	}
	else {
		cout << "Объекты не найдены" << endl;
	}
}


void InputUpdatePipes(vector<Pipe>& pipes) {
	cout << "Редактирование труб" << endl;
	cout << "1. Редактировать трубу по id" << endl;
	cout << "2. Редактировать множество труб" << endl;
	int select;
	select = getInt("Введите пункт меню: ", 1, 2);
	ClearMenu();
	if (select == 1) {
		int pipeId;
		pipeId = getInt("Введите id трубы: ", 0, 1000);
		ClearMenu();
		for (int i = 0; i < pipes.size(); i++) {
			if (pipes[i].id == pipeId) {
				cout << "Труба (" << pipeId << ")\nНазвание: " << pipes[i].id << "\nДлина: " << pipes[i].getLength() << "\nДиаметр : " << pipes[i].getDiametr() << "\nВ ремонте : " << pipes[i].getInRepair() << endl;
				cout << "Статус трубы изменен" << endl;
				pipes[i].updateInRepair();
			}
		}
	}

	/*if (select == 2) {
		InputFilterPipes(pipes);
	}*/
}

int main() {
	setlocale(LC_ALL, "");
	Pipe pipe;
	Station station;
	vector<Station> stations;
	vector<Pipe> pipes;
	int menu;
	while (1)
	{
		PrintMenu();
		menu = getInt("Введите пункт меню: ", 0, 10);
		if (cin.fail()) {
			clearCin();
		}
		else {

			switch (menu)
			{
			case 0:
				return 0;
				break;
			case 1:
				ClearMenu();
				InputPipe(pipe, pipes);
				break;
			case 2:
				ClearMenu();
				InputStation(stations, station);
				break;
			case 3:
			{
				ClearMenu();
				PrintPipes(pipes);
				PrintStations(stations);
				break;
			}
			case 4:
				// редактирование
				break;
			case 5:
				// редактирование
				break;
			case 6:
			{
				cout << "Введите название файла для сохранения: ";
				string path;
				cin >> path;
				SaveToFile(path, pipe, station);
				break;
			}
			case 7:
			{
				string path;
				cout << "Введите название файла для загрузки: ";
				cin >> path;
				LoadFromFile(path, pipe, station);
				break;
			}
			case 8:
			{
				/*ClearMenu();
				int select;
				cout << "1. Поиск труб по фильтру" << endl;
				cout << "2. Поиск станций по фильтру" << endl;
				select = getInt("Выберите : ", 1, 2);
				if (select == 1) {
					InputFilterPipes(pipes);
				}
				else {
					InputFilterStations(stations);
				}*/
			}
			case 9:
			{
				ClearMenu();
				// поиск станции
				break;
			}
			case 10:
			{
				ClearMenu();
				int pipeId;
				pipeId = getInt("Введите id трубы для удаления: ", 0, id - 1);
				DeletePipe(pipes, pipeId);
				break;
			}
			case 11:
			{
				ClearMenu();
				int stationId;
				stationId = getInt("Введите id станции для удаления: ", 0, id - 1);
				DeleteStation(stations, stationId);
				break;
			}
			default:
				break;
			}
		}
	}
	return 1;
}
