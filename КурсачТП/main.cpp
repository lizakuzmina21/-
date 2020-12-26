#include <iostream>
#include <fstream>
#include "windows.h"
#include <exception>
#include <algorithm>
#include <list>
#include <string>
#include "Park_Trans.h"
#include "Trans.h"
#include "Valid.h"
using namespace std;

Park_Trans reading(int);//читать из файла
void recording(Park_Trans);//записать в файл
int main_menu();

bool str_cmp(Data d1, Data d2)
{
	return d1.typeTrans > d2.typeTrans;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");

	int menu = 1; 
	int trans_type;
	int num;
	string tmp;
	Park_Trans h;
	int n = 0;
	while (menu)
	{
		system("cls");
		menu = main_menu();

		switch (menu)
		{
		case 1:
			system("cls");
			cout << "Какое количество транспорта вы хотите добавить в парк транспорта?\n";

			while (true) 
			{
				cout << "-> ";
				getline(cin, tmp);
				num = atoi(tmp.c_str());
				if (num_valid(tmp)) 
					if (num > 0) 
						break;
			}

			for (int i = 0; i < num; i++)
			{
				system("cls");
				cout << "Какую Категорию транспорта вы хотите добавить?" << endl;
				cout << "1) Легковая машина" << endl;
				cout << "2) Грузовая машина" << endl;
				cout << "3) Трамвай" << endl;

				while (true)
				{
					cout << "-> ";
					getline(cin, tmp);
					trans_type = atoi(tmp.c_str());
					if (num_valid(tmp))
						if (trans_type == 1 || trans_type == 2 || trans_type == 3)
							break;
				}

				if (trans_type == 1)
					h.create_passenger();
				else if (trans_type == 2)
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
			cout << "Какое количество транспорта вы хотите добавить из файла в парк транспорта ?\n";

			while (true)
			{
				cout << "-> ";
				getline(cin, tmp);
				num = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (num > 0)
						break;
			}

			h = reading(num);
			break;

		case 4:
			cout << "Выгрузка парка транспорта\n";
			recording(h);
			getchar();
			break;

		case 5:
			cout << "Какой транспорт вы хотите изменить в парке тарнспорта?" << endl;
			h.show();
			while (true)
			{
				cout << "-> ";
				getline(cin, tmp);
				num = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (num > 0)
						break;
			}
			h.change(num - 1);
			break;

		case 6:
			cout << "Какой транспорт вы хотите удалить из парка транспорта?" << endl;
			h.show();
			while (true)
			{
				cout << "-> ";
				getline(cin, tmp);
				num = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (num > 0)
						break;
			}
			h.delete_car(num - 1);
			break;

		}
	}
	
	return 0;
}

int main_menu()
{
	int menu;
	string tmp;
	cout << "\t\t\t\t\t|\t  \x1b[34m ПАРК ТРАНСПОРТА\x1b[0m \t\t\t|\t\t" << endl;
	cout << "\t\t\t\t\t|\t1. Добавить транспорт в парк\t\t|\t\t" << endl;
	cout << "\t\t\t\t\t|\t2. Показать парк\t\t\t|\t\t" << endl;
	cout << "\t\t\t\t\t|\t3. Загрузить транспорт из файла\t\t|\t" << endl;
	cout << "\t\t\t\t\t|\t4. Загрузить парк в файл\t\t|\t\t" << endl;
	cout << "\t\t\t\t\t|\t5. Изменить транспорт в парке\t\t|\t\t" << endl;
	cout << "\t\t\t\t\t|\t6. Удалить транспорт из парка\t\t\|\t\t" << endl;
	cout << "\t\t\t\t\t|\t0. Exit\t\t\t\t\t|" << endl;

	while (true) // Проверьте правильность ввода
	{
		cout << "-> ";
		getline(cin, tmp);
		menu = atoi(tmp.c_str());
		if (num_valid(tmp)) // Если проверка номера строки пройдена
			if (menu >= 0 && menu <= 6) // Если данные разумны
				break;
	}

	return menu;
}

Park_Trans reading(int num)
{
	ifstream in;
	Park_Trans h;
	Data data;
	string tmp;
	int flag = 1;
	int pos;

	try
	{
		in.open("C:\\Users\\Кузлик\\source\\repos\\Project9\\Project9\\Debug\\parck.txt", ios::in);
		if (!in.is_open())
			throw exception("Ошибка\n Файл не открывается\n");

		if (in.peek() == EOF)
			throw exception("Ошибка\n Пустой файл\n");

		while (in.peek() != EOF && num != 0) 
		{
			getline(in, tmp);
			if (tmp.empty())
				continue;

			cout << tmp << endl;

			switch (flag)
			{
			case 1:
				if (pos = tmp.find("Категория транспорта: ") != 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\n");

				data.typeTrans = tmp.substr(22);
			if (data.typeTrans != "Легковая машина" && data.typeTrans != "Грузовая машина" && data.typeTrans != "Трамвай")
					throw exception("Невозможно загрузить данные из файла\nОшибка в характеристике: Категория транспорта\n");
				break;

			case 2:
				if (pos = tmp.find("Цвет: ") != 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике машины: Цвет\n");

				data.color = tmp.substr(6);
				break;

			case 3:
				if (pos = tmp.find("Цена: ") != 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике машины: Цена\n");

				tmp = tmp.substr(6);
				if (!num_valid(tmp))
					throw exception("Обнаружена  ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике машины: Цена\n");

				data.price = atoi(tmp.c_str()); // Convert string to integer
				if (data.price < 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\n Ошибка в характеристике машины: Цена\n");
				break;

			case 4:
				if (pos = tmp.find("Объем двигателя: ") != 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике машины: Объем двигателя\n");

				tmp = tmp.substr(17);
				if (!num_valid(tmp))
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике машины: Объем двигателя\n");

				data.volumeD = atoi(tmp.c_str()); // Convert string to integer
				if (data.volumeD < 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике машины: Объем двигателя\n");
				break;

			case 5:
				if (pos = tmp.find("Номер маршрута: ") != 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Номер маршрута\n");

				tmp = tmp.substr(16);
				if (!num_valid(tmp))
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Номер маршрута\n");

				data.number = atoi(tmp.c_str()); // Convert string to integer
				if (data.number < 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Номер маршрута\n");
				break;
			case 6:
				if (pos = tmp.find("Год производства: ") != 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Год производства\n");

				tmp = tmp.substr(18);
				if (!num_valid(tmp))
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Год производства\n");

				data.yearP = atoi(tmp.c_str()); // Convert string to integer
				if (data.yearP < 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Год производства\n");
				break;

			case 7:
				if (pos = tmp.find("Год запуска в эксплуатацию: ") != 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Год запуска в эксплуатацию\n");

				tmp = tmp.substr(28);
				if (!num_valid(tmp))
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Год запуска в эксплуатацию\n");

				data.yearZ = atoi(tmp.c_str()); // Convert string to integer
				if (data.yearZ < 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Год запуска в эксплуатацию\n");
				break;

			case 8:
				if (pos = tmp.find("Тип топлива: ") != 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Тип топлива\n");

				data.type = tmp.substr(13);
				break;

			case 9:
				if (pos = tmp.find("Число пассажиров: ") != 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Число пассажиров\n");

				tmp = tmp.substr(18);
				if (!num_valid(tmp))
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Число пассажиров\n");

				data.passengers = atoi(tmp.c_str());
				if (data.passengers < 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Число пассажиров\n");
				break;

			case 10:
				if (pos = tmp.find("Объем груза: ") != 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Объем груза\n");

				tmp = tmp.substr(13);
				if (!num_valid(tmp))
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Объем груза\n");

				data.volumeG = atoi(tmp.c_str());
				if (data.volumeG < 0)
					throw exception("Обнаружена ошибка в файле\nНевозможно загрузить данные из файла\nОшибка в характеристике: Объем груза\n");
				break;
			}

			if (flag == 10)
			{
				cout << endl;
				flag = 0; 
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

void recording(Park_Trans h)
{
	ofstream out;
	Data d;
	list<Trans*> l = h.get_trans();

	l.sort([](const Trans* s1, const Trans* s2)
		{
			return s1->get_data().typeTrans < s2->get_data().typeTrans;
		});

	try
	{
		out.open("C:\\Users\\Кузлик\\source\\repos\\Project9\\Project9\\Debug\\parck.txt", ios_base::app);
		if (!out.is_open())
			throw exception("Ошибка\n Файл не открывается\n");

		for (auto el : l)
		{
			d = el->get_data();
			out << "Категория транспорта: " << d.typeTrans << endl;
			out << "Цвет: " << d.color << endl;
			out << "Цена: " << d.price << endl;
			out << "Объем двигателя: " << d.volumeD << endl;
			out << "Номер маршрута: " << d.number << endl;
			out << "Год производства: " << d.yearP << endl;
			out << "Год запуска в эксплуатацию: " << d.yearZ << endl;
			out << "Тип топлива: " << d.type << endl;
			out << "Число пассажиров: " << d.passengers << endl;
			out << "Объем груза: " << d.volumeG << endl<< endl;
		}
		out.close();
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}


