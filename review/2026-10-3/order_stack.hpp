#include<iostream>
#include<memory.h>
#pragma once

template<class T>
class OrderStack
{
    private:
        T* space_;
        int len_,top_;
    private:
        bool IsFull(){ return top_==len_; }

        void IncMem()
        {
            T* tmp=new T[len_*2];
            memmove(tmp,space_,len_*sizeof(T));
            delete[] space_;
            space_=tmp;
            len_*=2;    
        }
    public:
        OrderStack():len_(10),top_(-1)
        { 
            this->space_=new T[len_];   
        }

        OrderStack(const OrderStack& other)
        {
            len_=other.len_;
            top_=other.top_;

            space_=new T[len_];
            memmove(space_,other.space_,len_*sizeof(T));
        }

        OrderStack(OrderStack&& other)
        {
            len_=other.len_;
            top_=other.top_;
            space_=other.space_;
            other.space_=nullptr;
        }

        ~OrderStack()
        {
            if(space_) 
            {
                delete[] space_;
                space_=nullptr;
                top_=0;
            }
        }

        void operator=(const OrderStack& other)
        {
            if(space_) delete space_;
            len_=other.len_;
            top_=other.top_;
            space_=new T[len_];
            memmove(space_,other.space_,len_*sizeof(T));
        }

        void operator=(OrderStack&& other)
        {
            len_=other.len_;
            top_=other.top_;
            space_=other.space_;
            other.space_=nullptr;
        }

        bool IsEmpty(){ return top_==-1; }        
        void Clear(){ top_=-1; }

        void Push(T e)
        {
            if(top_++,IsFull()) IncMem();
            space_[top_]=e;
        }

        T Pop()
        {
            if(IsEmpty()) throw std::runtime_error("stack empty");

            T value=space_[top_--];
            return value;
        }
};