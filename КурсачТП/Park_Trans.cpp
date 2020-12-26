#include <iostream>
#include <string>
#include "Park_Trans.h"
#include "Truck_Product.h"
#include "Tram_Product.h"
#include "Car_Product.h"
#include "Valid.h"

void Park_Trans::create_truck()
{
	trans.push_back(new Truck_Product(0));
}

void Park_Trans::create_passenger()
{
	trans.push_back(new Car_Product(0));
}

void Park_Trans::create_tram()
{
	trans.push_back(new Tram_Product(0));
}


void Park_Trans::setData(Data d)
{
	trans.push_back(new Truck_Product(1, &d));
}


void Park_Trans::delete_car(int k)
{
	int i = 0;
	auto it = trans.begin();
	while (i <= k)
	{
		if (i == k)
		{
			trans.remove(*it);

			cout << "\n��������� �������� ���������� �� ����� ����������" << endl;
			break;
		}
		if (i != trans.size() - 1) *it++;
		i++;
	}
}

void Park_Trans::change(int k)
{
	Data d;
	int i = 0;

	for (auto el : trans)
	{
		if (i == k)
		{
			system("cls");
			string tmp;
			int flag = 0;

			cout <<"1.��������� ����������: " << endl;
			cout <<"1)�������� ������" << endl;
			cout <<"2)�������� ������" << endl;
			cout<< "3)�������" << endl;
			cin >> flag;
			if (flag == 1)
			{
				d.typeTrans = "�������� ������";
			}
			else if (flag == 2)
			{
				d.typeTrans = "�������� ������";
			}
			else
			{
				d.typeTrans = "�������";
			}
			cout << "2. ����: ";
			do
			{
				getline(cin, d.color);
			} while (!str_valid(d.color)) ;

			while (true)
			{
				cout << "3. ����: ";
				getline(cin, tmp);
				d.price = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (d.price > 0)
						break;

			}

			while (true)
			{
				cout << "4. ����� ���������: ";
				getline(cin, tmp);
				d.volumeD = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (d.volumeD > 0)
						break;

			}

			while (true)
			{
				cout << "5. ����� ��������: ";
				getline(cin, tmp);
				d.number = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (d.number > 0)
						break;

			}

			while (true)
			{
				cout << "6. ��� ������������: ";
				getline(cin, tmp);
				d.yearP = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (d.yearP > 0)
						break;

			}

			while (true)
			{
				cout << "7. ��� ������� � ������������: ";
				getline(cin, tmp);
				d.yearZ = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (d.yearZ > 0)
						break;

			}
			do
			{
				cout << "8. ��� �������: ";
				getline(cin, d.type);
			} while (!str_valid(d.type));

			while (true) 
			{
				cout << "9. ����� ����������: ";
				getline(cin, tmp);
				d.passengers = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (d.passengers > 0) 
						break;
			}

			while (true)
			{
				cout << "10. ����� �����: ";
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

void Park_Trans::show()
{
	Data d;

	for (auto el : trans)
	{
		d = el->get_data();
		std::cout << "��������� ����������: " << d.typeTrans << std::endl;
		std::cout << "����: " << d.color << std::endl;
		std::cout << "����: " << d.price << std::endl;
		std::cout << "����� ���������: " << d.volumeD << std::endl;
		std::cout << "����� ��������: " << d.number << std::endl;
		std::cout << "��� ������������: " << d.yearP << std::endl;
		std::cout << "��� ������� � ������������: " << d.yearZ << std::endl;
		std::cout << "��� �������: " << d.type << std::endl;
		std::cout << "����� ����������: " << d.passengers << std::endl;
		std::cout << "����� �����: " << d.volumeG << std::endl << std::endl;;
	}
}

std::list<Trans*> Park_Trans::get_trans()
{
	return trans;
}
