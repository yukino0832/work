#include "../include/graph.hpp"
#include <iostream>

int Point::Point_count = 0;
int Line::Line_count = 0;
int Circle::Circle_count = 0;
int Rectangle::Rectangle_count = 0;
int Triangle::Triangle_count = 0;

int main()
{
    double x_1, x_2, y_1, y_2, x_3, y_3, x_4, y_4, radius, dx, dy, center_x, center_y, angle, factor;
    int cin_shape, cin_operate;

    glfwInit();
    GLFWwindow *window = glfwCreateWindow(800, 800, "Geometric Graphs", nullptr, nullptr);

    glfwMakeContextCurrent(window);
    glOrtho(-10, 10, -10, 10, -1.0, 1.0); // 设置正交投影

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        std::cout << "选择你想要画的图形类型:" << std::endl;
        std::cout << "1.线段 2.圆 3.矩形 4.三角形 0.退出" << std::endl;
        std::cout << "请输入对应数字:" << std::endl;

        std::cin >> cin_shape;

        if (cin_shape == 0)
        {
            std::cout << "已退出" << std::endl;
            break;
        }
        else if (cin_shape == 1)
        {
            std::cout << "请输入4个实数代表起点、终点的x,y值:" << std::endl;
            std::cin >> x_1 >> y_1 >> x_2 >> y_2;
            Line line(Point(x_1, y_1), Point(x_2, y_2));
            std::cout << "已生成线段，颜色:蓝色，长度:" << line.getLength_Line() << std::endl;
            drawLine(line, {0.0f, 0.0f, 1.0f}); // 蓝色
            glfwSwapBuffers(window);
            glfwPollEvents();
            while (true)
            {
                std::cout << "请输入想要进行的操作:1.平移 2.旋转 3.镜像 4.缩放 0.退出" << std::endl;
                std::cin >> cin_operate;
                if (cin_operate == 0)
                {
                    std::cout << "线段数量:" << Line::Line_count << std::endl;
                    break;
                }
                else if (cin_operate == 1)
                {
                    std::cout << "请输入平移距离dx,dy:" << std::endl;
                    std::cin >> dx >> dy;
                    Line line_translate(line);
                    line_translate.translate_Line(dx, dy);
                    std::cout << "已平移线段，颜色:绿色，长度:" << line_translate.getLength_Line() << std::endl;
                    drawLine(line_translate, {0.0f, 1.0f, 0.0f}); // 绿色
                    glfwSwapBuffers(window);
                }
                else if (cin_operate == 2)
                {
                    std::cout << "请输入旋转中心的坐标x,y和旋转角度:" << std::endl;
                    std::cin >> center_x >> center_y >> angle;
                    Line line_rotate(line);
                    line_rotate.rotate_Line(Point(center_x, center_y), angle);
                    std::cout << "已旋转线段，颜色:黄色，长度:" << line_rotate.getLength_Line() << std::endl;
                    drawLine(line_rotate, {1.0f, 1.0f, 0.0f}); // 黄色
                    glfwSwapBuffers(window);
                }
                else if (cin_operate == 3)
                {
                    std::cout << "请输入镜像中心点x,y:" << std::endl;
                    std::cin >> center_x >> center_y;
                    Line line_mirror(line);
                    line_mirror.mirror_Line(Point(center_x, center_y));
                    std::cout << "已镜像线段，颜色:红色，长度:" << line_mirror.getLength_Line() << std::endl;
                    drawLine(line_mirror, {1.0f, 0.0f, 0.0f}); // 红色
                    glfwSwapBuffers(window);
                }
                else if (cin_operate == 4)
                {
                    std::cout << "请输入缩放倍数:" << std::endl;
                    std::cin >> factor;
                    Line line_scale(line);
                    line_scale.scale_Line(factor);
                    std::cout << "已缩放线段，颜色: 白色，长度:" << line_scale.getLength_Line() << std::endl;
                    drawLine(line_scale, {1.0f, 1.0f, 1.0f}); // 白色
                    glfwSwapBuffers(window);
                }
            }
        }
        else if (cin_shape == 2)
        {
            std::cout << "请输入三个实数代表圆心的坐标x,y以及半径" << std::endl;
            std::cin >> x_1 >> y_1 >> radius;
            Circle circle(Point(x_1, y_1), radius);
            std::cout << "已生成圆，颜色:蓝色，周长:" << circle.getCircle_perimeter() << "，面积:" << circle.getCircle_area() << std::endl;
            drawCircle(circle, {0.0f, 0.0f, 1.0f}); // 蓝色
            glfwSwapBuffers(window);
            glfwPollEvents();
            while (true)
            {
                std::cout << "请输入想要进行的操作:1.平移 2.旋转 3.镜像 4.缩放 0.退出" << std::endl;
                std::cin >> cin_operate;
                if (cin_operate == 0)
                {
                    std::cout << "圆数量:" << Circle::Circle_count << std::endl;
                    break;
                }
                else if (cin_operate == 1)
                {
                    std::cout << "请输入平移距离dx,dy:" << std::endl;
                    std::cin >> dx >> dy;
                    Circle circle_translate(circle);
                    circle_translate.translate_Circle(dx, dy);
                    std::cout << "已平移圆，颜色:绿色，周长:" << circle_translate.getCircle_perimeter() << "，面积:" << circle_translate.getCircle_area() << std::endl;
                    drawCircle(circle_translate, {0.0f, 1.0f, 0.0f}); // 绿色
                    glfwSwapBuffers(window);
                }
                else if (cin_operate == 2)
                {
                    std::cout << "请输入旋转中心的坐标x,y和旋转角度:" << std::endl;
                    std::cin >> center_x >> center_y >> angle;
                    Circle circle_rotate(circle);
                    circle_rotate.rotate_Circle(Point(center_x, center_y), angle);
                    std::cout << "已旋转圆，颜色:黄色，周长:" << circle_rotate.getCircle_perimeter() << "，面积:" << circle_rotate.getCircle_area() << std::endl;
                    drawCircle(circle_rotate, {1.0f, 1.0f, 0.0f}); // 黄色
                    glfwSwapBuffers(window);
                }
                else if (cin_operate == 3)
                {
                    std::cout << "请输入镜像中心的坐标x,y:" << std::endl;
                    std::cin >> center_x >> center_y;
                    Circle circle_mirror(circle);
                    circle_mirror.mirror_Circle(Point(center_x, center_y));
                    std::cout << "已镜像圆，颜色:红色，周长:" << circle_mirror.getCircle_perimeter() << "，面积:" << circle_mirror.getCircle_area() << std::endl;
                    drawCircle(circle_mirror, {1.0f, 0.0f, 0.0f}); // 红色
                    glfwSwapBuffers(window);
                }
                else if (cin_operate == 4)
                {
                    std::cout << "请输入缩放倍数:" << std::endl;
                    std::cin >> factor;
                    Circle circle_scale(circle);
                    circle_scale.scale_Circle(factor);
                    std::cout << "已缩放圆，颜色:白色，周长:" << circle_scale.getCircle_perimeter() << "，面积:" << circle_scale.getCircle_area() << std::endl;
                    drawCircle(circle_scale, {1.0f, 1.0f, 1.0f}); // 白色
                    glfwSwapBuffers(window);
                }
            }
        }
        else if (cin_shape == 3)
        {
            std::cout << "请输入8个实数代表矩形4个顶点的x,y:" << std::endl;
            std::cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3 >> x_4 >> y_4;
            Rectangle rectangle(Point(x_1, y_1), Point(x_2, y_2), Point(x_3, y_3), Point(x_4, y_4));
            std::cout << "已生成矩形，颜色:蓝色，周长:" << rectangle.getRectangle_perimeter() << "，面积:" << rectangle.getRectangle_area() << std::endl;
            drawRectangle(rectangle, {0.0f, 0.0f, 1.0f}); // 蓝色
            glfwSwapBuffers(window);
            glfwPollEvents();
            while (true)
            {
                std::cout << "请输入想要进行的操作:1.平移 2.旋转 3.镜像 4.缩放 0.退出" << std::endl;
                std::cin >> cin_operate;
                if (cin_operate == 0)
                {
                    std::cout << "矩形数量:" << Rectangle::Rectangle_count << std::endl;
                    break;
                }
                else if (cin_operate == 1)
                {
                    std::cout << "请输入平移距离dx,dy:" << std::endl;
                    std::cin >> dx >> dy;
                    Rectangle rectangle_translate(rectangle);
                    rectangle_translate.translate_Rectangle(dx, dy);
                    std::cout << "已平移矩形，颜色:绿色，周长:" << rectangle_translate.getRectangle_perimeter() << "，面积:" << rectangle_translate.getRectangle_area() << std::endl;
                    drawRectangle(rectangle_translate, {0.0f, 1.0f, 0.0f}); // 绿色
                    glfwSwapBuffers(window);
                }
                else if (cin_operate == 2)
                {
                    std::cout << "请输入旋转中心的x,y和旋转角度:" << std::endl;
                    std::cin >> center_x >> center_y >> angle;
                    Rectangle rectangle_rotate(rectangle);
                    rectangle_rotate.rotate_Rectangle(Point(center_x, center_y), angle);
                    std::cout << "已旋转矩形，颜色:黄色，周长:" << rectangle_rotate.getRectangle_perimeter() << "，面积:" << rectangle_rotate.getRectangle_area() << std::endl;
                    drawRectangle(rectangle_rotate, {1.0f, 1.0f, 0.0f}); // 黄色
                    glfwSwapBuffers(window);
                }
                else if (cin_operate == 3)
                {
                    std::cout << "请输入镜像中心的x,y:" << std::endl;
                    std::cin >> center_x >> center_y;
                    Rectangle rectangle_mirror(rectangle);
                    rectangle_mirror.mirror_Rectangle(Point(center_x, center_y));
                    std::cout << "已镜像矩形，颜色:红色，周长:" << rectangle_mirror.getRectangle_perimeter() << "，面积:" << rectangle_mirror.getRectangle_area() << std::endl;
                    drawRectangle(rectangle_mirror, {1.0f, 0.0f, 0.0f}); // 红色
                    glfwSwapBuffers(window);
                }
                else if (cin_operate == 4)
                {
                    std::cout << "请输入缩放倍数:" << std::endl;
                    std::cin >> factor;
                    Rectangle rectangle_scale(rectangle);
                    rectangle_scale.scale_Rectangle(factor);
                    std::cout << "已缩放矩形，颜色:白色，周长:" << rectangle_scale.getRectangle_perimeter() << "，面积:" << rectangle_scale.getRectangle_area() << std::endl;
                    drawRectangle(rectangle_scale, {1.0f, 1.0f, 1.0f}); // 白色
                    glfwSwapBuffers(window);
                }
            }
        }
        else if (cin_shape == 4)
        {
            std::cout << "请输入6个实数代表三角形三个顶点的x,y:" << std::endl;
            std::cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;
            Triangle triangle(Point(x_1, y_1), Point(x_2, y_2), Point(x_3, y_3));
            std::cout << "已生成三角形，颜色:蓝色，周长:" << triangle.getTriangle_perimeter() << "，面积:" << triangle.getTriangle_area() << std::endl;
            drawTriangle(triangle, {0.0f, 0.0f, 1.0f}); // 蓝色
            glfwSwapBuffers(window);
            glfwPollEvents();
            while (true)
            {
                std::cout << "请输入想要进行的操作:1.平移 2.旋转 3.镜像 4.缩放 0.退出" << std::endl;
                std::cin >> cin_operate;
                if (cin_operate == 0)
                {
                    std::cout << "三角形数量:" << Triangle::Triangle_count << std::endl;
                    break;
                }
                else if (cin_operate == 1)
                {
                    std::cout << "请输入平移距离dx,dy:" << std::endl;
                    std::cin >> dx >> dy;
                    Triangle triangle_translate(triangle);
                    triangle_translate.translate_Triangle(dx, dy);
                    std::cout << "已平移三角形，颜色:绿色，周长:" << triangle_translate.getTriangle_perimeter() << "，面积:" << triangle_translate.getTriangle_area() << std::endl;
                    drawTriangle(triangle_translate, {0.0f, 1.0f, 0.0f}); // 绿色
                    glfwSwapBuffers(window);
                }
                else if (cin_operate == 2)
                {
                    std::cout << "请输入旋转中心的坐标x,y和旋转角度:" << std::endl;
                    std::cin >> center_x >> center_y >> angle;
                    Triangle triangle_rotate(triangle);
                    triangle_rotate.rotate_Triangle(Point(center_x, center_y), angle);
                    std::cout << "已旋转三角形，颜色:黄色，周长:" << triangle_rotate.getTriangle_perimeter() << "，面积:" << triangle_rotate.getTriangle_area() << std::endl;
                    drawTriangle(triangle_rotate, {1.0f, 1.0f, 0.0f}); // 黄色
                    glfwSwapBuffers(window);
                }
                else if (cin_operate == 3)
                {
                    std::cout << "请输入镜像中心的坐标x,y:" << std::endl;
                    std::cin >> center_x >> center_y;
                    Triangle triangle_mirror(triangle);
                    triangle_mirror.mirror_Triangle(Point(center_x, center_y));
                    std::cout << "已镜像三角形，颜色:红色，周长:" << triangle_mirror.getTriangle_perimeter() << "，面积:" << triangle_mirror.getTriangle_area() << std::endl;
                    drawTriangle(triangle_mirror, {1.0f, 0.0f, 0.0f}); // 红色
                    glfwSwapBuffers(window);
                }
                else if (cin_operate == 4)
                {
                    std::cout << "请输入缩放倍数:" << std::endl;
                    std::cin >> factor;
                    Triangle triangle_scale(triangle);
                    triangle_scale.scale_Triangle(factor);
                    std::cout << "已缩放三角形，颜色:白色，周长:" << triangle_scale.getTriangle_perimeter() << "，面积:" << triangle_scale.getTriangle_area() << std::endl;
                    drawTriangle(triangle_scale, {1.0f, 1.0f, 1.0f}); // 白色
                    glfwSwapBuffers(window);
                }
            }
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
