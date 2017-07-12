#include  <iostream>
#include  <vector>
using namespace std;

int main()
{
	vector<int> v1;
	vector<int> v2(v1);
	vector<int> v3 = v1;
	
	vector<int> v4(10, 100);
	vecotr<int> v5(100);
	
 	vecotr<string> v6;
	
	v6.push_back("hello world.");
	v5.push_back(50);
	
	v4.pop_back();
	
	int nNum = v4[2];
	
	v4.at(2); 
	v4.front();
	v4.back();
	
	v4.size();
	v4.empty();
	
	
	
	return 0;	
}

