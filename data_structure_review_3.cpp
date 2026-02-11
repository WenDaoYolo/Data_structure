#include<iostream>
using namespace std;
/*
    Õ»-Ë³ÐòÕ»-cpp
*/

//Ë³ÐòÕ»µÄ¶¨Òå
#define MAXSIZE 3
typedef int ElemType;

class stack{
    public:
        ElemType* space;
        int top;

        //¹¹ÔìÕ»
        stack(){
            this->top=-1;
            this->space=new int[MAXSIZE];
        }

        //ÅÐ¶ÏÕ»¿Õ
        bool IsEmpty(){
            if(this->top==-1)
                return true;
            return false;
        }

        //ÅÐ¶ÏÕ»Âú
        bool IsFull(){
            if(this->top==MAXSIZE-1)
                return true;
            return false;
        }

        //Ñ¹Õ»¡¢ÈëÕ»
        void push(ElemType e){
            if(this->IsFull())
            {
                cout<<"stack is full!"<<endl;
                return;
            }
            this->top++;
            this->space[this->top]=e;
        }

        //³öÕ»
        void pop(ElemType* re){
            if(this->IsEmpty())
            {
                cout<<"stack is empty!"<<endl;
                return;
            }
            *re=this->space[this->top];
            this->top--;
        }

        //ÏÔÊ¾Õ»ÔªËØ
        void Display(){
            for(int i=this->top;i>-1;i--)
                cout<<this->space[i]<<" ";
            cout<<endl;
        }

        //Îö¹¹Õ»
        ~stack(){
            if(this->space!=NULL)
            {
                delete[] this->space;
                this->space=NULL;
                this->top=-1;
            }
        }
};

void test(){
    stack s1;
    ElemType tmp;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    s1.pop(&tmp);
    s1.Display();
    s1.pop(&tmp);
    s1.pop(&tmp);
    s1.pop(&tmp);
}

int main(){
    test();

    return 0;
}