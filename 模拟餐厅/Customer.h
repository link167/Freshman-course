#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Food.h"
/*
	Customer��ı���Ǵ�1��ʼ�� 
*/
class Customer
{
	public:
		
		Customer();
		
		//*******�ı�*****// 
		void static ChangeCounst(int n);
		
		//*******Get******//
		int GetNum();
		int static GetCounst();
		
	protected:
		
		int num;
		int static count;
};

#endif
