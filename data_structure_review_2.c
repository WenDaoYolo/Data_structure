#include<stdio.h>
#include<stdlib.h>
/*
    线性表-链表-c
*/

//单链表的定义(无哨兵版):需额外留意边界值,只作为学习,日常默认使用有哨兵版

typedef int ElemType; //结点的定义
typedef struct Node Node;

struct Node{
    ElemType data;    //数据域
    Node* next;       //指针域
};

typedef struct List{
    Node* head;
    int length;
}List_l;

//1.初始化
void InitList(List_l* list){
    list->head=NULL;
    list->length=0;
}

//2.1元素的插入-头插法(从头结点开始插入,插入的数据为顺序)
void HeadInsert(List_l* list,ElemType e){
    Node* tmp=(Node*)malloc(sizeof(Node));
    tmp->data=e;

    tmp->next=list->head;
    list->head=tmp;
    list->length++;
}

//2.2元素的插入-尾插法(从尾结点开始插入,插入的数据为逆序)
void TailInsert(List_l* list,ElemType e){
    Node* tmp=(Node*)malloc(sizeof(Node));
    tmp->data=e;

    Node* tail=list->head;
    while(tail!=NULL&&tail->next!=NULL)
        tail=tail->next;

    if(tail==NULL)
    {
        list->head=tmp;
        tmp->next=NULL;
    }
    else
    {
        tail->next=tmp;
        tmp->next=NULL;
    }
    list->length++;
}

//3.指定元素的删除
void DeleteList(List_l* list,int index){
    if(index<0||index>=list->length)
    {
        printf("index is error!\n");
        return;
    }

    Node* find=list->head;
    Node* tmp;
                
    if(list->length==1||index==0)
    {
        tmp=find;
        list->head=find->next;
    }
    else
    {
        for(int i=0;i<index-1;i++)
            find=find->next;
        tmp=find->next;
        find->next=find->next->next;
    }

    free(tmp);
    list->length--;
}

//4.元素查找、排序：详见算法

//5.显示元素
void DisplayList(List_l* list){
    Node* find=list->head;

    for(int i=0;i<list->length;i++)
    {
        printf("%d ",find->data);
        find=find->next;
    }

    putchar('\n');
}

//6.反初始化(释放内存),从头部处依次释放结点，用指针临时存储需要删除的结点
void DistroyList(List_l* list){
    Node* tmp=list->head;
    while(tmp!=NULL)
    {
        list->head=tmp->next;
        free(tmp);
        tmp=list->head;
    }
}

void DistroyList_r(Node* ptr){
    if(ptr==NULL)
        ;
    else
    {
        Node* tmp=ptr;
        DistroyList_r(ptr->next);
        printf("结点：%d已释放!\n",ptr->data);
        free(tmp);
    }
}

void test(){
    List_l list;
    List_l* list_ptr=&list;

    InitList(list_ptr);
    HeadInsert(list_ptr,3);
    HeadInsert(list_ptr,4);
    TailInsert(list_ptr,5);
    TailInsert(list_ptr,6);
    DisplayList(list_ptr);
    printf("after:\n");
    DeleteList(list_ptr,2);
    DeleteList(list_ptr,0);
    DisplayList(list_ptr);
    DistroyList_r(list.head);
    //DistroyList(list_ptr);
}

int main(){
    test();

    return 0;
}