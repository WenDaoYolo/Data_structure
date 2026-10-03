#include<iostream>
#include<memory.h>
#pragma once

template<class T>
class OrderList
{
    private:
        T* start_;
        T* end_;
        size_t defa_,len_;
    private:
        bool IsFull(){ return end_==start_+len_; }
        
        void IncMem()
        {
            if(!len_) len_=defa_;
            T* ptr=new T[len_*2];
            memmove(ptr,start_,len_*sizeof(T));
            size_t endpos=end_-start_;

            delete[] start_;
            start_=ptr;
            end_=start_+endpos;
            len_*=2;
        }
    public:
        OrderList():defa_(10),len_(defa_)
        {
            start_ =new T[len_];
            end_=start_;
        }

        OrderList(size_t len):defa_(10),len_(len)
        {
            start_ =new T[len_];
            end_=start_;
        }

        OrderList(const OrderList& other)
        {
            defa_=other.defa_;
            len_=other.len_;
            int endpos=other.end_-other.start_;

            start_=new T[len_];
            memcpy(start_,other.start_,len_*sizeof(T));
            end_=start_+endpos;
        }

        OrderList(OrderList&& other)
        {
            defa_=other.defa_;
            len_=other.len_;
            start_=other.start_;
            end_=other.end_;

            other.start_=nullptr;
        }

        ~OrderList(){ if(start_&&len_) delete[] start_; }
        
        void operator=(const OrderList& other)
        {
            defa_=other.defa_;
            len_=other.len_;
            int endpos=other.end_-other.start_;

            if(start_) delete[] start_;
            start_=new T[len_];
            memcpy(start_,other.start_,len_*sizeof(T));
            end_=start_+endpos;
        }

        void operator=(OrderList&& other)
        {
            defa_=other.defa_;
            len_=other.len_;
            start_=other.start_;
            end_=other.end_;

            other.start_=nullptr;
        }

        T& operator[](size_t index){ return *(start_+index); }
        bool IsEmpty(){ return end_==start_; };
        size_t Size(){ return end_-start_; };
        void Clear() { end_=start_; }

        void Insert(int index,T e)
        {
            if(index<0||index>len_) 
            {
                std::cout<<"index is wrong"<<std::endl;
                throw index;
            }

            if(IsFull()) IncMem();
            for(T* find=end_;find>start_+index;find--) *find=*(find-1);
            
            end_++;
            *(start_+index)=e;
        }

        void Delete(int index)
        {
            if(index<0||index>=end_-start_)
            {
                std::cout<<"index is wrong"<<std::endl;
                throw index;
            }

            for(T* find=start_+index;find<end_;find++) *find=*(find+1);
            end_--;
        }
        
        void PushBack(T e)
        {
            if(IsFull()) IncMem();
            *(end_++)=e;
        }

        T PopBack()
        {
            T tmp=*(--end_);
            return tmp;
        }
};