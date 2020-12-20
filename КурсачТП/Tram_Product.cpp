#include "Tram_Product.h"

Tram_Product::Tram_Product(int flag, Data* d)
{
	if (flag == 0)
		create(3);
	else
		set_data(*d);
}