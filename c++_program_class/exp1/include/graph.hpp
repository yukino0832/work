#include <iostream>
#include <algorithm>
#include <cmath>
#include <GLFW/glfw3.h>

class Point
{
public:
    double x, y;
    static int Point_count;
    Point()
    {
        Point_count++;
    }
    Point(double x, double y) : x(x), y(y)
    {
        Point_count++;
    }
    Point(const Point &other) : x(other.x), y(other.y) // 拷贝构造函数
    {
        Point_count++;
    }
    ~Point()
    {
        Point_count--;
    }
    void translate(double dx, double dy)
    {
        x += dx;
        y += dy;
    }
    void rotate(const Point &rotate_center, double angle) // 绕任意旋转中心逆时针旋转angle度
    {
        double dx = x - rotate_center.x;
        double dy = y - rotate_center.y;

        double radius = sqrt(dx * dx + dy * dy);
        double initial_angle = atan2(dy, dx);

        double radian = angle * M_PI / 180.0;
        double new_angle = initial_angle + radian;

        x = rotate_center.x + radius * cos(new_angle);
        y = rotate_center.y + radius * sin(new_angle);
    }
    void mirror(const Point &mirror_center) // 以任意点为中心进行镜像
    {
        x = 2 * mirror_center.x - x;
        y = 2 * mirror_center.y - y;
    }
    void scale(const Point &scale_center, double factor) // 沿图像中心缩放
    {
        x = scale_center.x + (x - scale_center.x) * factor;
        y = scale_center.y + (y - scale_center.y) * factor;
    }
    Point operator+(const Point &other) const
    {
        return Point(x + other.x, y + other.y);
    }
    Point operator/(double n) const
    {
        return Point(x / n, y / n);
    }
};

class Line
{
public:
    Point start_Point, end_Point;
    static int Line_count;
    Line(Point start, Point end) : start_Point(start), end_Point(end)
    {
        Line_count++;
    }
    Line(const Line &other) : Line(other.start_Point, other.end_Point)
    {
        Line_count++;
    }
    ~Line()
    {
        Line_count--;
    }
    double getLength_Line()
    {
        return pow(pow(start_Point.x - end_Point.x, 2) + pow(start_Point.y - end_Point.y, 2), 0.5);
    }
    void translate_Line(double dx, double dy) // 平移
    {
        start_Point.translate(dx, dy);
        end_Point.translate(dx, dy);
    }
    void rotate_Line(const Point &r_center, double angle) // 绕任意旋转中心逆时针旋转angle度
    {
        start_Point.rotate(r_center, angle);
        end_Point.rotate(r_center, angle);
    }
    void mirror_Line(const Point &m_center) // 绕任意镜像中心镜像
    {
        start_Point.mirror(m_center);
        end_Point.mirror(m_center);
    }
    void scale_Line(double factor) // 缩放factor倍
    {
        Point center = (start_Point + end_Point) / 2;
        start_Point.scale(center, factor);
        end_Point.scale(center, factor);
    }
};

class Circle
{
public:
    Point Circle_center;
    double radius;
    static int Circle_count;
    Circle(Point center, double r) : Circle_center(center), radius(r)
    {
        Circle_count++;
    }
    Circle(const Circle &other) : Circle(other.Circle_center, other.radius)
    {
        Circle_count++;
    }
    ~Circle()
    {
        Circle_count--;
    }
    double getCircle_perimeter() // 计算周长
    {
        return M_PI * 2 * radius;
    }
    double getCircle_area() // 计算面积
    {
        return M_PI * pow(radius, 2);
    }
    void translate_Circle(double dx, double dy) // 平移
    {
        Circle_center.translate(dx, dy);
    }
    void rotate_Circle(const Point &r_center, double angle)
    {
        Circle_center.rotate(r_center, angle);
    }
    void mirror_Circle(const Point &m_center)
    {
        Circle_center.mirror(m_center);
    }
    void scale_Circle(double factor)
    {
        radius = factor * radius;
    }
};

class Rectangle
{
private:
    // 对Rect的顶点进行排序，使其按左下角、左上角、右上角、右下角的顺序，并保证Rect[0],Rect[1]的x < Rect[2],Rect[3]的x
    void sortRectanglePoints(Point rect[4])
    {
        std::sort(rect, rect + 4, [](const Point &p1, const Point &p2)
                  { return p1.x < p2.x; });
        if (rect[0].y > rect[1].y)
            std::swap(rect[0], rect[1]);
        if (rect[2].y < rect[3].y)
            std::swap(rect[2], rect[3]);
    }

