#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct queue queue;
typedef struct Node Node;
/*
    和链表同理，相比顺序队列无需调整,且访问效率一致
    方式1：但在头部front出队，尾部rear入队(尾插法)
    方式2：或在头部rear入队(头插法)，尾部front出队
*/

struct Node{             //定义队列结点
    Node* next;
    ElemType data;
};
struct queue{            //定义队列
    Node* front;
    Node* rear;
};

void InitQueue(queue* q){
    q->front=NULL;
    q->rear=NULL;
}

int IsEmpty(queue* q){
    if(q->rear==NULL)
        return 1;
    return 0;
} 

//方式1,无哨兵的话则需通过初始锁对front头和rear尾进行初始的锁定
//初始锁也可以定义为队列的成员,有哨兵可直接在初始函数内锁定为哨兵
int fq_lock=0;
void equeue(queue* q,ElemType e){
    Node* tmp=(Node*)malloc(sizeof(Node));
    tmp->data=e;
    tmp->next=NULL;
    
    if(fq_lock==0)
    {
        q->front=tmp;
        q->rear=tmp;
        fq_lock=1;
        return;
    }
    q->rear->next=tmp;
    q->rear=tmp;
}

ElemType dequeue(queue* q){
    if(IsEmpty(q))
    {
        printf("queue is empty!\n");
        return -1;
    }

    if(q->front->next==NULL) //出队最后一个元素，则需要解除初始锁，队空
        fq_lock=0;

    Node* del=q->front;
    ElemType tmp=del->data;
    q->front=q->front->next;
    free(del);

    if(fq_lock==0)           //队空则front和rear指针要复位置空
    {
        q->front=NULL;
        q->rear=NULL;
    }
    return tmp;
}

void DisplayQueue(queue* q){
    Node* find=q->front;
    while(find!=NULL)
    {
        printf("%d ",find->data);
        find=find->next;
    }
    putchar('\n');
}

void DestroyQueue_n(queue* q){
    Node* find=q->front;
    while(find!=NULL)
    {
        q->front=q->front->next;
        free(find);
        find=q->front;
    }
}

void DestroyQueue_r(Node* ptr){
    if(ptr==NULL)
        ;
    else
    {
        DestroyQueue_r(ptr->next);
        free(ptr);
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
    tmp=dequeue(&q);
    printf("dequeue value:%d\n",tmp);
    DisplayQueue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    equeue(&q,999);
    DisplayQueue(&q);
    //DestroyQueue_n(&q);
    DestroyQueue_r(q.front);
}

int main(){
    test();

    return 0;
}