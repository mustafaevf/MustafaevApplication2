#include <iostream>
#include <map>
#include "Utils.h"
#include "GasTransportation.h"

void GasTransportation::Create(std::map<int, Pipe>& Pipes)
{
	int id1, id2;
	while (true) {
		id1 = getNumber("Введите id первой станции: ", 1, Station::IDcs);
		id2 = getNumber("Введите id второй станции: ", 1, Station::IDcs);
		if (id1 != id2)
			break;
		if (id1 == 0 || id2 == 0)
			break;
	}
	if(std::find(IdStations.begin(), IdStations.end(), id1) == IdStations.end())
		IdStations.push_back(id1);

	if (std::find(IdStations.begin(), IdStations.end(), id2) == IdStations.end())
		IdStations.push_back(id2);
	
	/*std::vector<int> finded;*/
	/*Pipe pipe;
	std::cin >> pipe;
	pipe.setInputStation(id1);
	pipe.setOutputStation(id2);
	Pipes.insert(std::make_pair(Pipe::IDp, pipe));
	if (std::find(IdPipes.begin(), IdPipes.end(), pipe.getId()) == IdPipes.end())
		IdPipes.push_back(pipe.getId());*/

	std::vector<int> finded;
	while (true) {
		switch (getNumber("Выберите диаметр трубы\n1) 500\n2) 700\n3) 1400\nВыберите: ", 1, 3)) {
			case 1:
				finded = SearchByFilterPipe(Pipes, FilterGetByDiametrPipe, (double)500);
				break;
			case 2:
				finded = SearchByFilterPipe(Pipes, FilterGetByDiametrPipe, (double)700);
				break;

			case 3:
				finded = SearchByFilterPipe(Pipes, FilterGetByDiametrPipe, (double)1400);
				break;
		}
		int k = 0;
		if (finded.size() == 0) {
			Pipe pipe;
			std::cin >> pipe;
			pipe.setInputStation(id1);
			pipe.setOutputStation(id2);
			Pipes.insert(std::make_pair(Pipe::IDp, pipe));
			if (std::find(IdPipes.begin(), IdPipes.end(), pipe.getId()) == IdPipes.end())
				IdPipes.push_back(pipe.getId());
			break;
		}
		else {
			
			for (int i = 0; i < finded.size(); i++) {
				if (Pipes[finded[i]].getInputStation() == 0 && Pipes[finded[i]].getOutputStation() == 0) {
					std::cout << "Труба найдена" << std::endl;
					Pipes[finded[i]].setInputStation(id1);
					Pipes[finded[i]].setOutputStation(id2);
					k++;
					if (std::find(IdPipes.begin(), IdPipes.end(), Pipes[finded[i]].getId()) == IdPipes.end())
						IdPipes.push_back(Pipes[finded[i]].getId());
					break;
				}
			}
		}
		if (k == 0) {
			Pipe pipe;
			std::cin >> pipe;
			pipe.setInputStation(id1);
			pipe.setOutputStation(id2);
			Pipes.insert(std::make_pair(Pipe::IDp, pipe));
			if (std::find(IdPipes.begin(), IdPipes.end(), pipe.getId()) == IdPipes.end())
				IdPipes.push_back(pipe.getId());
			break;
		}
	}

	/*while (true) {
	* 
		switch (getNumber("Выберите диаметр трубы\n1) 500 мм\n2) 700 мм\n3) 1400 мм\nВыберите: ", 1, 3)) {

		case 1:
			finded = SearchByFilterPipe(Pipes, FilterGetByDiametrPipe, (double)500);
			break;
		case 2:
			finded = SearchByFilterPipe(Pipes, FilterGetByDiametrPipe, (double)700);
			break;

		case 3:
			finded = SearchByFilterPipe(Pipes, FilterGetByDiametrPipe, (double)1400);
			break;
		}
		break;
	}
	if (finded.size() > 0) {
		for (int i = 0; i < finded.size(); i++) {
			if (Pipes[finded[i]].getInputStation() == 0 && Pipes[finded[i]].getOutputStation() == 0) {
				Pipes[finded[i]].setInputStation(id1);
				Pipes[finded[i]].setOutputStation(id2);
				IdPipes.push_back(finded[i]);
				break;
			}
		}
	}*/
	finded.clear();
	std::cout << "Газотранспортная сеть создана" << std::endl;
	
}



