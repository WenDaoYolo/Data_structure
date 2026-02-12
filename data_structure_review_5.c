#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 6
typedef struct queue queue;
typedef int ElemType;

struct queue{
    int front;
    ElemType* data;
    int rear;
};

void InitQueue(queue* q){
    q->data=(ElemType*)malloc(MAXSIZE*sizeof(ElemType));
    q->front=0;
    q->rear=0;
}

int IsEmpty(queue* q){            //判断队空
    if(q->rear==q->front)
        return 1;
    return 0;
}

void AdjustQueue(queue* q){       //调整队列
    if(q->front!=0){
        printf("before:%d - %d\n",q->front,q->rear);

        int flag=q->rear-(q->front-0);  //获取空位移动至队尾时的起始下标
        int find=0;
        while(find<flag){
            q->data[find]=q->data[q->front];
            find++;
            q->front++;
        }
        
        q->rear=find;
        q->front=0;
        printf("after:%d - %d\n",q->front,q->rear);
    }
}

int IsFull(queue* q){             //判断队满
    AdjustQueue(q);               //调整队列
    if(q->rear==MAXSIZE)
        return 1;
    return 0;
}

void equeue(queue* q,ElemType e){
    if(IsFull(q))
    {
        printf("Queue Is Full!\n");
        return;
    }
    q->data[q->rear]=e;
    q->rear++;  
}

ElemType dequeue(queue* q){
    if(IsEmpty(q))
    {
        printf("Queue Is Empty!\n");
        return -1;
    }
    ElemType tmp=q->data[q->front];
    q->front++;
    return tmp;
}

void DisplayQueue(queue q){
    while(q.rear!=q.front){
        printf("%d ",q.data[q.front]);
        q.front++;
    }
}

void DistroyQueue(queue* q){
    if(q->data!=NULL)
    {
        free(q->data);
        q->data=NULL;    
    }
}

void test(){
    queue q;
    ElemType tmp;
    InitQueue(&q);

    equeue(&q,1);
    equeue(&q,2);
    equeue(&q,3);
    equeue(&q,4);

    tmp=dequeue(&q);
    printf("dequeue value:%d\n",tmp);
    tmp=dequeue(&q);
    IsFull(&q);
    DisplayQueue(q);
    DistroyQueue(&q);
}

int main(){
    test();

    return 0;
}