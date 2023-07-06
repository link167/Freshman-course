#include "Food.h"

Food::Food()
{
}
Food::Food(string name,double price,string type)
{
	this->name=name;
	this->price=price;
	this->type=type;
}

//*********Show*****///
void Food::Show()
{
	cout<<type<<" "<<name<<" "<<price<<endl;
 } 

//*********Get*****//
string Food::GetName()
 {
 	return name;
 }
 double Food::GetPrice()
 {
 	return price;
 }
 string Food::GetType()
 {
 	return type;
 }
