#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Food.h"
/*
	Customer类的编号是从1开始的 
*/
class Customer
{
	public:
		
		Customer();
		
		//*******改变*****// 
		void static ChangeCounst(int n);
		
		//*******Get******//
		int GetNum();
		int static GetCounst();
		
	protected:
		
		int num;
		int static count;
};

#endif
