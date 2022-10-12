#include <iostream>
#include <string>

using namespace std;

void PrintMenu() {
	std::cout << "1. �������� �����" << std::endl;
	std::cout << "2. �������� �������" << std::endl;
	std::cout << "3. �������� ���� ��������" << std::endl;
	std::cout << "4. ������������� �����" << std::endl;
	std::cout << "5. ������������� �������" << std::endl;
	std::cout << "6. ���������" << std::endl;
	std::cout << "7. ���������" << std::endl;
	std::cout << "8. ����� �����" << std::endl;
	std::cout << "9. ����� �������" << std::endl;
	std::cout << "10. ������� �����" << std::endl;
	std::cout << "11. ������� �������" << std::endl;
	std::cout << "0. �����" << std::endl;
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
			std::cout << "���������� ��� ���" << endl;
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