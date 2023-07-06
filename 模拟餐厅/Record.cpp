#include "Record.h"

Record::Record()
{
	table=NULL;
}
Record::Record(Table* table,vector<Food*>food)
{
	this->table=table;
	this->food=food;
}

//*****Show**********//
void Record::Show()					//展示记录的全部信息
{
	cout<<table->GetNum()<<"号桌位"<<setw(6)<<"还剩"<<food.size()<<"个未作"<<endl;
	
	for(int i=0;i<food.size();++i)
	{
		cout<<food[i]->GetName()<<" ";
	}
	
	cout<<endl;
}
void Record::ShowFood()				//展示顾客所点菜品列表
{
	for(int i=0;i<food.size();++i)
	{
		cout<<i<<setw(6)<<food[i]->GetName()<<endl;
	}
}

//*****加减菜品******//
void Record::MinusFood(int num)
{
	this->food.erase(this->food.begin()+num); 
}
void Record::AddFood(Food* food)
{
	this->food.push_back(food);
	
	table->AddMoney(food->GetPrice());
}

//*****Set***********//
void Record::SetState(int num)
{
	if(num>=0 && num<=4)
	table->SetState(num);
}
void Record::InTable(Table*table)
{
	this->table=table;
}

//*****Get***********//
	//----Table----//
	int Record::GetState()
	{
		return table->GetState();
	}
	int Record::GetTableNum()
	{
		return table->GetNum();
	}
	//----Food----//
	int Record::GetFoodCount()
	{
		return food.size();
	}
	string Record::GetFood(int n)
	{
		return food[n]->GetName();
	}
