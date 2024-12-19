#include "../include/graph.hpp"
#include <iostream>

int main()
{
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(800, 800, "Graphs", nullptr, nullptr);

    glfwMakeContextCurrent(window);
    glOrtho(-10, 10, -10, 10, -1.0, 1.0); // 设置正交投影

    int cin_shape;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        std::cout << "选择你想要画的图形类型:" << std::endl;
        std::cout << "1.圆 2.正三角形 3.平行四边形 4.正方形 5.正六边形 0.退出" << std::endl;
        std::cout << "请输入对应数字:" << std::endl;

        std::cin >> cin_shape;

        if (cin_shape == 0)
        {
            std::cout << "已退出" << std::endl;
            break;
        }
        else if (cin_shape == 1)
        {
            std::cout << "请输入圆的半径:" << std::endl;
            double r;
            std::cin >> r;
            Circle circle(r);
            circle.draw();
            std::cout << "周长:" << circle.perimeter() << " 面积:" << circle.area() << std::endl;
        }
        else if (cin_shape == 2)
        {
            std::cout << "请输入正三角形的边长:" << std::endl;
            double side;
            std::cin >> side;
            Triangle triangle(side);
            triangle.draw();
            std::cout << "周长:" << triangle.perimeter() << " 面积:" << triangle.area() << std::endl;
        }
        else if (cin_shape == 3)
        {
            std::cout << "请输入平行四边形的底 高 两边的夹角:" << std::endl;
            double base, height, angle;
            std::cin >> base >> height >> angle;
            Parallelogram parallelogram(base, height, angle);
            parallelogram.draw();
            std::cout << "周长:" << parallelogram.perimeter() << " 面积:" << parallelogram.area() << std::endl;
        }
        else if (cin_shape == 4)
        {
            std::cout << "请输入正方形的边长:" << std::endl;
            double side;
            std::cin >> side;
            Square square(side);
            square.draw();
            std::cout << "周长:" << square.perimeter() << " 面积:" << square.area() << std::endl;
        }
        else if (cin_shape == 5)
        {
            std::cout << "请输入正六边形的半径:" << std::endl;
            double side;
            std::cin >> side;
            Hexagon hexagon(side);
            hexagon.draw();
            std::cout << "周长:" << hexagon.perimeter() << " 面积:" << hexagon.area() << std::endl;
        }
        glfwSwapBuffers(window);
    }

    return 0;
}