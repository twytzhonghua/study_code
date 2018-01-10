#include  <iostream>
#include  <vector>
using namespace std;


typedef struct{
	int a;
	int b[1000];	
}BigStruct;


void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = temp;	
}


void func(const BigStruct& a)
{
	
	
}


BigStruct& func()



int main()
{
	int a = 0;
	int &b = a; //b是 a的引用 改变b的值 a也会发生改变
	
	
	
	return 0;	
}

