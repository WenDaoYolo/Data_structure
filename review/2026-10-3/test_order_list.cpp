#include "order_list.hpp"

void test1()
{
    OrderList<int> o1;
    for(int i=0;i<11;i++)
        o1.PushBack(i);
    
    o1[0]=999;
    std::cout<<o1[0]<<std::endl;
    std::cout<<o1.Size()<<std::endl;

    std::cout<<o1.PopBack()<<std::endl;
    std::cout<<o1.PopBack()<<std::endl;
    std::cout<<o1.Size()<<std::endl;

    o1.Clear();
    std::cout<<o1.Size()<<std::endl;
}

void test2()
{
    OrderList<char> o1(5);
    for(int i=0;i<5;i++)
        o1.PushBack('A'+i);
    
    OrderList<char> o2(o1);
    o1.PopBack();
    OrderList<char> o3(std::move(o1));

    std::cout<<o2.Size()<<std::endl;
    std::cout<<o3.Size()<<std::endl;

    for(int i=0;i<o2.Size();i++)
        std::cout<<o2[i]<<" ";
    std::cout<<std::endl;

    for(int i=0;i<o3.Size();i++)
        std::cout<<o3[i]<<" ";
    std::cout<<std::endl;
}

void test3()
{
    OrderList<char> o1(5);
    OrderList<char> o2;
    OrderList<char> o3(5);

    for(int i=0;i<5;i++)
        o1.PushBack('A'+i);
    
    o2=o1;
    o1.PushBack('R');
    o3=std::move(o1);

    for(int i=0;i<o2.Size();i++)
        std::cout<<o2[i]<<" ";
    std::cout<<std::endl;

    for(int i=0;i<o3.Size();i++)
        std::cout<<o3[i]<<" ";
    std::cout<<std::endl;
}

void test4()
{
    OrderList<char> o1;
    for(int i=0;i<10;i++) o1.PushBack('A'+i);
    
    for(int i=0;i<o1.Size();i++)
        std::cout<<o1[i]<<" ";
    std::cout<<std::endl;
    
    o1.Insert(2,'Z');
    o1.Insert(o1.Size(),'K');

    for(int i=0;i<o1.Size();i++)
        std::cout<<o1[i]<<" ";
    std::cout<<std::endl;

    o1.Delete(0);
    o1.Delete(o1.Size()-1);

    for(int i=0;i<o1.Size();i++)
        std::cout<<o1[i]<<" ";
    std::cout<<std::endl;

    o1.Clear();
    if(o1.IsEmpty()) std::cout<<"empty..."<<std::endl;
    o1.PushBack('W');
    o1.PushBack('Y');

    for(int i=0;i<o1.Size();i++)
        std::cout<<o1[i]<<" ";
    std::cout<<std::endl;
}

int main()
{
    //test1();
    //test2();
    //test3();
    test4();

    return 0;
}