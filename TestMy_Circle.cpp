#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include "My_Circle.h"

#if 0
using namespace std;

int main() {
	My_Circle C;
	C.SetR(10);
	cout << "圆的半径:" << C.GetR() << endl;
	cout << "圆的面积:" << C.GetCircleArea() << endl;
	cout << "圆的周长:" << C.GetCircleLength() << endl;

	return 0;
}
#endif