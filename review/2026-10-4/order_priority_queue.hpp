#include<iostream>
#include<memory.h>
#pragma once

/*
    顺序存储中的下标关系
    i,i*2,i*2+1 or i,i*2+1,i*2+2
    j/2 or (j-1)/2
*/

template<class T>
class OrderPriorityQueue
{
    private:
        T* space_;
        size_t defa_,len_;
        int priority_,rear_,front_;
        //priority：1 Bigger，0 Smaller
    private:
        void IncMem()
        {
            T* tmp=new T[len_*2];
            memmove(tmp,space_,len_*sizeof(T));

            if(space_) delete[] space_;
            space_=tmp;
            len_*=2;
        }

        bool IsFull(){ return rear_==len_; }

        void BigHeapUp(int index)
        {
            int root=(index-1)/2;
            if(root>=0&&space_[index]>space_[root])
            {
                std::swap(space_[index],space_[root]);
                BigHeapUp(root);
            }
        }

        void BigHeapDown(int root)
        {
            int max=root,left=root*2+1,right=root*2+2;
            if(left<rear_&&space_[max]<space_[left])
                max=left;
            if(right<rear_&&space_[max]<space_[right])
                max=right;
            if(max!=root)
            {
                std::swap(space_[max],space_[root]);
                BigHeapDown(max);
            }
        }

        void SmallHeapUp(int index)
        {
            int root=(index-1)/2;
            if(root>=0&&space_[index]<space_[root])
            {
                std::swap(space_[index],space_[root]);
                SmallHeapUp(root);
            }
        }

        void SmallHeapDown(int root)
        {
            int min=root,left=root*2+1,right=root*2+2;
            if(left<rear_&&space_[min]>space_[left])
                min=left;
            if(right<rear_&&space_[min]>space_[right])
                min=right;
            if(min!=root)
            {
                std::swap(space_[min],space_[root]);
                SmallHeapDown(min);
            }
        }
    public:
        OrderPriorityQueue():defa_(10)
        {
            len_=defa_;
            priority_=1;
            space_=new T[len_];
            rear_=front_=0;
        }

        OrderPriorityQueue(size_t size,int priority):defa_(10)
        {
            len_=size;
            priority_=priority;
            if(len_==0) len_=defa_;
            space_=new T[len_];
            rear_=front_=0;
        }

        ~OrderPriorityQueue(){ if(space_) delete[] space_; }
        
        bool IsEmpty(){ return rear_==front_; }

        void EnQueue(T e)
        {
            if(IsFull()) IncMem();
            space_[rear_]=e;

            if(priority_)
                BigHeapUp(rear_);
            else
                SmallHeapUp(rear_);
            rear_++;
        }

        T DeQueue()
        {
            T value=space_[front_];
            std::swap(space_[front_],space_[rear_-1]);
            rear_--;

            if(priority_)
                BigHeapDown(front_);
            else
                SmallHeapDown(front_);
            return value;
        }
};