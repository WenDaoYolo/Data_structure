#include<iostream>
#define RLEN 6
#define CLEN RLEN
#define INVALID 99999

/**********************    UF_SET    **********************/
struct set_node
{
    int father;
};

void InitSetNode(set_node* sets)
{
    for(int i=0;i<RLEN;i++)
        sets[i].father=i;
}

int FindSet(set_node* sets,int x)
{
    if(sets[x].father==x)
        return x;
    else
        return sets[x].father=FindSet(sets,sets[x].father);
}

void UnionSet(set_node* sets,int x,int y)
{    
    int xf=FindSet(sets,x);
    int yf=FindSet(sets,y);

    if(xf==yf)
        return; 

    sets[yf].father=xf;
}
/**********************    UF_SET    **********************/

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
    set_node sets[RLEN];
    InitSetNode(sets);
    int cur_min_vertex=INVALID,cur_min_value=INVALID,father_vertex=INVALID;
    int tree_len=0,edge_sum_value=0;

    std::cout<<str<<std::endl;
    while(tree_len<RLEN-1)
    {
        cur_min_value=INVALID;
        for(int i=0;i<RLEN;i++)
        {
            for(int j=0;j<CLEN;j++)
            {
                if(graph[i][j]>0&&graph[i][j]<cur_min_value&&FindSet(sets,i)!=FindSet(sets,j))
                {
                    father_vertex=i;
                    cur_min_value=graph[i][j];
                    cur_min_vertex=j;
                }
            }
        }
        std::cout<<father_vertex+1<<"-"<<cur_min_vertex+1<<"   length="<<cur_min_value<<std::endl;
        UnionSet(sets,father_vertex,cur_min_vertex);
        edge_sum_value+=cur_min_value;
        tree_len++;
    }
    std::cout<<"edge sum value:"<<edge_sum_value<<std::endl;
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
    Kruskal("graph1 kruskal info:",graph1);

    return 0;  
}