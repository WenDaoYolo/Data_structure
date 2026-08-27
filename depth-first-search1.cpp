#include<iostream>
#define RLEN 5
#define CLEN RLEN

/******************************------DFS------******************************/

void Execute(int cur_vertex,int(*graph)[RLEN],bool* visted)
{
    visted[cur_vertex]=true;
    std::cout<<cur_vertex+1<<" ";

    for(int j=0;j<CLEN;j++)
    {
        if(graph[cur_vertex][j]&&!visted[j])
            Execute(j,graph,visted);
    }
}

void DFS(const char* str,int(*graph)[RLEN])
{
    int execute_count=1;
    bool visted[RLEN]={false};

    std::cout<<str;
    Execute(0,graph,visted);

    for(int i=0;i<RLEN;i++)
    {
        if(!visted[i])
        {
            Execute(i,graph,visted);
            execute_count++;
        }
    }

    if(execute_count>1)
        std::cout<<",is unconnected graph,branch nums:"<<execute_count<<std::endl;
    else
        std::cout<<",is connected graph"<<std::endl;
}
/******************************------DFS------******************************/

int main()
{
    //有向图的邻接矩阵
    int graph1[RLEN][CLEN]=
    {
        {0,1,0,1,0},
        {0,0,0,0,1},
        {0,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}
    };
    
    //无向图的邻接矩阵
    int graph2[RLEN][CLEN]=
    {
        {0,1,0,1,0},
        {1,0,1,0,1},
        {0,1,0,1,1},
        {1,0,1,0,0},
        {0,1,1,0,0}
    };

    //非连通无向图的邻接矩阵(原图中的顶点1、2以及3、4都不再相连)
    int graph3[RLEN][CLEN]=
    {
        {0,0,0,1,0},
        {0,0,1,0,1},
        {0,1,0,0,1},
        {1,0,0,0,0},
        {0,1,1,0,0}
    };

    DFS("graph1: ",graph1);
    DFS("graph2: ",graph2);
    DFS("graph3: ",graph3);

    return 0;  
}