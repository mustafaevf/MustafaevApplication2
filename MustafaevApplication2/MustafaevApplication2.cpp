#include <iostream>
#include <string>
#include <map>
#include "Utils.h"
#include "Station.h"
#include "Pipe.h"

using namespace std;

void PrintMenu() {
	cout << "1) Добавить трубу" << endl;
	cout << "2) Добавить компрессорную станцию" << endl;
	cout << "3) Показать все объекты" << endl;
	cout << "4) Редактировать состояние трубы" << endl;
	cout << "5) Редактировать количество цехов станции" << endl;
	cout << "6) Сохранить в файл" << endl;
	cout << "7) Загрузить из файла" << endl;
	cout << "8) Найти трубу" << endl;
	cout << "9) Найти компрессорную станцию" << endl;
	cout << "10) Удалить трубу" << endl;
	cout << "11) Удалить компрессорную станцию" << endl;
	cout << "12) Очистить консоль" << endl;
}


void EditPipes(map<int, Pipe>& Pipes) {
	cout << "Редактирование" << endl;
	cout << "1) Всех выбранных" << endl;
	int choose;
	choose = getNumber("Выберите вариант поиска для редактирования: ", 1, 1);
	switch (choose) {
	case 1:
		if (Pipes.size() == 0) {
			cout << "Добавте трубы" << endl;
			return;
		}
		while (1) {
			unsigned int x;
			x = getNumber("Введите id трубы для редактирования: ", (unsigned)0, Pipe::IDp);
			if (x == 0) {
				cout << "Выход из редактирования" << endl;
				return;
			}
			Pipes[x].updateRepair();
			cout << "Состояние трубы изменено" << endl;


		}
		break;
	}
}

istream& operator >> ( istream& in, Station& station) {
	station.setId(++Station::IDcs);
	int countWorkshop = getNumber("Введите количество цехов: ", 1, 1000);
	int countActiveWorkshop = getNumber("Введите количетсво рабочих цехов: ", 1, countWorkshop);
	double efficiency = getNumber("Введите эффективность компрессорной станции: ", 0, 100);
	cin.ignore();
	string name;
	cout << "Введите название станции: ";
	getline(cin, name);
	station.setCountWorkshop(countWorkshop);
	station.setCountActiveWorkshop(countActiveWorkshop);
	station.setEfficiency(efficiency);
	station.setName(name);
	return in;
}
istream& operator >> ( istream& in, Pipe& pipe) {
	pipe.setId(++Pipe::IDp);
	double length = getNumber("Введите длинну трубы: ", 1, 1000);
	double diametr = getNumber("Введите диаметр трубы: ", 1, 1000);
	bool repair = getNumber("В ремонте: ", 0, 1);
	pipe.setLength(length);
	pipe.setDiametr(diametr);
	pipe.setRepair(repair);
	return in;
}
ostream& operator << (ostream& out, map<int, Pipe>& Pipes) {
	for (unsigned int i = 1; i <= Pipe::IDp; i++) {
		cout << "Труба(" << Pipes[i].getId() << ")\n" << "Длина: " << Pipes[i].getLength() << "\nДиаметр: " << Pipes[i].getDiametr() << "\n" << (Pipes[i].getRepair() ? "В РЕМОНТЕ":"В РАБОТЕ") << endl;
	}
	return out;
}
ostream& operator << (ostream& out, map<int, Station>& Stations) {
	for (unsigned int i = 1; i <= Station::IDcs; i++) {
		cout << "Труба(" << Stations[i].getId() << ")\n" << "Название компрессорной станции: " << Stations[i].getName() << "\nКоличество цехов: " << Stations[i].getCountWorkshop() << "\nКоличество рабочих цехов: " << Stations[i].getCountActiveWorkshop() << "\nЭффективность компрессорной станции: " << Stations[i].getEfficiency() << endl;
	}
	return out;
}




int main() {
	setlocale(LC_ALL, "Russian");
	PrintMenu();
	std::map<int, Pipe> Pipes;
	std::map<int, Station> Stations;
	while (1) {
		int number;
		number = getNumber("Выберите действие: ", 0, 12);
		switch (number)
		{
		case 0:
			return 0;
			break;
		case 1:
			Pipe pipe;
			cin >> pipe;
			Pipes[Pipe::IDp] = pipe;
			break;
		case 2:
		{
			Station station;
			cin >> station;
			Stations[Station::IDcs] = station;
			break;
		}
		case 3:
			cout << Pipes;
			cout << Stations;
			break;
		case 4:
			EditPipes(Pipes);
			break;
		case 12:
			system("cls");
			PrintMenu();
			break;
		default:
			break;
		}
	}
	return 1;
}
