#include <iostream>
#include <cstdlib>
#include <chrono>

#include "Set.h"
#include "Point.h"

using namespace std::chrono;

Set buildSet(int numberOfPoints)
{
	Set set;
	for (size_t i = 0; i < numberOfPoints; i++)
	{
		int x = i;
		int y = rand() % 100;
		int z = rand() % 100;
		set.add(Point(x, y, z));
	}
	return set;
}

int main()
{

	Set testTwo = { Point(1,2,3),Point(0,0,0),Point(5,6,7) };

	/*auto start = high_resolution_clock::now();
	Set testTwo = { Point(1,2,3),Point(2,3,5) };
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << std::endl;*/

	auto test = [](const Point& a)
	{
		return a.getX() == 5 && a.getY() == 6 && a.getZ() == 7;
	};

	testTwo.remove(test);

	auto edit = [](Point& a)
	{
		a.setX(10);
	};
  
	std::cout << "Prije promjene: " << std::endl;
	testTwo.display();
	testTwo.forEach(edit);

	std::cout << "Nakon promjene: " << std::endl;
	testTwo.display();

	testTwo.forEach([](Point& a) {++a; });
	testTwo.display();


	return 0;

}

