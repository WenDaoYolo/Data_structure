#include<stdio.h>
#include<stdlib.h>
/*
    线性表-顺序表-c
*/

//顺序表的定义            
typedef int ElemType;   //typedef用处1：以后符号名可以一次性修改
typedef struct List_s{  //typedef用处2：定义别名简化c结构体类型引用的语法    
    ElemType* space;
    int length;
}List_s;

//1.初始化
void InitList(List_s* list)
{
    list->space=NULL;
    list->length=0;
}

//2.元素的插入
void InsertList(List_s* list,ElemType e){
    //realloc传入空地址其效果和malloc一样
    list->space=(ElemType*)realloc(list->space,(list->length+1)*sizeof(ElemType));
    list->space[list->length]=e;
    list->length++;
}

//3.指定元素的删除：待删除位置后的元素均向前移动并覆盖
void DeleteList(List_s* list,int index){
    if(index>=list->length||index<0){
        printf("index error!\n");
        return;
    }

    for(int i=index;i<list->length-1;i++)
        list->space[i]=list->space[i+1];
    list->length--;
}

//4.元素查找、排序：详见算法

//5.显示元素
void DisplayList(List_s* list){
    for(int i=0;i<list->length;i++)
        printf("%d ",list->space[i]);
    putchar('\n');
}

//6.反初始化(释放内存)
void DistroyList(List_s* list){
    if(list->space!=NULL)
    {
        free(list->space);
        list->length=0;
    }
}

void test(){
    List_s list;
    List_s* list_ptr=&list;      //传入指针而非对结构体取地址，使语法更简洁

    InitList(list_ptr);
    InsertList(list_ptr,3);
    InsertList(list_ptr,4);
    InsertList(list_ptr,5);
    InsertList(list_ptr,6);
    DisplayList(list_ptr);
    printf("after:\n");
    DeleteList(list_ptr,2);
    DisplayList(list_ptr);
    DistroyList(list_ptr);
}

int main(){
    test();

    return 0;
}