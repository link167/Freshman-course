#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <pthread.h>
#include <time.h>
using namespace std;


class data
{
	private:
		int year;
		int month;
		int day;
	public:
		//********构造*******// 
		data();
		data(int year_parm,int month_parm,int day_parm);
		
		
		void show();
		void show_month(int year,int month); 
		//*****判断*********//
		bool judge(int year,int month,int day);
		bool judge_LeapYear(int year_parm);
		//*****运算符重载***// 
		data operator +(int parm);
		data operator -(int parm);
		data operator -(data pram);
		//*****get*********//
		int get_year(){return year;}
		int get_month(){return month;}
		int get_day(){return day;}
		int get_month_day(int year,int month);
		//*****change*****//
		void change_year(int pram){year=pram;}
		void change_month(int pram){month=pram;}
		void change_day(int pram){day=pram;}
		//*****比较*******//
		bool Compare(data pram); 
		//*****交换******//
		void Change(data &pram);
		//*****赋值*****//
		void SetDay(int day);
		void SetMonth(int month);
		void SetYear(int year); 
	protected:
};

#endif
