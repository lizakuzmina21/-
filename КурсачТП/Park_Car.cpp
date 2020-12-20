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
};

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
