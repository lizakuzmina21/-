#pragma once

#include <iostream>

struct Data
{
	std::string color;//����
	int price;//����
	int volumeD;//����� ���������
	int number;//����� ��������
	int yearP;//��� ������������
	int yearZ;//��� ������� � ������������
	std::string type;//��� �������
	int passengers;//����� ����������
	int volumeG;//����� �����
	std::string typeTrans;//��� ������;
};

class Trans
{
protected:
	Data data;
public:
	virtual ~Trans() {};
	void create(int flag);
	void set_data(struct Data);
	Data get_data() const;
};
