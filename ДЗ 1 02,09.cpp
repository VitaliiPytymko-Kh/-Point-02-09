// ДЗ Point 02,09.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Создайте вектор для хранения элементов типа Point. Сохраните в этом векторе 5 элементов типа Point.
//Выведите элементы сохраненного вектора на экран.

#include <iostream>
#include <vector>
#include <List>
#include <set>


template <typename T>
class Point {
public:
	T X;
	T Y;

	Point() : X(0), Y(0) {}

	Point(T x, T y) : X(x), Y(y) {}
	// Перегрузка оператора <<
	friend std::ostream& operator<<(std::ostream& out, const Point& point) {
		out << "(" << point.X << ", " << point.Y << ")";
		return out;
	}
	// Оператор сравнения для множества (сравниваем по значениям X и Y)
	bool operator<(const Point& other) const {
		if (X == other.X) {
			return Y < other.Y;
		}
		return X < other.X;
	}
};

int main() {
	setlocale(LC_ALL, "");


	std::vector<Point<int>> pointsV;
	pointsV.push_back(Point<int>(3, 7));
	pointsV.push_back(Point<int>(2, 2));
	pointsV.push_back(Point<int>(4, 5));
	pointsV.push_back(Point<int>(1, 6));
	pointsV.push_back(Point<int>(1, 3));

	std::cout << "Vector Point " << std::endl;
	for (const Point<int>& point : pointsV) {
		std::cout << "V Point: " << point << std::endl;
	}

	std::list<Point<int>> pointsL;

	pointsL.push_back(Point<int>(11, 7));
	pointsL.push_back(Point<int>(22, 2));
	pointsL.push_back(Point<int>(44, 5));
	pointsL.push_back(Point<int>(55, 6));
	pointsL.push_back(Point<int>(66, 3));
	std::cout << "List Point " << std::endl;
	for (const Point<int>& point : pointsL) {
		std::cout << "L Point: " << point << std::endl;
	}

	std::set<Point<int>> pointsS;
	pointsS.insert(Point<int>(1, 2));
	pointsS.insert(Point<int>(3, 4));
	pointsS.insert(Point<int>(2, 2));
	pointsS.insert(Point<int>(4, 5));
	pointsS.insert(Point<int>(1, 2)); // Дубликат, не будет добавлен
	std::cout << "Set Point " << std::endl;
	for (const Point<int>& point : pointsS) {
		std::cout << "S Point: " << point << std::endl;
	}
	// Поиск элемента
	Point<int> searchPoint(3, 4);
	auto found = pointsS.find(searchPoint);
	// Проверка нашли ли элемент
	if (found != pointsS.end()) {
		std::cout << "Элемент  найден: " << *found << std::endl;
	}
	else {
		std::cout << "Элемент " << searchPoint << " не найден." << std::endl;
	}


	return 0;

}