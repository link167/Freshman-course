#ifndef RECORD_H
#define RECORD_H
#include"Table.h"
class Record
{
	public:
		
		Record();
		Record(Table* table,vector<Food*>food);
		
		//*****Show**********//
		void Show();                //չʾ��¼��ȫ����Ϣ 
		void ShowFood();            //չʾ�˿������Ʒ�б� 
		
		//*****�Ӽ���Ʒ******// 
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
