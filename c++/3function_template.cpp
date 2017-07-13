#include  <iostream>
#include  <vector>
using namespace std;

template <typename T>
T add(T a, T b)
{
	return a+b;
}


int main()
{
	int ret = add(1, 2);
	
	float r = add(1.1, 2.2);
	
	cout<<ret<<" "<<r<<endl;
	
	return 0;	
}

