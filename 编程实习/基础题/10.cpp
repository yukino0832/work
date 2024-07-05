#include <iostream>

int main()
{
    std::cout << "请输入分数(输入-1退出):" << std::endl;
    int score;
    std::cin >> score;
    while(score!=-1)
    {
        if (score < 60)
            std::cout << "E" << std::endl;
        else if(score <=70)
            std::cout << "D" << std::endl;
        else if (score <= 80)
            std::cout << "C" << std::endl;
        else if (score <= 90)
            std::cout << "B" << std::endl;
        else if (score <= 100)
            std::cout << "A" << std::endl;
        std::cin >> score;
    }
    return 0;
}
