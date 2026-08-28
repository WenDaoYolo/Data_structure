#include<iostream>
#define VERTEXS 5
#define UNINVALID -999

/******************************------queue struct------******************************/
typedef int elemtype;

struct link_node
{
    elemtype data;
    link_node* next;
};

class queue
{
    public:
        link_node* front;
        link_node* rear;
        
        queue()
        {
            rear=front=new link_node;
            front->data=UNINVALID;
            front->next=NULL;
        }

        bool IsEmpty()
        {
            if(front->next==NULL)
                return true;
            return false;
        }

        void equeque(elemtype e)
        {
            link_node* tmp=new link_node;
            tmp->data=e;

            tmp->next=rear->next;
            rear->next=tmp;
            rear=tmp;
        }

        elemtype dequeue()
        {
            if(IsEmpty())
                return UNINVALID;

            link_node* tmp=front->next;
            front->next=tmp->next;
            elemtype value=tmp->data;
            delete tmp;

            //出队后应立即检查队列，而不是等下次出队时再进行检查处理
            //若最后一个元素出队列，尾指针就会悬空，再入队则会出问题
            if(IsEmpty())
                rear=front;

            return value;
        }

        ~queue()
        {
            while(dequeue()!=UNINVALID);
            delete front;
            front=rear=NULL;
        }
};
/******************************------graph struct------******************************/
struct graph_link_node
{
    int index;
    graph_link_node* next;
};

struct graph_node
{
    graph_link_node* head;
};
/******************************------BFS------******************************/
void Execute(int start,graph_node* graph,bool* visted)
{
    queue q;
    q.equeque(start);
    visted[start]=true;

    while(!q.IsEmpty())
    {
        elemtype e=q.dequeue();
        std::cout<<e+1<<" ";
        
        graph_link_node* find=graph[e].head->next;
        while(find!=NULL)
        {
            if(!visted[find->index])
            {
                q.equeque(find->index);
                //入队后就将其标记，否则可能会导致重复入队，循环访问，甚至无限循环
                visted[find->index]=true;
            }
            find=find->next;
        }
    }
}

void BFS(const char* str,graph_node* graph)
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
/******************************------BFS------******************************/

void InitGraph(graph_node* graph)
{
    for(int i=0;i<VERTEXS;i++)
    {
        graph[i].head=new graph_link_node;
        graph[i].head->index=-1;
        graph[i].head->next=NULL;
    }
}

void InsertLinkNode(graph_node* node,int index)
{
    node--;
    graph_link_node* tmp=new graph_link_node;
    tmp->index=index-1;
    tmp->next=node->head->next;
    node->head->next=tmp;
}

void DestroyGraph(graph_node* graph)
{
    for(int i=0;i<VERTEXS;i++)
    {
        graph_link_node* tmp;
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
    
    //非连通无向图的邻接表(原图中的顶点1、2，3、4，4、5都不再相连)
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
    InsertLinkNode(&graph1[4],5);

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
    InsertLinkNode(&graph2[4],5);
    InsertLinkNode(&graph2[5],2);
    InsertLinkNode(&graph2[5],3);
    InsertLinkNode(&graph2[5],4);

    InsertLinkNode(&graph3[1],4);
    InsertLinkNode(&graph3[2],3);
    InsertLinkNode(&graph3[2],5);
    InsertLinkNode(&graph3[3],2);
    InsertLinkNode(&graph3[3],5);
    InsertLinkNode(&graph3[4],1);
    InsertLinkNode(&graph3[5],2);
    InsertLinkNode(&graph3[5],3);

    BFS("graph1: ",graph1);
    BFS("graph2: ",graph2);
    BFS("graph3: ",graph3);

    DestroyGraph(graph1);
    DestroyGraph(graph2);
    DestroyGraph(graph3);

    return 0;
}