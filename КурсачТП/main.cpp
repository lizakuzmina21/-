#include <iostream>
#include <fstream>
#include "windows.h"
#include <exception>
#include <algorithm>
#include <list>
#include <string>
#include "Park_Car.h"
#include "Car.h"
#include "Valid.h"
using namespace std;

Park_Car read_from_file(int);//читать из файла
void write_to_file(Park_Car);//записать в файл
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
	int ship_type;
	int num;
	string tmp;
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

			while (true) // Проверьте правильность ввода
			{
				cout << "> ";
				getline(cin, tmp);
				num = atoi(tmp.c_str());
				if (num_valid(tmp)) // Если проверка номера строки пройдена
					if (num > 0) // Если данные разумны
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
					getline(cin, tmp);
					ship_type = atoi(tmp.c_str());
					if (num_valid(tmp))
						if (ship_type == 1 || ship_type == 2 || ship_type == 3)
							break;
				}

				if (ship_type == 1)
					h.create_passenger();
				else if (ship_type == 2)
					h.create_truck();
				else
					h.create_tram();
			}
			break;

		case 2:
			h.show();
			getchar();
			break;

		case 3:
			system("cls");
			cout << "Сколько машин вы хотите добавить из файла ?\n";

			while (true)
			{
				cout << "> ";
				getline(cin, tmp);
				num = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (num > 0)
						break;
			}

			h = read_from_file(num);
			break;

		case 4:
			cout << "Выгрузка парка\n";
			write_to_file(h);
			getchar();
			break;

		case 5:
			cout << "Какую машину вы хотите изменить" << endl;
			h.show();

		/*	cin >> n;*/
			while (true)
			{
				cout << "> ";
				getline(cin, tmp);
				num = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (num > 0)
						break;
			}
			h.change(num - 1);

		}
	}
	
	return 0;
}

int main_menu()
{
	int menu;
	string tmp;

	cout << "1. Добавить машину в парк" << endl;
	cout << "2. Показать парк" << endl;
	cout << "3. Загрузить машины из файла" << endl;
	cout << "4. Загрузить парк в файл" << endl;
	cout << "5. Изменить машину в парке" << endl;
	cout << "0. Exit" << endl;

	while (true) // Проверьте правильность ввода
	{
		cout << "> ";
		getline(cin, tmp);
		menu = atoi(tmp.c_str());
		if (num_valid(tmp)) // Если проверка номера строки пройдена
			if (menu >= 0 && menu <= 5) // Если данные разумны
				break;
	}

	return menu;
}

