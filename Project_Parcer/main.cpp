
#include "Parcer_XML.h"

int main()
{

	try
	{
		Parcer_XML obj(R"(D:\tmp_xml\data.xml)");

		obj.Deserialization();
		obj.show();
	}

	catch (const std::exception& obj)
	{
		std::cout << obj.what();
	}


	return 0;
}