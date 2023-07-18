#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector> 
#include<windows.h>
#define N 100

using namespace std;
class student
{
	private:
		int num;
		string name;
		int age;
		string sex;
		int math;
		int english;
		int chinese;
		int score;
		string major;
		
	public:
		student();
		student(int num1,string name1,int age1,string sex1,int math1,int english1,int chinese1,string major);
		void dispaly();
		
		//*********get********//
		
		int get_num(){return num;}
		string get_name(){return name;}
		int get_age(){return age;}
		string get_sex(){return sex;}
		int get_math(){return math;}	
		int get_english(){return english;}
		int get_chinese(){return chinese;}
		int get_score(){return score;}
		string get_major(){return major;}
		
	    //*******¸ü¸Ä********//
		void num_change(int num1){num=num1;} 
		void name_change(string name1){name=name1;}
		void age_change(int age1){age=age1;}
		void sex_change(string sex1){sex=sex1;}
		void math_change(int math1){math=math1;}
		void english_change(int english1){english=english1;}
		void chinese_change(int chinese1){chinese=chinese1;}
		void major_change(string major1){major=major1;}
};

#endif
