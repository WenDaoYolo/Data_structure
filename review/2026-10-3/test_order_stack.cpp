#include "order_stack.hpp"

void test1()
{
    OrderStack<char> o1;

    o1.Push('A');
    std::cout<<o1.Pop()<<std::endl;

    for(int i=0;i<11;i++)
        o1.Push('A'+i);

    OrderStack<char> o2(o1);
    OrderStack<char> o3(std::move(o1));
    //o2.Clear();
    
    while(!o2.IsEmpty())
        std::cout<<o2.Pop()<<" ";
    std::cout<<std::endl;

    while(!o3.IsEmpty())
        std::cout<<o3.Pop()<<" ";
    std::cout<<std::endl;
}

void test2()
{
    OrderStack<int> o1;
    OrderStack<int> o2;
    OrderStack<int> o3;

    for(int i=0;i<5;i++)
        o1.Push(i*100);
    
    o2=o1;
    o3=std::move(o1);

    while(!o2.IsEmpty())
        std::cout<<o2.Pop()<<" ";
    std::cout<<std::endl;

    while(!o3.IsEmpty())
        std::cout<<o3.Pop()<<" ";
    std::cout<<std::endl;
}

int main()
{
    //test1();
    test2();

    return 0;
}