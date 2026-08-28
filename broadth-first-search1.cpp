#include<iostream>
#define RLEN 5
#define CLEN RLEN
#define UNINVALID -999

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

/******************************------BFS------******************************/

void Execute(int start,int(*graph)[RLEN],bool* visted)
{
    queue q;
    q.equeque(start);
    visted[start]=true;

    while(!q.IsEmpty())
    {
        elemtype e=q.dequeue();
        std::cout<<e+1<<" ";
        
        for(int i=0;i<RLEN;i++)
        {
            if(graph[e][i]&&!visted[i])
            {
                q.equeque(i);
                //入队后就将其标记，否则可能会导致重复入队，循环访问，甚至无限循环
                visted[i]=true;
            }
        }
    }
}

void BFS(const char* str,int(*graph)[RLEN])
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
/******************************------BFS------******************************/

int main()
{
    //有向图的邻接矩阵
    int graph1[RLEN][CLEN]=
    {
        {0,1,0,1,0},
        {0,0,0,0,1},
        {0,1,0,0,1},
        {0,0,1,0,1},
        {0,0,0,0,0}
    };
    
    //无向图的邻接矩阵
    int graph2[RLEN][CLEN]=
    {
        {0,1,0,1,0},
        {1,0,1,0,1},
        {0,1,0,1,1},
        {1,0,1,0,1},
        {0,1,1,1,0}
    };

    //非连通无向图的邻接矩阵(原图中的顶点1、2,3、4,4、5都不再相连)
    int graph3[RLEN][CLEN]=
    {
        {0,0,0,1,0},
        {0,0,1,0,1},
        {0,1,0,0,1},
        {1,0,0,0,0},
        {0,1,1,0,0}
    };

    BFS("graph1: ",graph1);
    BFS("graph2: ",graph2);
    BFS("graph3: ",graph3);

    return 0;  
}