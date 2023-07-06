#ifndef RESTAURANT_H
#define RESTAURANT_H
#include"Record.h"

class Restaurant
{
	public:
		
		Restaurant();
		Restaurant(int);
		
		//*******�˵�����*******//
		void Show();				// 1.�鿴����״̬
		void LevelUp();				// 2.��������
		void Recept();				// 3.ӭ��
		void Order();				// 4.���
		void ShowOrder(); 			// 5.�鿴��ͼ�¼
		void Cook();				// 6.����
		void CheckOut();			// 7.����
		void Save();				// 8����
		void Read(char save_name[]);// 9.���� 
		void AddFood(string name,double price,string type);
									// 10.��Ӳ�Ʒ
		void StatisticalAnalysis(); // 11.ͳ�Ʒ��� 
		//*******Get******//
		string GetName();
		int GetLevel(); 
		int GetFoodCount();
		
	protected:
		
		string name;
		double money;
		int level;
		map<string,int>stats;
		vector<Table*> table_list;
		vector<Food*> food_list;
		vector<Record*> record_list;
};

#endif
