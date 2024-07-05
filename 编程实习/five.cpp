#include <iostream>
int fac(int x)
{
    if(x == 0 || x == 1)
        return 1;
    else
        return fac(x - 1)*x;
}
int main()
{
    int n;
    int answer = 0;
    std::cout << "请输入奇数：" << std::endl;
    std::cin >> n;
    for (int i = 1; i <= n; i += 2)
    {
        answer += fac(n);
    }
    std::cout << answer << std::endl;
    return 0;
}
