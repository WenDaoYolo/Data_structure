#include<iostream>
using namespace std;

//方式1，有哨兵
#define UNVARIABLE -999
typedef int ElemType;

struct Node{
    ElemType data;    
    Node* next;
};

class queue{
    public:
        Node* front;
        Node* rear;

        queue(){
            this->front=new Node;         //定义哨兵
            this->rear=this->front;

            this->front->data=UNVARIABLE; //锁定front头和rear尾
            this->front->next=NULL;
        }

        bool IsEmpty(){
            if(this->front==this->rear)
                return true;
            return false;
        }

        void equeue(ElemType e){
            Node* tmp=new Node;
            tmp->data=e;
            tmp->next=NULL;

            this->rear->next=tmp;
            this->rear=tmp;
        }

        ElemType dequeue(){
            if(this->IsEmpty())
            {
                cout<<"queue is empty!"<<endl;
                return -1;
            }

            //出队最后一个元素后队空，rear需要复位
            if(this->front->next==this->rear)
                this->rear=this->front;

            Node* del=this->front->next;
            ElemType tmp=del->data;
            this->front->next=del->next;

            free(del);
            return tmp;
        }

        void Display(){
            Node* find=this->front->next;
            while(find!=NULL)
            {
                cout<<find->data<<" ";
                find=find->next;
            }
            cout<<endl;
        }

        ~queue(){
            Node* tmp=this->front->next;
            while(tmp!=NULL){
                this->front->next=this->front->next->next;
                delete tmp;
                tmp=this->front->next;
            }
        }
};

void test(){
    queue q;
    ElemType tmp;
    q.equeue(1);
    q.equeue(2);
    q.equeue(3);
    q.equeue(4);

    tmp=q.dequeue();
    cout<<"dequeue after:"<<tmp<<endl;
    q.Display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
}

int main(){
    test();

    return 0;
}