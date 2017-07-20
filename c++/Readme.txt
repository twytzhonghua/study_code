1vector_1.cpp
1vector.cpp					容器
2call_func_1.cpp
2call_func.cpp				引用 调用函数
2object.cpp					对象
2reload.cpp					重载
3function_template.cpp  	模板
4class_1					类
5constructor   				构造函数 析构函数
6this_pointer				this 指针  重复构造函数  static成员变量函数， 只能类访问， 对象不能访问
7friend						友元函数 友元类  友元函数可以访问类中的private成员
8Overload_operator			重载运算符
	3种方式: 
		1. 函数Time AddTime(Time& time1, Time& time2)	友元
		2. Time operator+(Time& time1, Time& time2)    友元
		3. Time Time::operator+(Time& time) 		内部函数
		
9继承与派生基础:
		已经存在的类叫父类, 基类或超类, 新建立的类被成为派生类或者子类
		
10 派生类的使用
	is -a 关系
	派生类中有方法的时候优先使用派生类的方法， 没有的话会使用基类的方法， 如果都有却想使用派生类的方法， 就必须指明基类
	派生类属于基类， 可以将派生类对象赋值给一个基类
	CCurrentTime curTime;
	Time time = curTime;
	
	也可以将基类的指针活引用直接引用给子类的对象
	Ctime* pTime = &curTime;
	pTime->getHour(); //基类的指针只能调用基类的方法, 不能调用派生类的方法
	
	has -a关系(包含)
	在类中把另一个类的对象作为本类的数据成员
	

