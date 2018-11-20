#include "int_buffer.h"


int_buffer::int_buffer(size_t size) : buf_size(size), buf(new int[size])
{
	
}
int_buffer::int_buffer(const int* source, size_t size) : buf(new int[size]), buf_size(size)
{
	for (size_t i = 0; i < size; i++)
	{
		buf[i] = source[i];
	}
}
int_buffer::int_buffer(const int_buffer& rhs)
{
	buf = new int[rhs.buf_size];
	buf_size = rhs.buf_size;
	int i = 0;
	for (int a : rhs)
	{
		buf[i] = a;
		i++;
	}
}
int_buffer::int_buffer(int_buffer&& rhs) 
{
	buf = rhs.buf;
	buf_size = rhs.buf_size;
	rhs.buf = nullptr;
	rhs.buf_size = 0;
}
int_buffer & int_buffer::operator=(const int_buffer& rhs)
{
	if (this != &rhs)
	{
		buf = new int[rhs.buf_size];
		buf_size = rhs.buf_size;
		int i = 0;
		for (int a : rhs)
		{
			buf[i] = a;
			i++;
		}
	}
	return *this;
}
int_buffer & int_buffer::operator=(int_buffer&& rhs)
{
	if (this != &rhs)
	{
		std::swap(buf, rhs.buf);
		std::swap(buf_size, rhs.buf_size);
	}
	return *this;
}
int & int_buffer::operator[](size_t index)
{
	return buf[index];
}
size_t int_buffer::size() const
{
	return buf_size;
}
int* int_buffer::begin()
{
	return buf;
}
int* int_buffer::end()
{
	return (buf + buf_size);
}
const int* int_buffer::begin() const
{
	return buf;
}
const int* int_buffer::end() const
{
	return (buf + buf_size);
}
int_buffer::~int_buffer()
{
	delete[] buf;
}
