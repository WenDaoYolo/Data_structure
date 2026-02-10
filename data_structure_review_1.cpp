#include<iostream>
using namespace std;
/*
    线性表-顺序表-c++
*/

//顺序表的定义
#define LIST_MAX_SIZE 100       //顺序表中c++无法像c一样重新调整内存大小
typedef int ElemType;

class List_s{
    public:
        ElemType* space;
        int length;

        //1.构造顺序表
        List_s(){
            this->length=0;
            this->space=new ElemType[LIST_MAX_SIZE];    
        }

        //2.元素的插入
        void Insert(ElemType e){
            if(this->length>LIST_MAX_SIZE){   //判断容量是否已满
                cout<<"is full!"<<endl;
                return;
            }

            this->space[this->length]=e;
            this->length++;
        }

        //3.指定元素的删除：待删除位置后的元素均向前移动并覆盖
        void Delete(int index){
            if(index<0||index>=this->length)
            {
                cout<<"error"<<endl;
                return;
            }

            for(int i=index;i<this->length-1;i++)
                this->space[i]=this->space[i+1];
            this->length--;
        }

        //4.元素查找、排序：详见算法

        //5.显示元素
        void Display(){
            for(int i=0;i<this->length;i++)
                cout<<this->space[i]<<" ";
            cout<<endl;
        }

        //6.反初始化(释放内存)
        ~List_s(){
            if(this->space!=NULL)
            {
                delete[] this->space;
                this->length=0;
            }
        }
};

void test(){
    List_s list;

    list.Insert(3);
    list.Insert(4);
    list.Insert(5);
    list.Insert(6);

    list.Display();
    printf("after:\n");
    list.Delete(2);
    list.Display();
}

int main(){
    test();

    return 0;
}