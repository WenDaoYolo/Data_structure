#include "order_queue.hpp"

void test1()
{
    OrderQueue<int> o1;
    OrderQueue<char> o2(0);

    if(o1.IsEmpty()&&o2.IsEmpty())
        std::cout<<"empty..."<<std::endl;
    
    o1.EnQueue(1);
    o1.EnQueue(2);
    o1.EnQueue(3);
    o1.EnQueue(4);
    o1.EnQueue(5);
    o1.EnQueue(6);
    o1.EnQueue(7);
    o1.EnQueue(8);
    o1.EnQueue(9);
    o1.EnQueue(10);

    while(!o1.IsEmpty())
        std::cout<<o1.DeQueue()<<" ";
    std::cout<<std::endl;
}

int main()
{
    test1();

    return 0;
}