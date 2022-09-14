#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int loop = 1;

struct Pipe {
	float lengthPipe;
	float diametrPipe;
	bool inRepair;

	bool valid() {
		if (lengthPipe > 0 && diametrPipe > 0 && (inRepair == 1 || inRepair == 0)) {
			return true;
		}
		else {
			return false;
		}
	}
};

struct Station {
	string name;
	int countWorkshop;
	int countActiveWorkshop;
	float property;

	bool valid() {
		if (!name.empty() && (countWorkshop - countActiveWorkshop) >= 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

Pipe newPipe;

Station newStation;


void inline clearMenu() {
	system("cls");
}

bool validateInput() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(312312, '\n');
		return true;
	}
	else {
		return false;
	}
}

void printMenu() {
	cout << "1. Добавить трубу" << endl;
	cout << "2. Добавить КС" << endl;
	cout << "3. Просмотр всех объектов" << endl;
	cout << "4. Редактировать трубу" << endl;
	cout << "5. Редактировать КС" << endl;
	cout << "6. Сохранить" << endl;
	cout << "7. Загрузить" << endl;
	cout << "0. Выйти" << endl;
}

void editPipe() {
	clearMenu();
	if (newPipe.valid()) {
		cout << "| Редактирование трубы |" << endl;
		cout << " Длина трубы: " << newPipe.lengthPipe << endl;
		cout << " Диаметр трубы: " << newPipe.diametrPipe << endl;
		cout << " В ремонте: " << newPipe.inRepair << endl;
		cout << "Введите длину трубы: ";
		cin >> newPipe.lengthPipe;
		cout << "Введите диаметр трубы: ";
		cin >> newPipe.diametrPipe;
		cout << "В ремонте: ";
		cin >> newPipe.inRepair;
		if (validateInput()) editPipe();
		if (newPipe.valid()) {
			clearMenu();
			cout << "Успешно" << endl;
		}
		else {
			cout << "Ошибка" << endl;
		}
	}
	else {
		cout << "Трубы не существует" << endl;
	}
	printMenu();
	loop = 1;
}

void editStation() {
	clearMenu();
	if (newStation.valid()) {
		cout << "| Редактирование КС |" << endl;
		cout << " Название кс: " << newStation.name << endl;
		cout << " Цехов: " << newStation.countWorkshop << endl;
		cout << " Рабочих цехов: " << newStation.countActiveWorkshop << endl;
		cout << " Показатель эффективности: " << newStation.property << endl;
		cout << "Введите название: ";
		cin >> newStation.name;
		cout << "Введите количество цехов: ";
		cin >> newStation.countWorkshop;
		cout << "Введите количество рабочих цехов: ";
		cin >> newStation.countActiveWorkshop;
		cout << "Введите показатель: ";
		cin >> newStation.property;
		if (newStation.valid()) {
			clearMenu();
			cout << "Успешно" << endl;
		}
		else {
			cout << "Ошибка" << endl;
		}
	}
	else {
		cout << "КС не существует" << endl;
	}
	printMenu();
	loop = 1;
}

void SaveToFile() {
	clearMenu();
	string path;
	cout << "Введите название файла: ";
	cin >> path;
	ofstream fout;
	fout.open(path, ofstream::trunc);
	if (fout.is_open()) {
		if (newPipe.valid()) {
			fout << "Т" << endl;
			fout << newPipe.lengthPipe << endl;
			fout << newPipe.diametrPipe << endl;
			fout << newPipe.inRepair << endl;
			newPipe.lengthPipe = 0;
		}
		else {
			clearMenu();
			cout << "Создайте трубу" << endl;
			fout.close();
			printMenu();
			loop = 1;
			return;
		}

		if (newStation.valid()) {
			fout << "К" << endl;
			fout << newStation.name << endl;
			fout << newStation.countWorkshop << endl;
			fout << newStation.countActiveWorkshop << endl;
			fout << newStation.property << endl;
			newStation.name = "";
		}
		else {
			clearMenu();
			cout << "Создайте КС" << endl;
			fout.close();
			printMenu();
			loop = 1;
			return;
		}
		clearMenu();
		cout << "Файл сохранен" << endl;
	}
	else {
		clearMenu();
		cout << "Ошибка сохранения" << endl;
	}
	fout.close();
	printMenu();
	loop = 1;
}

void LoadFromFile() {
	clearMenu();
	string path;
	cout << "Введите название файла: ";
	cin >> path;
	ifstream fin;
	fin.open(path);
	if (fin.is_open()) {
		string ch;
		fin >> ch;
		fin >> newPipe.lengthPipe;
		fin >> newPipe.diametrPipe;
		fin >> newPipe.inRepair;
		fin >> ch;
		fin >> newStation.name;
		fin >> newStation.countWorkshop;
		fin >> newStation.countActiveWorkshop;
		fin >> newStation.property;
		clearMenu();
		cout << "Файл импортирован" << endl;
	}
	else {
		clearMenu();
		cout << "Ошибка открытия файла" << endl;
	}
	fin.close();
	printMenu();
	loop = 1;
}


void addPipe()
{
	clearMenu();
	cout << "Введите длину трубы: ";
	cin >> newPipe.lengthPipe;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		addPipe();
	}
	cout << "Введите диаметр трубы: ";
	cin >> newPipe.diametrPipe;
	cout << "В ремонте: ";
	cin >> newPipe.inRepair;
	cout << newPipe.valid();
	if (newPipe.valid()) {
		clearMenu();
		cout << "Труба добавлена" << endl;
		printMenu();
		loop = 1;
	}
	else
	{
		addPipe();
	}
	
}



