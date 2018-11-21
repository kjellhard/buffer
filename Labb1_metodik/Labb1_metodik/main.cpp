#include <iostream>
#include "int_buffer.h"
#include "int_sorted.h"
#include <ctime>
#include <chrono>

void f(int_buffer buf)
{
	int x = 1;
	for (int* i = buf.begin(); i != buf.end(); i++)
	{
		*i = x;
		x++;
	}

	for (const int* i = buf.begin(); i != buf.end(); i++)
	{
		std::cout << *i << std::endl;
	}
}
void fill(int_buffer& buf)
{
	for (int* i = buf.begin(); i != buf.end(); i++)
	{
		*i = rand();
	}
}

void print(const int* begin, const int* end)
{
	for (const int* i = begin; i != end; i++)
	{
		std::cout << *i << '\n';
	}
}

void sel_sort(int_buffer& buf)
{
	int tmp;
	for (int* i = buf.begin(); i != buf.end(); i++)
	{
		for (int* j = buf.begin(); j != buf.end(); j++)
		{
			if (*i < *j)
			{
				tmp = *i;
				*i = *j;
				*j = tmp;
			}
		}
	}
}
int main()
{
	srand(time(NULL));
	size_t size = 10;
	int_buffer sel(size), std(size), sort(size);
	f(sel);
	fill(sel);
	std = sort = sel;
	auto sel_start = std::chrono::high_resolution_clock::now();
	sel_sort(sel);
	auto sel_stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> sel_diff = sel_stop - sel_start;
	std::cout << "öööööööö\n";
	print(sel.begin(), sel.end());
	std::cout << "Selected sort time: " << sel_diff.count() << '\n';

	auto std_start = std::chrono::high_resolution_clock::now();
	std::sort(std.begin(), std.end());
	auto std_stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> std_diff = std_stop - std_start;
	std::cout << "öööööööö\n";
	print(std.begin(), std.end());
	std::cout << "std::sort time: " << std_diff.count() << '\n';

	auto start = std::chrono::high_resolution_clock::now();
	int_sorted a(sort.begin(), sort.size());
	auto stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = stop - start;
	std::cout << "öööööööö\n";
	print(a.begin(), a.end());
	std::cout << "Merge sort time: " << diff.count() << '\n';
	std::cin.get();
}