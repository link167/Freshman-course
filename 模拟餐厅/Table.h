#ifndef TABLE_H
#define TABLE_H
#include"Customer.h"
/*
	1.Table���Ŵ�0��ʼ�ġ�
*/
class Table
{
	public:
		
		Table();
		Table(double money_table,int state,Customer* customer);
		
		//*****�ʽ�Ĵ�ȡ****//
		void AddMoney(double); //�������ӵ�Ǯ 
		double TakeAwayMoney();//����Ǯ 
		
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
		double money_table;	   //�˿�Ҫ֧����Ǯ 
		int state;			   //0.����  1.׼�����  2.׼���ϲ�  3.׼������
		int static count;
		Customer* customer;
};

#endif
