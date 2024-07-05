#include <iostream>

int main()
{
    int number;
    std::cin >> number;
    short position1, position2, position3, position4;
    position1 = number / 1000;
    position2 = number % 1000 / 100;
    position3 = number % 100 / 10;
    position4 = number % 10;
    std::cout << "个:" << position4 << " 十:" << position3 << " 百:" << position2 << " 千:" << position1 << std::endl;
    return 0;
}
