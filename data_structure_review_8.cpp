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
enum op{
    Add,
    Sub,
    Mul,
    Div,
    LeftC,
    RightC,
    Exp,
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

//处理后缀表达式
int Process(const string expr){
    int pos=0,num1,num2;
    op flag;
    stack s;

    while((flag=GetCharType(expr[pos]))!=Eos){
        if(flag==Num)
        {
            s.push(expr[pos]-'0');
        }
        else if(flag!=LeftC&&flag!=RightC)
        {
                num2=s.pop();
                num1=s.pop();
            switch(flag)
            {
                case Add:
                    s.push(num1+num2);
                    break;
                case Sub:
                    s.push(num1-num2);
                    break;
                case Mul:
                    s.push(num1*num2);
                    break;
                case Div:
                    s.push(num1/num2);
                    break;
                case Exp:
                    s.push(pow(num1,num2));
                    break;
                default:
                    cout<<"error"<<endl;
            }
        }
        pos++;
    }
    return s.pop();
}

void test(){
    int result;
    const string expr1="82/2+56*-";
    const string expr2="232^^45*+62/-23^-422^^+";
    const string expr3="12/3-45*+12*-";

    result=Process(expr1);
    cout<<"result 1:"<<result<<endl;
    result=Process(expr2);
    cout<<"result 2:"<<result<<endl;
    result=Process(expr3);
    cout<<"result 3:"<<result<<endl;
}

int main(){
    test();

    return 0;
}