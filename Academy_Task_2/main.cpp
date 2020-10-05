
#include "Anytype.h"

int main()
{
	try
	{
		int tmp = 0;
		int b = 10;
		Anytype a;
		Anytype c;
		a = b;
		tmp = a.ToInt();
		std::cout << tmp;
		c = a;
		tmp = c.ToInt();
		std::cout << tmp;
	}

	catch (const exception& obj)
	{
		std::cout << obj.what();
	}

	return 0;
}