#include <iostream>
int judge(int a)
{
    for (int i = 2; i <= a / 2; i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    for (int i = 3; i <= 100;i++)
    {
        if(judge(i))
            std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
