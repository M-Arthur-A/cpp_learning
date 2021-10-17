#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

/* Не меняя функцию main, реализуйте недостающие функции и классы:
 * базовый класс Figure с чисто виртуальными методами Name, Perimeter и Area;
 * классы Triangle, Rect и Circle, которые являются наследниками класса Figure и переопределяют его виртуальные методы;
 * функцию CreateFigure, которая в зависимости от содержимого входного потока создаёт
 * shared_ptr<Rect>, shared_ptr<Triangle> или shared_ptr<Circle>.
 * Гарантируется, что размеры всех фигур — это натуральные числа не больше 1000. В качестве значения PI используйте 3,14.
 */

class Figure {
public:
	virtual string Name() = 0;
	virtual double Perimeter() = 0;
	virtual double Area() = 0;
};

class Triangle : public Figure {
	unsigned a;
	unsigned b;
	unsigned c;
public:
	Triangle(const unsigned& a_value,
			 const unsigned& b_value,
			 const unsigned& c_value)
			 : a(a_value),
			   b(b_value),
			   c(c_value) {}
	string Name() override {
		return "TRIANGLE";
	}
	double Perimeter() override {
		return a + b + c;
	}
	double Area() override {
		int temp = (a + b + c) / 2;
	    return sqrt( (temp - a) * (temp - b) * ( temp - c) * temp);
	}
};

class Rect : public Figure {
	unsigned width;
	unsigned height;
public:
	Rect(const unsigned& width_value, const unsigned& height_value)
		 : width(width_value), height(height_value) {}
	string Name() override {
		return "RECTANGLE";
	}
	double Perimeter() override {
		return (width + height) * 2;
	}
	double Area() override {
		return width * height;
	}
};

class Circle : public Figure {
	double Pi = 3.14;
	unsigned radius;
public:
	Circle(const unsigned& radius_value) : radius(radius_value) {};
	string Name() override {
		return "CIRCLE";
	}
	double Perimeter() override {
		return 2 * Pi * radius;
	}
	double Area() override {
		return Pi * radius * radius;
	}
};

shared_ptr<Figure> CreateFigure(istream& is_name) {
	string name, values;
	is_name >> name;
	if (name == "TRIANGLE") {
		unsigned a, b, c;
		is_name >> a >> b >> c;
		return make_shared<Triangle>(a, b, c);
	} else if (name == "RECT") {
		unsigned width, height;
		is_name >> width >> height;
		return make_shared<Rect>(width, height);
	} else if (name == "CIRCLE") {
		int radius;
		is_name >> radius;
		return make_shared<Circle>(radius);
	} else { cout << name << " doesn't exists!" << endl; }
}


int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
/* input:
 *       ADD RECT 2 3
 *       ADD TRIANGLE 3 4 5
 *       ADD RECT 10 20
 *       ADD CIRCLE 5
 *       PRINT
 * output
 *       RECT 10.000 6.000
 *       TRIANGLE 12.000 6.000
 *       RECT 60.000 200.000
 *       CIRCLE 31.400 78.500
 */
