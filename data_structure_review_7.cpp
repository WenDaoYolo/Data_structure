#include<iostream>
using namespace std;

#define MAXSIZE 6
typedef int ElemType;

class queue{
    public:
        ElemType* data;
        int front,rear;

        queue(){
            this->rear=0;
            this->front=0;
            this->data=new ElemType[MAXSIZE];
        }

        bool IsFull(){
            if((this->rear+1)%MAXSIZE==this->front)
                return true;
            return false;
        }

        bool IsEmpty(){
            if(this->rear==this->front)
                return true;
            return false;
        }

        void equeue(ElemType e){
            if(this->IsFull())
            {
                cout<<"queue is full!"<<endl;
                return;
            }
            this->data[this->rear]=e;
            this->rear=(this->rear+1)%MAXSIZE;
        }

        ElemType dequeue(){
            if(this->IsEmpty())
            {
                cout<<"queue is empty!"<<endl;
                return -1;
            }
            ElemType tmp=this->data[this->front];
            this->front=(this->front+1)%MAXSIZE;
            return tmp;
        }

        void Display(){
            int find=this->front;
            while(find!=this->rear){
                cout<<this->data[find]<<" ";
                find=(find+1)%MAXSIZE;
            }
            cout<<endl;
        }

        ~queue(){
            if(this->data!=NULL){
                delete[] this->data;
                this->data=NULL;
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
    q.equeue(5);
    q.equeue(6);

    tmp=q.dequeue();
    cout<<"after dequeue:"<<tmp<<endl;
    q.Display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.equeue(666);
    q.Display();
}

int main(){
    test();

    return 0;
}