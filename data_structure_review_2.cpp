#include<iostream>
using namespace std;
/*
    线性表-链表-c++
*/

//单链表的定义(默认有哨兵版)

typedef int ElemType;
#define UNVARIABLE 99999999     //定义无效数

struct Node{                    //结点的定义
    ElemType data;
    Node* next;
};

class List_l{
    public:
        Node* head;
        int length;

        //构造链表
        List_l(){
            this->head=(Node*)malloc(sizeof(Node));
            
            this->head->next=NULL;
            this->head->data=UNVARIABLE;
            this->length=0;
        }

        //头插法
        void HeadInsert(ElemType e){
            Node* find=this->head;
            Node* tmp=new Node;

            tmp->data=e;
            this->length++;
            tmp->next=find->next;
            find->next=tmp;
        }

        //尾插法
        void TailInsert(ElemType e){
            Node* find=this->head;
            Node* tmp=(Node*)malloc(sizeof(Node));
            tmp->data=e;
            this->length++;

            while(find->next!=NULL)
                find=find->next;
            
            tmp->next=find->next;
            find->next=tmp;
        }

        //删除指定位置的元素
        void Delete(int index){
            if(index<0||index>=this->length)
            {
                cout<<"index is error!"<<endl;
                return;
            }

            Node* find=this->head;
            Node* tmp=NULL;
            for(int i=0;i<index;i++)
                find=find->next;

            tmp=find->next;
            find->next=tmp->next;
            delete tmp;
            this->length--;
        }

        //排序，查找，详见算法

        //打印链表元素
        void Display(){
            Node* find=this->head->next;
            while(find!=NULL){
                cout<<find->data<<" ";
                find=find->next;
            }
            cout<<endl;
        }

        //析构，反初始化
        ~List_l(){
            Node* find=this->head;
            Node* tmp=NULL;
            
            while(find->next!=NULL){
                tmp=find->next;
                find->next=tmp->next;
                delete tmp;
            }

            this->length=0;
        }

        void Reverse(){
            Node* first,*second,*third;
            first=NULL;
            second=this->head->next;
            third=second->next;
            //反转结点的后继
            while(third!=NULL){
                second->next=first;
                first=second;
                second=third;
                third=third->next;
            }
            //反转尾结点的后继
            second->next=first;      
            //添加哨兵
            this->head=new Node;
            this->head->data=UNVARIABLE;
            this->head->next=second;
        }

        void DeleteMidNode(){
            Node* fast,*slow;
            fast=this->head;
            slow=this->head;
            while(fast->next!=NULL&&fast->next->next!=NULL)
            {
                fast=fast->next->next;
                slow=slow->next;
            }

            Node* tmp=slow->next;
            slow->next=slow->next->next;
            delete tmp;
        }
};

void test(){
    List_l list;

    list.HeadInsert(3);
    list.HeadInsert(4);
    list.TailInsert(5);
    list.TailInsert(6);
    list.Display();
    printf("after:\n");
    list.Delete(2);
    list.Delete(0);
    list.Display();
}

void test2(){
    List_l list;
    list.HeadInsert(1);
    list.HeadInsert(2);
    list.HeadInsert(3);
    list.HeadInsert(4);
    list.TailInsert(6);
    list.TailInsert(9);

    cout<<"before:"<<endl;
    list.Display();
    cout<<"after reverse:"<<endl;
    list.Reverse();
    list.Display();
}

void test3(){
    List_l list1;
    List_l list2;

    list1.HeadInsert(1);
    list1.HeadInsert(2);
    list1.HeadInsert(3);
    list2.HeadInsert(1);
    list2.HeadInsert(2);
    list2.HeadInsert(3);
    list2.HeadInsert(4);
    list1.DeleteMidNode();
    list2.DeleteMidNode();
    
    list1.Display();
    list2.Display();
}

int main(){
    test();
    test2();
    test3();

    return 0;
}
