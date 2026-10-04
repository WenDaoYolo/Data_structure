#include "link_queue.hpp"

void test1()
{
    LinkQueue<char> l1;
    LinkQueue<char> l2;
    if(l1.IsEmpty()) std::cout<<"empty..."<<std::endl;

    for(int i=0;i<10;i++)
    {
        l1.EnQueue('A'+i);
        l2.EnQueue('a'+i);
    }

    while(!l1.IsEmpty())
        std::cout<<l1.DeQueue()<<" ";
    std::cout<<std::endl;
}

int main()
{
    test1();

    return 0;
}