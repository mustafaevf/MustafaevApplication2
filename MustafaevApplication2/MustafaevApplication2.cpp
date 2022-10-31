#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "Utils.h"

using namespace std;

typedef map<int, Pipe> PipesMap;
typedef map<int, Station> StationsMap;

void SaveToFile(PipesMap& Pipes, StationsMap& Stations, string __name) {
	ofstream fout;
	fout.open(__name + ".txt");
	if (Pipes.size() != 0) {
		fout << Pipes.size() << endl;
		for (auto& pipes : Pipes) {
			pipes.second.Save(fout);
		}
	}
	else {
		cout << "Трубы не найдены" << endl;
	}
	if (Stations.size() != 0) {
		fout << Stations.size() << endl;
		for (auto& stations : Stations) {
			stations.second.Save(fout);
		}
	}
	else {
		cout << "Станции не найдены" << endl;
	}

}

void ImportFromFile(PipesMap& Pipes, StationsMap& Stations, string __name) {
	ifstream fin;
	fin.open(__name + ".txt");
	if (fin.is_open()) {
		int countPipes;
		int countCS;
		fin >> countPipes;
		if (countPipes > 0) {
			for (int i = 0; i < countPipes; i++)
			{
				Pipe pipe;
				pipe.Load(fin);
				pipe.setId(++Pipe::IDp);
				Pipes[Pipe::IDp] = pipe;
			}
			fin >> countCS;
			if (countCS > 0) {
				for (int i = 0; i < countCS; i++)
				{
					Station station;
					station.Load(fin);
					station.setId(++Station::IDcs);
					Stations[Station::IDcs] = station;
				}
			}
			else {
				cout << "Станции не найдены" << endl;
			}
		}
		else {
			cout << "Трубы не найдены" << endl;
		}
	}
	else {
		cout << "Ошибка открытия файла" << endl;
	}

}


void PrintMenu() {
	cout << "1) Добавить трубу" << endl
		<< "2) Добавить компрессорную станцию" << endl
		<< "3) Показать все объекты" << endl
		<< "4) Редактировать состояние трубы" << endl
		<< "5) Редактировать количество цехов станции" << endl
		<< "6) Сохранить в файл" << endl
		<< "7) Загрузить из файла" << endl
		<< "8) Найти трубу" << endl
		<< "9) Найти компрессорную станцию" << endl
		<< "10) Удалить трубу" << endl
		<< "11) Удалить компрессорную станцию" << endl
		<< "12) Очистить консоль" << endl;
}

void DeletePipe(PipesMap& Pipes, int id) {
	Pipes.erase(id);

}

void DeleteStation(StationsMap& Stations, int id) {
	Stations.erase(id);
}


vector<int> SelectPipesByFilter(map<int, Pipe>& Pipes) {
	cout << "Поиск по фильтру" << endl;
	cout << "1) По id" << endl;
	cout << "2) По признаку" << endl;
	vector<int> search;
	int choose = getNumber("Выберите вариант поиска: ", 1, 2);
	if (choose == 2) {
		int param = getNumber("Введите параметр для поиска: ", 0, 1);
		search = SearchPipesByFilter(Pipes, choose, param);
	}
	if (choose == 1) {
		int param = getNumber("Введите параметр для поиска: ", 0, Pipe::IDp);
		search = SearchPipesByFilter(Pipes, choose, param);
	}
	return search;
}

vector<int> SelectStationsByFilter(StationsMap& Stations) {
	cout << "Поиск по фильтру" << endl;
	cout << "1) По названию" << endl;
	cout << "2) По проценту" << endl;
	vector<int> search;
	int choose = getNumber("Выберите вариант поиска: ", 1, 2);
	if (choose == 2) {
		double param = getNumber("Введите параметр для поиска: ", 0, 100);
		search = SearchStationsByFilter(Stations, param);
	}
	if (choose == 1) {
		string param;
		cout << "Введите название станции: ";
		cin.ignore();
		getline(cin, param);
		search = SearchStationsByFilter(Stations, param);
	}
	return search;
}


void EditPipes(PipesMap& Pipes) {
	cout << "Редактирование" << endl;
	cout << "1) Всех выбранных" << endl;
	cout << "2) Всех труб" << endl;
	int choose;
	choose = getNumber("Выберите вариант поиска для редактирования: ", 1, 2);
	switch (choose) {
	case 1:
		if (Pipes.size() == 0) {
			cout << "У вас нет труб" << endl;
			return;
		}
		while (1) {
			int x;
			x = getNumber("Введите id трубы для редактирования: ", 0, Pipe::IDp);
			if (x == 0) {
				cout << "Выход из редактирования" << endl;
				return;
			}
			Pipes[x].updateRepair();
			cout << "Состояние трубы изменено" << endl;
		}
		break;
	case 2:
		if (Pipes.size() == 0) {
			cout << "У вас нет труб" << endl;
			return;
		}
		for (auto& pipes : Pipes) {
			pipes.second.updateRepair();
		}
		cout << "Состояние труб изменено" << endl;
		break;
	}
}

void EditStations(StationsMap& Stations) {
	cout << "Редактирование" << endl;
	cout << "1) Выбор станции по id" << endl;
	int choose = getNumber("Выберите вариант: ", 1, 1);
	if (choose == 1) {
		int choose_id = getNumber("Введите id станции: ", 1, Station::IDcs);
		cout << "Станция" << choose_id << "\nКоличество цехов: " << Stations[choose_id].getCountWorkshop() << "\nКоличество рабочих цехов: " << Stations[choose_id].getCountActiveWorkshop() << endl;
		int editWorkshop = getNumber("Введите: ", 0, Stations[choose_id].getCountWorkshop());
		Stations[choose_id].setCountActiveWorkshop(editWorkshop);
		cout << "Успешно" << endl;
	}
}


