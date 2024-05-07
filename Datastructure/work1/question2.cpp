/*
设计思想：
要求出两个数组合并后的中位数，可以转求各个数组的中位数，合并后的中位数必定在这两个数中间。记数组1的中位数为A，数组2的中位数为B，可分为以下三种情况：
1.若A>B，则要求的中位数在数组A的左半部分或数组B的右半部分
2.若A=B，A，B即为中位数
3.若A<B，则要求的中位数在数组A的右半部分或数组B的左半部分
将两个数组取中位数可能存在的那一半，重复上述步骤，直到某个数组无法取左半或右半为止。
*/
#include <iostream>
#include <vector>
template <typename T>
int find_mid(T& A)
{
    if(A.size() % 2 == 0)
        return A.size()/2 - 1;
    else
        return A.size()/2;
}
template <typename T>
bool left(T& A) // 取数组A中小于中位数的部分
{
    if(A.size()==2 || A.size()==1)
        return false;
    else
    {
        A.erase(A.end() - A.size() / 2, A.end());
        return true;
    }
}
template <typename T>
bool right(T& A) // 取大于中位数的部分
{
    if (A.size() == 1)
        return false;
    else
    {
        A.erase(A.begin(), A.begin() + find_mid(A));
        return true;
    }
}

int main(){
    int L; // the number of array is L
    std::cin >> L;
    std::vector<int> A;
    std::vector<int> B;
    int num, answer;
    for (int i = 0; i < L; i++)
    {
        std::cin >> num;
        A.push_back(num);
    }
    for (int i = 0; i < L; i++)
    {
        std::cin >> num;
        B.push_back(num);
    }
    while(true)
    {
        if(A[find_mid(A)] == B[find_mid(B)])
        {
            std::cout << A[find_mid(A)] << std::endl;
            break;
        }
        else if(A[find_mid(A)] < B[find_mid(B)])    // 如果A的中位数小于B的，则A取右半，B取左半
        {
            bool boolA = right(A);
            bool boolB = left(B);
            if(boolA == false && boolB == false)
            {
                answer = A[0]<B[0] ? A[0] : B[0];
                break;
            }
            else if(boolA == false)
            {
                answer = A[0];
                break;
            }
            else if(boolB == false)
            {
                answer = B[0];
                break;
            }
        }
        else
        {
            bool boolA = left(A);
            bool boolB = right(B);
            if (boolA == false && boolB == false)
            {
                answer = A[0] < B[0] ? A[0] : B[0];
                break;
            }
            else if (boolA == false)
            {
                answer = A[0];
                break;
            }
            else if (boolB == false)
            {
                answer = B[0];
                break;
            }
        }
    }
    std::cout << answer << std::endl;
    return 0;
}
/*
若忽略输入数组、模板函数造成的时间复杂度，仅考虑算法的时间复杂度，由于每次循环将数组A，B进行对半分割操作，算法的时间复杂度为O(log2n)。
由于数组只需要常数级别的内存，空间复杂度为O(1)。
*/
