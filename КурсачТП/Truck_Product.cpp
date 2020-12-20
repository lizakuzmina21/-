#include "Truck_Product.h"

Truck_Product::Truck_Product(int flag, Data* d)
{
	if (flag == 0)
		create(2);
	else
		set_data(*d);
}
