#include <iostream>
const int num = 10;
int main()
{
    double score[num];
    double sum = 0;
    std::cout << "请输入成绩:" << std::endl;
    for(int i = 0; i < num; i++)
    {
        std::cin >> score[i];
        sum += score[i];
    }
    double average = sum / num;
    std::cout << "平均分: " << average << std::endl;
    for(int i = 0; i < num; i++)
    {
        if(average < score[i])
        {
            std::cout << score[i] << " " << std::endl;
        }
    }
    return 0;
}
