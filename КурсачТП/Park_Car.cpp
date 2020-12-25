#include <iostream>
#include <string>
#include "Park_Car.h"
#include "Truck_Product.h"
#include "Tram_Product.h"
#include "Car_Product.h"
#include "Valid.h"

void Park_Car::create_truck()
{
	car.push_back(new Truck_Product(0));
}

void Park_Car::create_passenger()
{
	car.push_back(new Car_Product(0));
}

void Park_Car::create_tram()
{
	car.push_back(new Tram_Product(0));
}


void Park_Car::setData(Data d)
{
	car.push_back(new Truck_Product(1, &d));
}


void Park_Car::delete_car(int k)
{
	int i = 0;
	auto it = car.begin();
	while (i <= k)
	{
		if (i == k)
		{
			car.remove(*it);

			cout << "\n deleted" << endl;
			break;
		}
		if (i != car.size() - 1) *it++;
		i++;
	}
}

void Park_Car::change(int k)
{
	Data d;
	int i = 0;

	for (auto el : car)
	{
		if (i == k)
		{
			system("cls");
			string tmp;
			int flag = 0;

			cout << "��������� ������:\n1.�������� ������\n2.�������� ������\n3.������� " << endl;
			cin >> flag;
			if (flag == 1)
			{
				d.typeCar = "�������� ������";
			}
			else if (flag == 2)
			{
				d.typeCar = "�������� ������";
			}
			else
			{
				d.typeCar = "�������";
			}
			
			do
			{
				cout << "1. ���� ������: ";//����� �����-�� 

				getline(cin, d.color);
			} while (!str_valid(d.color));

			while (true)
			{
				cout << "2. ����: ";
				getline(cin, tmp);
				d.price = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (d.price > 0)
						break;

			}

			while (true)
			{
				cout << "3. �����: ";
				getline(cin, tmp);
				d.volumeD = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (d.volumeD > 0)
						break;

			}

			while (true)
			{
				cout << "4. ����� ��������: ";
				getline(cin, tmp);
				d.number = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (d.number > 0)
						break;

			}

			while (true)
			{
				cout << "5. ��� ������������: ";
				getline(cin, tmp);
				d.yearP = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (d.yearP > 0)
						break;

			}

			while (true)
			{
				cout << "6. ��� ������� � ������������: ";
				getline(cin, tmp);
				d.yearZ = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (d.yearZ > 0)
						break;

			}
			do
			{
				cout << "7. ��� �������: ";
				getline(cin, d.type);
			} while (!str_valid(d.type));

			while (true) // Check for correct input
			{
				cout << "8. ����� ����������: ";
				getline(cin, tmp);
				d.passengers = atoi(tmp.c_str());
				if (num_valid(tmp)) // If string-num check passed
					if (d.passengers > 0) // If data are reasonable
						break;
			}

			while (true)
			{
				cout << "9. ����� �����: ";
				getline(cin, tmp);
				d.volumeG = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (d.volumeG > 0)
						break;
			}


			el->set_data(d);
		}
		i++;
	}

};

void Park_Car::show()
{
	Data d;

	for (auto el : car)
	{
		d = el->get_data();
		std::cout << "��� ������: " << d.typeCar << std::endl;
		std::cout << "���� ������: " << d.color << std::endl;
		std::cout << "����� ���������: " << d.volumeD << std::endl;
		std::cout << "����� ��������: " << d.number << std::endl;
		std::cout << "��� ������������: " << d.yearP << std::endl;
		std::cout << "��� ������� � ������������: " << d.yearZ << std::endl;
		std::cout << "��� �������: " << d.type << std::endl;
		std::cout << "����� ����������: " << d.passengers << std::endl;
		std::cout << "����� �����: " << d.volumeG << std::endl;
	}
}

std::list<Car*> Park_Car::get_Car()
{
	return car;
}
