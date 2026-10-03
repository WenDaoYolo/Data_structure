#include<iostream>
#pragma once

template<class T>
struct Node
{
    Node* last;
    T data;
    Node* next;
};

template<class T>
class LinkList
{
    private:
        Node<T>* head_;
        Node<T>* tail_;

    public:
        LinkList()
        {
            head_=new Node<T>;
            head_->last=nullptr;
            head_->data=0;
            head_->next=nullptr;
            tail_=head_;
        }

        bool IsEmpty(){ return head_==tail_; };

        void PushBack(T e)
        {
            Node<T>* tmp=new Node<T>;
            tmp->data=e;
            tmp->last=tail_;
            tmp->next=nullptr;
            
            tail_->next=tmp;
            tail_=tmp;
        }

        T PopBack()
        {
            T value=tail_->data;
            tail_=tail_->last;
            tail_->next=nullptr;

            delete tail_->next;
            return value;
        }

        void PushFront(T e)
        {
            Node<T>* tmp=new Node<T>;
            tmp->data=e;
            tmp->last=head_;
            tmp->next=head_->next;

            if(head_->next!=nullptr)
                head_->next->last=tmp;
            else
                tail_=tmp;

            head_->next=tmp;
        }

        T PopFront()
        {
            Node<T>* tmp=head_->next;
            T value=tmp->data;

            head_->next=tmp->next;
            if(head_->next!=nullptr)
                head_->next->last=head_;    
            else
                tail_=head_;

            delete tmp;
            return value;
        }

                                                      //和STL容器中迭代器失效的场景同理
        Node<T>* FrontNode(){ return (head_->next); } //插入删除或扩容后，原指针可能会失效
        Node<T>* TailNode(){ return tail_; }          //插入删除或扩容后，原指针可能会失效

        ~LinkList()
        {
            Node<T>* ptr;
            while(head_!=nullptr)
            {
                ptr=head_;
                head_=head_->next;
                delete ptr;
            }
        }
};