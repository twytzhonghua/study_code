#include  <iostream>
#include  <vector>
using namespace std;

int main()
{
	string str;
	vector<string> v;
	
	while(getline(cin, str)){
		if(str == "qt"){
			break;
		}
		v.push_back(str);		
	}

	int nChars = 0;
	
	for(int i=0; i < v.size(); i++){
		string s = v[i];
		nChars += s.size();
		
	}
	
	cout<<"total lines: " <<v.size()<< "total chars "<<nChars<<endl;
	
	for(int i =0; i < v.size(); i++){
		
		string s = v[i];
		cout<<i<<" "<<s<<" "<<s.size()<<endl;
		
	}
	
	return 0;	
}

