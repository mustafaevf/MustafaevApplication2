#include "Utils.h"


void PrintMenu() {
	std::cout << "1) Добавить трубу" << std::endl
		<< "2) Добавить компрессорную станцию" << std::endl
		<< "3) Показать все объекты" << std::endl
		<< "4) Сохранить в файл" << std::endl
		<< "5) Загрузить из файла" << std::endl
		<< "6) Найти трубу" << std::endl
		<< "7) Найти компрессорную станцию" << std::endl
		<< "8) Удалить трубу" << std::endl
		<< "9) Удалить компрессорную станцию" << std::endl
		<< "10) Очистить консоль" << std::endl
		<< "11) Добавить газотранспортную сеть" << std::endl
		<< "12) Вывести газотранспортную сеть" << std::endl
		<< "13) Топологическая сортировка" << std::endl
		<< "14) Максимальный поток" << std::endl
		<< "15) Минимальный путь между компрессорными станциями" << std::endl
		<< "16) Удалить газотранспортную сеть" << std::endl;
}

std::string getText(std::string message) {
	std::string text;
	std::cout << message;
	std::cin.ignore();
	getline(std::cin, text);
	return text;
}

bool FilterGetByNamePipe(Pipe& pipe, std::string name) {
	std::string ame = pipe.getName();
	if (size_t(ame.find(name)) != std::string::npos)
		return true;
}

bool FilterGetByNameStation(Station& station, std::string name) {
	std::string ame = station.getName();
	std::cout << size_t(ame.find(name));
	if (size_t(ame.find(name)) != std::string::npos)
		return true;
}

bool FilterGetByRepairPipe(Pipe& pipe, bool repair) {
	return pipe.getRepair() == repair;
}

bool FilterGetByEfficiencyStation(Station& station, double efficiency) {
	return station.getEfficiency() == efficiency;
}


bool FilterGetByDiametrPipe(Pipe& pipe, double diametr) {
	return pipe.getDiametr() == diametr;
}