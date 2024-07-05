#include <iostream>

int main()
{
    int n;
    std::cout << "请输入想要验证的自然数n:";
    std::cin >> n;
    std::cout << n * n - n + 1;
    for (int i = 1; i < n; i++)
    {
        std::cout << "+" << n * n - n + 1 + i * 2;
    }
    std::cout << "=" << n*n*n << std::endl;
    return 0;
}
