#include <iostream>
const int people_num = 5;
struct
{
    std::string name;
    int num;
} people[people_num];
int main()
{
    std::cout << "请输入候选人名字及票数：" << std::endl;
    for (int i = 0; i < people_num; i++)
    {
        std::cin >> people[i].name >> people[i].num;
    }
    for (int i = 0; i < people_num; i++)
    {
        std::cout << people[i].name << ":" << people[i].num << std::endl;
    }
    return 0;
}
