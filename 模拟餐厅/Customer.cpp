#include "Customer.h"

int Customer::count=0;

Customer::Customer()
{
	count++;
	num=count;
}

//*******�ı�******// 
void Customer::ChangeCounst(int n)
{
	count=n;
}

//******Get*******//
int Customer::GetNum()
{
	return num;
}
int  Customer::GetCounst() 
{
	return count;
}

