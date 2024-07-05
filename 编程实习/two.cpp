#include <iostream>
const int num = 10;
int main()
{
    int arr[num];
    std::cout << "请输入10个整数:" << std::endl;
    for (int i = 0; i < num; i++)
    {
        std::cin >> arr[i];
    }
    
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int exc = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = exc;
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
