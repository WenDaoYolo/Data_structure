#include<iostream>
#pragma once

template<class T>
class OrderQueue
{
    private:
        T* space_;
        int rear_,front_;
        size_t defa_,size_;
        
    public:
        OrderQueue():defa_(10),size_(defa_)
        {
            space_=new T[size_];
            rear_=front_=0;
        }

        OrderQueue(size_t size):defa_(10)
        {
            if(size==0) size_=1;
            space_=new T[size_];
            rear_=front_=0;
        }

        ~OrderQueue(){ if(space_) delete[] space_; }

        bool IsEmpty(){ return rear_==front_; }
        bool IsFull(){ return (rear_+1)%size_==front_; }
        
        void EnQueue(T e)
        {
            if(IsFull()) return;
            rear_=(rear_+1)%size_;
            space_[rear_]=e;
        }

        T DeQueue()
        {
            front_=(front_+1)%size_;
            T value=space_[front_];
            return value;
        }
};