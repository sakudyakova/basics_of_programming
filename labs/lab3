#include <iostream>
#include <cmath>

// Абстрактный класс "Точка"
class Point {
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual void move(int dx, int dy) = 0;
    virtual ~Point() {}
};

// Класс "Линия"
class Line : public Point {
protected:
    int x1, y1, x2, y2;
public:
    Line(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    void draw() override {
        std::cout << "Drawing Line from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << std::endl;
    }
    void erase() override {
        std::cout << "Erasing Line from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << std::endl;
    }
    void move(int dx, int dy) override {
        x1 += dx;
        y1 += dy;
        x2 += dx;
        y2 += dy;
    }
};

// Класс "Прямоугольник"
class Rectangle : public Point {
protected:
    int x, y, width, height;
public:
    Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
    void draw() override {
        std::cout << "Drawing Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << std::endl;
    }
    void erase() override {
        std::cout << "Erasing Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << std::endl;
    }
    void move(int dx, int dy) override {
        x += dx;
        y += dy;
    }
};

// Класс "Квадрат"
class Square : public Rectangle {
public:
    Square(int x, int y, int side) : Rectangle(x, y, side, side) {}
    void draw() override {
        std::cout << "Drawing Square at (" << x << ", " << y << ") with side " << width << std::endl;
    }
    void erase() override {
        std::cout << "Erasing Square at (" << x << ", " << y << ") with side " << width << std::endl;
    }
};

// Класс "Параллелограмм"
class Parallelogram : public Square {
public:
    Parallelogram(int x, int y, int side) : Square(x, y, side) {}
};

int main() {
    Line line(0, 0, 10, 10);
    line.draw();
    
    Rectangle rectangle(10, 10, 20, 10);
    rectangle.draw();

    Square square(20, 20, 30);
    square.draw();

    line.erase();
    rectangle.erase();
    square.erase();

    rectangle.move(5, 0); // Перемещение прямоугольника на (5, 0)
    rectangle.draw();
    
    Parallelogram parallelogram(30, 30, 40); // Создание параллелограмма
    parallelogram.draw();
    
    Point* shape = new Square(40, 40, 50); // Позднее связывание для методов геометрических объектов
    shape->draw();
    
    delete shape;

    return 0;
}
