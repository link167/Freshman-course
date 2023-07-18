#include "student.h"

//**********¹¹Ôì*********// 
student::student()
{
}

student::student(int num1,string name1,int age1,string sex1,int math1,int english1,int chinese1,string major1)
{
	num=num1;
	name=name1;
	age=age1;
	sex=sex1;
	math=math1;
	english=english1;
	chinese=chinese1;
	score=math+english+chinese;
	major=major1;
}

//********show*********//
void student::dispaly()
{
	cout<<setw(6)<<left<<num
	    <<setw(6)<<left<<name
		<<setw(6)<<left<<age
		<<setw(6)<<left<<sex
		<<setw(6)<<left<<math
		<<setw(6)<<left<<english
		<<setw(6)<<left<<chinese
		<<setw(6)<<left<<score
		<<setw(6)<<left<<major<<endl;
}

