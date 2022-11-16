#pragma once
#include <iostream>

class Point
{
private:
	int x, y, z;
public:
	Point() = default;
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}
	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;

		return *this;
	}
	~Point() = default;


	Point(int x, int y, int z) : x(x), y(y), z(z) {}



	bool operator==(const Point& other)
	{
		if (x == other.x && y == other.y && z == other.z)
			return true;
		return false;
	}
	Point& operator+(const Point& other)const
	{
		Point ans;
		ans.x = this->x + other.x;
		ans.y = this->y + other.y;
		ans.z = this->z + other.z;
		return ans;

	}

	std::ostream& print(std::ostream& os = std::cout)const
	{


		os << "{" << x << ", " << y << ", " << z << "}" << std::endl;
		return os;

	}

	friend std::ostream& operator<<(std::ostream& os, const Point& obj)
	{
		return obj.print(os);
	}
	friend std::istream& operator>>(std::istream& is, Point& obj)
	{
		is >> obj.x >> obj.y >> obj.z;
		return is;
	}
	Point& operator++()
	{
		x++;
		y++;
		z++;
		return *this;
	}
	Point& operator++(int)
	{
		Point temp = *this;
		x++;
		y++;
		z++;
		return temp;
	}

	bool operator!=(const Point& other)
	{

		return !operator==(other);
	}


	int getX()const
	{
		return x;
	}
	int getY()const
	{
		return y;
	}
	int getZ()const
	{
		return z;
	}

	void setX(int value)
	{
		this->x = value;
	}
	void setY(int value)
	{
		this->y = value;
	}
	void setZ(int value)
	{
		this->z = value;
	}
};
