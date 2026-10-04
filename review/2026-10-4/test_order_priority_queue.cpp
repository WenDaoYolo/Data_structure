#include "order_priority_queue.hpp"

void test1()
{
    OrderPriorityQueue<char> o1(5,0);
    OrderPriorityQueue<int> o2;

    o1.EnQueue('W');
    o1.EnQueue('A');
    o1.EnQueue('C');
    o1.EnQueue('B');
    o1.EnQueue('T');
    o1.EnQueue('D');
    o1.EnQueue('F');
    o1.EnQueue('E');

    o2.EnQueue(7);
    o2.EnQueue(11);
    o2.EnQueue(14);
    o2.EnQueue(5);
    o2.EnQueue(127);
    o2.EnQueue(13);

    while(!o1.IsEmpty())
        std::cout<<o1.DeQueue()<<" ";
    std::cout<<std::endl;

    while(!o2.IsEmpty())
        std::cout<<o2.DeQueue()<<" ";
    std::cout<<std::endl;
}

int main()
{
    test1();

    return 0;
}