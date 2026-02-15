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

//计算表达式(出栈，出栈，出栈，计算压栈)
void Calculate(stack& s1,stack& s2,ElemType type){
    int num2=s1.pop();
    int num1=s1.pop();
    switch(type)
    {
        case Add:
        s1.push(num1+num2);
        break;
        case Sub:
        s1.push(num1-num2);
        break;
        case Mul:
        s1.push(num1*num2);
        break;
        case Div:
        s1.push(num1/num2);
        break;
        case Exp:
        s1.push((int)pow(num1,num2));
    }
    s2.pop();
}

//处理表达式
int Process(const string expr){
    stack s1,s2;
    int stack_in[]={0,9,4,4,6,6,7};               //栈内优先级
    int stack_out[]={10,9,4,4,6,6,7};             //栈外优先级
    int coop[]={0,0,0,0,0,0,1};                   //结合性映射表,左结合0,右结合1
    s2.push(-1);                                  //压入哨兵
    int find=0;                                   //用于遍历表达式的下标
    ElemType tmp;                                 //存储字符的编码和类型
    while((tmp=GetCharType(expr[find]))!=Eos){ 
        if(tmp==Num)                              //操作数直接压栈
        {
            s1.push(expr[find]-'0');
        }
        else
        {
            if(tmp==LeftC)                        //左括号直接压栈
            {
                s2.push(LeftC);
            }
            else if(tmp==RightC)                  //右括号持续出栈计算并压栈
            {
                while(s2.space[s2.top]!=LeftC){
                    Calculate(s1,s2,s2.space[s2.top]);
                }
                s2.pop();                         //弹出左括号
            }
            else     
            {                                     //哨兵-1没有映射优先级,所以要么进行映射要么就额外处理以访内存越界    
                if(coop[tmp]==0)                  //优先级高的位于栈顶先弹出,加减乘除都是左结合性,同级的先入栈的先弹出
                {
                    while(stack_out[tmp]<=stack_in[s2.space[s2.top]]&&s2.space[s2.top]!=-1)
                        Calculate(s1,s2,s2.space[s2.top]);
                }
                else                              //优先级高的位于栈顶先弹出,幂运算是右结合性,同级的先入栈的后弹出
                {
                    while(stack_out[tmp]<stack_in[s2.space[s2.top]]&&s2.space[s2.top]!=-1)
                        Calculate(s1,s2,s2.space[s2.top]);
                }
                s2.push(tmp);                     //直到栈顶操作符优先级比当前操作符低，才压栈
            }
        }
        find++;
    }
    while(s2.top!=0){                             //遇到\0持续计算直至遇到哨兵
        Calculate(s1,s2,s2.space[s2.top]);
    }
    return s1.pop();                              //返回最终计算结果
}

void test(){
    const string expr="((3+5)-2)*2^3^2";
    int result=Process(expr);
    cout<<expr<<"="<<result<<endl;
}

/*
关键：
枚举成员的值、栈元素的值、优先级数组的下标，结合性数组下标，四者建立映射关系，正确的转换规则
栈内存的是运算符的编号(即枚举成员的值)，比较时先映射成对应数组的优先级或者结合性再比较和判断

记录第一次手撕中缀表达式时遇到的bug：
1.哨兵优先级未映射，要么进行映射要么进行额外处理
2.计算表达式时错了，使用的是当前操作符而非栈顶操作符
3.表达式计算完成后，当前操作符忘记压栈
4.没有考虑和判断当前的操作符是否能压栈
*/
int main(){
    test();

    return 0;
}