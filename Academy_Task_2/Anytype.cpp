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
		int tmp = get<int>(buffer);
		return tmp;
	}
	else
		throw bad_cast();
}

double Anytype::ToDouble() const
{
	if (this->buffer.index() == 1)
	{
		double tmp = get<double>(buffer);
		return tmp;
	}
	else
		throw bad_cast();
}

char Anytype::ToChar() const
{
	if (this->buffer.index() == 2)
	{
		char tmp = get<char>(buffer);
		return tmp;
	}
	else
		throw bad_cast();
}

bool Anytype::ToBool()const
{
	if (this->buffer.index() == 3)
	{
		bool tmp = get<bool>(buffer);
		return tmp;
	}
	else
		throw bad_cast();
}

