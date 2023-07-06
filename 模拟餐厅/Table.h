#ifndef TABLE_H
#define TABLE_H
#include"Customer.h"
/*
	1.Table类编号从0开始的。
*/
class Table
{
	public:
		
		Table();
		Table(double money_table,int state,Customer* customer);
		
		//*****资金的存取****//
		void AddMoney(double); //增加桌子的钱 
		double TakeAwayMoney();//拿走钱 
		
		//*****Show*********// 
		void Show();
		
		//*****Set**********//
		void SetState(int);
		void Seated(Customer*);
		void static SetCount(int n);
		
		//*****Get**********//
		int GetNum();
		int GetState();
		double GetMoneyTable();
			//--Customer--//
		    int GetCustomerNum();
		
	protected:
		int num;
		double money_table;	   //顾客要支付的钱 
		int state;			   //0.无人  1.准备点餐  2.准备上菜  3.准备结账
		int static count;
		Customer* customer;
};

#endif
