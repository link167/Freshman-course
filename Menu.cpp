#include "Menu.h"


Menu::Menu()
{
}

void Menu::add()
{
	cout<<endl;
	cout<<"������һ������"<<endl;
	//******������*****// 
	int year;
	int month;
	int day;
	cin>>year>>month>>day;
	data help(year,month,day);
	
	cout<<"��������������"<<endl;
	int increase;
	cin>>increase;
	data help2=help+increase;
	
	help2.show();
	system("pause");
	system("cls");
}
void Menu::Minus()			 
{
	cout<<"������һ������"<<endl;
	//******������*****// 
	int year;
	int month;
	int day;
	cin>>year>>month>>day;
	data help(year,month,day);
	
	cout<<"��������ٵ�����"<<endl;
	int decrease;
	cin>>decrease;
	data help2=help-decrease;
	
	help2.show();
	system("pause");
	system("cls");
}
void Menu::interval()		
{
	cout<<"������������"<<endl;
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
	cout<<"������Ҫ�鿴������"<<endl;
	int year;
	int month;
	cin>>year>>month; 
	
	dispaly :show_month(year,month);
	
	Sleep(1000);
	
	cout<<"1.��һ����    2.��һ����"<<endl;
	cout<<"3.�鿴�·�    0.�˳�"<<endl; 
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
	cout<<"***************������**************"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"* 1.���ڼ�     2.���ڼ�           *"<<endl;
	cout<<"* 3,���ڼ��   4.�鿴����  5.�˳� *"<<endl;
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