void GasTransportation::Save(std::ofstream& fout)
{
	for (int i = 0; i < IdStations.size(); i++) {
		fout << IdStations[i] << std::endl;
	}
	for (int i = 0; i < IdPipes.size(); i++) {
		fout << IdPipes[i] << std::endl;
	}
}

std::vector<int> GasTransportation::getIdPipes()
{
	return IdPipes;
}

std::vector<int> GasTransportation::getIdStations()
{
	return IdStations;
}

void GasTransportation::Load(std::ifstream& fin, std::string name)
{
	int value;
	fin >> value;
	if (name == "p")
		IdPipes.push_back(value);
	if (name == "s")
		IdStations.push_back(value);
}

void GasTransportation::CreateMatrixForMinimumPath(std::map<int, Pipe>& Pipes) 
{
	matrix.resize(IdStations.size());
	for (int i = 0; i < IdStations.size(); i++) {
		matrix[i].resize(IdStations.size());
	}
	for (auto& pipe : Pipes) {
		int first = -1;
		int second = -1;
		for (int i = 0; i < IdStations.size(); i++) {
			if (pipe.second.getInputStation() == IdStations[i])
				first = i;
		}
		for (int i = 0; i < IdStations.size(); i++) {
			if (pipe.second.getOutputStation() == IdStations[i])
				second = i;
		}
		if (first > -1 && second > -1 && pipe.second.getRepair() != 1)
			matrix[first][second] = pipe.second.getLength();
	}
	/*for (int i = 0; i < IdStations.size(); i++)
	{
		for (int j = 0; j < IdStations.size(); j++)
		{
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}*/
}

void GasTransportation::CreateMatrixForMaximumFlow(std::map<int, Pipe>& Pipes)
{
	matrix.resize(IdStations.size());
	for (int i = 0; i < IdStations.size(); i++) {
		matrix[i].resize(IdStations.size());
	}
	for (auto& pipe : Pipes)
	{
		int first = -1;
		int second = -1;
		for (int i = 0; i < IdStations.size(); i++)
		{
			if (pipe.second.getInputStation() == IdStations[i])
				first = i;
		}
		for (int i = 0; i < IdStations.size(); i++)
		{
			if (pipe.second.getOutputStation() == IdStations[i])
				second = i;
		}
		if (first > -1 && second > -1 && pipe.second.getRepair() != 1)
			matrix[first][second] = pipe.second.getEfficiency();
	}
	/*for (int i = 0; i < IdStations.size(); i++)
	{
		for (int j = 0; j < IdStations.size(); j++)
		{
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}*/
}


void GasTransportation::CreateMatrixForTopologicalSort(std::map<int, Pipe>& Pipes)
{
	matrix.resize(IdStations.size());
	for (int i = 0; i < IdStations.size(); i++) {
		matrix[i].resize(IdStations.size());
	}
	for (auto& pipe : Pipes) {
		int first = -1;
		int second = -1;
		for (int i = 0; i < IdStations.size(); i++) {
			if (pipe.second.getInputStation() == IdStations[i])
				first = i;
		}
		for (int i = 0; i < IdStations.size(); i++) {
			if (pipe.second.getOutputStation() == IdStations[i])
				second = i;
		}
		if (first != -1 && second != -1)
			matrix[first][second] = 1;
	}
}


int findindex(std::vector<int> v, int value) {
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == value)
			return i;
	}
	return -1;
}


std::vector<int> GasTransportation::TopologicalSort(std::map<int, Pipe>& Pipes)
{
	std::vector<int> sorted;
	CreateMatrixForTopologicalSort(Pipes);
	for (int k = 0; k < IdStations.size(); k++) {
		for (int i = 0; i < IdStations.size(); i++) {
			int sum = 0;
			for (int j = 0; j < IdStations.size(); j++) {
				sum += matrix[i][j];
			}
			if (sum == 0) {
				sorted.push_back(IdStations[i]);
				for (int j = 0; j < IdStations.size(); j++) {
					matrix[j][i] = 0;
				}
				matrix[i][i] = 1;
			}
		}
	}
	matrix.clear();
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].clear();
	}
	
	reverse(sorted.begin(), sorted.end());
	return sorted;
}

