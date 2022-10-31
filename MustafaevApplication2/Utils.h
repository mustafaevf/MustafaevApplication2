#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Pipe.h"
#include "Station.h"

template <typename T>
T getNumber(std::string text, T borderMin, T borderMax) {
	T number;
	while (1) {
		std::cout << text;
		std::cin >> number;
		if (std::cin.fail() || number > borderMax || number < borderMin) {
			std::cout << "Попробуйте еще раз" << std::endl;
			std::cin.clear();
			std::cin.ignore(1234, '\n');
		}
		else {
			return number;
		}
	}
}

template <typename T>
std::vector<int> SearchPipesByFilter(std::map<int, Pipe>& Pipes, int param_search, T parametr)
{
	std::vector<int> result;
	for (auto& pipe : Pipes)
	{
		if (param_search == 1) {
			if (pipe.second.getId() == parametr) {
				result.push_back(pipe.second.getId());
			}
		}
		if (param_search == 2) {
			if (pipe.second.getRepair() == (bool)parametr) {
				result.push_back(pipe.second.getId());
			}
		}
		

	}
	return result;
}


std::vector<int> SearchStationsByFilter(std::map<int, Station>& Stations, std::string parametr) {
	std::vector<int> result;
	for (auto& station : Stations) {
		if (station.second.getName() == parametr) {
			result.push_back(station.second.getId());
		}
	}
	return result;
}

template <typename T>
std::vector<int> SearchStationsByFilter(std::map<int, Station>& Stations, T parametr) {
	std::vector<int> result;
	for (auto& station : Stations) {
		if (station.second.getEfficiency() == parametr)
			result.push_back(station.second.getId());
	}
	return result;
}
