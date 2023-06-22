#include<iostream>
#include<vector>
#include<string>

class Point {
	double x;
	double y;
	int NOD(int tmpX, int tmpY)
	{
		int nod = 1;
		if (x > y)
			std::swap(tmpX, tmpY);
		for (int i = 1; i <= tmpX; i++)
		{
			if (tmpX % i == 0 && tmpY % i == 0)
				nod = i;
		}
		return nod;
	}
public:
	Point() {
		x = 0.0;
		y = 0.0;
		std::cout << "Конструктор по умолчанию\n";
	}
	Point(double x, double y) {
		this->x = x;
		this->y = y;
		std::cout << "Конструктор с параметрами\n";
	}
	Point(const Point& other) {
		this->x = other.x;
		this->y = other.y;
		std::cout << "Конструктор копирования\n";
	}

	int Integer() {
		int tmpX = x;
		int tmpY = y;
		int nod = NOD(tmpX, tmpY);
		tmpX /= nod;
		tmpY /= nod;
		std::cout << tmpX << '/' << tmpY << ' ';
		return tmpX / tmpY;
	}

	

	Point& operator =(const Point&other) {
		this->x = other.x;
		this->y = other.y;
		std::cout << "Войдовское присваивание!!!\n";
		return *this;
	}
	Point operator+(const Point& other) {
		return Point(this->x + other.x, this->y + other.y);
	}
	Point operator-(const Point& other) {
		return Point(this->x - other.x, this->y - other.y);
	}
	bool operator ==(const Point& other) {
		return this->x == other.x && this->y == other.y;
	}
	bool operator !=(const Point& other) {
		return this->x != other.x || this->y != other.y;
	}
	
};

int main() {
	setlocale(LC_ALL, "ru");

	Point A;
	Point B(1.1,3.0);
	Point C(A);
	A = B;
	Point A1(30,20 );
	std::cout<<A1.Integer();
	
	return 0;
}