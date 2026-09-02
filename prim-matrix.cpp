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

void Prim(const char* str,int(*graph)[RLEN])
{
    bool visited[RLEN]={false};
    int edge_value_sum=0;

    int tree_len=1;
    visited[0]=true;

    std::cout<<str<<std::endl;
    while(tree_len<RLEN)
    {
        int cur_min_vertex,cur_min_value=INVALID;
        int parent_vertex;

        for(int i=0;i<RLEN;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<CLEN;j++)
                {
                    if(!visited[j]&&graph[i][j]>0&&graph[i][j]<cur_min_value)
                    {
                        parent_vertex=i;
                        cur_min_vertex=j;
                        cur_min_value=graph[i][j];
                    }
                }
            }
        }
        
        std::cout<<parent_vertex+1<<"-"<<cur_min_vertex+1<<"   length="<<cur_min_value<<std::endl;
        edge_value_sum+=cur_min_value;
        visited[cur_min_vertex]=true;
        tree_len++;
    }
    std::cout<<"edge value sum:"<<edge_value_sum<<std::endl;
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
    Prim("graph1 prim info:",graph1);

    return 0;  
}