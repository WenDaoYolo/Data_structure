#include<iostream>
#define RLEN 6
#define CLEN RLEN
#define INVALID 99999

void OutputGraphInfo(const char* str,int(*graph)[RLEN])
{
    std::cout<<str<<std::endl;
    for(int i=0;i<RLEN;i++)
    {
        for(int j=0;j<CLEN;j++)
        {
            if(graph[i][j]>0)
                std::cout<<"vertex"<<i+1<<" to vertex"<<j+1<<" have edge"<<std::endl;
        }
    }
}

void Kruskal(const char* str,int(*graph)[RLEN])
{
    
}

int main()
{
    //带权无向图的邻接矩阵
    int graph1[RLEN][CLEN]=
    {
        {-1,6,1,5,-1,-1},
        {6,-1,5,-1,3,-1},
        {1,5,-1,4,6,4},
        {5,-1,4,-1,-1,2},
        {-1,3,6,-1,-1,6},
        {-1,-1,4,2,6,-1}
    };

    OutputGraphInfo("graph1 info:",graph1);
    Kruskal("graph1 prim info:",graph1);

    return 0;  
}