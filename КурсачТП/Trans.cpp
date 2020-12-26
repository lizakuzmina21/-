#include <iostream>
#include <string>
#include "Trans.h"
#include "Valid.h"

using namespace std;

void Trans::create(int flag)
{
	string tmp;
	
	cout << "1.��������� ����������: ";
	if (flag == 1)
	{
		data.typeTrans = "�������� ������";
		cout << "�������� ������" << endl;
	}
	else if (flag == 2)
	{
		data.typeTrans = "�������� ������";
		cout << "�������� ������" << endl;
	}
	else
	{
		data.typeTrans = "�������";
		cout << "�������" << endl;
	}


	do
	{
		cout << "2. ����: ";
		getline(cin, data.color);
	} while (!str_valid(data.color));
	

	while (true)
	{
		cout << "3. ����: ";
		getline(cin, tmp);
		data.price = atoi(tmp.c_str());
		if (num_valid(tmp))
			if (data.price > 0)
				break;

	}

	while (true)
	{
		cout << "4. ����� ���������: ";
		getline(cin, tmp);
		data.volumeD = atoi(tmp.c_str());
		if (num_valid(tmp))
			if (data.volumeD > 0)
				break;

	}

	while (true)
	{
		cout << "5. ����� ��������: ";
		getline(cin, tmp);
		data.number = atoi(tmp.c_str());
		if (num_valid(tmp))
			if (data.number > 0)
				break;

	}

	while (true)
	{
		cout << "6. ��� ������������: ";
		getline(cin, tmp);
		data.yearP = atoi(tmp.c_str());
		if (num_valid(tmp))
			if (data.yearP > 0)
				break;

	}

	while (true)
	{
		cout << "7. ��� ������� � ������������: ";
		getline(cin, tmp);
		data.yearZ = atoi(tmp.c_str());
		if (num_valid(tmp))
			if (data.yearZ > 0)
				break;

	}
	do
	{
		cout << "8. ��� �������: ";
		getline(cin, data.type);
	} while (!str_valid(data.type));
	
	while (true) 
	{
		cout << "9. ����� ����������: ";
		getline(cin, tmp);
		data.passengers = atoi(tmp.c_str());
		if (num_valid(tmp)) 
			if (data.passengers > 0) 
				break;
	}

	while (true)
	{
		cout << "10. ����� �����: ";
		getline(cin, tmp);
		data.volumeG = atoi(tmp.c_str());
		if (num_valid(tmp))
			if (data.volumeG > 0)
				break;
	}


}


void Trans::set_data(Data d)
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
	data.typeTrans = d.typeTrans;
}

Data Trans::get_data() const
{
	return data;
}
