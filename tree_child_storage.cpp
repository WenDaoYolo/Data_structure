#include<iostream>

typedef char elemtype;

struct clink_node
{
    int index_in_array;
    clink_node* next;
};

struct tree_node
{
    elemtype data;
    clink_node childs;
    clink_node* tail;
};

//链表也可改用为c++动态数组，更简单方便
tree_node tree[10]=
{
    {'A',{-1,NULL}},{'B',{-1,NULL}},
    {'C',{-1,NULL}},{'D',{-1,NULL}},
    {'E',{-1,NULL}},{'F',{-1,NULL}},
    {'G',{-1,NULL}},{'H',{-1,NULL}},
    {'I',{-1,NULL}},{'J',{-1,NULL}}
};

void InsertLink(tree_node& node,int position)
{
    clink_node* tmp=new clink_node;
    tmp->index_in_array=position;
    tmp->next=NULL;

    node.tail->next=tmp;
    node.tail=tmp;
}

void InitTree()
{
    tree[0].tail=&(tree[0].childs);
    tree[1].tail=&(tree[1].childs);
    tree[2].tail=&(tree[2].childs);
    tree[3].tail=&(tree[3].childs);
    tree[4].tail=&(tree[4].childs);
    tree[5].tail=&(tree[5].childs);
    tree[6].tail=&(tree[6].childs);
    tree[7].tail=&(tree[7].childs);
    tree[8].tail=&(tree[8].childs);
    tree[9].tail=&(tree[9].childs);
}

void CreateTree()
{
    InsertLink(tree[0],1);
    InsertLink(tree[0],2);
    InsertLink(tree[0],3);

    InsertLink(tree[1],4);
    InsertLink(tree[1],5);

    InsertLink(tree[3],6);

    InsertLink(tree[6],7);
    InsertLink(tree[6],8);
    InsertLink(tree[6],9);
}

void DisplayChild(clink_node* start)
{
    clink_node* look=start;
    while(look!=NULL)
    {
        int index=look->index_in_array;
        std::cout<<tree[index].data<<" ";
        look=look->next;
    }
    std::cout<<std::endl;
}

void TestTree()
{
    std::cout<<"A's Child:";
    DisplayChild(tree[0].childs.next);
    std::cout<<"C's Child:";
    DisplayChild(tree[2].childs.next);
    std::cout<<"G's Child:";
    DisplayChild(tree[6].childs.next);

    std::cout<<"I's Father:";
    for(int i=0;i<10;i++)
    {
        clink_node* find=tree[i].childs.next;
        while(find!=NULL)
        {
            if(find->index_in_array==8)
            {
                std::cout<<tree[i].data<<std::endl;
                return;
            }
            find=find->next;
        }
    }
    std::cout<<"not exist"<<std::endl;
}

void DestroyTree()
{
    for(int i=0;i<10;i++)
    {
        clink_node* temp=NULL;
        clink_node* find=tree[i].childs.next;
        while(find!=NULL)
        {
            temp=find;
            find=find->next;
            delete temp;
        }
    }
}

int main()
{
    InitTree();
    CreateTree();
    TestTree();
    DestroyTree();

    return 0;
}