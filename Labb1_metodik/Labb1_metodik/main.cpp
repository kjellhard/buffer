#include <iostream>
#include "int_buffer.h"
#include "int_sorted.h"
#include <ctime>
#include <chrono>

void f(int_buffer& buf)
{
	int x;
	for (int* i = buf.begin(); i != buf.end(); i++)
	{
		x = rand();
		*i = x;
	}

	/*for (const int* i = buf.begin(); i != buf.end(); i++)
	{
		std::cout << *i << std::endl;
	}*/
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
	size_t size = 400000;
	int_buffer sel(size), std(size), sort(size);
	f(sel);
	std = sort = sel;
	auto sel_start = std::chrono::high_resolution_clock::now();
	sel_sort(sel);
	auto sel_stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> sel_diff = sel_stop - sel_start;
	std::cout << "öööööööö\n";
	for (const int* i = sel.begin(); i != sel.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	std::cout << "Selected sort time: " << sel_diff.count() << '\n';
	auto std_start = std::chrono::high_resolution_clock::now();
	std::sort(std.begin(), std.end());
	auto std_stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> std_diff = std_stop - std_start;
	std::cout << "öööööööö\n";
	/*for (const int* i = sel.begin(); i != sel.end(); i++)
	{
		std::cout << *i << std::endl;
	}*/
	std::cout << "std::sort time: " << std_diff.count() << '\n';
	auto start = std::chrono::high_resolution_clock::now();
	int_sorted a(sort.begin(), sort.size());
	auto stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = stop - start;
	std::cout << "öööööööö\n";
	/*for (const int* i = sel.begin(); i != sel.end(); i++)
	{
		std::cout << *i << std::endl;
	}*/
	std::cout << "Merge sort time: " << diff.count() << '\n';
	std::cin.get();
}