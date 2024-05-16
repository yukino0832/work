#include <iostream>

typedef struct
{
    int weight;
    int value;
    int parent, lchild, rchild;
    std::string code;
} tree;

class create_tree
{
private:
    tree *htp;
public:
    create_tree() {}
    create_tree(int p[][2], int n)      // 构造函数初始化树
    {
        int m = 2 * n - 1;
        htp = new tree[m+1];
        int min1=0, min2=0, pmin1=0, pmin2=0;
        for (int i = 0; i < m; i++)
        {
            htp[i].parent = -1;
            htp[i].lchild = -1;
            htp[i].rchild = -1;
            if (i < n)
            {
                htp[i].value = p[i][0];
                htp[i].weight = p[i][1];
            }
            else
            {
                htp[i].weight = 0;
            }
        }
        for (int i = n; i < m; i++)
        {
            int end = i - 1;
            int k = 0;
            while (htp[k].parent != -1 && k <= end)
            {
                k += 1;
            }
            min1 = htp[k].weight;
            pmin1 = k;
            k++;
            while (htp[k].parent != -1 && k <= end)
            {
                k++;
            }
            if (htp[k].weight < min1) // min2大，min1小
            {
                min2 = min1;
                pmin2 = pmin1;
                min1 = htp[k].weight;
                pmin1 = k;
            }
            else
            {
                min2 = htp[k].weight;
                pmin2 = k;
            }
            for (int j = k + 1; j <= end; j++)
            {
                if (htp[j].parent != -1)
                {
                    continue;
                }

                if (htp[j].weight < min1)
                {
                    min2 = min1;
                    min1 = htp[j].weight;
                    pmin2 = pmin1;
                    pmin1 = j;
                }

                else if (htp[j].weight >= min1 && htp[j].weight < min2)
                {
                    min2 = htp[j].weight;
                    pmin2 = j;
                }
            }
            htp[pmin1].parent = i;
            htp[pmin2].parent = i;
            htp[i].lchild = pmin1;
            htp[i].rchild = pmin2;
            htp[i].weight = min1 + min2;
        }
    }

    ~create_tree() {}

    void printHT(int n)  // 输出HT表
    {
        for (int i = 0; i < 2 * n - 1; i++)
        {
            std::cout << i + 1 << ' ' << htp[i].weight << ' ' << htp[i].parent+1 << ' ' << htp[i].lchild+1 << ' ' << htp[i].rchild+1 << std::endl;
        }
    }

    void printcode(std::string s, int n)
    {
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (htp[j].parent != -1)
            {
                if(htp[htp[j].parent].lchild == j)
                    (htp[i].code).insert(0, 1, '0');
                else
                    (htp[i].code).insert(0, 1, '1');
                j = htp[j].parent;
            }
        }
        for (int i = 0; i < n; i++)
        {
            std::cout << char('a' + htp[i].value) << ':' << htp[i].code << ' ';
        }
        std::cout << std::endl;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(htp[j].value == s[i]-'a')
                {
                    std::cout << htp[j].code;
                    break;
                }
            }
        }
        std::cout << std::endl;
        std::cout << s << std::endl;
    }
};