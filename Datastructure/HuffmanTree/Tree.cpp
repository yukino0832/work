#include <iostream>
#include "hftree.hpp"
#define INPUT_MAX 100

int main(){

    std::string input_s[INPUT_MAX];  // 最大可输入100组数据
    std::string s;
    int m = 0;
    
    std::cout << "请输入数据,0表示退出:" << std::endl;

    while(true)
    {
        std::cin >> s;
        if(s == "0")
            break;
        input_s[m++] = s;
    }
    
    std::cout << "以下为输出:" << std::endl;

    for(int i = 0; i < m; i++)
    {
        int n = 0;
        int arr[26] = {0};
        s = input_s[i];
        for(int i = 0; i < s.length(); i++)
        {
            arr[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < 26; i++)
        {
            if(arr[i] != 0)
            {
                n += 1;
            }
        }
        int node[n][2];
        int N = 0;
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] != 0)
            {
                node[N][0] = i;
                node[N][1] = arr[i];
                N += 1;
            }
        }
        for(int i = 0; i < n; i++)
        {
            std::cout << char('a' + node[i][0]) << ':' << node[i][1] << ' ';
        }
        std::cout << std::endl;
        create_tree Tree(node, n);
        Tree.printHT(n);
        Tree.printcode(s, n);
    }

    return 0;

}
