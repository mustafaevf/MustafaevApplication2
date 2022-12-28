#include "Utils.h"


void PrintMenu() {
	std::cout  << "1. добавить трубу" << std::endl
		<< "2. добавить компрессорную станцию" << std::endl
		<< "3. вывести все объекты" << std::endl
		<< "4. сохранить объекты и газотранспортную сеть в файл" << std::endl
		<< "5. загрузить объекты и газотранспортную сеть из файла" << std::endl
		<< "6. найти трубу" << std::endl
		<< "7. найти компрессорную станцию" << std::endl
		<< "8. очистить консоль" << std::endl
		<< "9. создать газотранспортную сеть" << std::endl
		<< "10. вывод газотранспортной сети" << std::endl
		<< "11. топологическая сортировка газотранспортной сети" << std::endl
		<< "12. максимальный поток" << std::endl
		<< "13. миинимальный путь между компрессорными станциями" << std::endl
		<< "14. удалить газотранспортную сеть" << std::endl << std::endl;
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