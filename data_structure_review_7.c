#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 6
typedef int ElemType;
typedef struct queue queue;

struct queue{
    int front,rear;
    ElemType* data;
};

void InitQueue(queue* q){
    q->front=0;
    q->rear=0;
    q->data=(ElemType*)malloc(MAXSIZE*sizeof(ElemType));
}

int IsFull(queue* q){
    if((q->rear+1)%MAXSIZE==q->front)
        return 1;
    return 0;
}

int IsEmpty(queue* q){
    if(q->rear==q->front)
        return 1;
    return 0;
}

void equeue(queue* q,ElemType e){
    if(IsFull(q))
    {
        printf("queue is full!\n");
        return;
    }
    q->data[q->rear]=e;
    q->rear=(q->rear+1)%MAXSIZE;
}

ElemType dequeue(queue* q){
    if(IsEmpty(q))
    {
        printf("queue is empty!\n");
        return -1;
    }
    ElemType tmp=q->data[q->front];
    q->front=(q->front+1)%MAXSIZE;
    return tmp;
}

void DisplayQueue(queue* q){
    int find=q->front;
    while(find!=q->rear){
        printf("%d ",q->data[find]);
        find=(find+1)%MAXSIZE;
    }
    putchar('\n');
}

void DestroyQueue(queue* q){
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
    equeue(&q,5);
    equeue(&q,6);
    DisplayQueue(&q);
    tmp=dequeue(&q);
    printf("after dequeue:%d\n",tmp);
    dequeue(&q);
    equeue(&q,666);
    equeue(&q,999);
    equeue(&q,111);
    DisplayQueue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    DestroyQueue(&q);
}

int main(){
    test();

    return 0;
}