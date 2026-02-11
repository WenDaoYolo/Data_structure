#include<stdio.h>
#include<stdlib.h>
/*
    Õ»-Á´Õ»-c
*/


//Á´Ê½Õ»¶¨Òå
typedef int ElemType;
typedef struct stack stack;
typedef struct Node Node;

struct Node{
    ElemType data;
    Node* next;
};

struct stack{
    Node* top;
    int length;
};

//Õ»µÄ³õÊ¼»¯
void InitStack(stack* s){
    s->length=0;
    s->top=NULL;
}

//ÅÐ¶ÏÕ»¿Õ
int IsEmpty(stack* s){
    if(s->length==0)
        return 1;
    return 0;
}

//Ñ¹Õ»¡¢ÈëÕ»
void push(stack* s,ElemType e){
    Node* tmp=(Node*)malloc(sizeof(Node));
    tmp->data=e;

    tmp->next=s->top;
    s->top=tmp;
    s->length++;
}

//³öÕ»
void pop(stack* s,ElemType* re){
    if(IsEmpty(s))
    {
        printf("stack is empty!\n");
        return;
    }

    Node* tmp;
    tmp=s->top;
    *re=tmp->data;

    s->top=s->top->next;
    free(tmp);
    s->length--;
}

//ÏÔÊ¾Õ»ÔªËØ
void DisplayStack(stack* s){
    Node* find=s->top;
    while(find!=NULL)
    {
        printf("%d ",find->data);
        find=find->next;
    }
    putchar('\n');
}

//Ïú»ÙÕ»
void DistroyStack_n(stack* s){
    Node* del;
    while(s->top!=NULL)
    {
        del=s->top;
        s->top=s->top->next;
        free(del);
        del=NULL;
    }
    s->top=NULL;
    s->length=0;
}

//Ïú»ÙÕ»-µÝ¹é
void DistroyStack_r(Node* find){
    if(find==NULL)
        ;
    else
    {
        DistroyStack_r(find->next);
        free(find);
    }
}

void test(){
    stack s;
    ElemType tmp;
    InitStack(&s);
    push(&s,4);
    push(&s,3);
    push(&s,2);
    push(&s,1);
    pop(&s,&tmp);

    DisplayStack(&s);
    pop(&s,&tmp);
    pop(&s,&tmp);
    pop(&s,&tmp);
    pop(&s,&tmp);
    //DistroyStack_r(s.top);
    DistroyStack_n(&s);    
}

int main(){
    test();

    return 0;
}