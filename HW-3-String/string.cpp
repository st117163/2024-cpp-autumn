#include "string.h"

String::String(const char* str)
{
	size = strlen(str);
	this->str = new char[size + 1];
	for (size_t i = 0; i <= size; ++i)
	{
		this->str[i] = str[i];
	}
}

String::String(const String& other) : size(other.size)
{
	str = new char[size + 1];
	strcpy(str, other.str);
}
String::~String()
{
	delete[] str;
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = new char[this->size + 1];
		strcpy(this->str, other.str);
	}

	return *this;
}
String String::operator[](size_t index) const
{
	if (this->size == index)
	{
		String tmp;
		return tmp;
	}

	if (this->size < strlen(this->str))
	{
		String tmp;
        tmp.size = index - this->size;

		for (int i = 0; i < tmp.size; ++i)
		{
			tmp.str[i] = this->str[this->size + i];
		}
		return tmp;
	}
	String tmp(this->str);
	tmp.size = index;
	return tmp;
}

std::ostream& operator<<(std::ostream& stream, const String& text)
{
	for (int i = 0; i < text.size; i++)
	{
		stream << text.str[i];
	}
	return stream;
}