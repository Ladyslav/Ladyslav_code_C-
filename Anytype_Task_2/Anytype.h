
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

	std::variant<int, double, char, bool> buffer;

public:

	Anytype();

	~Anytype();

	Anytype(string& obj) = delete;

	Anytype& operator=(string& obj) = delete;

	Anytype(const Anytype&& obj) = delete;

	Anytype(const Anytype& obj);

	Anytype& operator=(Anytype& obj);

	template<class T>
	Anytype(T obj)
	{
		const char* tmp = typeid(obj).name();
	
		if (!strcmp(tmp, "int") ||
			!strcmp(tmp, "double") ||
			!strcmp(tmp, "char") ||
			!strcmp(tmp, "bool"))
		{
			this->buffer = obj;
		}
		else throw std::bad_cast();

	};

	template<class T>
	Anytype& operator= (T& data)
	{
		this->buffer = data;
		return *this;
	}

	template<class T>
	Anytype& operator+= (T& data)
	{
		const char* tmp = typeid(data).name();

		if (!strcmp(tmp, "int")
			|| !strcmp(tmp, "double"))
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
		const char* tmp = typeid(data).name();

		if (!strcmp(tmp, "int")
			|| !strcmp(tmp, "double"))
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
		const char* tmp = typeid(data).name();

		if (!strcmp(tmp, "int")
			|| !strcmp(tmp, "double"))
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
		const char* tmp = typeid(data).name();
		if (!strcmp(tmp, "int") ||
			!strcmp(tmp, "double"))
		{
			if (this->buffer.index() < 2)
			{
				this->buffer = std::get<T>(buffer) / data;
				return *this;
			}
			else
				throw std::bad_cast();
		}
		else throw std::bad_cast();
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

// Line 128: The 'throw' keyword could be missing: throw bad_cast()
// Line 130: Non-void function should return a value.
// Line 27, Line 29 Anytype(string obj) = delete; Use reference as a method parameter.
// Line 36, Use reference as a method parameter. (T& obj)  
// Line 38, Please create a separate variable for 'typeid(obj).name()', it is code duplicate. 
