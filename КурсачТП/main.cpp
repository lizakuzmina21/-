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



void write_to_file(Park_Car);//�������� � ����
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
			cout << "������� ����� �� ������ ��������?\n";

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
				cout << "1. �������� ������" << endl;
				cout << "2. �������� ������" << endl;
				cout << "3.�������" << endl;

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
			system("pause");
			break;

		case 3:
			cout << "�������� �����\n";
			write_to_file(h);
			break;

		case 4:
			cout << "����� ������ �� ������ ��������" << endl;
			h.show();
			cin >> n;
			while (true)
			{
				cout << "> ";
				cin>> tmp;
				break;
			}
			h.change(n - 1);

		}
	}

	return 0;
}

int main_menu()
{
	int menu;
	int tmp;

	cout << "1. �������� ������ � ����" << endl;
	cout << "2. �������� ����" << endl;
	cout << "3. ��������� ������ � ����" << endl;
	cout << "4. �������� ������ � �����" << endl;
	cout << "0. Exit" << endl;

	while (true) // ��������� ������������ �����
	{
		cout << "> ";
		cin >> tmp;
		menu = tmp;

		break;
	}

	return menu;
}



void write_to_file(Park_Car h)
{
	ofstream out;
	Data d;
	list<Car*> l = h.get_Car();




	out.open("C:\\Users\\������\\source\\repos\\Project9\\Project9\\Debug\\parck.txt", ios_base::app);


	for (auto el : l)
	{
		d = el->get_data();

		out << "��� ������: " << d.typeCar << endl;
		out << "���� ������: " << d.color << endl;
		out << "����� ���������: " << d.volumeD << endl;
		out << "����� ��������: " << d.number << endl;
		out << "��� ������������: " << d.yearP << endl;
		out << "��� ������� � ������������: " << d.yearZ << endl;
		out << "��� �������: " << d.type << endl;
		out << "����� ����������: " << d.passengers << endl;
		out << "����� �����: " << d.volumeG << endl;
	}
	out.close();

}



