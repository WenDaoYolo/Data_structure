#include<iostream>
using namespace std;
/*
    Õ»-Á´Õ»-cpp
*/

//Á´Ê½Õ»¶¨Òå
typedef int ElemType;

class Node{
    public:
        ElemType data;
        Node* next;
};

class stack{
    public:
        int length;
        Node* top;

        //¹¹ÔìÕ»
        stack(){
            this->length=0;
            this->top=NULL;
        }

        //ÅÐ¶ÏÕ»¿Õ
        bool IsEmpty(){
            if(this->length==0)
                return true;
            return false;
        }

        //Ñ¹Õ»¡¢ÈëÕ»
        void push(ElemType e){
            Node* tmp=new Node;
            tmp->data=e;

            tmp->next=this->top;
            this->top=tmp;
            this->length++;
        }

        //³öÕ»
        void pop(ElemType* re){
            if(this->IsEmpty())
            {
                cout<<"stack is empty!"<<endl;
                return;
            }
            
            Node* tmp=this->top;
            this->top=this->top->next;
            *re=tmp->data;
            delete tmp;
            this->length--;
        }

        //ÏÔÊ¾Õ»ÔªËØ
        void Display(){
            Node* find=this->top;
            while(find!=NULL)
            {
                cout<<find->data<<" ";
                find=find->next;
            }
            cout<<endl;
        }

        //Îö¹¹Õ»
        ~stack(){
            Node* find=this->top;
            Node* del=NULL;
            while(find!=NULL)
            {
                del=find;
                find=find->next;
                delete del;
                del=NULL;
            }
        }
};

void test(){
    stack s1;
    ElemType tmp;
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);

    s1.pop(&tmp);
    cout<<"pop after:"<<tmp<<endl;
    s1.Display();
    s1.pop(&tmp);
    s1.pop(&tmp);
    s1.pop(&tmp);
    s1.pop(&tmp);
    s1.pop(&tmp);
}

int main(){
    test();

    return 0;
}

