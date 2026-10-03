#include "link_stack.hpp"

void test1()
{
    LinkStack<char> l1;
    if(l1.IsEmpty()) std::cout<<"empty..."<<std::endl;

    l1.Push('D');
    l1.Push('C');
    l1.Push('B');
    l1.Push('A');

    while(!l1.IsEmpty())
        std::cout<<l1.Pop()<<" ";
    std::cout<<std::endl;
}

int main()
{
    test1();

    return 0;
}