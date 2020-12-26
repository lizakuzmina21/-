#include "Valid.h"
bool num_valid(std::string str)
{//12
	char tmp[1028];
	if (_itoa_s(atoi(str.c_str()), tmp, 10) == 0) //если число не боьше 10 символов
		if (str == tmp) 
			return true;

	return false;
}

bool str_valid(std::string str)
{

	if (!str.empty() && str.find_first_not_of(' ') >= 0) 
		return true;

	return false;
}
