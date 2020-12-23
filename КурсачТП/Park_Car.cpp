#include <iostream>
#include <string>
#include "Park_Car.h"
#include "Truck_Product.h"
#include "Tram_Product.h"
#include "Car_Product.h"

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
void Park_Car::change(int k)
{
	Data d;
	int i = 0;

	for (auto el : car)
	{
		if (i == k)
		{
			string tmp;
			int flag;

			cout << "��������� ������:\n1.�������� ������\n2.�������� ������\n3.������� " << endl;
			cin >> flag;
			if (flag == 1)
			{
				d.typeCar = "Car_Product";
			}
			else if (flag == 2)
			{
				d.typeCar = "Truck_Product";
			}
			else
			{
				d.typeCar = "Tram_Product";
			}
			while (true)
			{
				cout << "1.����: ";
				cin.get();
				getline(cin, tmp);
				d.color = tmp;
				break;
			}

			while (true)
			{
				cout << "2. ����: ";
				getline(cin, tmp);
				d.price = atoi(tmp.c_str());
				break;
			}

			while (true)
			{
				cout << "3. ����� ���������: ";
				getline(cin, tmp);
				d.volumeD = atoi(tmp.c_str());
				break;
			}

			while (true)
			{
				cout << "4. ����� ��������: ";
				getline(cin, tmp);
				d.number = atoi(tmp.c_str());

				break;
			}

			while (true)
			{
				cout << "5. ��� ������������: ";
				getline(cin, tmp);
				d.yearP = atoi(tmp.c_str());
				break;
			}

			while (true)
			{
				cout << "6. ��� ������� � ������������: ";
				getline(cin, tmp);
				d.yearZ = atoi(tmp.c_str());
				break;
			}
			cout << "7. ��� �������: ";
			getline(cin, d.type);




			while (true) // Check for correct input
			{
				cout << "8. ����� ����������: ";
				getline(cin, tmp);
				d.passengers = atoi(tmp.c_str());
				break;
			}



			while (true)
			{
				cout << "9. ����� �����: ";
				getline(cin, tmp);
				d.volumeG = atoi(tmp.c_str());
				break;
			}

			el->set_data(d);
		}
		i++;
	}

}
;

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
