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

			cout << "Категория машины:\n1.Легковая машина\n2.Грузовая машина\n3.Трамвай " << endl;
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
				cout << "1.цвет: ";
				cin.get();
				getline(cin, tmp);
				d.color = tmp;
				break;
			}

			while (true)
			{
				cout << "2. Цена: ";
				getline(cin, tmp);
				d.price = atoi(tmp.c_str());
				break;
			}

			while (true)
			{
				cout << "3. Объем двигателя: ";
				getline(cin, tmp);
				d.volumeD = atoi(tmp.c_str());
				break;
			}

			while (true)
			{
				cout << "4. Номер маршрута: ";
				getline(cin, tmp);
				d.number = atoi(tmp.c_str());

				break;
			}

			while (true)
			{
				cout << "5. Год производства: ";
				getline(cin, tmp);
				d.yearP = atoi(tmp.c_str());
				break;
			}

			while (true)
			{
				cout << "6. Год запуска в эксплуатацию: ";
				getline(cin, tmp);
				d.yearZ = atoi(tmp.c_str());
				break;
			}
			cout << "7. Тип топлива: ";
			getline(cin, d.type);




			while (true) // Check for correct input
			{
				cout << "8. Число пассажиров: ";
				getline(cin, tmp);
				d.passengers = atoi(tmp.c_str());
				break;
			}



			while (true)
			{
				cout << "9. Объем груза: ";
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
		std::cout << "Тип машины: " << d.typeCar << std::endl;
		std::cout << "Цвет машины: " << d.color << std::endl;
		std::cout << "Объем двигателя: " << d.volumeD << std::endl;
		std::cout << "Номер маршрута: " << d.number << std::endl;
		std::cout << "Год производства: " << d.yearP << std::endl;
		std::cout << "Год запуска в эксплуатацию: " << d.yearZ << std::endl;
		std::cout << "Тип топлива: " << d.type << std::endl;
		std::cout << "Число пассажиров: " << d.passengers << std::endl;
		std::cout << "Объем груза: " << d.volumeG << std::endl;
	}
}

std::list<Car*> Park_Car::get_Car()
{
	return car;
}
