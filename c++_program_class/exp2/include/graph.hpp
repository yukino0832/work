#include <iostream>
#include <cmath>
#include <algorithm>
#include <GLFW/glfw3.h>

enum class graph_type
{
    POINT,
    LINE,
    CIRCLE,
    TRIANGLE,
    PARALLELOGRAM,
    RECTANGLE,
    HEXAGON
};

struct Color
{
    float r, g, b;
};

// 基类
class Shape
{
public:
    Shape(const graph_type &name) : name(name) {}

    virtual ~Shape() {}

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void draw() const = 0;

private:
    graph_type name;
};

class Circle : public Shape
{
public:
    Circle(double radius) : Shape(graph_type::CIRCLE), radius(radius) {}

    double area() const override
    {
        return M_PI * radius * radius;
    }

    double perimeter() const override
    {
        return 2 * M_PI * radius;
    }

    void draw() const override
    {
        std::cout << "Circle radius:" << radius << std::endl;
        Color color{0.0f, 0.0f, 1.0f}; // 蓝色
        glColor3f(color.r, color.g, color.b);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 100; i++)
        {
            double angle = 2 * M_PI * i / 100;
            glVertex2d(radius * cos(angle),
                       radius * sin(angle));
        }
        glEnd();
    }

private:
    double radius;
};

class Triangle : public Shape
{
public:
    Triangle(double side) : Shape(graph_type::TRIANGLE), side(side) {}

    double area() const override
    {
        return (std::sqrt(3) / 4) * side * side;
    }

    double perimeter() const override
    {
        return 3 * side;
    }

    void draw() const override
    {
        std::cout << "Triangle side:" << side << std::endl;
        std::vector<std::vector<double>> Triangle;
        Triangle.push_back({0, side / std::sqrt(3)});
        Triangle.push_back({-side / 2, -side / (2 * std::sqrt(3))});
        Triangle.push_back({side / 2, -side / (2 * std::sqrt(3))});
        Color color{1.0f, 1.0f, 1.0f}; // 白色
        glColor3f(color.r, color.g, color.b);
        glBegin(GL_LINE_LOOP);
        glVertex2d(Triangle[0][0], Triangle[0][1]);
        glVertex2d(Triangle[1][0], Triangle[1][1]);
        glVertex2d(Triangle[2][0], Triangle[2][1]);
        glEnd();
    }

private:
    double side; // 边长
};

class Parallelogram : public Shape
{
public:
    Parallelogram(double base, double height, double angle) : Shape(graph_type::PARALLELOGRAM), base(base), height(height), angle(angle / 180 * M_PI) {}

    double area() const override
    {
        return base * height;
    }

    double perimeter() const override
    {
        return 2 * (base + height / std::sin(angle));
    }

    void draw() const override
    {
        std::cout << "Parallelogram" << std::endl;
        std::vector<std::vector<double>> Parallelogram;
        Parallelogram.push_back({0, 0});
        Parallelogram.push_back({base, 0});
        Parallelogram.push_back({base + height / std::tan(angle), height});
        Parallelogram.push_back({height / std::tan(angle), height});
        Color color{0.0f, 1.0f, 0.0f}; // 绿色
        glColor3f(color.r, color.g, color.b);
        glBegin(GL_LINE_LOOP);
        glVertex2d(Parallelogram[0][0], Parallelogram[0][1]);
        glVertex2d(Parallelogram[1][0], Parallelogram[1][1]);
        glVertex2d(Parallelogram[2][0], Parallelogram[2][1]);
        glVertex2d(Parallelogram[3][0], Parallelogram[3][1]);
        glEnd();
    }

private:
    double base, height, angle; // 底边,高度,两边夹角
};

class Square : public Parallelogram
{
public:
    Square(double side) : Parallelogram(side, side, 90) {}

private:
    double side;
};

class Hexagon : public Shape
{
public:
    Hexagon(double side) : Shape(graph_type::HEXAGON), side(side) {}

    double area() const override
    {
        return (3 * std::sqrt(3) / 2) * side * side;
    }

    double perimeter() const override
    {
        return 6 * side;
    }

    void draw() const override
    {
        std::cout << "Hexagon side:" << side << std::endl;
        std::vector<std::vector<double>> Hexagon;
        Hexagon.push_back({side / 2, side / 2 * std::sqrt(3)});
        Hexagon.push_back({side, 0});
        Hexagon.push_back({side / 2, -side / 2 * std::sqrt(3)});
        Hexagon.push_back({-side / 2, -side / 2 * std::sqrt(3)});
        Hexagon.push_back({-side, 0});
        Hexagon.push_back({-side / 2, side / 2 * std::sqrt(3)});
        Color color{1.0f, 0.0f, 0.0f}; // 红色
        glColor3f(color.r, color.g, color.b);
        glBegin(GL_LINE_LOOP);
        glVertex2d(Hexagon[0][0], Hexagon[0][1]);
        glVertex2d(Hexagon[1][0], Hexagon[1][1]);
        glVertex2d(Hexagon[2][0], Hexagon[2][1]);
        glVertex2d(Hexagon[3][0], Hexagon[3][1]);
        glVertex2d(Hexagon[4][0], Hexagon[4][1]);
        glVertex2d(Hexagon[5][0], Hexagon[5][1]);
        glEnd();
    }

private:
    double side; // 边长
};