#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>
#include <sstream>


class IConfigParcer
{
public:
	//virtual void FileFormatCheck() = 0;
	virtual bool Deserialization() = 0;
	virtual bool Serialization() = 0;
};