double GasTransportation::MinimumPath(std::map<int, Pipe>& Pipes, std::map<int,Station>& Stations) 
{
	
	int id1 = getNumber("Введите id первой компрeссорной станции: ", 0, Station::IDcs);
	int id2 = getNumber("Введите id второй компрессорной станции: ", 0, Station::IDcs);

	if (id1 == id2) {
		std::cout << "Ошибка ввода" << std::endl;
		return -1;
	}
	
	for (auto& i : IdStations) {
		Stations[i].weight = INFINITY;
	}
	Stations[id1].weight = 0;
	//Stations[id2].weight = INFINITY;
	//Stations[id2].weight = INFINITY;

	
	CreateMatrixForMinimumPath(Pipes);
	std::vector<int> queue;
	queue.push_back(id1);
	int iterator = findindex(IdStations, id1);
	while (true)
	{
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[iterator][i] != 0)
			{
				if (Stations[IdStations[i]].weight >= (matrix[iterator][i] + Stations[queue[0]].weight))
				{
					Stations[IdStations[i]].weight = matrix[iterator][i] + Stations[queue[0]].weight;
					bool f = false;
					for (auto& k : queue)
					{
						if (k == IdStations[i])
							f = true;
					}
					if (f == false)
						queue.push_back(IdStations[i]);
				}
			}
		}
		queue.erase(queue.begin());
		if (queue.size() == 0)
			return Stations[id2].weight;
		double min = INFINITY;
		int id = 0;
		for (auto& i : queue)
		{
			if (min > Stations[i].weight)
			{
				min = Stations[i].weight;
				id = findindex(queue, i);
			}
		}
		std::swap(queue[0], queue[id]);
		iterator = findindex(IdStations, queue[0]);
	}

	matrix.clear();
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].clear();
	}

}

double GasTransportation::MaximumFlow(std::map<int, Pipe>& Pipes, std::map<int, Station>& Stations)
{
	int id1 = getNumber("Введите id первой компрeссорной станции: ", 0, Station::IDcs);
	int id2 = getNumber("Введите id второй компрессорной станции: ", 0, Station::IDcs);

	if (id1 == id2) {
		std::cout << "Ошибка ввода" << std::endl;
		return -1;
	}


	if (findindex(IdStations, id1) == -1 && findindex(IdStations, id2) == -1)
		return -1;

	Stations[id1].weight = INFINITY;
	Stations[id2].weight = 0;

	CreateMatrixForMaximumFlow(Pipes);

	float F = 0;
	while (true)
	{
		std::vector<int> queue;
		queue.push_back(id1);
		int count = 0;
		int iterator = findindex(IdStations, id1);
		Stations[id1].weight = INFINITY;
		while (Stations[id2].weight == 0)
		{
			for (int i = 0; i < matrix.size(); i++)
			{
				if (matrix[iterator][i] != 0)
				{
					if (Stations[queue[0]].weight >= matrix[iterator][i])
					{
						Stations[IdStations[i]].weight = matrix[iterator][i];
						Stations[IdStations[i]].last = IdStations[iterator];
						queue.push_back(IdStations[i]);
					}
					else
					{
						Stations[IdStations[i]].weight = Stations[queue[0]].weight;
						Stations[IdStations[i]].last = IdStations[iterator];
						queue.push_back(IdStations[i]);
					}
				}
			}
			queue.erase(queue.begin());
			if (queue.size() == 0)
				return F;
			iterator = findindex(IdStations, queue[0]);
			count++;
		}
		int s = Stations[id2].weight;
		int iter = id2;
		int index1 = findindex(IdStations, Stations[id2].last);
		int index2 = findindex(IdStations, id2);
		for (int i = 0; i < count; i++)
		{
			matrix[index1][index2] -= s;
			if (matrix[index1][index2] == s)
				matrix[index1][index2] = 0;
			int pr = index1;
			index2 = index1;
			index1 = findindex(IdStations, Stations[IdStations[pr]].last);
			if (index1 < 0)
				break;
			iter = Stations[iter].last;
		}
		for (auto& i : IdStations)
		{
			Stations[i].weight = 0;
		}
		F += s;
	}

	matrix.clear();
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].clear();
	}

	return F;
}

void GasTransportation::Delete(std::map<int, Pipe>& Pipes)
{
	matrix.clear();

	for (int i = 0; i < matrix.size(); i++)
		matrix[i].clear();

	IdStations.clear();

	for (auto& p : IdPipes) {
		Pipes[p].setInputStation(0);
		Pipes[p].setOutputStation(0);
	}
	IdPipes.clear();

	std::cout << "Сети удалены" << std::endl;
}
