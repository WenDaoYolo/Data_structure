#include<iostream>
#define VERTEXS 5

struct link_node
{
    int index;
    link_node* next;
};

struct graph_node
{
    link_node* head;
};

/******************************------DFS------******************************/
void Execute(int cur_vertex,graph_node* graph,bool* visted)
{
    std::cout<<cur_vertex+1<<" ";
    visted[cur_vertex]=true;

    link_node* tmp=graph[cur_vertex].head->next;
    while(tmp!=NULL)
    {
        if(!visted[tmp->index])
            Execute(tmp->index,graph,visted);
        tmp=tmp->next;
    }
}

void DFS(const char* str,graph_node* graph)
{
    int execute_count=1;
    bool visted[VERTEXS]={false};

    std::cout<<str;
    Execute(0,graph,visted);

    for(int i=0;i<VERTEXS;i++)
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

void InitGraph(graph_node* graph)
{
    for(int i=0;i<VERTEXS;i++)
    {
        graph[i].head=new link_node;
        graph[i].head->index=-1;
        graph[i].head->next=NULL;
    }
}

void InsertLinkNode(graph_node* node,int index)
{
    node--;
    link_node* tmp=new link_node;
    tmp->index=index-1;
    tmp->next=node->head->next;
    node->head->next=tmp;
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

int main()
{
    //有向图的邻接表
    graph_node graph1[VERTEXS]={{NULL},{NULL},{NULL},{NULL},{NULL}};
    
    //无向图的邻接表
    graph_node graph2[VERTEXS]={{NULL},{NULL},{NULL},{NULL},{NULL}};
    
    //非连通无向图的邻接表(原图中的顶点1、2以及3、4都不再相连)
    graph_node graph3[VERTEXS]={{NULL},{NULL},{NULL},{NULL},{NULL}};

    InitGraph(graph1);
    InitGraph(graph2);
    InitGraph(graph3);

    InsertLinkNode(&graph1[1],2);
    InsertLinkNode(&graph1[1],4);
    InsertLinkNode(&graph1[2],5);
    InsertLinkNode(&graph1[3],2);
    InsertLinkNode(&graph1[3],5);
    InsertLinkNode(&graph1[4],3);

    InsertLinkNode(&graph2[1],2);
    InsertLinkNode(&graph2[1],4);
    InsertLinkNode(&graph2[2],1);
    InsertLinkNode(&graph2[2],3);
    InsertLinkNode(&graph2[2],5);
    InsertLinkNode(&graph2[3],2);
    InsertLinkNode(&graph2[3],4);
    InsertLinkNode(&graph2[3],5);
    InsertLinkNode(&graph2[4],1);
    InsertLinkNode(&graph2[4],3);
    InsertLinkNode(&graph2[5],2);
    InsertLinkNode(&graph2[5],3);

    InsertLinkNode(&graph3[1],4);
    InsertLinkNode(&graph3[2],3);
    InsertLinkNode(&graph3[2],5);
    InsertLinkNode(&graph3[3],2);
    InsertLinkNode(&graph3[3],5);
    InsertLinkNode(&graph3[4],1);
    InsertLinkNode(&graph3[5],2);
    InsertLinkNode(&graph3[5],3);

    DFS("graph1: ",graph1);
    DFS("graph2: ",graph2);
    DFS("graph3: ",graph3);

    DestroyGraph(graph1);
    DestroyGraph(graph2);
    DestroyGraph(graph3);

    return 0;
}