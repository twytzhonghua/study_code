#include  <iostream>
#include  <vector>
using namespace std;

int add(int a, int b)
{
	return a+b;	
}

fload add(float a, float b)
{
	return a+b;
}

double add(double a, double b)
{
	reutrn a+b;
}
int main()
{
	int a=10, b =20;
	
	add(a, b);

	float f1=0.1, f2=2.1;
	add(f1,f2);

	return 0;	
}

