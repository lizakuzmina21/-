#include "Valid.h"
bool num_valid(std::string str)
{
	char tmp[1028];
	if (_itoa_s(atoi(str.c_str()), tmp, 10) == 0) // ѕреобразование строки в число, а затем обратно в строку
		if (str == tmp) // ≈сли строки равны и ошибок не возникает
			return true;

	return false;
}

bool str_valid(std::string str)
{
	if (!str.empty() && str.find_first_not_of(' ') >= 0) // ≈сли строка не пуста€ и состоит не только из пробелов
		return true;

	return false;
}
