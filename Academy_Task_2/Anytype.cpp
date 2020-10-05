#include "Anytype.h"


Anytype::Anytype()
{

}

Anytype::~Anytype()
{

}

Anytype::Anytype(const Anytype& obj)
{
	this->buffer = obj.buffer;
}

Anytype& Anytype::operator=(Anytype& obj)
{
	this->buffer = obj.buffer;
	return *this;
}

void Anytype::swap(Anytype& obj)
{
	Anytype tmp;
	tmp.buffer = this->buffer;
	this->buffer = obj.buffer;
	obj.buffer = tmp.buffer;
}

int Anytype::ToInt() const
{
	if (this->buffer.index() == 0)
	{
		int tmp = std::get<int>(buffer);
		return tmp;
	}
	else
		throw std::bad_cast();
}

double Anytype::ToDouble() const
{
	if (this->buffer.index() == 1)
	{
		double tmp = std::get<double>(buffer);
		return tmp;
	}
	else
		throw std::bad_cast();
}

char Anytype::ToChar() const
{
	if (this->buffer.index() == 2)
	{
		char tmp = std::get<char>(buffer);
		return tmp;
	}
	else
		throw std::bad_cast();
}

bool Anytype::ToBool()const
{
	if (this->buffer.index() == 3)
	{
		bool tmp = std::get<bool>(buffer);
		return tmp;
	}
	else
		throw std::bad_cast();
}

std::ostream& operator<<(std::ostream& out, const Anytype& obj)
{
	out << obj.buffer;
	return out;
}