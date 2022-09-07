#include <iostream>
#include <string>

using namespace std;

int loop = 1;

struct Pipe {
	float lengthPipe;
	float diametrPipe;
	bool inRepair;
};

struct Station {
	string name;
	int countWorkshop;
	int countActiveWorkshop;
	float property;
};



void showMenu()
{
	cout << "1. Добавить трубу" << endl;
	cout << "2. Добавить КС" << endl;
	cout << "3. Просмотр всех объектов" << endl;
	cout << "4. Редактировать трубу" << endl;
	cout << "5. Редактировать КС" << endl;
	cout << "6. Сохранить" << endl;
	cout << "7. Загрузить" << endl;
	cout << "0. Выйти" << endl;
}

void addPipe()
{
	Pipe newPipe;
	cout << "Введите длину трубы: ";
	cin >> newPipe.lengthPipe;
	cout << "Введите диаметр трубы: ";
	cin >> newPipe.diametrPipe;
	cout << "В ремонте: ";
	cin >> newPipe.inRepair;
	// cout << "————————————————————————————————————————————————————————————————" << endl;
	cout << "|                           Труба добавлена                    |" << endl;
	// cout << "————————————————————————————————————————————————————————————————" << endl;
	showMenu();
	loop = 1;

}

void addKs()
{
	Station newStation;
	cout << "Укажите название станции: ";
	cin >> newStation.name;
	cout << "Укажите кол-во цехов: ";
	cin >> newStation.countWorkshop;
	cout << "Укажите кол-во активных цехов: ";
	cin >> newStation.countActiveWorkshop;
	cout << "Укажите некий показатель эффективности: ";
	cin >> newStation.property;
	cout << "|                           КС добавлена                    |" << endl;
	showMenu();
	loop = 1;
}



int main()
{
	setlocale(LC_ALL, "");
	int menupoint;
	showMenu();
	while (loop != 0)
	{
		cout << "Выберите пункт меню: ";
		cin >> menupoint;
		switch (menupoint)
		{
		case 1:
			loop = 0;
			addPipe();
			break;
		case 2:
			loop = 0;
			addKs();
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "Повторите еще раз";
			break;
		}
	}
	return 0;
}