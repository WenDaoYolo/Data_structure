#include<iostream>
#pragma once

template<class T>
struct Node
{
    T data;
    Node<T>* next;
};

template<class T>
class LinkQueue
{
    private:
        Node<T>* rear_;
        Node<T>* front_;
    public:
        LinkQueue()
        {
            rear_=new Node<T>;
            rear_->data=0;
            rear_->next=nullptr;
            front_=rear_;
        }

        ~LinkQueue()
        {
            while(front_)
            {
                Node<T>* tmp=front_;
                front_=front_->next;
                delete tmp;
            }
        }

        bool IsEmpty(){ return front_->next==nullptr; }

        void EnQueue(T e)
        {
            Node<T>* tmp=new Node<T>;
            tmp->data=e;
            
            tmp->next=rear_->next;
            rear_->next=tmp;
            rear_=tmp;
        }

        T DeQueue()
        {
            Node<T>* tmp=front_->next;
            front_->next=tmp->next;

            if(tmp==rear_)
                rear_=front_;
            
            T value=tmp->data;
            delete tmp;
            return value;
        }
};  