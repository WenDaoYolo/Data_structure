#include "link_list.hpp"

void test1()
{
    LinkList<char> l1;
    if(l1.IsEmpty()) std::cout<<"empty..."<<std::endl;

    l1.PushBack('A');
    l1.PushBack('B');
    l1.PushBack('C');
    std::cout<<l1.PopFront()<<" "<<l1.PopFront()<<" "<<l1.PopFront()<<std::endl;

    l1.PushFront('A');
    l1.PushFront('B');
    l1.PushFront('C');
    std::cout<<l1.PopBack()<<" "<<l1.PopBack()<<" "<<l1.PopBack()<<std::endl;
}

void test2()
{
    LinkList<float> l1;
    l1.PushBack(3.14);
    l1.PushBack(3.15);
    l1.PushBack(3.16);
    l1.PushBack(3.17);
    l1.PushFront(3.33);

    Node<float>* find1=l1.FrontNode();
    while(!l1.IsEmpty()&&find1)
    {
        std::cout<<find1->data<<" ";
        find1=find1->next;
    }
    std::cout<<std::endl;

    Node<float>* find2=l1.TailNode();
    while(!l1.IsEmpty()&&find2->last!=nullptr)
    {
        std::cout<<find2->data<<" ";
        find2=find2->last;
    }
    std::cout<<std::endl;
}

int main()
{
    //test1();
    test2();

    return 0;
}