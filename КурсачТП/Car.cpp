#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

void Car::create(int flag)
{
	string tmp;

	cout << "1.��������� ������: ";
	if (flag == 1)
	{
		data.typeCar = "Car_Product";
		cout << "��������" << endl;
	}
	else if (flag == 2)
	{
		data.typeCar = "Truck_Product";
		cout << "�������� ������" << endl;
	}
	else
	{
		data.typeCar = "Tram_Product";
		cout << "�������" << endl;
	}

	while (true)
	{
		cout << "1.����: ";
		getline(cin, tmp);
		data.color = atoi(tmp.c_str());
		break;
	}

	while (true)
	{
		cout << "2. ����: ";
		getline(cin, tmp);
		data.price = atoi(tmp.c_str());

		break;
	}

	while (true)
	{
		cout << "3. ����� ���������: ";
		getline(cin, tmp);
		data.volumeD = atoi(tmp.c_str());

		break;
	}

	while (true)
	{
		cout << "4. ����� ��������: ";
		getline(cin, tmp);
		data.number = atoi(tmp.c_str());
		break;
	}

	while (true)
	{
		cout << "5. ��� ������������: ";
		getline(cin, tmp);
		data.yearP = atoi(tmp.c_str());
		break;
	}

	while (true)
	{
		cout << "6. ��� ������� � ������������: ";
		getline(cin, tmp);
		data.yearZ = atoi(tmp.c_str());

		break;
	}
	//do
	//{
	//	cout << "7. ��� �������: ";
	//	getline(cin, data.type);
	//} while (!str_valid(data.type));



	while (true) // Check for correct input
	{
		cout << "8. ����� ����������: ";
		getline(cin, tmp);
		data.passengers = atoi(tmp.c_str());

		break;
	}



	while (true)
	{
		cout << "9. ����� �����: ";
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
