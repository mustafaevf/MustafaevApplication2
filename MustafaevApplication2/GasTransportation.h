#pragma once
#include <vector>
#include <fstream>
#include <set>
#include "Pipe.h"
#include "Station.h"


class GasTransportation {
private:
	std::vector<std::vector<int>> matrix;
	std::vector<int> IdPipes;
	std::vector<int> IdStations;
public:
	void Create(std::map<int, Pipe>& Pipes);
	void Save(std::ofstream& fout);
	std::vector<int> getIdPipes();
	std::vector<int> getIdStations();
	void Load(std::ifstream& fin, std::string name);
	void CreateMatrixForTopologicalSort(std::map<int, Pipe>& Pipes);
	void CreateMatrixForMinimumPath(std::map<int, Pipe>& Pipes);
	void CreateMatrixForMaximumFlow(std::map<int, Pipe>& Pipes);
	double MinimumPath(std::map<int, Pipe>& Pipes, std::map<int, Station>& Stations);
	double MaximumFlow(std::map<int, Pipe>& Pipes, std::map<int, Station>& Stations);
	void Delete(std::map<int, Pipe>& Pipes);
	std::vector<int> TopologicalSort(std::map<int, Pipe>& Pipes);
};