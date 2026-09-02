#include<iostream>
#define INVALID 99999
#define VERTEXS 6

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

void Prim(const char* str,graph_node* graph)
{
    bool visited[VERTEXS]={false};
    int edge_value_sum=0;

    int tree_len=1;
    visited[0]=true;

    std::cout<<str<<std::endl;
    while(tree_len<VERTEXS)
    {
        int cur_min_vertex,cur_min_value=INVALID;
        int parent_vertex;

        for(int i=0;i<VERTEXS;i++)
        {
            if(visited[i])
            {
                link_node* find=graph[i].head->next;
                while(find!=NULL)
                {
                    if(!visited[find->index]&&find->edge_value<cur_min_value)
                    {
                        parent_vertex=i;
                        cur_min_vertex=find->index;
                        cur_min_value=find->edge_value;
                    }
                    find=find->next;
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
    Prim("graph1 prim info:",graph1);
    
    DestroyGraph(graph1);
    return 0;
}