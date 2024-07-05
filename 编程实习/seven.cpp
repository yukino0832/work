#include <iostream>
#include <fstream>
int main()
{
    std::string s;
    std::cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] <= 'z' && s[i] >= 'a')
            s[i] -= 32;
    }
    std::ofstream outf;
    outf.open("./data.txt");
    outf << s << std::endl;
    outf.close();
    return 0;
}
