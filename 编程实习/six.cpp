#include <iostream>
struct
{
    int number;
    std::string name;
    std::string gender;
    double score;
} student;
int main()
{
    std::cout << "请依次输入学号、姓名、性别、成绩:" << std::endl;
    std::cin >> student.number >> student.name >> student.gender >> student.score;
    std::cout << "学号：" << student.number << std::endl;
    std::cout << "姓名：" << student.name << std::endl;
    std::cout << "性别：" << student.gender << std::endl;
    std::cout << "成绩：" << student.score << std::endl;
    return 0;
}
