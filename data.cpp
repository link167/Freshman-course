#include "data.h"

//*********构造*******// 
data::data()
{
	year=1990;
	month=1;
	day=1;
}
data::data(int year_parm,int month_parm,int day_parm)
{
	while(1)
	{
		if( judge(year_parm,month_parm,day_parm) )
		{
			break;
		}
		else
		{
			cout<<"所输入日期不合法"<<endl;
			cin>>year_parm>>month_parm>>day_parm;
		}
	}
	
	year=year_parm;
	month=month_parm;
	day=day_parm;
}
//*********判断*******//
bool data::judge(int year_parm,int month_parm,int day_parm)
{
	if(year_parm<=0 || month_parm<=0||month_parm>=13 )
	{
		return 0;
	}
	
	if( day_parm<1||day_parm>get_month_day(year_parm,month_parm) )
	{
		return 0;
	}

	return 1;
}
bool data::judge_LeapYear(int year_parm)
{
	if( (year_parm%4==0 && year_parm%100!=0) || year_parm%400==0 )
	{
		return 1;
	}
	else return 0;
}
 void data::show()
{
	cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
}
 void data::show_month(int year,int month)
{
	if(month==1||month==2)
	{
		month=12+month;
		year--;
	}
	int day=1;
	int week=(day+1+2*month+3*(month+1)/5+year+year/4-year/100+year/400)%7;
	cout<<setw(6)<<"一"<<setw(6)<<"二"<<setw(6)<<"三"<<setw(6)<<"四"<<setw(6)<<"五"<<setw(6)<<"六"<<setw(6)<<"七"<<endl; 
	if(week==0)week=7;
	for(int i=1;i<week;++i)
	{
		cout<<"      ";
	}
	if(month>12)
	{
		month=month-12;
		year++;
	}
	for(int i=1;i<=get_month_day(year,month);++i)
	{
		if(week==7)
		{
			cout<<setw(6)<<i;
			cout<<endl;
			week=1;
		}
		else
		{
			cout<<setw(6)<<i;
			++week;
		}
	}
	cout<<endl;
}
int data::get_month_day(int year_parm,int month_parm)
{
	//                 0 1  2  3  4  5  6  7  8  9  10 11 12
	int day_count[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if( month_parm==2&&judge_LeapYear(year_parm) )
	{
		return 29;
	}
	return day_count[month_parm];
}
//************运算符重载**********//
data data::operator +(int parm)
{
	
	day=day+parm;
	while(day>get_month_day(year,month))
	{
			day=day-get_month_day(year,month);
			++month;
			if(month==13)
			{
				year++;
				month=1;
			}
	}
	 
	return *this;
}
data data::operator -(int parm)
{
	day=day-parm;
	while(day<=0)
	{
		month--;
		day=day+get_month_day(year,month);
		
		if(month==0)
		{
			month=12;
			year--;
		}
	}
	
	if(year<=0)
	{
		cout<<"减少的天数大于输入天数"<<endl;
	}
	return *this;
}
data data::operator -(data pram)
{
	if(Compare(pram))
	{
		day=day-pram.get_day();
		if(day<0)
		{
			day=day+get_month_day(year,month);
			month--;
		}
		month=month-pram.get_month();
		if(month < 0)
		{
			month=month+12;
			year--;
		}
		year=year-pram.get_year(); 
	}
	else
	{
		Change(pram);
		day=day-pram.get_day();
		if(day<0)
		{
			day=day+get_month_day(year,month);
			month--;
		}
		month=month-pram.get_month();
		if(month < 0)
		{
			month=month+12;
			year--;
		}
		year=year-pram.get_year(); 
		
	}
	return *this;
}
//**********比较*********//
bool data::Compare(data pram)
{
	if(year<pram.get_year() )
	return 0;
	
	else
	{
		if(month<pram.get_month())
		return 0;
		
		else
		{
			if(day<pram.get_day())
			return 0;
		}
	}
	return 1;
} 
//*********交换*********// 
void data::Change(data &pram)
{
	data help;
	help.SetDay(pram.get_day());
	help.SetMonth(pram.get_month());
	help.SetYear(pram.get_year());
	
	pram.SetDay(day);
	pram.SetMonth(month);
	pram.SetYear(year);
	
	SetDay(help.get_day());
	SetMonth(help.get_month());
	SetYear(help.get_year());
}
//**********赋值********//
void data::SetDay(int day)
{
	this->day=day;
 } 
void data::SetMonth(int month)
{
 	this->month=month;
 }
void data::SetYear(int year)
{
 	this->year=year;
 }
