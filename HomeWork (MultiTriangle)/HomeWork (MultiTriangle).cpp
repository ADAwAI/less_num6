#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
//using namespace std;

// Базовый класс Figure
class Figure {
public:
    // Чистая виртуальная функция для вывода информации о фигуре
    virtual void print_info() const = 0;
    virtual ~Figure() = default;
};

// Класс Triangle, наследующий класс Figure
class Triangle : public Figure {
protected:
    double a, b, c; // Длины сторон
    double A, B, C; // Величины углов

public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {}

    void print_info() const override {
        std::cout << "Треугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b)
        : Triangle(a, b, std::sqrt(a* a + b * b), 0, 0, 90) {
        // Углы A и B можно вычислить исходя из сторон a и b
        A = std::atan(b / a) * (180 / M_PI);
        B = 90 - A;
    }

    void print_info() const override {
        std::cout << "Прямоугольный треугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=90\n";
    }
};

// Класс IsoscelesTriangle, наследующий класс Triangle
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b)
        : Triangle(a, b, a, 0, 0, 0) {
        // Угол B можно вычислить исходя из сторон a и b
        B = std::acos((2 * a * a - b * b) / (2 * a * a)) * (180 / M_PI);
        A = (180 - B) / 2;
        C = A;
    }

    void print_info() const override {
        std::cout << "Равнобедренный треугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << a << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << A << "\n";
    }
};

// Класс EquilateralTriangle, наследующий класс Triangle
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60) {}

    void print_info() const override {
        std::cout << "Равносторонний треугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=60 B=60 C=60\n";
    }
};

// Класс Quadrilateral, наследующий класс Figure
class Quadrilateral : public Figure {
protected:
    double a, b, c, d; // Длины сторон
    double A, B, C, D; // Величины углов

public:
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    void print_info() const override {
        std::cout << "Четырёхугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }
};

// Класс Rectangle, наследующий класс Quadrilateral
class Rectangle : public Quadrilateral {
public:
    Rectangle(double a, double b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {}

    void print_info() const override {
        std::cout << "Прямоугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=90 B=90 C=90 D=90\n";
    }
};

// Класс Square, наследующий класс Quadrilateral
class Square : public Quadrilateral {
public:
    Square(double side)
        : Quadrilateral(side, side, side, side, 90, 90, 90, 90) {}

    void print_info() const override {
        std::cout << "Квадрат:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=90 B=90 C=90 D=90\n";
    }
};

// Класс Parallelogram, наследующий класс Quadrilateral
class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {}

    void print_info() const override {
        std::cout << "Параллелограмм:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << A << " D=" << B << "\n";
    }
};

// Класс Rhombus, наследующий класс Quadrilateral
class Rhombus : public Quadrilateral {
public:
    Rhombus(double side, double A, double B)
        : Quadrilateral(side, side, side, side, A, B, A, B) {}

    void print_info() const override {
        std::cout << "Ромб:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << A << " D=" << B << "\n";
    }
};

// Функция main
int main() {
    setlocale(LC_ALL, "Russian");

    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle rightTriangle(10, 20);
    IsoscelesTriangle isoscelesTriangle(10, 20);
    EquilateralTriangle equilateralTriangle(30);
    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    std::vector<Figure*> figures = { &triangle, &rightTriangle, &isoscelesTriangle, &equilateralTriangle, &quadrilateral, &rectangle, &square, &parallelogram, &rhombus };

    for (const Figure* fig : figures) {
        fig->print_info();
        std::cout << std::endl;
    }

    return 0;
}
