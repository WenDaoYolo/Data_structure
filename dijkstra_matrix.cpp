#include<iostream>
#define RLEN 6
#define CLEN RLEN
#define X 999
#define INVALID -1

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
    for(int i=0;i<RLEN;i++)
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
    for(int i=0;i<RLEN;i++)
    {
        if(i==start)
            continue;
        std::cout<<M[i]<<"          "<<M[T[i].pre]<<"        "<<T[i].distance<<"         ";
        OutputRoad(start,i,T,M);
        std::cout<<std::endl;
    }
}
/**********************        DIJKSTRA TABLE        **********************/

/**********************           DIJKSTRA          **********************/
void Dijkstra(const char* str, int(*G)[RLEN], const char* M, int start)
{
    bool visited[RLEN]={false};
    table_node T[RLEN];
    
    //初始化表和起点
    InitTable(T);
    T[start].distance = 0;
    T[start].pre=INVALID;
    
    //创建优先队列和起点元素
    PriorityQueue Q(RLEN*2,0);
    edge start_e = {start,start,0};
    Q.enqueue(start_e);
    
    while (!Q.IsEmpty())
    {
        edge cur = Q.dequeue();
        int u = cur.target;
        
        //跳过过时数据
        if (visited[u]) continue;

        //顶点路径已确认
        visited[u] = true;
        
        //访问邻接点，并更新其距离
        for (int v = 0; v < CLEN; v++)
        {
            if(G[u][v]!=X)
            {
                int new_dist = T[u].distance + G[u][v];
                if (new_dist < T[v].distance)
                {
                    T[v].distance = new_dist;
                    T[v].pre = u;
                    edge e = {u, v, new_dist};
                    Q.enqueue(e);
                }
            }
        }
    }
    //输出结果
    std::cout<<str<<std::endl;
    DisTableInfo(T,M,start);
}
/**********************           DIJKSTRA          **********************/

/**********************           GRAPHIC           **********************/

//带权无向图的邻接矩阵
int graph1[RLEN][CLEN]=
{
    {X,2,5,X,X,X},
    {X,X,1,3,X,X},
    {X,X,X,3,4,1},
    {X,X,X,X,1,4},
    {X,X,X,X,X,1},
    {X,X,X,X,X,X}
};

//顶点编号映射表
char vertex_map[RLEN]={'A','B','C','D','E','F'};

void OutputGraphInfo(const char* str,int(*graph)[RLEN])
{
    std::cout<<str<<std::endl;
    for(int i=0;i<RLEN;i++)
    {
        for(int j=0;j<CLEN;j++)
        {
            if(graph[i][j]!=X)
                std::cout<<"vertex"<<i+1<<" to vertex"<<j+1<<" have edge"<<std::endl;
        }
    }
}
/**********************           GRAPHIC           **********************/

int main()
{
    OutputGraphInfo("graph1 info:",graph1);
    std::cout<<std::endl;
    Dijkstra("graph1 dijkstra info:",graph1,vertex_map,0);

    return 0;
}