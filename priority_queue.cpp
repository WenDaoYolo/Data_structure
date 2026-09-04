#include<iostream>
typedef char elemtype;

class PriorityQueue
{
    private:
        elemtype* space;
        int flag,size,front;

        void QueueSwap(elemtype& a,elemtype& b)
        {
            if(a==b)
                return;
            a=a^b;
            b=a^b;
            a=a^b;
        }

        void AdjustBigQueueDown(int root)//大根堆下沉
        {
            int left=root*2,right=root*2+1,max=root;
            if(left<=front&&space[max]<space[left])//比左子结点小
                max=left;
            if(right<=front&&space[max]<space[right])//比右子结点小
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
            while(cur>1&&space[cur]>space[cur/2])//比父结点大
            {
                QueueSwap(space[cur],space[cur/2]);
                cur/=2;
            }
        }

        void AdjustSmallQueueDown(int root)//小根堆下沉
        {
            int left=root*2,right=root*2+1,min=root;
            if(left<=front&&space[min]>space[left])//比左子结点大
                min=left;
            if(right<=front&&space[min]>space[right])//比右子结点大
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
            while(cur>1&&space[cur]<space[cur/2])//比父结点小
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

        int dequeue()
        {
            if(IsEmpty())
                return -1;
            
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
                std::cout<<e<<" ";
            }
            std::cout<<std::endl;
        }
};

void Test()
{
    PriorityQueue queue(10,0);
    queue.enqueue('A');
    queue.enqueue('D');
    queue.enqueue('V');
    queue.enqueue('C');
    queue.enqueue('W');
    queue.dequeue_all();

    queue.SetPriority(1);
    queue.enqueue('A');
    queue.enqueue('D');
    queue.enqueue('V');
    queue.enqueue('C');
    queue.enqueue('W');
    queue.dequeue_all();
}

int main()
{
    Test();
    return 0;
}