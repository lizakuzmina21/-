#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

void Car::create(int flag)
{
	string tmp;

	cout << "1.Категория машины: ";
	if (flag == 1)
	{
		data.typeCar = "Car_Product";
		cout << "Легковая" << endl;
	}
	else if (flag == 2)
	{
		data.typeCar = "Truck_Product";
		cout << "Грузовая машина" << endl;
	}
	else
	{
		data.typeCar = "Tram_Product";
		cout << "Трамвай" << endl;
	}

	while (true)
	{
		cout << "1.цвет: ";
		getline(cin, tmp);
		data.color = atoi(tmp.c_str());
		break;
	}

	while (true)
	{
		cout << "2. Цена: ";
		getline(cin, tmp);
		data.price = atoi(tmp.c_str());

		break;
	}

	while (true)
	{
		cout << "3. Объем двигателя: ";
		getline(cin, tmp);
		data.volumeD = atoi(tmp.c_str());

		break;
	}

	while (true)
	{
		cout << "4. Номер маршрута: ";
		getline(cin, tmp);
		data.number = atoi(tmp.c_str());
		break;
	}

	while (true)
	{
		cout << "5. Год производства: ";
		getline(cin, tmp);
		data.yearP = atoi(tmp.c_str());
		break;
	}

	while (true)
	{
		cout << "6. Год запуска в эксплуатацию: ";
		getline(cin, tmp);
		data.yearZ = atoi(tmp.c_str());

		break;
	}
	//do
	//{
	//	cout << "7. Тип топлива: ";
	//	getline(cin, data.type);
	//} while (!str_valid(data.type));



	while (true) // Check for correct input
	{
		cout << "8. Число пассажиров: ";
		getline(cin, tmp);
		data.passengers = atoi(tmp.c_str());

		break;
	}



	while (true)
	{
		cout << "9. Объем груза: ";
		getline(cin, tmp);
		data.volumeG = atoi(tmp.c_str());

		break;
	}


}


void Car::set_data(Data d)
{
	data.color = d.color;
	data.price = d.price;
	data.volumeD = d.volumeD;
	data.number = d.number;
	data.yearP = d.yearP;
	data.yearZ = d.yearZ;
	data.type = d.type;
	data.passengers = d.passengers;
	data.volumeG = d.volumeG;
	data.typeCar = d.typeCar;
}

Data Car::get_data() const
{
	return data;
}
