#include <iostream>
#include <string>
#include "diagram.hpp"

int find(std::string name, char a)
{
    for(int i=0; i < name.length(); i++)
    {
        if(a == name[i])
            return i;
    }
    return -1;
}

int main()
{
    int m, n;
    while (true)
    {
        std::cout << "请输入：" << std::endl;
        std::cin >> n >> m;
        if (m == 0 && n == 0)
            break;
        std::string name;
        char a, b, c;
        int distance;
        graph dijgraph(n, m);
        getchar();
        for (int i = 0; i < n; i++)
        {
            std::cin >> c;
            name += c;
            getchar();
        }
        for (int i = 0; i < m; i++)
        {
            std::cin >> a;
            getchar();
            std::cin >> b;
            getchar();
            std::cin >> distance;
            getchar();
            dijgraph.append(find(name, a), find(name, b), distance);
        }
        char begin_city, find_city;
        std::cin >> begin_city;
        getchar();
        std::cin >> find_city;
        dijgraph.dijkstra(find(name, begin_city), name);
        std::cout << "以下为输出：" << std::endl;
        dijgraph.print(find(name, find_city));
    }
    return 0;
}
