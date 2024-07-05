#include <iostream>

int main()
{
    int int_a;
    std::cout << "请输入整数：" << std::endl;
    std::cin >> int_a;
    std::cout << "无符号: " << static_cast<unsigned int>(int_a) << std::endl;
    std::cout << "八进制: " << std::oct << int_a << std::endl;
    std::cout << "十六进制: " << std::hex << int_a<< std::endl;
    return 0;
}
