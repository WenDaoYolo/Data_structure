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

int main()
{
    //不带权有向图邻接表
    graph_node graph1[VERTEXS]={{NULL},{NULL},{NULL},{NULL},{NULL}};
    //不带权无向图邻接表
    graph_node graph2[VERTEXS]={{NULL},{NULL},{NULL},{NULL},{NULL}};

    InitGraph(graph1);
    InitGraph(graph2);

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

    OutputGraphInfo("graph1 info:",graph1);
    OutputGraphInfo("graph2 info:",graph2);

    DestroyGraph(graph1);
    DestroyGraph(graph2);

    return 0;
}