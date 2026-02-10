#include<iostream>
using namespace std;

void function1(){
	for(int i=0;i<100;i++)
		putchar('a');          //执行100次
	
	puts("-----------");       //执行1次	
	putchar('\n');             //执行1次
}                             

//100+1+1结果为常数，所以时间复杂度为O(1)

void function2(int n){
	for(int i=1;i<n;i=i*2)     
		putchar('a');          //2^x=n,x=log2n,所以执行log2n次
	
	putchar('\n');             //执行1次
}

//log2n+1，取log2n，所以时间复杂度为O(log2n)

void function3(int n){
	for(int i=0;i<=n;i++)
		putchar('a');          //执行n+1次
	
	putchar('\n');             //执行1次
}

//n+1+1，取n，所以时间复杂度为O(n)

void function4(int n){
	for(int i=0;i<=n;i++)
        for(int j=0;j<n;j*=2)
		    putchar('a');//执行(n+1)log2n次，实际估算可以直接将+1省略，但最终表达式省略更严谨
	
	putchar('\n');       //执行1次
}

//(n+1)log2n+1即nlog2n+log2n+1，取nlog2n，所以时间复杂度为O(nlog2n)

void function5(int n){
	for(int i=0;i<n;i++)
		for(int j=0;i<n;i++)
			putchar('a');          //执行n*n,即n^2次
}

//n^2，所以时间复杂度为O(n^2)

void function6(int n){
	for(int i=0;i<n;i++)
		for(int j=0;i<n;i++)
			for(int k=0;k<n;k++)
				putchar('a');     //执行n*n*n,即n^3次
}

//n^3，所以时间复杂度为O(n^3)

int main(){

    return 0;
}