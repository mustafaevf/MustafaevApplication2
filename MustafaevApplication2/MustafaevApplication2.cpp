#include <iostream>
#include <string>
#include <fstream>
#include "Pipe.h"
#include "Station.h"

using namespace std;
 
void clearCin() {
	cin.clear();
	cin.ignore(123456, '\n');
}

void printMenu() {
	cout << "1. Добавить трубу" << endl;
	cout << "2. Добавить станцию" << endl;
	cout << "3. Просмотр всех объектов" << endl;
	cout << "4. Редактировать трубу" << endl;
	cout << "5. Редактировать станцию" << endl;
	cout << "6. Сохранить" << endl;
	cout << "7. Загрузить" << endl;
	cout << "0. Выйти" << endl;
}

void clearMenu() {
	system("cls");
}

void SaveToFile(string path, Pipe& pipe, Station& station) {
	clearMenu();
	ofstream fout;
	fout.open(path + ".txt", ofstream::trunc);
	if (fout.is_open()) {
		if (pipe.getLength() != 0 && station.getName() != "") {
			fout << pipe.getLength() << endl;
			fout << pipe.getDiametr() << endl;
			fout << pipe.getInRepair() << endl;
			fout << station.getName() << endl;
			fout << station.getCountWorkshop() << endl;
			fout << station.getCountActiveWorkshop() << endl;
			fout << station.getEfficiency() << endl;
			cout << "Файл " << path << ".txt" << " сохранен" << endl;
		}
		else {
			cout << "Ошибка сохранения. Добавте все объекты" << endl;

		}
	}
	else {
		cout << "Ошибка открытия файла" << endl;
	}
	fout.close();
	
}

