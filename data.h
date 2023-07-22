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
		//********����*******// 
		data();
		data(int year_parm,int month_parm,int day_parm);
		
		
		void show();
		void show_month(int year,int month); 
		//*****�ж�*********//
		bool judge(int year,int month,int day);
		bool judge_LeapYear(int year_parm);
		//*****���������***// 
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
		//*****�Ƚ�*******//
		bool Compare(data pram); 
		//*****����******//
		void Change(data &pram);
		//*****��ֵ*****//
		void SetDay(int day);
		void SetMonth(int month);
		void SetYear(int year); 
	protected:
};

#endif
