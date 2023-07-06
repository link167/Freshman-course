#ifndef FOOD_H
#define FOOD_H
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>
#include<windows.h>
#include<string.h>
#include<map> 

using namespace std;

void Gotoxy(int x,int y);

class Food
{
	public:
		
		Food();
		Food(string,double,string);
		
		//****Show***//
		void Show();
		
		//****Get****//
		string GetName();
		double GetPrice();
		string GetType();

	protected:
		
		string name;
		double price;
		string type;
};

#endif
