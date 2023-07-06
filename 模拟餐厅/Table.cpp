#include "Table.h"

int Table::count=-1;

Table::Table()
{
	count++; 
	
	num=count;
	state=0;
	money_table=0;
	customer=NULL;
}
Table::Table(double money_table,int state,Customer* customer)
{
	count++;
	
	num=count;
	this->money_table=money_table;
	this->state=state;
	this->customer=customer;
}

//*****资金的存取****//
void Table::AddMoney(double price)
{
	money_table=money_table+price;
}
double Table::TakeAwayMoney()
{
	double hand=money_table;
	money_table=0;
	return hand;
}

//*****Show*********// 
void Table::Show()
{
	cout<<num<<"号桌位    ";
	
	switch(state)
	{
		case 0:cout<<"【空位】"<<endl;break;
		case 1:cout<<"【准备点餐】"<<endl;break;
		case 2:cout<<"【准备上菜】"<<endl;break;
		case 3:cout<<"【准备结账】"<<endl;break;
	}
}

//*****Set**********//
void Table::Seated(Customer* customer)
{
	this->customer=customer;
	state=1;
}
void Table::SetCount(int n)
{
	count=n;
}
void Table::SetState(int pram)
{
	if(pram<4 && pram>=0) state=pram;
}

//*****Get**********//
int Table::GetNum()
{
	return num;
}
int Table::GetState()
{
	return state;
}
double Table::GetMoneyTable()
{
	return money_table;
}
	//--Customer--//
	int Table::GetCustomerNum()
	{
		return customer->GetNum();
	}





