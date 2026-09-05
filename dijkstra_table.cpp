#include<iostream>
#define INVALID -1
#define VERTEXS 6
#define X 999

/**********************        PRIORITY QUEUE        **********************/

struct edge
{
    int start,target,width;
};

edge invalid={INVALID,INVALID};

typedef edge elemtype;
class PriorityQueue
{
    private:
        elemtype* space;
        int flag,size,front;

        void QueueSwap(elemtype& a,elemtype& b)
        {
            if(a.target==b.target)
                return;
            
            a.target=a.target^b.target;
            b.target=a.target^b.target;
            a.target=a.target^b.target;

            if(a.width==b.width)
                return;
            
            a.width=a.width^b.width;
            b.width=a.width^b.width;
            a.width=a.width^b.width;
        }

        void AdjustBigQueueDown(int root)//大根堆下沉
        {
            int left=root*2,right=root*2+1,max=root;
            if(left<=front&&space[max].width<space[left].width)//比左子结点小
                max=left;
            if(right<=front&&space[max].width<space[right].width)//比右子结点小
                max=right;
            
            if(max!=root)
            {
                QueueSwap(space[root],space[max]);
                AdjustBigQueueDown(max);
            }
        }

        void AdjustBigQueueUp()//大根堆上浮
        {
            int cur=front;
            while(cur>1&&space[cur].width>space[cur/2].width)//比父结点大
            {
                QueueSwap(space[cur],space[cur/2]);
                cur/=2;
            }
        }

        void AdjustSmallQueueDown(int root)//小根堆下沉
        {
            int left=root*2,right=root*2+1,min=root;
            if(left<=front&&space[min].width>space[left].width)//比左子结点大
                min=left;
            if(right<=front&&space[min].width>space[right].width)//比右子结点大
                min=right;
            
            if(min!=root)
            {
                QueueSwap(space[root],space[min]);
                AdjustSmallQueueDown(min);
            }
        }

        void AdjustSmallQueueUp()//小根堆上浮
        {
            int cur=front;
            while(cur>1&&space[cur].width<space[cur/2].width)//比父结点小
            {
                QueueSwap(space[cur],space[cur/2]);
                cur/=2;
            }
        }

    public:
        PriorityQueue(int size,int flag):size(size),flag(flag)
        {
            this->space=new elemtype[size+1];
            this->front=0;
        }

        ~PriorityQueue()
        {
            delete[] this->space;
            this->space=NULL;
        }

        bool IsEmpty()
        {
            if(this->front==0)
                return true;
            return false;
        }

        bool IsFull()
        {
            if(this->front==this->size)
                return true;
            return false;
        }

        void SetPriority(int flag){ this->flag=flag; }

        void enqueue(elemtype e)
        {   
            if(IsFull())
                return;
            
            
            this->front++;
            space[front]=e;
            
            if(flag==0)
                AdjustSmallQueueUp();
            else
                AdjustBigQueueUp();
        }

        elemtype dequeue()
        {
            if(IsEmpty())
                return invalid;
            
            elemtype tmp=space[1];
            QueueSwap(space[1],space[front]);//出队的元素放到队尾,覆盖删除
            front--;                         
            
            if(flag==0)
                AdjustSmallQueueDown(1);
            else
                AdjustBigQueueDown(1);

            return tmp;
        }

        void dequeue_all()
        {
            std::cout<<"dequeue order:";
            while(!IsEmpty())
            {
                elemtype e=dequeue();
                std::cout<<e.target<<"("<<e.width<<") ";
            }
            std::cout<<std::endl;
        }
};
/**********************        PRIORITY QUEUE        **********************/

/**********************        DIJKSTRA TABLE        **********************/
struct table_node
{
    int distance,pre;
};

void InitTable(table_node* T)
{
    for(int i=0;i<VERTEXS;i++)
    {
        //初始到任何点都为无穷大
        T[i].distance=X;
        T[i].pre=i;
    }
}

void OutputRoad(int start,int cur,table_node* T,const char* M)
{
    if(cur!=start)
        OutputRoad(start,T[cur].pre,T,M);
    std::cout<<M[cur];
}

void DisTableInfo(table_node* T,const char* M,int start)//M:顶点编号映射表
{
    std::cout<<"VERTEX    PRE    DISTANCE    ROAD    "<<std::endl;
    for(int i=0;i<VERTEXS;i++)
    {
        if(i==start)
            continue;
        std::cout<<M[i]<<"          "<<M[T[i].pre]<<"        "<<T[i].distance<<"         ";
        OutputRoad(start,i,T,M);
        std::cout<<std::endl;
    }
}
/**********************        DIJKSTRA TABLE        **********************/

/**********************           GRAPHIC           **********************/
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
        graph[i].head->edge_value=X;
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

//顶点编号映射表
char vertex_map[VERTEXS]={'A','B','C','D','E','F'};
/**********************           GRAPHIC           **********************/

/**********************           DIJKSTRA          **********************/
void Dijkstra(const char* str, graph_node* G, const char* M, int start)
{
    bool visited[VERTEXS]={false};
    table_node T[VERTEXS];
    
    //初始化表和起点
    InitTable(T);
    T[start].distance = 0;
    T[start].pre=INVALID;
    
    //创建优先队列和起点元素
    PriorityQueue Q(VERTEXS*2,0);
    edge start_e={start,start,0};
    Q.enqueue(start_e);
    
    while (!Q.IsEmpty())
    {
        edge cur=Q.dequeue();
        int u=cur.target;
        
        //跳过过时数据
        if (visited[u]) continue;

        //顶点路径已确认
        visited[u]=true;
        
        //访问邻接点，并更新其距离
        link_node* find=G[u].head->next;
        while(find!=NULL)
        {
            int new_dist=T[u].distance+find->edge_value;
            if (new_dist<T[find->index].distance)
            {
                T[find->index].distance=new_dist;
                T[find->index].pre=u;
                edge e={u,find->index,new_dist};
                Q.enqueue(e);
            }
            find=find->next;
        }
    }
    //输出结果
    std::cout<<str<<std::endl;
    DisTableInfo(T,M,start);
}
/**********************           DIJKSTRA          **********************/

void CreateGraph(graph_node* graph1)
{
    InitGraph(graph1);
    InsertLinkNode(&graph1[1],2,2);
    InsertLinkNode(&graph1[1],3,5);
    InsertLinkNode(&graph1[2],3,1);
    InsertLinkNode(&graph1[2],4,3);
    InsertLinkNode(&graph1[3],4,3);
    InsertLinkNode(&graph1[3],5,4);
    InsertLinkNode(&graph1[3],6,1);
    InsertLinkNode(&graph1[4],5,1);
    InsertLinkNode(&graph1[4],6,4);
    InsertLinkNode(&graph1[5],6,1);
}

int main()
{
    //带权无向图邻接表
    graph_node graph1[VERTEXS]={{NULL},{NULL},{NULL},{NULL},{NULL}};
    CreateGraph(graph1);
    
    OutputGraphInfo("graph1 info:",graph1);
    Dijkstra("graph1 dijkstra info:",graph1,vertex_map,0);
    
    DestroyGraph(graph1);
    return 0;
}