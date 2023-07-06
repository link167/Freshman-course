#ifndef RECORD_H
#define RECORD_H
#include"Table.h"
class Record
{
	public:
		
		Record();
		Record(Table* table,vector<Food*>food);
		
		//*****Show**********//
		void Show();                //展示记录的全部信息 
		void ShowFood();            //展示顾客所点菜品列表 
		
		//*****加减菜品******// 
		void MinusFood(int num);
		void AddFood(Food* food);
		
		//*****Set***********//
		void SetState(int num);
		void InTable(Table*table);
		
		//*****Get***********//
			//----Table----//
			int GetState();
			int GetTableNum();
			//----Food----//
			int GetFoodCount();
			string GetFood(int n);
		
	protected:
		Table* table;
		vector<Food*>food;
};

#endif
