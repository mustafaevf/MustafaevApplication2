#include <iostream>
#include <string>
#include "Pipe.h"
#include "Station.h"
#include <vector>
#include <fstream>
#include "Utils.h"


using namespace std;
 
static int id = 1;


void SaveToFile(string path, vector<Pipe>& pipes, vector<Station>& stations) {
	ofstream fout;
	fout.open(path + ".txt", ofstream::trunc);
	if (fout.is_open()) {
		fout << pipes.size() << endl;
		fout << stations.size() << endl;

		/*if (pipes.size() != 0) {
			for (int k = 0; k < pipes.size(); k++) {

			}
		}*/
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


bool CheckPipeInPipes(vector<Pipe>& pipes, int id) {
	
	for (int i = 0; i < pipes.size(); i++) {
		if (id == pipes[i].id) {
			return true;
		}
	}
}

bool CheckStationInStations(vector<Station>& stations, int id) {
	for (int i = 0; i < stations.size(); i++) {
		if (id == stations[i].id) {
			return true;
		}
	}
}

bool CheckStations(vector<Station>& stations) {
	if (stations.size() == 0) {
		return false;
	}
}

bool CheckPipes(vector<Pipe>& pipes) {
	if (pipes.size() == 0) {
		return false;
	}
}

void DeleteStation(vector<Station>& stations, int id) {
	stations.erase(stations.begin() + id - 1);
}

void DeletePipe(vector<Pipe>& pipes, int id) {
	pipes.erase(pipes.begin() + id - 1);
}


void PrintStations(vector<Station>& stations) { // вывод всех станций
	if (!CheckStations(stations)) {
		cout << "Станций не найдена" << endl;
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

void PrintPipes(vector<Pipe>& pipes) { // вывод всех труб
	if (!CheckPipes(pipes)) {
		cout << "Трубы не найдены" << endl;
		return;
	}

	for (int i = 0; i < pipes.size(); i++) {
		cout << "Труба (" << pipes[i].id << ")" << endl;
		cout << "Название: " << pipes[i].getName() << endl;
		cout << "Длина: " << pipes[i].getLength() << endl;
		cout << "Диаметр: " << pipes[i].getDiametr() << endl;
		cout << "В ремонте: " << pipes[i].getInRepair() << endl;
	}
} 


void InputCreateStation(vector<Station>& stations, Station& station) {
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

void InputCreatePipe(vector<Pipe>& pipes, Pipe& pipe) {
	double length, diametr;
	bool inrepair;
	string name;
	
	length = getInt("Введите длину: (м) ", 0, 1000);
	diametr = getInt("Введите диаметр: (мм) ", 0, 1000);
	inrepair = getInt("В работе: ", 0, 1);

	do {
		cout << "Введите название трубы: ";
		cin.ignore();
		getline(cin, name);

	} while (cin.fail());

	pipe.id = id++;
	pipe.setName(name);
	pipe.setDiametr(diametr);
	pipe.setLength(length);
	pipe.setInRepair(inrepair);
	pipes.push_back(pipe);
}


void PrintStation(vector<Station>& stations, int id) {
	if (stations.size() != 0) {
		for (int i = 0; i < stations.size(); i++) {
			if (id == stations[i].id) {
				cout << "Станция (" << stations[i].id << ")" << endl;
				cout << "Название: " << stations[i].getName() << endl;
				cout << "Цехов: " << stations[i].getCountWorkshop() << endl;
				cout << "Рабочих цехов: " << stations[i].getCountActiveWorkshop() << endl;
				cout << "Эффективность: " << stations[i].getEfficiency() << endl;
			}
			
		}
	}
}

void PrintPipe(vector<Pipe>& pipes, int id) {
	if (pipes.size() != 0) {
		for (int i = 0; i < pipes.size(); i++) {
			if (id == pipes[i].id) {
				cout << "Труба (" << pipes[i].id << ")" << endl;
				cout << "Название: " << pipes[i].getName() << endl;
				cout << "Длина: " << pipes[i].getLength() << endl;
				cout << "Диаметр: " << pipes[i].getDiametr() << endl;
				cout << "В работе: " << pipes[i].getInRepair() << endl;
			}
		}
	}
}


void InputUpdatePipes(vector<Pipe>& pipes) {
	if (!CheckPipes(pipes)) {
		cout << "Добавте трубы" << endl;
		return;
	}
	cout << "1) Выбрать трубы для отправки в ремонт" << endl;
	cout << "2) Выбрать трубы для починки" << endl;

	int i;

	i = getInt("Выберите: ", 1, 2);

	if (i == 1) {
		cout << "Введите 0 для выхода" << endl;
		while (1) {
			int pipeId;
			pipeId = getInt("Введите id трубы: ", 0, 100);
			if (pipeId == 0) {
				break;
			}
			for (int k = 0; k < pipes.size(); k++) {
				if (pipes[k].id == pipeId) {
					if (pipes[k].getInRepair() == 1) {
						cout << "Успешно. Труба отправлена в ремонт" << endl;
						pipes[k].updateInRepair();
					}
					else {
						cout << "Ошибка. Труба уже в ремонте" << endl;
					}
					
				}
				else {
					cout << "Ошибка. Труба не найдена" << endl;
				}
			}
		}
	}

	if (i == 2) {
		cout << "Введите 0 для выхода" << endl;
		while (1) {
			int pipeId;
			pipeId = getInt("Введите id трубы: ", 0, 100);
			if (pipeId == 0) {
				break;
			}
			for (int k = 0; k < pipes.size(); k++) {
				if (pipes[k].id == pipeId) {
					if (pipes[k].getInRepair() == 0) {
						cout << "Успешно. Труба в работе" << endl;
						pipes[k].updateInRepair();
					}
					else {
						cout << "Ошибка. Труба уже работает" << endl;
					}

				}
				else {
					cout << "Ошибка. Труба не найдена" << endl;
				}
			}
		}
	}
	
}

void InputUpdateStations(vector<Station>& stations) {
	if (!CheckStations(stations)) {
		cout << "Станции не найдены" << endl;
		return;
	}
	int stationId;
	stationId = getInt("Введите id станции: ", 1, id);
	for (int k = 0; k < stations.size(); k++) {
		if (stations[k].id == stationId) {
			PrintStation(stations, stationId);
			int activeWorkshop;
			activeWorkshop = getInt("Введите количество рабочих цехов: ", 0, stations[k].getCountWorkshop());
			stations[k].setCountActiveWorkshop(activeWorkshop);
			cout << "Успешно. Данные по станции обновлены" << endl;
		}
		else {
			cout << "Станция не найдена" << endl;
		}
	}
}


void InputFilterPipes(vector<Pipe>& pipes) {
	cout << "Выберите фильтр для поиска труб" << endl;
	cout << "1) По названию" << endl;
	cout << "2) По признаку в ремонте" << endl;
	int i;
	i = getInt("Выберите фильтр: ", 1, 2);
	if (i == 1) {
		cout << "Введите название трубы: " << endl;
		string name;
		cin.ignore();
		getline(cin, name);
		vector<int> find = searchByFilterPipe(pipes, name);
		if (find.size() == 0) {
			cout << "Трубы не найдены" << endl;
			return;
		}
		for (int k = 0; k < find.size(); k++) {
			PrintPipe(pipes, find[k]);
		}
	}
	if (i == 2) {
		cout << "В ремонте или нет" << endl;
		bool status;
		status = getInt("Введит 0 или 1: ", 0, 1);
		vector<int> find = searchByFilterPipe(pipes, status);
		if (find.size() == 0) {
			cout << "Трубы не найдены" << endl;
			return;
		}
		for (int k = 0; k < find.size(); k++) {
			PrintPipe(pipes, find[k]);
		}
	}
}

void InputFilterStations(vector<Station>& stations) {
	cout << "Выберите фильтр для поиска станций" << endl;
	cout << "1) По названию" << endl;
	int i;
	i = getInt("Выберите фильтр: ", 1, 1);
	if (i == 1) {
		cout << "Введите название станции: " << endl;
		string name;
		cin.ignore();
		getline(cin, name);
		vector<int> find = searchByFilterStation(stations, name);
		if (find.size() == 0) {
			cout << "Станции не найдены" << endl;
			return;
		}
		for (int k = 0; k < find.size(); k++) {
			PrintStation(stations, find[k]);
		}
	}
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
		menu = getInt("Введите пункт меню: ", 0, 11);
		switch (menu)
		{
		case 0:
			return 0;
			break;
		case 1:
			ClearMenu();
			InputCreatePipe(pipes, pipe);
			break;
		case 2:
			ClearMenu();
			InputCreateStation(stations, station);
			break;
		case 3:
		{
			ClearMenu();
			PrintPipes(pipes);
			PrintStations(stations);
			break;
		}
		case 4:
			ClearMenu();
			InputUpdatePipes(pipes);
			break;
		case 5:
			ClearMenu();
			InputUpdateStations(stations);
			break;
		case 6:
		{
			cout << "Введите название файла для сохранения: ";
			string path;
			cin >> path;
			SaveToFile(path, pipes, stations);
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
			ClearMenu();
			InputFilterPipes(pipes);
			break;
		}

		case 9:
		{
			
			ClearMenu();
			InputFilterStations(stations);
			break;
		}

		case 10:
		{
			ClearMenu();
			cout << "Удаление трубы" << endl;
			int pipeId;
			pipeId = getInt("Введите id трубы: ", 1, id);
			if (!CheckPipeInPipes(pipes, pipeId)) {
				cout << "Труба не найдена" << endl;
				break;
			}
			DeletePipe(pipes, pipeId);
			break;
		}
		case 11:
		{
			ClearMenu();
			cout << "Удаление станции" << endl;
			int stationId;
			stationId = getInt("Введите id станции: ", 1, id);
			if (!CheckStationInStations(stations, stationId)) {
				cout << "Станция не найдена" << endl;
				break;
			}
			DeleteStation(stations, stationId);
			break;
		}

		default:
			break;
		}
	}
	return 1;
}
