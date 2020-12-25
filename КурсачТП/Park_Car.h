#pragma once
#include <list>
#include "Factory.h"
using namespace std;
class Park_Car : public Factory
{
private:
	list <Car*> car;
public:
	void create_passenger() override;
	void create_truck() override;
	void create_tram() override;
	void change(int);//изменение
	void delete_car(int);
	void setData(Data);
	void show();
	list<Car*> get_Car();
};
