#include<iostream>
typedef char elemtype;

struct tree_node
{
    elemtype data;
    int father;
};

void TestTree(tree_node* tree,int len)
{
    int index=tree[1].father;
    std::cout<<"B's father:"<<tree[index].data<<std::endl;

    index=tree[6].father;
    std::cout<<"G's father:"<<tree[index].data<<std::endl;

    index=tree[9].father;
    std::cout<<"J's father:"<<tree[index].data<<std::endl;
    
    index=6;
    std::cout<<"G's child:";
    for(int i=0;i<10;i++)
    {
	    int temp=tree[i].father;
	    if(temp==index)
		    std::cout<<tree[i].data<<" ";
    }
    std::cout<<std::endl;
}

int main()
{
    //-1表示A是根结点，没有父亲
    tree_node tree[10]={{'A',-1},{'B',0},{'C',0},{'D',0},{'E',1},{'F',1},{'G',3},{'H',6},{'I',6},{'J',6}};
    int len=sizeof(tree)/sizeof(tree_node);
    TestTree(tree,len);

    return 0;
}
