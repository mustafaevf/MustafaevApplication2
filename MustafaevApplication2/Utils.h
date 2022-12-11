#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <string>
#include "Pipe.h"
#include "Station.h"


void PrintMenu();
bool FilterGetByNamePipe(Pipe& pipe, std::string name);
bool FilterGetByNameStation(Station& station, std::string name);
bool FilterGetByDiametrPipe(Pipe& pipe, double diametr);
bool FilterGetByRepairPipe(Pipe& pipe, bool repair);

bool FilterGetByEfficiencyStation(Station& station, double efficiency);
std::string getText(std::string message);


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
using FilterPipe = bool(*)(Pipe& t, T parametr);
template <typename T>
std::vector<int> SearchByFilterPipe(std::map<int, Pipe>& t, FilterPipe<T> f, T parametr)
{
	std::vector<int> result;
	for (auto& o : t)
	{
		if (f(o.second, parametr))
		{
			result.push_back(o.second.getId());
		}
	}
	return result;
}

template <typename T>
using FilterStation = bool(*)(Station& t, T parametr);
template <typename T>
std::vector<int> SearchByFilterStation(std::map<int, Station>& t, FilterStation<T> f, T parametr)
{
	std::vector<int> result;
	for (auto& o : t)
	{
		if (f(o.second, parametr))
		{
			result.push_back(o.second.getId());
		}
	}
	return result;
}

