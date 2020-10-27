#include "XmlConfigParcer.h"

int main()
{

		XmlConfigParcer obj(R"(D:\tmp_xml\data.xml)");
		obj.Deserialization();
		obj.show();
		
	return 0;
}