Park_Car read_from_file(int num)
{
	ifstream in;
	Park_Car h;
	Data data;
	string tmp;
	int flag = 1;
	int pos;

	try
	{
		in.open("C:\\Users\\Кузлик\\source\\repos\\Project9\\Project9\\Debug\\parck.txt", ios::in);
		if (!in.is_open())
			throw exception("Файл не открывается!\n");

		if (in.peek() == EOF)
			throw exception("Файл пуст!\n");

		while (in.peek() != EOF && num != 0) // Read data from file
		{
			getline(in, tmp);
			if (tmp.empty())
				continue;

			cout << tmp << endl;

			switch (flag)
			{
			case 1:
				if (pos = tmp.find("Тип машины: ") != 0)
					throw exception("Ошибка в файле\n");

				data.typeCar = tmp.substr(12);
			if (data.typeCar != "Легковая" && data.typeCar != "Грузовая" && data.typeCar != "Трамвай")
					throw exception("В файле есть ошибка Типа машины");
				break;

			case 2:
				if (pos = tmp.find("Цвет машины: ") != 0)
					throw exception("Ошибка в файле\n");

				data.color = tmp.substr(13);
				break;

			case 3:
				if (pos = tmp.find("Цена: ") != 0)
					throw exception("Ошибка в файле\n");

				tmp = tmp.substr(6);
				if (!num_valid(tmp))
					throw exception("Ошибка в файле\n");

				data.price = atoi(tmp.c_str()); // Convert string to integer
				if (data.price < 0)
					throw exception("Ошибка цены в файле\n");
				break;

			case 4:
				if (pos = tmp.find("Объем двигателя: ") != 0)
					throw exception("Ошибка в файле\n");

				tmp = tmp.substr(17);
				if (!num_valid(tmp))
					throw exception("Ошибка в файле\n");

				data.volumeD = atoi(tmp.c_str()); // Convert string to integer
				if (data.volumeD < 0)
					throw exception("Ошибка объема двигателя в файле\n");
				break;

			case 5:
				if (pos = tmp.find("Номер маршрута: ") != 0)
					throw exception("Ошибка в файле\n");

				tmp = tmp.substr(16);
				if (!num_valid(tmp))
					throw exception("Ошибка в файле\n");

				data.number = atoi(tmp.c_str()); // Convert string to integer
				if (data.number < 0)
					throw exception("Ошибка номера маршрута в файле\n");
				break;
			case 6:
				if (pos = tmp.find("Год производства: ") != 0)
					throw exception("Ошибка в файле\n");

				tmp = tmp.substr(18);
				if (!num_valid(tmp))
					throw exception("Ошибка в файле\n");

				data.yearP = atoi(tmp.c_str()); // Convert string to integer
				if (data.yearP < 0)
					throw exception("Ошибка год производства в файле\n");
				break;

			case 7:
				if (pos = tmp.find("Год запуска в эксплуатацию: ") != 0)
					throw exception("Ошибка в файле\n");

				tmp = tmp.substr(28);
				if (!num_valid(tmp))
					throw exception("Ошибка в файле\n");

				data.yearZ = atoi(tmp.c_str()); // Convert string to integer
				if (data.yearZ < 0)
					throw exception("Ошибка год запуска в эксплуатацию в файле\n");
				break;

			case 8:
				if (pos = tmp.find("Тип топлива: ") != 0)
					throw exception("Ошибка в файле\n");

				data.type = tmp.substr(13);
				break;

			case 9:
				if (pos = tmp.find("Число пассажиров: ") != 0)
					throw exception("Ошибка в файле\n");

				tmp = tmp.substr(18);
				if (!num_valid(tmp))
					throw exception("Ошибка в файле\n");

				data.passengers = atoi(tmp.c_str());
				if (data.passengers < 0)
					throw exception("Ошибка числа пассажиров в файле\n");
				break;

			case 10:
				if (pos = tmp.find("Объем груза: ") != 0)
					throw exception("Ошибка в файле\n");

				tmp = tmp.substr(13);
				if (!num_valid(tmp))
					throw exception("Ошибка в файле\n");

				data.volumeG = atoi(tmp.c_str());
				if (data.volumeG < 0)
					throw exception("Ошибка в объеме груза в файле\n");
				break;
			}
			//cout << "фхует";
			//system("pause");
			if (flag == 10)
			{
				cout << endl;
				flag = 0; // Zero because of increment below
				h.setData(data);
				num--;
			}

			flag++;
		}
	}

	catch (exception& ex)
	{
		cout << ex.what() << endl;
		getchar();
	}

	in.close();

	return h;
}

void write_to_file(Park_Car h)
{
	ofstream out;
	Data d;
	list<Car*> l = h.get_Car();

	l.sort([](const Car* s1, const Car* s2)
		{
			return s1->get_data().typeCar < s2->get_data().typeCar;
		});

	try
	{
		out.open("C:\\Users\\Кузлик\\source\\repos\\Project9\\Project9\\Debug\\parck.txt", ios_base::app);
		if (!out.is_open())
			throw exception("File can not be opened!");

		for (auto el : l)
		{
			d = el->get_data();
			out << "Тип машины: " << d.typeCar << endl;
			out << "Цвет машины: " << d.color << endl;
			out << "Цена: " << d.price << endl;
			out << "Объем двигателя: " << d.volumeD << endl;
			out << "Номер маршрута: " << d.number << endl;
			out << "Год производства: " << d.yearP << endl;
			out << "Год запуска в эксплуатацию: " << d.yearZ << endl;
			out << "Тип топлива: " << d.type << endl;
			out << "Число пассажиров: " << d.passengers << endl;
			out << "Объем груза: " << d.volumeG << endl;
		}
		out.close();
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}


