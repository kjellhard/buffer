#include "int_sorted.h"
#include <iostream>

int_sorted::int_sorted(const int* source, size_t size) : buff(nullptr, 0)
{
	if (size == 0)
		return;
	else if (size == 1)
	{
		insert(*source);
		return;
	}
	int_buffer tmp(source, size);
	buff = std::move(sort(tmp.begin(), tmp.end()).buff);
	//std::sort(tmp.begin(), tmp.end());
	//buff = std::move(tmp);
}

size_t int_sorted::size() const
{
	return buff.size();
}

int* int_sorted::insert(int value)
{
	int_buffer temp(buff.size()+1);
	int* i = buff.begin();
	int* j = temp.begin();
	int* r = nullptr;
	bool stop = false;
	for (; j != temp.end(); i++, j++)
	{
		if (*i > value && !stop)
		{
			r = j;
			*j = value;
			i--;
			stop = true;
		}
		else
			*j = *i;
	}
	if (!r) //Om index ej hittats
	{
		--j;
		r = j;
		*r = value;
	}

	buff = std::move(temp);
	return r;
}

const int* int_sorted::begin() const
{
	return buff.begin();
}

const int * int_sorted::end() const
{
	return buff.end();
}

int_sorted int_sorted::merge(const int_sorted & merge_with) const
{
	int_sorted merged(nullptr, 0);
	int_buffer merging(size() + merge_with.size());
	const int* i = begin();
	const int* j = merge_with.begin();
	int* k = merging.begin();
	while (i != end() && j != merge_with.end())
	{
		if (*i > *j)
		{
			*k = *j;
			j++;
		}
		else
		{
			*k = *i;
			i++;
		}
		k++;
	}
	while (i != end())
	{
		*k = *i;
		i++;
		k++;
	}
	while (j != merge_with.end())
	{
		*k = *j;
		j++;
		k++;
	}
	merged.buff = std::move(merging);
	return merged;
}

int_sorted int_sorted::sort(const int* begin, const int* end)
{
	if(begin == end) 
		return int_sorted(nullptr, 0);
	if(begin == end - 1)
		return int_sorted(begin, 1);
	ptrdiff_t half = (end - begin) / 2; //pointer  diff  type
	const int* mid = begin + half;
	return sort(begin, mid).merge(sort(mid, end));
}

/*int_sorted int_sorted::sel_sort(const int* begin, const int* end)
{
	int_buffer temp(begin, end - begin);
	int tmp;
	if (begin == end)
		return int_sorted(nullptr, 0);
	if (begin == end - 1)
		return int_sorted(begin, 1);
	for (int* i = temp.begin(); i != temp.end(); i++)
	{
		for (int* j = temp.begin(); j != temp.end(); j++)
		{
			if (*i < *j)
			{
				tmp = *i;
				*i = *j;
				*j = tmp;
			}
		}
	}
	buff = std::move(temp);
	return *this;
}*/

int_sorted::~int_sorted()
{

}
