#pragma once

#include <iostream>

struct Data
{
	std::string color;//цвет
	int price;//цена
	int volumeD;//объем двигателя
	int number;//номер маршрута
	int yearP;//год производства
	int yearZ;//год запуска в эксплуатацию
	std::string type;//тип топлива
	int passengers;//число пассажиров
	int volumeG;//объем груза
	std::string typeTrans;//тип машины;
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
