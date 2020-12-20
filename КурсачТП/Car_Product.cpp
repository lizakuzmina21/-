#include "Car_Product.h"


Car_Product::Car_Product(int flag, Data* d)
{
	if (flag == 0)
		create(1);
	else
		set_data(*d);
}

