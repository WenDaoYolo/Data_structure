#include<iostream>
#include<iomanip>
using namespace std;

int b5;               //.bss
int b3=10;            //.data
const int b4=1;       //.rodata 

void stack_fun()
{
    int b2;           //stack
    int* b1=new int;  //heap

    cout<<left<<setw(20)<<"stack address:"<<hex<<&b2<<endl; 
    cout<<left<<setw(20)<<"heap address:"<<hex<<b1<<endl;
}

int main(){
    stack_fun();
    cout<<left<<setw(20)<<"bss address:"<<hex<<&b5<<endl;
    cout<<left<<setw(20)<<"data address:"<<hex<<&b3<<endl;
    cout<<left<<setw(20)<<"rodata address:"<<hex<<&b4<<endl;
    
    return 0;
}