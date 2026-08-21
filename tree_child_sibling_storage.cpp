#include<iostream>

typedef char elemtype;

struct tree_node 
{
    elemtype data;
    tree_node* first_child;
    tree_node* next_sibling;
};

struct tree
{
    tree_node* head;
};

tree T;
tree_node* tmp0;
tree_node* tmp1;
tree_node* tmp2;
tree_node* tmp3;
tree_node* tmp4;
tree_node* tmp5;
tree_node* tmp6;
tree_node* tmp7;
tree_node* tmp8;
tree_node* tmp9;

void CreatTree()
{
    tmp0=new tree_node;
    tmp1=new tree_node;
    tmp2=new tree_node;
    tmp3=new tree_node;
    tmp4=new tree_node;
    tmp5=new tree_node;
    tmp6=new tree_node;
    tmp7=new tree_node;
    tmp8=new tree_node;
    tmp9=new tree_node;

    T.head=tmp0;
    tmp0->data='A';
    tmp1->data='B';
    tmp2->data='C';
    tmp3->data='D';
    tmp4->data='E';
    tmp5->data='F';
    tmp6->data='G';
    tmp7->data='H';
    tmp8->data='I';
    tmp9->data='J';

    tmp0->first_child=tmp1;
    tmp0->next_sibling=NULL;

    tmp1->first_child=tmp4;
    tmp1->next_sibling=tmp2;

    tmp2->first_child=NULL;
    tmp2->next_sibling=tmp3;

    tmp3->first_child=tmp6;
    tmp3->next_sibling=NULL;

    tmp4->first_child=NULL;
    tmp4->next_sibling=tmp5;

    tmp5->first_child=NULL;
    tmp5->next_sibling=NULL;

    tmp6->first_child=tmp7;
    tmp6->next_sibling=NULL;

    tmp7->first_child=NULL;
    tmp7->next_sibling=tmp8;
    
    tmp8->first_child=NULL;
    tmp8->next_sibling=tmp9;
    
    tmp9->first_child=NULL;
    tmp9->next_sibling=NULL;
}

void PrevOrderSearch(tree_node* root)
{
	if(root==NULL)
	{
        std::cout<<"#";
        return;
    }
	std::cout<<root->data;
	PrevOrderSearch(root->first_child);
	PrevOrderSearch(root->next_sibling);
}

void MidOrderSearch(tree_node* root)
{
	if(root==NULL)
	{
        std::cout<<"#";
        return;
    }
	MidOrderSearch(root->first_child);
	std::cout<<root->data;
	MidOrderSearch(root->next_sibling);
}

void BehindOrderSearch(tree_node* root)
{
	if(root==NULL)
	{
        std::cout<<"#";
        return;
    }
	BehindOrderSearch(root->first_child);
	BehindOrderSearch(root->next_sibling);
	std::cout<<root->data;
}

void DestroyTree()
{
    delete tmp0;
    delete tmp1;
    delete tmp2;
    delete tmp3;
    delete tmp4;
    delete tmp5;
    delete tmp6;
    delete tmp7;
    delete tmp8;
    delete tmp9;
}

int main()
{
    CreatTree();
    
    PrevOrderSearch(T.head);   
    std::cout<<std::endl;
    MidOrderSearch(T.head);
    std::cout<<std::endl;
    BehindOrderSearch(T.head);
    std::cout<<std::endl;

    DestroyTree();
    return 0;
}