void printObjects()
{
	clearMenu();
	ifstream fin;
	int i, p;
	cout << "1. Просмотреть трубы" << endl;
	cout << "2. Просмотреть кс" << endl;
	cout << "Выберите пункт: ";
	cin >> p;
	clearMenu();
	switch (p)
	{
	case 1:
		if (newPipe.valid()) {
			cout << "Труба " << endl;
			cout << " | Длина трубы: " << newPipe.lengthPipe << endl;
			cout << " | Диаметр трубы: " << newPipe.diametrPipe << endl;
			cout << " | В ремонте: " << newPipe.inRepair << endl;
		}
		else {
			cout << "Записей нет" << endl;
		}

		printMenu();
		loop = 1;
		break;
	case 2:
		if (newStation.valid()) {
			cout << "Станция " << endl;
			cout << " | Название: " << newStation.name << endl;
			cout << " | Цехов: " << newStation.countWorkshop << endl;
			cout << " | Рабочих цехов: " << newStation.countActiveWorkshop << endl;
			cout << " | Показатель: " << newStation.property << endl;
		}
		else {
			cout << "Записей нет" << endl;
		}

		printMenu();
		loop = 1;
		break;
	}
	fin.close();
}

void addStation()
{
	clearMenu();
	cout << "Укажите название станции: ";
	cin >> newStation.name;
	cout << "Укажите кол-во цехов: ";
	cin >> newStation.countWorkshop;
	cout << "Укажите кол-во активных цехов: ";
	cin >> newStation.countActiveWorkshop;
	cout << "Укажите некий показатель эффективности: ";
	cin >> newStation.property;
	if (!newStation.valid()) {
		cout << "Ошибка, попробуйте еще раз" << endl;
		addStation();
	}
	clearMenu();
	cout << "КС добавлена" << endl;
	printMenu();
	loop = 1;
}

int main()
{
	setlocale(LC_ALL, "");
	int menupoint;
	printMenu();
	while (loop != 0)
	{
		cout << "Выберите пункт меню: ";
		cin >> menupoint;
		if (cin.fail())
		{
			cout << "Ошибка" << endl;
			cin.clear();
			cin.ignore(12, '\n');
			clearMenu();
			main();
			
		}
		switch (menupoint)
		{
		case 1:	
			loop = 0;
			addPipe();
			break;
		case 2:
			loop = 0;
			addStation();
			break;
		case 3:
			loop = 0;
			printObjects();
			break;
		case 4:
			loop = 0;
			editPipe();
			break;
		case 5:
			loop = 0;
			editStation();
			break;
		case 6:
			loop = 0;
			SaveToFile();
			break;
		case 7:
			loop = 0;
			LoadFromFile();
			break;
		case 0:
			cout << "Завершение программы";
			return 0;
			break;
		default:
			cout << "Повторите еще раз";
			break;
		}
		
	}
	return 0;
}