    bool isRectangle() // 判断是否是矩形
    {
        double d01 = Line(Rect[0], Rect[1]).getLength_Line();
        double d12 = Line(Rect[1], Rect[2]).getLength_Line();
        double d23 = Line(Rect[2], Rect[3]).getLength_Line();
        double d30 = Line(Rect[3], Rect[0]).getLength_Line();
        double d02 = Line(Rect[0], Rect[2]).getLength_Line();
        double d13 = Line(Rect[1], Rect[3]).getLength_Line();

        return d01 == d23 && d12 == d30 && d02 == d13;
    }

public:
    Point Rect[4];
    static int Rectangle_count;
    Rectangle(const Point &x1, const Point &x2, const Point &x3, const Point &x4)
    {
        Rect[0] = x1;
        Rect[1] = x2;
        Rect[2] = x3;
        Rect[3] = x4;
        if (!isRectangle())
        {
            throw std::invalid_argument("不是矩形！");
        }
        sortRectanglePoints(Rect);
        Rectangle_count++;
    }
    Rectangle(const Rectangle &other) : Rectangle(other.Rect[0], other.Rect[1], other.Rect[2], other.Rect[3])
    {
        Rectangle_count++;
    }
    ~Rectangle()
    {
        Rectangle_count--;
    }
    double getRectangle_perimeter()
    {
        return 2 * (Line(Rect[0], Rect[1]).getLength_Line() + Line(Rect[1], Rect[2]).getLength_Line());
    }
    double getRectangle_area()
    {
        return Line(Rect[0], Rect[1]).getLength_Line() * Line(Rect[1], Rect[2]).getLength_Line();
    }
    void translate_Rectangle(double dx, double dy)
    {
        Rect[0].translate(dx, dy);
        Rect[1].translate(dx, dy);
        Rect[2].translate(dx, dy);
        Rect[3].translate(dx, dy);
    }
    void rotate_Rectangle(const Point &r_center, double angle)
    {
        Rect[0].rotate(r_center, angle);
        Rect[1].rotate(r_center, angle);
        Rect[2].rotate(r_center, angle);
        Rect[3].rotate(r_center, angle);
        sortRectanglePoints(Rect);
    }
    void mirror_Rectangle(const Point &m_center)
    {
        Rect[0].mirror(m_center);
        Rect[1].mirror(m_center);
        Rect[2].mirror(m_center);
        Rect[3].mirror(m_center);
        sortRectanglePoints(Rect);
    }
    void scale_Rectangle(double factor)
    {
        Point center = (Rect[0] + Rect[2]) / 2;
        Rect[0].scale(center, factor);
        Rect[1].scale(center, factor);
        Rect[2].scale(center, factor);
        Rect[3].scale(center, factor);
    }
};

class Triangle
{
public:
    Point Tri[3];
    static int Triangle_count;
    Triangle(const Point &x1, const Point &x2, const Point &x3)
    {
        Tri[0] = x1;
        Tri[1] = x2;
        Tri[2] = x3;
        Triangle_count++;
    }
    Triangle(const Triangle &other) : Triangle(other.Tri[0], other.Tri[1], other.Tri[2])
    {
        Triangle_count++;
    }
    ~Triangle()
    {
        Triangle_count--;
    }
    double getTriangle_perimeter()
    {
        return Line(Tri[0], Tri[1]).getLength_Line() + Line(Tri[1], Tri[2]).getLength_Line() + Line(Tri[2], Tri[0]).getLength_Line();
    }
    double getTriangle_area()
    {
        double p = this->getTriangle_perimeter() / 2;
        return pow(p * fabs(p - Line(Tri[0], Tri[1]).getLength_Line()) * fabs(p - Line(Tri[1], Tri[2]).getLength_Line()) * fabs(p - Line(Tri[2], Tri[0]).getLength_Line()), 0.5);
    }
    void translate_Triangle(double dx, double dy)
    {
        Tri[0].translate(dx, dy);
        Tri[1].translate(dx, dy);
        Tri[2].translate(dx, dy);
    }
    void rotate_Triangle(const Point &r_center, double angle)
    {
        Tri[0].rotate(r_center, angle);
        Tri[1].rotate(r_center, angle);
        Tri[2].rotate(r_center, angle);
    }
    void mirror_Triangle(const Point &m_center)
    {
        Tri[0].mirror(m_center);
        Tri[1].mirror(m_center);
        Tri[2].mirror(m_center);
    }
    void scale_Triangle(double factor)
    {
        Point center = (Tri[0] + Tri[1] + Tri[2]) / 3;
        Tri[0].scale(center, factor);
        Tri[1].scale(center, factor);
        Tri[2].scale(center, factor);
    }
};

struct Color
{
    float r, g, b;
};

// 绘制点
void drawPoint(const Point &point, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2d(point.x, point.y);
    glEnd();
}

// 绘制线
void drawLine(const Line &line, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2d(line.start_Point.x, line.start_Point.y);
    glVertex2d(line.end_Point.x, line.end_Point.y);
    glEnd();
}

// 绘制圆
void drawCircle(const Circle &circle, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100; i++)
    {
        double angle = 2 * M_PI * i / 100;
        glVertex2d(circle.Circle_center.x + circle.radius * cos(angle),
                   circle.Circle_center.y + circle.radius * sin(angle));
    }
    glEnd();
}

// 绘制矩形
void drawRectangle(const Rectangle &rectangle, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_LINE_LOOP);
    glVertex2d(rectangle.Rect[0].x, rectangle.Rect[0].y);
    glVertex2d(rectangle.Rect[1].x, rectangle.Rect[1].y);
    glVertex2d(rectangle.Rect[2].x, rectangle.Rect[2].y);
    glVertex2d(rectangle.Rect[3].x, rectangle.Rect[3].y);
    glEnd();
}

// 绘制三角形
void drawTriangle(const Triangle &triangle, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_LINE_LOOP);
    glVertex2d(triangle.Tri[0].x, triangle.Tri[0].y);
    glVertex2d(triangle.Tri[1].x, triangle.Tri[1].y);
    glVertex2d(triangle.Tri[2].x, triangle.Tri[2].y);
    glEnd();
}
