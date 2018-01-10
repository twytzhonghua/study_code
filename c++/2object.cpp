#include  <iostream>
#include  <vector>
using namespace std;

class Student
{
	public:
	void print()
	{
		std::cout<<name<<","<<age<<","<<addr<<std::endl;
	}
	int getAge();
private:
	char name[128];
	int age;
	char addr[128];
		
};

int Student::getAge()
{
	return age;
}


int main()
{
	Student stu;
	stu.print();
	stu.getAge();
	
	Student *p = &stu; //指针
	p->print();
	p->getAge();
	
	Student & s = stu;  //引用
	s.print();
	s.getAge();
				
	return 0;	
}

