#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <exception>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>
#include <sstream>


class Parcer_Interface
{
	//virtual void FileFormatCheck() = 0;
	virtual void Deserialization() = 0;
	virtual void Serialization() = 0;
};


