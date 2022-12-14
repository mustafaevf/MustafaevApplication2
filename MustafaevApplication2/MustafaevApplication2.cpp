#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "Utils.h"
#include "File.h"
#include "GasTransportation.h"

using namespace std;

typedef map<int, Pipe> PipesMap;
typedef map<int, Station> StationsMap;

ostream& operator << (ostream& out, PipesMap& Pipes) {
	for (auto& pipes : Pipes) {
		out << pipes.second << endl;
	}
	return out;
}

ostream& operator << (ostream& out, StationsMap& Stations) {
	for (auto& stations : Stations) {
		out << stations.second << endl;
	}
	return out;
}

template <typename T>
void Delete(map<int, T>& t, int id) {
	t.erase(id);
}


template <typename T>
bool Check(map<int, T>& t) {
	return t.size() != 0;
}


int main() {
	setlocale(LC_ALL, "Russian");
	PrintMenu();
	PipesMap Pipes;
	StationsMap Stations;
	GasTransportation gt;
	while (1) {
		switch (getNumber("Выберите действие: ", 0, 16))
		{
		case 0:
			return 0;
			break;
		case 1:
		{
			Pipe pipe;
			cin >> pipe;
			Pipes.insert(make_pair(Pipe::IDp, pipe));
			break;
		}
		case 2:
		{
			Station station;
			cin >> station;
			Stations.insert(make_pair(Station::IDcs, station));
			break;
		}
		case 3:
			if (!Check(Pipes))
				cout << "Трубы не найдены" << endl;
			cout << Pipes;
			if (!Check(Stations))
				cout << "Станции не найдены" << endl;
			cout << Stations;
			break;
		case 4:
		{
			switch (getNumber("Выберите пункт сохранения : \n1) Сохранить трубы и станции\n2) Сохранить гтс\n: ", 1, 2)) {
			case 1:
			{
				ofstream fout = OpenFout(getText("Ввведите названме файла: "));
				if (Check(Pipes))
					SaveToFile(fout, Pipes);
				else cout << "Трубы не найдены" << endl;
				if (Check(Stations))
					SaveToFile(fout, Stations);
				else cout << "Станции не найдены" << endl;
				FoutClose(fout);
				break;
			}
			case 2:
			{
				if (gt.getIdPipes().size() == 0)
					break;
				if (gt.getIdStations().size() == 0)
					break;
				ofstream fout1;
				fout1.open("gt.txt");
				fout1 << gt.getIdStations().size() << endl;
				fout1 << gt.getIdPipes().size() << endl;
				gt.Save(fout1);
				break;
			}

			}
			break;
		}
		case 5:
		{
			switch (getNumber("Выберите пункт загрузки : \n1) Загрузить трубы и станции\n2) Загрузить гтс\n: ", 1, 2)) {
			case 1:
			{
				int countStation, countPipe;
				ifstream fin = OpenFin(getText("Введите название файла: "));
				fin >> countPipe;
				if (countPipe > 0) {
					Pipe::IDp = 0;
					Pipes.clear();
					for (int i = 0; i < countPipe; i++) {
						Pipe pipe;
						pipe.Load(fin);
						Pipes.insert(make_pair(Pipe::IDp, pipe));
					}
				}
				fin >> countStation;
				if (countStation > 0) {
					Station::IDcs = 0;
					Stations.clear();
					for (int i = 0; i < countStation; i++) {
						Station station;
						station.Load(fin);
						Stations.insert(make_pair(Station::IDcs, station));
					}
			
					
				}
				break;
			}
			case 2:
			{
				ifstream fin1;
				fin1.open("gt.txt");
				if (fin1.is_open()) {
					int count1;
					int count2;
					fin1 >> count1;
					fin1 >> count2;
					if (count1 > 0) {
						for (int i = 0; i < count1; i++) {
							gt.Load(fin1, "s");
						}
					}
					if (count2 > 0) {
						for (int i = 0; i < count2; i++) {
							gt.Load(fin1, "p");
						}
					}
				}

				break;
			}
			}
			break;
		}
		case 6:
		{
			if (!Check(Pipes)) {
				cout << "Трубы не найдены" << endl;
				break;
			}
			vector<int> finded;
			switch (getNumber("1) Поиск по названию\n2) Поиск по статусу\n0) Выход\nВыберите: ", 0, 2))
			{
			case 0:
				break;
			case 1:
			{
				finded = SearchByFilterPipe(Pipes, FilterGetByNamePipe, getText("Введите название трубы: "));
				break;
			}
			case 2:
			{
				finded = SearchByFilterPipe(Pipes, FilterGetByRepairPipe, (bool)getNumber("Ввведите параметр для поиска: ", 0, 1));
				break;
			}
			}
			if (finded.size() == 0) {
				cout << "Трубы не найдены" << endl;
				break;
			}
			for (auto& i : finded)
				cout << endl << Pipes[i] << endl;

			switch (getNumber("1) Удалить\n2) Редактировать\n0) Выйти\nВведите: ", 0, 2)) {
			case 1:
				for (auto& i : finded) {
					cout << Pipes[i] << endl;
					int action = getNumber("1) Удалмть\n2) Пропустить\n- ", 1, 2);
					if (action == 1)
						if (Pipes[i].getInputStation() != 0 || Pipes[i].getOutputStation() != 0)
						{
							cout << "Удалите трубу из газотранспортной сети" << endl;
							break;
						}
						Delete(Pipes, i);
				}
				break;

			case 2:
				for (auto& i : finded) {
					cout << Pipes[i] << endl;
					Pipes[i].Edit();
				}
				break;
			}
			break;
		}
		case 7:
		{
			if (!Check(Stations)) {
				cout << "Станции не найдены" << endl;
				break;
			}
			vector<int> finded;
			switch (getNumber("1) Поиск по названию\n2) Поиск по эффективности\n0) Выход\nВыберите: ", 0, 2))
			{
			case 0:
				break;
			case 1:
			{
				finded = SearchByFilterStation(Stations, FilterGetByNameStation, getText("Введите название станции: "));
				break;
			}
			case 2:
			{
				finded = SearchByFilterStation(Stations, FilterGetByEfficiencyStation, (double)getNumber("Ввведите параметр для поиска: ", 1, 100));
				break;
			}
			}
			if (finded.size() == 0) {
				cout << "Станции не найдены" << endl;
				break;
			}
			for (auto& i : finded)
				cout << endl << Stations[i] << endl;

			switch (getNumber("1) Удалить\n2) Редактировать\n0) Выйти\nВведите: ", 0, 2)) {
			case 1:
				for (auto& i : finded) {
					cout << Stations[i] << endl;
					int action = getNumber("1) Удалить\n2) Пропустить\n- ", 1, 2);
					if (action == 1)
						Delete(Stations, i);
				}
				break;

			case 2:
				for (auto& i : finded) {
					cout << Stations[i] << endl;
					int action = getNumber("1) Редактировать\n2) Пропустить\n- ", 1, 2);
					if (action == 1)
						Stations[i].setCountActiveWorkshop(getNumber("Введите количество рабочих цехов: ", 0, Stations[i].getCountWorkshop()));
				}
				break;
			}
			break;
		}
		case 8:
		{
			if (Check(Pipes)) Delete(Pipes, getNumber("Введите id трубы: ", 1, Pipe::IDp));
			break;
		}
		case 9:
		{
			if (Check(Stations)) Delete(Stations, getNumber("Введите id станции: ", 1, Station::IDcs));
			break;
		}
		case 10:
			system("cls");
			PrintMenu();
			break;
		case 11:
			if (Check(Stations))
				gt.Create(Pipes);
			break;
		case 12:
		{
			for (auto& pipe : Pipes) 
				if (pipe.second.getOutputStation() != 0)
					cout << "Станция " << pipe.second.getInputStation() << " - Труба(id" << pipe.second.getId() << ") - Станция " << pipe.second.getOutputStation() << endl;
			break;
		}
		case 13:
			{
				vector<int> sorted;
				sorted = gt.TopologicalSort(Pipes);
				if (sorted.size() == 0) {
					cout << "Цикл" << endl;
					break;
				}
				int k = 1;
				for (auto& i : sorted)
				{
					cout << "Вершина №" << k << " (id " << i << ")" << endl;
					k++;
				}
				break;
			}
		case 14:
		{
			cout << "Максимальный поток: " << gt.MaximumFlow(Pipes, Stations) << endl;
			break;
		}

		case 15:
		{
			cout << "Минимальный путь: " << gt.MinimumPath(Pipes, Stations) << endl;
			break;
		}
		case 16:
		{
			gt.Delete(Pipes);
			break;
		}


		}
	}
}