void LoadFromFile(string path, Pipe& pipe, Station& station) {
	clearMenu();
	ifstream fin;
	fin.open(path + ".txt");
	if (fin.is_open()) {
		float ch;
		int i;
		string name;
		i = 0;
		while (getline(fin, name))
		{
			if (i == 0) {
				pipe.setLength(stod(name));
			}
			if (i == 1) {
				pipe.setDiametr(stod(name));
			}
			if (i == 2) {
				if (name == "1") {
					pipe.setInRepair(1);
				}
				else {
					pipe.setInRepair(0);
				}
			}
			if (i == 3) {
				station.setName(name);
			}
			if (i == 4) {
				station.setCountWorkshop(stoi(name));
			}
			if (i == 5) {
				station.setCountActiveWorkshop(stoi(name));
			}
			if (i == 6) {
				station.setEfficiency(stod(name));
			}
			i++;
		}
		 
		if (pipe.getLength() != 0 && pipe.getDiametr() != 0 && station.getName() != "" && station.getCountWorkshop() != 0 && station.getEfficiency() != 0) {
			cout << "Файл загружен" << endl;
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

void createPipe(Pipe& pipe, double length, double diametr, bool inRepair) {
	pipe.setLength(length);
	pipe.setDiametr(diametr);
	pipe.setInRepair(inRepair);

}

void createStation(Station& station, string name, int countWorkshop, int countActiveWorkshop, double efficiency) {
	station.setName(name);
	station.setCountWorkshop(countWorkshop);
	station.setCountActiveWorkshop(countActiveWorkshop);
	station.setEfficiency(efficiency);
}

void InputStation(Station& station) {
	clearMenu();
	string name;
	int countWorkshop, countActiveWorkshop;
	double efficiency;
	do {
		clearCin();
		cout << "Введите количество цехов: ";
		cin >> countWorkshop;
	} while (cin.fail() || countWorkshop <= 0);

	do {
		clearCin();
		cout << "Введите количество работающих цехов: ";
		cin >> countActiveWorkshop;

	} while (cin.fail() || countActiveWorkshop < 0 || countActiveWorkshop > countWorkshop);

	do {
		clearCin();
		cout << "Введите показатель эффективности: ";
		cin >> efficiency;
	} while (cin.fail() || efficiency < 0 || efficiency > 100);

	do {
		cout << "Введите название станции: ";
		cin.ignore();
		getline(cin, name);
		cin.clear();

	} while (cin.fail());

	createStation(station, name, countWorkshop, countActiveWorkshop, efficiency);
}

void InputPipe(Pipe& pipe) {
	clearMenu();
	double length, diametr;
	bool inrepair;
	
	do {
		clearCin();
		cout << "Введите длину трубы: ";
		cin >> length;
	} while (cin.fail() || length <= 0);

	do {
		clearCin();
		cout << "Введите диаметр трубы: ";
		cin >> diametr;
	} while (cin.fail() || diametr <= 0);
	
	do {
		clearCin();
		cout << "В работе: ";
		cin >> inrepair;
	} while (cin.fail());

	createPipe(pipe, length, diametr, inrepair);
}



void updateStation(Station& station) {
	int countOn;
	clearMenu();
	if (station.getName() == "") {
		cout << "Станция не найдена" << endl;
		return;
	}	
	int action;
	cout << "Количество цехов: " << station.getCountWorkshop() << "\nРабочих цехов: " << station.getCountActiveWorkshop() << "\n0. Отключить\n1. Включить" << endl;
	cout << "Выберите действие: ";
	cin >> action;
	if (action == 1) {
		cout << "Введите количество цехов для включения: ";
		cin >> countOn;
		if ((countOn <= station.getCountWorkshop() - station.getCountActiveWorkshop()) && countOn > 0) {
			station.setCountActiveWorkshop(station.getCountActiveWorkshop() + countOn);
		}
		else {
			cout << "Ошибка" << endl;
		}
	} 
	else if (action == 0) {
		cout << "Введите количество цехов для выключения: ";
		cin >> countOn;
		if (countOn <= station.getCountActiveWorkshop() && countOn > 0) {
			station.setCountActiveWorkshop(station.getCountActiveWorkshop() - countOn);
		}
		else {
			cout << "Ошибка" << endl;
		}
	}
	else {
		cout << "Попробуйте еще раз" << endl;
	}
	
	
	
	
}

void updatePipe(Pipe& pipe) {
	clearMenu();
	if (pipe.getLength() == 0) {
		cout << "Труба не найдена" << endl;
		return;
	}
	int action;
	cout << "Статус трубы: " << (pipe.getInRepair() ? "true" : "false") << "\n0. Отключить\n1. Включить" << endl;
	cout << "Выберите: ";
	cin >> action;
	clearMenu();
	if (action == 0) {
		if (pipe.getInRepair() != 0) {
			pipe.setInRepair(0);
			cout << "Труба отключена" << endl;
		}
		else {
			cout << "Труба уже отключена" << endl;
		}
	}
	else if (action == 1) {
		if (pipe.getInRepair() != 1) {
			pipe.setInRepair(1);
			cout << "Труба включена" << endl;
		}
		else {
			cout << "Труба уже включена" << endl;
		}
	}
	else {
		cout << "Повторите попытку" << endl;
	}
}

void printObjects(Pipe& pipe, Station& station) {
	clearMenu();
	if(pipe.getLength() != 0 && pipe.getDiametr() != 0)
		cout << "Труба\nДлина: " << pipe.getLength() << "\nДиаметр: " << pipe.getDiametr() << "\n" << (pipe.getInRepair()? "В работе":"Не работает") << endl;
	if (station.getName() != "" && station.getCountWorkshop() != 0 && station.getEfficiency() != 0)
		cout << "Станция " << station.getName() << "\nКоличество цехов: " << station.getCountWorkshop() << "\nКоличество рабочих цехов: " << station.getCountActiveWorkshop() << "\nЭффективность: " << station.getEfficiency() << endl;
	
}

int main() {
	setlocale(LC_ALL, "");
	Pipe pipe;
	Station station;
	int menu;
	while (1)
	{
		printMenu();
		cout << "Введите пункт меню: ";
		cin >> menu;
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
				InputPipe(pipe);
				break;
			case 2:
				InputStation(station);
				break;
			case 3:
				printObjects(pipe, station);
				break;
			case 4:
				updatePipe(pipe);
				break;
			case 5:
				updateStation(station);
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
			default:
				break;
			}
		}
	}
	return 1;
}