istream& operator >> (istream& in, Station& station) {
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
istream& operator >> (istream& in, Pipe& pipe) {
	pipe.setId(++Pipe::IDp);
	string name;
	in.ignore();
	cout << "Введите название трубы: ";
	getline(in, name);
	double length = getNumber("Введите длинну трубы: ", 1, 1000);
	double diametr = getNumber("Введите диаметр трубы: ", 1, 1000);
	bool repair = getNumber("В ремонте: ", 0, 1);
	pipe.setLength(length);
	pipe.setDiametr(diametr);
	pipe.setRepair(repair);
	pipe.setName(name);
	return in;
}
ostream& operator << (ostream& out, map<int, Pipe>& Pipes) {
	for (auto& pipes : Pipes) {
		out << "Труба (" << pipes.second.getId() << ")" << endl;
		out << "Название: " << pipes.second.getName() << endl;
		out << "Длина: " << pipes.second.getLength() << endl;
		out << "Диаметр: " << pipes.second.getDiametr() << endl;
		out << (pipes.second.getRepair() ? "В РЕМОНТЕ" : "В РАБОТЕ") << endl;
	}
	return out;
}
ostream& operator << (ostream& out, map<int, Station>& Stations) {
	for (auto& stations : Stations) {
		out << "Станция (" << stations.second.getId() << ")" << endl;
		out << "Название: " << stations.second.getName() << endl;
		out << "Количество цехов: " << stations.second.getCountWorkshop() << endl;
		out << "Количетсво рабочих цехов: " << stations.second.getCountActiveWorkshop() << endl;
		out << "Эффективность: " << stations.second.getEfficiency() << endl;
	}
	return out;
}




int main() {
	setlocale(LC_ALL, "Russian");
	PrintMenu();
	PipesMap Pipes;
	StationsMap Stations;
	while (1) {
		int number;
		number = getNumber("Выберите действие: ", 0, 12);
		switch (number)
		{
		case 0:
			return 0;
			break;
		case 1:
		{
			Pipe pipe;
			cin >> pipe;
			Pipes[Pipe::IDp] = pipe;
			break;
		}
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
		case 5:
			EditStations(Stations);
			break;
		case 6:
		{
			string name;
			cout << "Введите название файла: ";
			cin >> name;
			SaveToFile(Pipes, Stations, name);
			break;
		}
		case 7:
		{
			string name;
			cout << "Введите название файла: ";
			cin >> name;
			ImportFromFile(Pipes, Stations, name);
			break;
		}
		case 8:
		{
			vector<int> finded;
			finded = SelectPipesByFilter(Pipes);
			for (int i = 0; i < finded.size(); i++) {
				cout << "Труба (" << finded[i] << ")" << "\nДлина трубы: " << Pipes[finded[i]].getLength() << "\nДиаметр трубы: " << Pipes[finded[i]].getDiametr() << "\n" << (Pipes[finded[i]].getRepair() ? "В РЕМОНТЕ" : "В РАБОТЕ") << endl;
			}
			if (finded.size() == 0) {
				cout << "Трубы не найдены" << endl;
				break;
			}
			int choose = getNumber("0.Выход\n1.Редактировать\n2.Удалить\nВыберите действие: ", 0, 2);
			if (choose == 0) {
				break;
			}
			if (choose == 1) {
				for (auto& find : finded) {
					Pipes[find].updateRepair();
				}
				cout << "Состояние трубы изенено" << endl;
			}
			if (choose == 2) {
				for (auto& find : finded) {
					DeletePipe(Pipes, find);
				}
				cout << "Трубы удалены" << endl;
			}

			break;
		}
		case 9:
		{
			vector<int> finded;
			finded = SelectStationsByFilter(Stations);
			for (int i = 0; i < finded.size(); i++) {
				cout << "Станция(" << finded[i] << ")\n" << "Название компрессорной станции: " << Stations[finded[i]].getName() << "\nКоличество цехов: " << Stations[finded[i]].getCountWorkshop() << "\nКоличество рабочих цехов: " << Stations[finded[i]].getCountActiveWorkshop() << "\nЭффективность компрессорной станции: " << Stations[finded[i]].getEfficiency() << endl;
			}
			if (finded.size() == 0) {
				cout << "Станции не найдены" << endl;
				break;
			}
			int choose = getNumber("0.Выход\n1.Редактировать\n2.Удалить\nВыберите действие: ", 0, 2);
			if (choose == 0) {
				break;
			}
			if (choose == 1) {
				for (auto& find : finded) {
					int editWorkshop = getNumber("Введите количество для включения: ", 0, Stations[find].getCountWorkshop());
					Stations[find].setCountActiveWorkshop(editWorkshop);
				}
				cout << "Станции отредактированы" << endl;
			}
			if (choose == 2) {
				for (auto& find : finded) {
					DeleteStation(Stations, find);
				}
				cout << "Станции удалены" << endl;
			}

			break;
		}
		case 10:
		{
			int pipe_id = getNumber("Введите id трубы: ", 1, Pipe::IDp);
			DeletePipe(Pipes, pipe_id);
			break;
		}
		case 11:
		{
			int station_id = getNumber("Введите id станции: ", 1, Station::IDcs);
			DeleteStation(Stations, station_id);
			break;
		}
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
