#include <iostream>
const double PI = 3.14;
int main()
{
    int k;
    double r;
    std::cin >> r >> k;
    double S = PI * r * r;
    double C = 2 * PI * r;
    if (k == 1)
        std::cout << "面积:" << S << std::endl;
    else if (k == 2)
        std::cout << "周长:" << C << std::endl;
    else if(k == 3)
        std::cout << "周长:" << C << " " << "面积:" << S << std::endl;
    return 0;
}
