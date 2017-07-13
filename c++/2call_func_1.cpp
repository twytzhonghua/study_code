#include  <iostream>
#include  <vector>
using namespace std;


void move(int step = 1, int delta = 20);


void func(int i, int j=10, int k =20, int l =30);

int main()
{

	move(2, 40);
	move(2);
	move(); //不指定使用默认值
	
	
	func(10, 20, 30, 40);
	func(10, 20, 30);
	func(10, 20);
	func(10);
	
	return 0;	
}

