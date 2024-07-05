#include <iostream>

int main()
{
    int n = 0;
    while (true)
    {
        if (n % 2 == 1 &&
            n % 3 == 2 &&
            n % 5 == 4 &&
            n % 6 == 5 &&
            n % 7 == 0)
        {
            break;
        }
        n++;
    }
    std::cout << "阶梯数为:" << n << std::endl;
    return 0;
}
