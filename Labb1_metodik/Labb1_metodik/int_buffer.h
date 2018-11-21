#ifndef INT_BUFFER_H
#define INT_BUFFER_H
#define _SCL_SECURE_NO_WARNINGS

#include <cstdlib>
#include <utility>
#include <algorithm>

class int_buffer
{
public:
	explicit int_buffer(size_t size);
	int_buffer(const int* source, size_t size);
	int_buffer(const int_buffer& rhs);
	int_buffer(int_buffer&& rhs);
	int_buffer & operator=(const int_buffer& rhs);
	int_buffer & operator=(int_buffer&& rhs);
	int & operator[](size_t index);
	size_t size() const;
	int* begin();
	int* end();
	const int* begin() const;
	const int* end() const;
	void swap(int_buffer& a, int_buffer& b);
	~int_buffer();
private:
	size_t buf_size = 0;
	int* buf = nullptr;
};
#endif