
#ifndef ANYTYPE
#define ANYTYPE

#include <iostream>
#include <string>
#include <variant>
#include <typeinfo>
#include <typeindex>

using std::variant;
using std::string;
using std::exception;

class Anytype
{
private:

	variant<int, double, char, bool> buffer;

public:

	Anytype();

	~Anytype();

	Anytype(string obj) = delete;

	Anytype& operator=(string obj) = delete;

	Anytype(const Anytype&& obj) = delete;

	Anytype(const Anytype& obj);

	template<class T>
	Anytype(T obj)
	{
		if (!strcmp(typeid(obj).name(), "int") ||
			!strcmp(typeid(obj).name(), "double") ||
			!strcmp(typeid(obj).name(), "char") ||
			!strcmp(typeid(obj).name(), "bool"))
		{
			this->buffer = obj;
		}
		else throw std::bad_cast();

	};

	Anytype& operator=(Anytype& obj);

	template<class T>
	Anytype& operator= (T& data)
	{
		this->buffer = data;
		return *this;
	}

	template<class T>
	Anytype& operator+= (T& data)
	{

		if (!strcmp(typeid(data).name(), "int")
			|| !strcmp(typeid(data).name(), "double"))
		{
			if (this->buffer.index() < 2)
			{
				this->buffer = std::get<T>(buffer) + data;
				return *this;
			}
			else
				throw std::bad_cast();
		}
		else
			throw std::bad_cast();
	}

	template<class T>
	Anytype& operator-= (T& data)
	{
		if (!strcmp(typeid(data).name(), "int")
			|| !strcmp(typeid(data).name(), "double"))
		{
			if (this->buffer.index() < 2)
			{
				this->buffer = std::get<T>(buffer) - data;
				return *this;
			}
			else
				throw std::bad_cast();
		}
		else
			throw std::bad_cast();

	}

	template<class T>
	Anytype& operator*= (T& data)
	{
		if (!strcmp(typeid(data).name(), "int")
			|| !strcmp(typeid(data).name(), "double"))
		{
			if (this->buffer.index() < 2)
			{
				this->buffer = std::get<T>(buffer) * data;
				return *this;
			}
			else
				throw std::bad_cast();
		}
		else
			throw std::bad_cast();
	}

	template<class T>
	Anytype& operator/= (T& data)
	{
		if (!strcmp(typeid(data).name(), "int") ||
			!strcmp(typeid(data).name(), "double"))
		{
			if (this->buffer.index() < 2)
			{
				this->buffer = std::get<T>(buffer) / data;
				return *this;
			}
			else
				throw std::bad_cast();
		}
		else std::bad_cast();

	}

	void swap(Anytype& obj);

	friend std::ostream& operator<<(std::ostream& out, const Anytype& obj);

	int ToInt() const;

	double ToDouble() const;

	char ToChar() const;

	bool ToBool() const;
};

/*std::ostream& operator<<(std::ostream& out, const Anytype& obj)
{
	out << obj.buffer;
	return out;
}*/

#endif

// Tests
