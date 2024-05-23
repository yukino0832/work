#include <iostream>
#include <string>
const int infinity = 1000;

struct gra
{
    int value;
    bool is_visit;
    std::string path;
    gra()
    {
        value = 0;
        is_visit = false;
        path = "";
    }
};

class graph
{    

private:

    int vexnum;  // 顶点个数
    int edgenum; // 边数
    int **arcs;  // 邻接矩阵
    gra *dia;    // 最短路径存储表


public:

    graph(int vex, int edge)
    {
        vexnum = vex;
        edgenum = edge;
        dia = new gra[vexnum];
        arcs = new int *[vexnum];
        for(int i = 0; i < vexnum; i++)
        {
            arcs[i] = new int[vexnum];
            for(int j = 0; j < vexnum; j++)
            {
                arcs[i][j] = infinity;
            }
        }
    }

    ~graph()
    {
        delete[] dia;
        for(int i = 0; i < vexnum; i++)
        {
            delete[] arcs[i];
        }
        delete[] arcs;
    }

    void append(int i, int j, int value)
    {
        arcs[i][j] = value;
    }

    void dijkstra(int begin, std::string name)
    {
        for (int i = 0; i < vexnum; i++)
        {
            dia[i].path += name[begin];
            dia[i].path += ' ';
            dia[i].path += name[i];
            dia[i].value = arcs[begin][i];
        }
        dia[begin].value = 0;
        dia[begin].is_visit = true;
        int count = vexnum - 1;
        while(count--)
        {
            int min = infinity;
            int min_temp = 0;
            for(int i = 0; i < vexnum; i++)
            {
                if(!dia[i].is_visit && dia[i].value<min)
                {
                    min = dia[i].value;
                    min_temp = i;
                }
            }
            dia[min_temp].is_visit = true;
            for (int i = 0; i < vexnum; i++)
            {
                if(!dia[i].is_visit && arcs[min_temp][i] != infinity && arcs[min_temp][i] + dia[min_temp].value < dia[i].value)
                {
                    dia[i].value = dia[min_temp].value + arcs[min_temp][i];
                    dia[i].path = dia[min_temp].path + ' ' +name[i];
                }
            }
        }
    }

    void print(int find)
    {
        std::cout << dia[find].value << std::endl;
        std::cout << dia[find].path << std::endl;
    }
};
