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

Park_Trans reading(int);//������ �� �����
void recording(Park_Trans);//�������� � ����
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
			cout << "����� ���������� ���������� �� ������ �������� � ���� ����������?\n";

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
				cout << "����� ��������� ���������� �� ������ ��������?" << endl;
				cout << "1) �������� ������" << endl;
				cout << "2) �������� ������" << endl;
				cout << "3) �������" << endl;

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
			cout << "����� ���������� ���������� �� ������ �������� �� ����� � ���� ���������� ?\n";

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
			cout << "�������� ����� ����������\n";
			recording(h);
			getchar();
			break;

		case 5:
			cout << "����� ��������� �� ������ �������� � ����� ����������?" << endl;
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
			cout << "����� ��������� �� ������ ������� �� ����� ����������?" << endl;
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
	cout << "\t\t\t\t\t|\t  \x1b[34m ���� ����������\x1b[0m \t\t\t|\t\t" << endl;
	cout << "\t\t\t\t\t|\t1. �������� ��������� � ����\t\t|\t\t" << endl;
	cout << "\t\t\t\t\t|\t2. �������� ����\t\t\t|\t\t" << endl;
	cout << "\t\t\t\t\t|\t3. ��������� ��������� �� �����\t\t|\t" << endl;
	cout << "\t\t\t\t\t|\t4. ��������� ���� � ����\t\t|\t\t" << endl;
	cout << "\t\t\t\t\t|\t5. �������� ��������� � �����\t\t|\t\t" << endl;
	cout << "\t\t\t\t\t|\t6. ������� ��������� �� �����\t\t\|\t\t" << endl;
	cout << "\t\t\t\t\t|\t0. Exit\t\t\t\t\t|" << endl;

	while (true) // ��������� ������������ �����
	{
		cout << "-> ";
		getline(cin, tmp);
		menu = atoi(tmp.c_str());
		if (num_valid(tmp)) // ���� �������� ������ ������ ��������
			if (menu >= 0 && menu <= 6) // ���� ������ �������
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
		in.open("C:\\Users\\������\\source\\repos\\Project9\\Project9\\Debug\\parck.txt", ios::in);
		if (!in.is_open())
			throw exception("������\n ���� �� �����������\n");

		if (in.peek() == EOF)
			throw exception("������\n ������ ����\n");

		while (in.peek() != EOF && num != 0) 
		{
			getline(in, tmp);
			if (tmp.empty())
				continue;

			cout << tmp << endl;

			switch (flag)
			{
			case 1:
				if (pos = tmp.find("��������� ����������: ") != 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n");

				data.typeTrans = tmp.substr(22);
			if (data.typeTrans != "�������� ������" && data.typeTrans != "�������� ������" && data.typeTrans != "�������")
					throw exception("���������� ��������� ������ �� �����\n������ � ��������������: ��������� ����������\n");
				break;

			case 2:
				if (pos = tmp.find("����: ") != 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � �������������� ������: ����\n");

				data.color = tmp.substr(6);
				break;

			case 3:
				if (pos = tmp.find("����: ") != 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � �������������� ������: ����\n");

				tmp = tmp.substr(6);
				if (!num_valid(tmp))
					throw exception("����������  ������ � �����\n���������� ��������� ������ �� �����\n������ � �������������� ������: ����\n");

				data.price = atoi(tmp.c_str()); // Convert string to integer
				if (data.price < 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n ������ � �������������� ������: ����\n");
				break;

			case 4:
				if (pos = tmp.find("����� ���������: ") != 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � �������������� ������: ����� ���������\n");

				tmp = tmp.substr(17);
				if (!num_valid(tmp))
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � �������������� ������: ����� ���������\n");

				data.volumeD = atoi(tmp.c_str()); // Convert string to integer
				if (data.volumeD < 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � �������������� ������: ����� ���������\n");
				break;

			case 5:
				if (pos = tmp.find("����� ��������: ") != 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ����� ��������\n");

				tmp = tmp.substr(16);
				if (!num_valid(tmp))
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ����� ��������\n");

				data.number = atoi(tmp.c_str()); // Convert string to integer
				if (data.number < 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ����� ��������\n");
				break;
			case 6:
				if (pos = tmp.find("��� ������������: ") != 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ��� ������������\n");

				tmp = tmp.substr(18);
				if (!num_valid(tmp))
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ��� ������������\n");

				data.yearP = atoi(tmp.c_str()); // Convert string to integer
				if (data.yearP < 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ��� ������������\n");
				break;

			case 7:
				if (pos = tmp.find("��� ������� � ������������: ") != 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ��� ������� � ������������\n");

				tmp = tmp.substr(28);
				if (!num_valid(tmp))
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ��� ������� � ������������\n");

				data.yearZ = atoi(tmp.c_str()); // Convert string to integer
				if (data.yearZ < 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ��� ������� � ������������\n");
				break;

			case 8:
				if (pos = tmp.find("��� �������: ") != 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ��� �������\n");

				data.type = tmp.substr(13);
				break;

			case 9:
				if (pos = tmp.find("����� ����������: ") != 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ����� ����������\n");

				tmp = tmp.substr(18);
				if (!num_valid(tmp))
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ����� ����������\n");

				data.passengers = atoi(tmp.c_str());
				if (data.passengers < 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ����� ����������\n");
				break;

			case 10:
				if (pos = tmp.find("����� �����: ") != 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ����� �����\n");

				tmp = tmp.substr(13);
				if (!num_valid(tmp))
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ����� �����\n");

				data.volumeG = atoi(tmp.c_str());
				if (data.volumeG < 0)
					throw exception("���������� ������ � �����\n���������� ��������� ������ �� �����\n������ � ��������������: ����� �����\n");
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
		out.open("C:\\Users\\������\\source\\repos\\Project9\\Project9\\Debug\\parck.txt", ios_base::app);
		if (!out.is_open())
			throw exception("������\n ���� �� �����������\n");

		for (auto el : l)
		{
			d = el->get_data();
			out << "��������� ����������: " << d.typeTrans << endl;
			out << "����: " << d.color << endl;
			out << "����: " << d.price << endl;
			out << "����� ���������: " << d.volumeD << endl;
			out << "����� ��������: " << d.number << endl;
			out << "��� ������������: " << d.yearP << endl;
			out << "��� ������� � ������������: " << d.yearZ << endl;
			out << "��� �������: " << d.type << endl;
			out << "����� ����������: " << d.passengers << endl;
			out << "����� �����: " << d.volumeG << endl<< endl;
		}
		out.close();
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}


