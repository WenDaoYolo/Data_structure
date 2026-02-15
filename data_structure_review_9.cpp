#include<iostream>
#include<cmath>
using namespace std;

#define MAXSIZE 64
typedef int ElemType;

class stack{
    public:
        ElemType* space;
        int top;

        //构造栈
        stack(){
            this->top=-1;
            this->space=new ElemType[MAXSIZE];
        }

        //判断栈空
        bool IsEmpty(){
            if(this->top==-1)
                return true;
            return false;
        }

        //判断栈满
        bool IsFull(){
            if(this->top==MAXSIZE-1)
                return true;
            return false;
        }

        //压栈、入栈
        void push(ElemType e){
            if(this->IsFull())
            {
                cout<<"stack is full!"<<endl;
                return;
            }
            this->top++;
            this->space[this->top]=e;
        }

        //出栈
        ElemType pop(){
            if(this->IsEmpty())
            {
                cout<<"stack is empty!"<<endl;
                return -1;
            }
            ElemType tmp=this->space[this->top];
            this->top--;
            return tmp;
        }

        //显示栈元素
        void Display(){
            for(int i=this->top;i>-1;i--)
                cout<<this->space[i]<<" ";
            cout<<endl;
        }

        //析构栈
        ~stack(){
            if(this->space!=NULL)
            {
                delete[] this->space;
                this->space=NULL;
                this->top=-1;
            }
        }
};

//定义符号类型
enum op{          //符号编码
    LeftC,        //0
    RightC,       //1
    Add,          //2
    Sub,          //3
    Mul,          //4
    Div,          //5
    Exp,          //6
    Eos,
    Num
};

//获取符号类型
op GetCharType(const char& ch){
        switch(ch){
            case '+':
                return Add;
            case '-':
                return Sub;
            case '*':
                return Mul;
            case '/':
                return Div;
            case '\0':
                return Eos;
            case '(':
                return LeftC;
            case ')':
                return RightC;
            case '^':
                return Exp;
            default:
                return Num;
        }
}

void PrintOP(const ElemType i){
    switch(i){
        case Add:
            cout<<'+';
            break;
        case Sub:
            cout<<'-';
            break;
        case Mul:
            cout<<'*';
            break;
        case Div:
            cout<<'/';
            break;
        case Exp:
            cout<<'^';
        default:
            ;
    }
}

/*
关键：
枚举成员的值、栈元素的值、优先级数组的下标，结合性数组下标，四者建立映射关系，正确的转换规则
栈内存的是运算符的编号(即枚举成员的值)，比较时先映射成对应数组的优先级或者结合性再比较和判断
*/

void Process(const string expr){
    int find=0;
    stack s;
    op type;
    s.push(-1);                                    //压入一个优先级最低的哨兵用于条件判断
                                                   //数组下标映射符号编码，数值越大优先级越高
    int stack_out[]={8,7,2,2,4,4,6};               //栈外优先级，'('一定比')'优先级高
    int stack_in[]={0,7,2,2,4,4,6};                //栈内优先级，'('入栈后优先级降为最低
    int coop[]={0,0,0,0,0,0,1};                    //操作符结合性的映射表,左结合性0,右结合性1
    
    while((type=GetCharType(expr[find]))!=Eos){
        if(type==Num)
            cout<<expr[find]; 
        else
        {
            if(type==LeftC)
                s.push(LeftC);                      //符号编码0,映射stack_in[0]=0,优先级最低
            else if(type==RightC)                   //右括号不需要入栈
            {
                while(s.space[s.top]!=LeftC){  
                    PrintOP(s.pop());
                }
                s.pop();                            //弹出左括号
            }
            else                                    //操作符优先级和结合性的判断,是算法的核心
            {
                if(coop[type]==0)                   //优先级高的位于栈顶先弹出,加减乘除都是左结合性,同级的先入栈的先弹出
                {                                   //哨兵-1没有映射优先级,所以要么进行映射要么就额外处理以访内存越界
                    while(stack_out[type]<=stack_in[s.space[s.top]]&&s.space[s.top]!=-1)
                    {
                        PrintOP(s.space[s.top]);
                        s.pop();
                    }
                }
                else                                //优先级高的位于栈顶先弹出,幂运算是右结合性,同级的先入栈的后弹出
                {
                    while(stack_out[type]<stack_in[s.space[s.top]]&&s.space[s.top]!=-1)
                    {
                        PrintOP(s.space[s.top]);
                        s.pop();
                    }
                }
                s.push(type);                       //直到栈顶操作符优先级比当前操作符低,才压栈
            }
        }
        find++;                                     //遍历表达式
    }
    while(s.top!=0){                                //遇到\0持续出栈输出直至遇到哨兵
        PrintOP(s.pop());
    }   
}

void test(){
    char expr[] = "2^3^2+4*5-6/2";
    Process(expr);
}

int main(){
    test();

    return 0;
}