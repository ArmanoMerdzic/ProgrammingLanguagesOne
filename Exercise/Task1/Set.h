#pragma once
#include "Point.h"
#include <iostream>
#include <functional>

class Set
{
private:
	Point* arr;
	size_t size;
	size_t capacity;
public:
	Set() :arr(nullptr), size(0), capacity(0) {}
	Set(std::initializer_list<Point> list)
	{
		for (auto element : list)
			add(element);

	}

	Set(const Set& other)
	{
		dispose();
		arr = new Point[other.capacity];

		for (size_t i = 0; i < other.size; i++)
		{
			arr[i] = other.arr[i];
		}
		size = other.size;
		capacity = other.capacity;
	}
	Set& operator=(const Set& other)
	{
		dispose();


		for (size_t i = 0; i < other.size; i++)
		{
			add(other.arr[i]);
		}
		return *this;
	}
	Set(Set&& other)
	{
		*this = std::move(other);
	}

	Set& operator=(Set&& other)
	{
		if (this != &other)
		{
			dispose();
			arr = other.arr;
			size = other.size;
			capacity = other.capacity;
			other.arr = nullptr;
			other.size = 0;
			other.capacity = 0;
		}
		return *this;
	}
	Set& operator()(std::function<void(Point&)> edit)
	{
		for (size_t i = 0; i < size; i++)
			edit(arr[i]);

		return *this;

	}
	Set& operator()(std::function<void(const Point&)> edit)const
	{
		Set tmp = *this;
		for (size_t i = 0; i < size; i++)
			edit(tmp.arr[i]);

		return tmp;

	}

	void add(const Point& obj)
	{
		if (find(obj))
			return;

		if (size == capacity)
		{
			realloc();
		}


		arr[size] = obj;
		size++;

	}
	void remove(const Point& other)
	{
		Point* new_arr = new Point[capacity * 2];

		int index = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] != other)
				new_arr[index++] = arr[i];
		}
		size = index;
	}
	void remove(std::function<bool(const Point&)> test)
	{
		Point* new_arr = new Point[this->capacity];

		int index = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (test(arr[i]))
			{
				continue;
			}
			new_arr[index++] = arr[i];
		}
		size = index;
		dispose();
		arr = new_arr;

	}
	void forEach(std::function<void(Point&)> edit)
	{
		for (size_t i = 0; i < size; i++)
			edit(arr[i]);

	}
	void display()
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

	size_t getSize()
	{
		return size;
	}

	bool find(const Point& other)const
	{
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] == other)
				return true;
		}
		return false;
	}
	bool operator==(const Set& other)
	{
		if (this->size != other.size)
			return false;
		for (size_t i = 0; i < size; i++)
		{
			if (!other.find(this->arr[i]))
				return false;

		}
		return true;
	}



	void sort(std::function<bool(const Point&, const Point&)> compare)
	{


		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				if (compare(arr[i], arr[j]))
				{
					Point tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}

	}
private:
	void realloc()
	{
		Point* new_arr = new Point[capacity * 2 + 1];

		for (size_t i = 0; i < this->size; i++)
		{
			new_arr[i] = arr[i];
		}

		dispose();

		arr = new_arr;
		capacity = capacity * 2 + 1;

	}
	void dispose()
	{
		delete[]arr;
	}
};

