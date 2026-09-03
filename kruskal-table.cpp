#include<iostream>
#define INVALID 99999
#define VERTEXS 6

/**********************    UF_SET    **********************/
struct set_node
{
    int father;
};

void InitSetNode(set_node* sets)
{
    for(int i=0;i<VERTEXS;i++)
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

struct link_node
{
    int index,edge_value;
    link_node* next;
};

struct graph_node
{
    link_node* head;
};

void InitGraph(graph_node* graph)
{
    for(int i=0;i<VERTEXS;i++)
    {
        graph[i].head=new link_node;
        graph[i].head->index=-1;
        graph[i].head->edge_value=INVALID;
        graph[i].head->next=NULL;
    }
}

void InsertLinkNode(graph_node* node,int index,int edge_value)
{
    node--;
    link_node* tmp=new link_node;
    tmp->index=index-1;
    tmp->edge_value=edge_value;
    tmp->next=node->head->next;
    node->head->next=tmp;
}

void OutputGraphInfo(const char* str,graph_node* graph)
{
    std::cout<<str<<std::endl;
    for(int i=0;i<VERTEXS;i++)
    {
        link_node* find=graph[i].head->next;
        while(find!=NULL)
        {
            std::cout<<"vertex"<<i+1<<" to vertex"<<find->index+1<<" have edge"<<std::endl;
            find=find->next;
        }
    }
    std::cout<<std::endl;
}

void DestroyGraph(graph_node* graph)
{
    for(int i=0;i<VERTEXS;i++)
    {
        link_node* tmp;
        while(graph[i].head!=NULL)
        {
            tmp=graph[i].head;
            graph[i].head=tmp->next;
            delete tmp;
        }
    }
}

void Kruskal(const char* str,graph_node* graph)
{
    set_node sets[VERTEXS];
    InitSetNode(sets);
    int cur_min_vertex=INVALID,cur_min_value=INVALID,father_vertex=INVALID;
    int tree_len=0,edge_sum_value=0;

    std::cout<<str<<std::endl;
    while(tree_len<VERTEXS-1)
    {
        cur_min_value=INVALID;
        for(int i=0;i<VERTEXS;i++)
        {
            link_node* find=graph[i].head->next;
            while(find!=NULL)
            {
                if(find->edge_value<cur_min_value&&FindSet(sets,i)!=FindSet(sets,find->index))
                {
                    father_vertex=i;
                    cur_min_value=find->edge_value;
                    cur_min_vertex=find->index;
                }
                find=find->next;
            }
        }
        std::cout<<father_vertex+1<<"-"<<cur_min_vertex+1<<"   length="<<cur_min_value<<std::endl;
        UnionSet(sets,father_vertex,cur_min_vertex);
        edge_sum_value+=cur_min_value;
        tree_len++;
    }
    std::cout<<"edge sum value:"<<edge_sum_value<<std::endl;
}

void CreateGraph(graph_node* graph1)
{
    InitGraph(graph1);
    InsertLinkNode(&graph1[1],2,6);
    InsertLinkNode(&graph1[1],3,1);
    InsertLinkNode(&graph1[1],4,5);
    InsertLinkNode(&graph1[2],1,6);
    InsertLinkNode(&graph1[2],3,5);
    InsertLinkNode(&graph1[2],5,3);
    InsertLinkNode(&graph1[3],1,1);
    InsertLinkNode(&graph1[3],2,5);
    InsertLinkNode(&graph1[3],4,4);
    InsertLinkNode(&graph1[3],5,6);
    InsertLinkNode(&graph1[3],6,4);
    InsertLinkNode(&graph1[4],1,5);
    InsertLinkNode(&graph1[4],3,4);
    InsertLinkNode(&graph1[4],6,2);
    InsertLinkNode(&graph1[5],2,3);
    InsertLinkNode(&graph1[5],3,6);
    InsertLinkNode(&graph1[5],6,6);
    InsertLinkNode(&graph1[6],3,4);
    InsertLinkNode(&graph1[6],4,2);
    InsertLinkNode(&graph1[6],5,6);
}

int main()
{
    //带权无向图邻接表
    graph_node graph1[VERTEXS]={{NULL},{NULL},{NULL},{NULL},{NULL}};
    CreateGraph(graph1);
    
    OutputGraphInfo("graph1 info:",graph1);
    Kruskal("graph1 prim info:",graph1);
    
    DestroyGraph(graph1);
    return 0;
}