#include "Menu.h"


Menu::Menu()
{
}

void Menu::add()
{
	cout<<endl;
	cout<<"请输入一个日期"<<endl;
	//******对象建立*****// 
	int year;
	int month;
	int day;
	cin>>year>>month>>day;
	data help(year,month,day);
	
	cout<<"请输入增加天数"<<endl;
	int increase;
	cin>>increase;
	data help2=help+increase;
	
	help2.show();
	system("pause");
	system("cls");
}
void Menu::Minus()			 
{
	cout<<"请输入一个日期"<<endl;
	//******对象建立*****// 
	int year;
	int month;
	int day;
	cin>>year>>month>>day;
	data help(year,month,day);
	
	cout<<"请输入减少的天数"<<endl;
	int decrease;
	cin>>decrease;
	data help2=help-decrease;
	
	help2.show();
	system("pause");
	system("cls");
}
void Menu::interval()		
{
	cout<<"请输入两日期"<<endl;
	int year;
	int month;
	int day;
	
	cin>>year>>month>>day;
	data pram1(year,month,day);
	
	cin>>year>>month>>day;
	data pram2(year,month,day);
	
	data outcome=pram1-pram2;
	outcome.show();
	
	system("pause");
	system("cls");
}
void Menu::view_month()		
{
	cout<<"请输入要查看的年月"<<endl;
	int year;
	int month;
	cin>>year>>month; 
	
	dispaly :show_month(year,month);
	
	Sleep(1000);
	
	cout<<"1.下一个月    2.上一个月"<<endl;
	cout<<"3.查看月份    0.退出"<<endl; 
	int opt;
	cin>>opt;
	switch(opt)
	{
		case 1:month++;
		       if(month==13)
		       {
		       		month=1;
		       		year++;
			   }
		       goto dispaly;
		case 2:month--;
		       if(month==0)
		       {
		       		month=12;
		       		year--;
			   }
		       goto dispaly;
		case 3:view_month();break;
		case 0:break; 
	}
}
void Menu::menue()			
{
	cout<<"***************万年历**************"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"* 1.日期加     2.日期减           *"<<endl;
	cout<<"* 3,日期间隔   4.查看日历  5.退出 *"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"***********************************"<<endl;
	int opt;
	cin>>opt;
	switch(opt)
	{
		case 1:system("cls");
				add();break;
		case 2:Minus();break;
		case 3:interval();break;
		case 4:view_month();break;
		case 5:exit(0); 
	}
}
