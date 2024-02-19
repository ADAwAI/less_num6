#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
//using namespace std;


class Figure {
public:
    virtual void print_info() const = 0;
    virtual bool check() const = 0;
    virtual ~Figure() {}
};

class Triangle : public Figure {
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {}

    void print_info() const override {
        std::cout << "Треугольник:\n";
        std::cout << (check() ? "Правильная\n" : "Неправильная\n");
        std::cout << "Количество сторон: 3\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
    }

    bool check() const override {
        return a + b + c > 0 && A + B + C == 180;
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b)
        : Triangle(a, b, std::sqrt(a* a + b * b), 0, 0, 90) {
        A = std::atan2(b, a) * (180 / M_PI);
        B = 90 - A;
    }
    void print_info() const override {
        std::cout << "Прямоугольный треугольник:\n";
        std::cout << (check() ? "Правильная\n" : "Неправильная\n");
        std::cout << "Количество сторон: 3\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=90\n";
    }
    bool check() const override {
        return Triangle::check() && std::abs(c * c - (a * a + b * b)) < std::numeric_limits<double>::epsilon();
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b)
        : Triangle(a, b, a, 0, 0, 0) {
        double base_angle = std::acos((2 * a * a - b * b) / (2 * a * a)) * (180 / M_PI);
        A = base_angle;
        B = 180 - 2 * base_angle;
        C = base_angle;
    }
    void print_info() const override {
        std::cout << "Равнобедренный треугольник:\n";
        std::cout << (check() ? "Правильная\n" : "Неправильная\n");
        std::cout << "Количество сторон: 3\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << a << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << A << "\n";
    }
    bool check() const override {
        return a == c && A + B + C == 180;
    }
};


class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60) {}

    void print_info() const override {
        std::cout << "Равносторонний треугольник:\n";
        Triangle::print_info();
    }

    bool check() const override {
        return a == b && b == c && A == 60;
    }
};

class Quadrilateral : public Figure {
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    void print_info() const override {
        std::cout << "Четырёхугольник:\n";
        std::cout << (check() ? "Правильная\n" : "Неправильная\n");
        std::cout << "Количество сторон: 4\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }

    bool check() const override {
        return A + B + C + D == 360 && A > 0 && B > 0 && C > 0 && D > 0;
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double a, double b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {}

    void print_info() const override {
        std::cout << "Прямоугольник:\n";
        std::cout << (check() ? "Правильная\n" : "Неправильная\n");
        std::cout << "Количество сторон: 4\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=90 B=90 C=90 D=90\n";
    }

    bool check() const override {
        return Quadrilateral::check() && A == 90;
    }
};

class Square : public Quadrilateral {
public:
    Square(double side)
        : Quadrilateral(side, side, side, side, 90, 90, 90, 90) {}

    void print_info() const override {
        std::cout << "Квадрат:\n";
        Quadrilateral::print_info();
    }

    bool check() const override {
        return Quadrilateral::check() && a == b;
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {}

    void print_info() const override {
        std::cout << "Параллелограмм:\n";
        Quadrilateral::print_info();
    }

    bool check() const override {
        return Quadrilateral::check() && a == c && b == d && A == C && B == D;
    }
};

class Rhombus : public Quadrilateral {
public:
    Rhombus(double side, double A, double B)
        : Quadrilateral(side, side, side, side, A, B, A, B) {}

    void print_info() const override {
        std::cout << "Ромб:\n";
        Quadrilateral::print_info();
    }

    bool check() const override {
        return Quadrilateral::check() && a == b;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<Figure*> figures = {
        new Triangle(10, 20, 30, 50, 60, 70),
        new RightTriangle(10, 20),
        new IsoscelesTriangle(10, 20),
        new EquilateralTriangle(30),
        new Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80),
        new Rectangle(10, 20),
        new Square(20),
        new Parallelogram(20, 30, 30, 40),
        new Rhombus(30, 30, 40)
    };

    for (Figure* fig : figures) {
        fig->print_info();
        std::cout << "\n";
    }

    // Очистка выделенной памяти
    for (Figure* fig : figures) {
        delete fig;
    }

    return 0;
}
