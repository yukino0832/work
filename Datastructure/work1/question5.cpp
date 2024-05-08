/*
采用string类存储字符串，使用left，right两个指针从左右两端往中间比较，若不相等则返回false，直到比到中间则返回true
*/
#include <iostream>
#include <string>
template<typename T>
bool compare(T s)
{
    int left = 0;
    int right = s.length() - 1;
    while(left < right)
    {
        if(s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
int main(){
    std::string s;
    std::cin >> s;
    std::cout << (compare(s) ? "yes" : "no") << std::endl;
    return 0;
}
