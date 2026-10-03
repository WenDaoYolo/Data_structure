#include<iostream>
#pragma once

template<class T>
struct Node
{
    T data;
    Node<T>* next;
};

template<class T>
class LinkStack
{
    private:
        Node<T>* top_;
    public:
        LinkStack():top_(nullptr){}

        ~LinkStack()
        {
            while(top_)
            {
                Node<T>* tmp=top_;
                top_=top_->next;
                delete tmp;
            }
        }

        bool IsEmpty(){ return top_==nullptr; }

        void Push(T e)
        {
            Node<T>* tmp=new Node<T>;
            tmp->data=e;

            if(top_!=nullptr)
                tmp->next=top_;
            else
                tmp->next=nullptr;

            top_=tmp;
        }

        T Pop()
        {
            Node<T>* tmp=top_;
            top_=top_->next;
            
            T value=tmp->data;
            delete tmp;
            return value;
        }
};