#include <iostream>
#include <fstream>
#include "windows.h"
#include <exception>
#include <algorithm>
#include <list>
#include <string>
#include "Park_Car.h"
#include "Car.h"

using namespace std;



int main_menu();

bool str_cmp(Data d1, Data d2)
{
	return d1.typeCar > d2.typeCar;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");

	int menu = 1;
	int car_type;
	int num;
	int tmp;
	Park_Car h;
	int n = 0;
	while (menu)
	{
		system("cls");
		menu = main_menu();

		switch (menu)
		{
		case 1:
			system("cls");
			cout << "Сколько машин вы хотите добавить?\n";

			while (true)
			{
				cout << "> ";
				cin >> tmp;
				num = tmp;
				break;
			}

			for (int i = 0; i < num; i++)
			{
				system("cls");
				cout << "1. Легковая машина" << endl;
				cout << "2. Грузовая машина" << endl;
				cout << "3.Трамвай" << endl;

				while (true)
				{
					cout << "> ";
					cin >> tmp;
					car_type = tmp;

					if (car_type == 1 || car_type == 2 || car_type == 3)
						break;
				}

				if (car_type == 1)
					h.create_passenger();
				else if (car_type == 2)
					h.create_truck();
				else
					h.create_tram();
			}
			break;

		case 2:
			h.show();
			getchar();
			break;

		}
	}

	return 0;
}

int main_menu()
{
	int menu;
	int tmp;

	cout << "1. Добавить машину в парк" << endl;
	cout << "2. Показать парк" << endl;
	cout << "0. Exit" << endl;

	while (true)
	{
		cout << "> ";
		cin >> tmp;
		menu = tmp;

		break;
	}

	return menu;
}




