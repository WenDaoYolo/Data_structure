#include<iostream>
using namespace std;
#define MAXSIZE 6
typedef int ElemType;

class queue{
    public:
        int front,rear;
        ElemType* data;

        queue(){
            this->front=0;
            this->rear=0;
            this->data=new ElemType[MAXSIZE];
        }

        bool IsEmpty(){
            if(this->front==this->rear)
                return true;
            return false;
        }

        void Adjust(){
            if(this->front!=0)
            {
                cout<<"before:"<<this->front<<"-"<<this->rear<<endl;

                int flag=this->rear-(this->front-0);
                int find=0;
                while(find<flag)
                {
                    this->data[find]=this->data[this->front];
                    find++;
                    this->front++;
                }

                this->rear=find;
                this->front=0;
                cout<<"after:"<<this->front<<"-"<<this->rear<<endl;
            }
        }

        bool IsFull(){
            this->Adjust();
            if(this->rear==MAXSIZE)
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
            this->rear++;
        }

        ElemType dequeue(){
            if(this->IsEmpty())
            {
                cout<<"queue is empty!"<<endl;
                return -1;
            }
            ElemType tmp=this->data[this->front];
            this->front++;
            return tmp;
        }

        void Display(){
            int find=this->front;
            while(find!=this->rear){
                cout<<this->data[find]<<" ";
                find++;
            }
            cout<<endl;
        }

        ~queue(){
            if(this->data!=NULL)
            {
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

    tmp=q.dequeue();
    cout<<"dequeue value:"<<tmp<<endl;
    q.dequeue();
    q.IsFull();
    q.Display();
}

int main(){
    test();

    return 0;
}
