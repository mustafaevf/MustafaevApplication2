#include <iostream>
#include <string>

using namespace std;

void PrintMenu() {
	std::cout << "1. Добавить трубу" << std::endl;
	std::cout << "2. Добавить станцию" << std::endl;
	std::cout << "3. Просмотр всех объектов" << std::endl;
	std::cout << "4. Редактировать трубы" << std::endl;
	std::cout << "5. Редактировать станции" << std::endl;
	std::cout << "6. Сохранить" << std::endl;
	std::cout << "7. Загрузить" << std::endl;
	std::cout << "8. Поиск трубы" << std::endl;
	std::cout << "9. Поиск станции" << std::endl;
	std::cout << "10. Удалить трубу" << std::endl;
	std::cout << "11. Удалить станцию" << std::endl;
	std::cout << "0. Выйти" << std::endl;
}


void ClearMenu() {
	system("cls");
}

void clearCin() {
	std::cin.clear();
	std::cin.ignore(123456, '\n');
}


template <typename T>
T getInt(std::string text, T a, T b) {
	
	T value;
	while (1) {
		cout << text;
		cin >> value;
		if (cin.fail() || value < a || value > b) {
			clearCin();
			std::cout << "Попробуйте еще раз" << endl;
		}
		else {
			return value;
		}
	}
	

}

vector<int> searchByFilterPipe(vector<Pipe>& pipes, string name) {
	vector<int> findedPipes;
	for (int i = 0; i < pipes.size(); i++) {
		if (pipes[i].getName() == name) {
			findedPipes.push_back(pipes[i].id);
		}
	}

	return findedPipes;
}

template <typename T>
vector<int> searchByFilterPipe(vector<Pipe>& pipes, T& params) {
	vector<int> findedPipes;
	
	for (int i = 0; i < pipes.size(); i++) {
		if (pipes[i].getInRepair() == params) {
			findedPipes.push_back(pipes[i].id);
		}
	}
	
	return findedPipes;

}

vector<int> searchByFilterStation(vector<Station>& stations, string name) {
	vector<int> findedStations;
	for (int i = 0; i < stations.size(); i++) {
		if (stations[i].getName() == name) {
			findedStations.push_back(stations[i].id);
		}
	}

	return findedStations;
}

vector<int> searchByFilterStation(vector<Station>& stations, double params) {
	vector<int> findedStations;
	
	for (int i = 0; i < stations.size(); i++) {
		if (stations[i].getEfficiency() == params) {
			findedStations.push_back(stations[i].id);
		}
	}
	
	return findedStations;

}