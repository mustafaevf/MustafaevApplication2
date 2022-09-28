#include <iostream>
#include <string>
#include <fstream>
#include "Pipe.h"
#include "Station.h"

using namespace std;
 

void clearCin() {
	cin.clear();
	cin.ignore(123, '\n');
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

void SaveToFile(string path, const Pipe& pipe, const Station& station) {
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
			cout << "Ошибка сохранения. Создайте все объекты" << endl;

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
		int ch;
		string name;

		for (int i = 0; i <= 6; i++) {
			if (i == 3)
			{
				fin >> name;
			}
			else {
				fin >> ch;
			}

			switch (i) {
			case 0:
				pipe.setLength(ch);
				break;
			case 1:
				pipe.setDiametr(ch);
				break;
			case 2:
				pipe.setInRepair(ch);
				break;
			case 3:
				station.setName(name);
				break;
			case 4:
				station.setCountWorkshop(ch);
				break;
			case 5:
				station.setCountActiveWorkshop(ch);
				break;
			case 6:
				station.setEfficiency(ch);
				break;
			}

		}
		if (pipe.getLength() != 0 && pipe.getDiametr() != 0 && station.getName() != "" && station.getCountWorkshop() != 0) {
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

void createPipe(Pipe& pipe, int length, int diametr, bool inRepair) {
	pipe.setLength(length);
	pipe.setDiametr(diametr);
	pipe.setInRepair(inRepair);

}

void createStation(Station& station, string name, int countWorkshop, int countActiveWorkshop, int efficiency) {
	station.setName(name);
	station.setCountWorkshop(countWorkshop);
	station.setCountActiveWorkshop(countActiveWorkshop);
	station.setEfficiency(efficiency);
}

void InputStation(Station& station) {
	clearMenu();
	string name;
	int countWorkshop, countActiveWorkshop, efficiency;
	bool st_name = 0, st_countWorkshop = 0, st_countActiveWorkshop = 0, st_efficiency = 0;
	while (true) {
		if (st_name != 1) {
			cout << "Введите название станции: ";
			cin >> name;
			if (!cin.fail()) {
				st_name = 1;
				
			}
			else {
				cout << "Попробуйте еще раз" << endl;
				clearCin();
			}
		}
		if (st_countWorkshop != 1 && st_name == 1) {
			cout << "Введите количество цехов: ";
			cin >> countWorkshop;
			if (countWorkshop > 0 && !cin.fail()) {
				st_countWorkshop = 1;

			}
			else {
				cout << "Количество должно быть больше 0" << endl;
				clearCin();
			}
		}
		if (st_countActiveWorkshop != 1 && st_countWorkshop == 1 && st_name == 1) {
			cout << "Введите количество активных цехов: ";
			cin >> countActiveWorkshop;
			if (countActiveWorkshop > 0 && countActiveWorkshop <= countWorkshop && !cin.fail()) {
				st_countActiveWorkshop = 1;

			}
			else {
				cout << "Количество должно быть больше 0 и меньше количетсва цехов" << endl;
				clearCin();
			}
		}
		if (st_efficiency != 1 && st_countWorkshop == 1 && st_countActiveWorkshop == 1 && st_name == 1) {
			cout << "Введите эффективность: ";
			cin >> efficiency;
			if (efficiency > 0 && efficiency <= 100 && !cin.fail()) {
				st_efficiency = 1;
				clearMenu();
				cout << "Станция добавлена" << endl;
				createStation(station, name, countWorkshop, countActiveWorkshop, efficiency);
				return;
			}
			else {
				cout << "Эффективность > 0 и < 100" << endl;
				clearCin();
			}
		}
	}
}

void InputPipe(Pipe& pipe) {
	clearMenu();
	int length, diametr;
	bool inrepair;
	bool st_length = 0, st_diametr = 0, st_inreapir = 0;
	while (true) {
		if (st_length != 1) {
			cout << "Введите длину трубы: ";
			cin >> length;
			if (length > 0 && !cin.fail()) {
				st_length = 1;
				
			}
			else {
				cout << "Длина должна быть больше 0" << endl;
				clearCin();
			}
		}
		if (st_diametr != 1 && st_length == 1) {
			cout << "Введите диаметр трубы: ";
			cin >> diametr;
			if (diametr > 0 && !cin.fail()) {
				st_diametr = 1;
			}
			else {
				cout << "Диаметр должна быть больше 0" << endl;
				clearCin();
			}
		}
		if (st_inreapir != 1 && st_diametr == 1 && st_length == 1) {
			cout << "В ремонте: ";
			cin >> inrepair;
			if (!cin.fail()) {
				st_inreapir = 1;
				createPipe(pipe, length, diametr, inrepair);
				return;
			}
			else {
				cout << "1 или 0" << endl;
				clearCin();
			}
		}
		
	}
}





void updateStation(Station& station) {
	clearMenu();
	if (station.getName() == "") return;
	int action;
	cout << "Количество цехов: " << station.getCountWorkshop() << "\nРабочих цехов: " << station.getCountActiveWorkshop() << "\n0. Отключить\n1. Включить" << endl;
	cout << "Выберите: ";
	cin >> action;
	clearMenu();
	if (action == 0)
	{
		if (station.getCountActiveWorkshop() > 0) {
			station.setCountActiveWorkshop(station.getCountActiveWorkshop() - 1);
			cout << "Цех отключен" << endl;
			return;
		}
		else {
			cout << "Все цеха выключены" << endl;
		}
	}
	if (action == 1) {
		if (station.getCountActiveWorkshop() < station.getCountWorkshop()) {
			station.setCountActiveWorkshop(station.getCountActiveWorkshop() + 1);
			cout << "Цех включен" << endl;
			return;
		}
		else {
			cout << "Достигнуто максимальное количетсво цехов" << endl;
		}
	}
	else {
		cout << "Повторите попытку" << endl;
		updateStation(station);
	}
	
	
}

void updatePipe(Pipe& pipe) {
	clearMenu();
	if (pipe.getLength() == 0) return;
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
		cout << "Труба\nДлина: " << pipe.getLength() << "\nДиаметр: " << pipe.getDiametr() << "\nВ ремонте: " << (pipe.getInRepair()? "true":"false") << endl;
	if (station.getName() != "" && station.getCountWorkshop() != 0 && station.getCountActiveWorkshop() != 0 && station.getEfficiency() != 0)
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
