#include<stdio.h>
#include<stdlib.h>
/*
    栈-顺序栈-c
*/

//顺序栈的定义
#define MAXSIZE 3             //定义栈的大小
typedef int ElemType;
typedef struct stack stack;

struct stack{
    ElemType* space;
    int top;
};

void InitStack(stack* s){
    s->top=-1;
    s->space=(ElemType*)malloc(MAXSIZE);
}

int IsEmpty(stack* s){
    if(s->top==-1)
        return 1;
    return 0;
}

int IsFull(stack* s){
    if(s->top==MAXSIZE-1)
        return 1;
    return 0;
}

void push(stack* s,ElemType e){
    if(IsFull(s))
    {
        printf("stack is full!\n");
        return;
    }
    s->top++;
    s->space[s->top]=e;
}

void pop(stack* s,ElemType* re){
    if(IsEmpty(s))
    {
        printf("stack is empty!\n");
        return;
    }
    *re=s->space[s->top];
    s->top--;
}

void DisplayStack(stack* s){
    for(int i=s->top;i>-1;i--)
        printf("%d ",s->space[i]);
    putchar('\n');
}

void DistroyStack(stack* s){
    if(s->space!=NULL)
    {
        free(s->space);
        s->space=NULL;
        s->top=-1;
    }
}

void test(){
    stack s1;
    InitStack(&s1);
    ElemType tmp;
    push(&s1,1);
    push(&s1,2);
    push(&s1,3);
    push(&s1,4);

    pop(&s1,&tmp);
    DisplayStack(&s1);
    pop(&s1,&tmp);
    pop(&s1,&tmp);
    pop(&s1,&tmp);
    DistroyStack(&s1);
}

int main(){
    test();

    return 0;
}