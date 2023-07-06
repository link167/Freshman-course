#ifndef RESTAURANT_H
#define RESTAURANT_H
#include"Record.h"

class Restaurant
{
	public:
		
		Restaurant();
		Restaurant(int);
		
		//*******菜单功能*******//
		void Show();				// 1.查看餐厅状态
		void LevelUp();				// 2.餐厅升级
		void Recept();				// 3.迎客
		void Order();				// 4.点菜
		void ShowOrder(); 			// 5.查看点餐记录
		void Cook();				// 6.做菜
		void CheckOut();			// 7.结账
		void Save();				// 8保存
		void Read(char save_name[]);// 9.读档 
		void AddFood(string name,double price,string type);
									// 10.添加菜品
		void StatisticalAnalysis(); // 11.统计分析 
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
