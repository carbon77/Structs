#include "VectorTask.h"

struct Point
{
	int x;
	int y;
};

Point& getPoint()
{
	int x, y;
	std::cin >> x >> y;
	Point p = { x, y };
	return p;
}

bool isParallel(Point a, Point b, Point c, Point d)
{
	// a/b = c/d <=> ad = bc
	int ad = (b.x - a.x) * (d.y - c.y);
	int bc = (d.x - c.x) * (b.y - a.y);
	return ad == bc;
}

bool isParallelogram(Point A, Point B, Point C, Point D)
{
	return (isParallel(A, B, C, D) && isParallel(B, C, A, D)) ||
		(isParallel(A, B, C, D) && isParallel(A, C, B, D)) ||
		(isParallel(B, C, A, D) && isParallel(A, C, B, D));
}

void vectorTask()
{
	std::cout << "Enter point d: ";
	Point d = getPoint();
	
	int count;
	std::cout << "Enter count of points: ";
	std::cin >> count;

	std::vector<Point> pts;
	std::vector<std::array<Point, 3>> correct;
	for (int i = 0; i < count; i++)
	{
		std::cout << i + 1 << " -> ";
		Point p = getPoint();
		pts.push_back(p);
	}

	for (int i = 0; i < pts.size(); i++)
	{
		for (int j = i + 1; j < pts.size(); j++)
		{
			for (int k = j + 1; k < pts.size(); k++)
			{
				Point a = pts.at(i); 
				Point b = pts.at(j);
				Point c = pts.at(k);

				if (isParallelogram(a, b, c, d))
				{
					std::array<Point, 3> s = { a, b, c };
					correct.push_back(s);
				}
			}
		}
	}

	std::cout << "All points that are a parallelogram with point d: ";
	for (std::array<Point, 3>& s : correct)
	{
		std::cout << std::endl;
		std::cout << "(" << d.x << ", " << d.y << ") ";
		for (Point& p : s) {
			std::cout << "(" << p.x << ", " << p.y << ") ";
		}
	}
}
