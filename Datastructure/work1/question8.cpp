/*
首先可以知道未出现的最小正整数小于等于n+1。定义一个长度为n，值都为-1的数组，遍历原数组并将每个正整数放在新数组下标为其值减一处，若其值小于0或大于数组长度则略过。然后遍历新数组，直到碰到值不等于下标加一的位置为止，答案为下标加一；若都相等，则答案为数组长度加一。
*/
#include <iostream>
int main(){
    int n;
    std::cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        std::cin >> a[i];
    }
    int b[n] = {0};
    for(int i=0; i<n; i++)
    {
        if(a[i]>0 && a[i]<=n)
        {
            b[a[i]-1] = a[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(b[i] != i+1)
        {
            std::cout << i+1 <<std::endl;
            return 0;
        }
    }
    std::cout << n+1 << std::endl;
    return 0;
}
// 时间复杂度为O(n),空间复杂度为O(1)。
