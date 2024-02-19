#include <iostream>
#include <string>
//using namespace std;

// Базовый класс Figure
class Figure {
protected:
    int sides_count; // Количество сторон фигуры
    std::string name; // Название фигуры

public:
    // Конструктор для установки количества сторон и названия фигуры
    Figure(int sides = 0, const std::string& name = "Фигура") : sides_count(sides), name(name) {}

    // Метод для получения количества сторон фигуры
    int get_sides_count() const {
        return sides_count;
    }

    // Метод для вывода информации о фигуре
    virtual void print_info() const {
        std::cout << name << ": " << sides_count << std::endl;
    }
};

// Класс Triangle, наследующий класс Figure
class Triangle : public Figure {
public:
    // Конструктор класса Triangle, вызывающий конструктор базового класса с параметром 3
    Triangle() : Figure(3, "Треугольник") {}
};

// Класс Quadrangle, наследующий класс Figure
class Quadrangle : public Figure {
public:
    // Конструктор класса Quadrangle, вызывающий конструктор базового класса с параметром 4
    Quadrangle() : Figure(4, "Четырёхугольник") {}
};

int main() {
    setlocale(LC_ALL, "Russian");

    // Создание экземпляров классов
    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;

    // Вывод заголовка перед информацией о фигурах
    std::cout << "Количество сторон:" << std::endl;

    // Вывод информации о каждой фигуре
    figure.print_info();
    triangle.print_info();
    quadrangle.print_info();

    return 0;
}
