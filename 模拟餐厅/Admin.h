#ifndef ADMIN_H
#define ADMIN_H
#include "Restaurant.h"

class Admin
{
	public:
		
		Admin();
		
		//****菜单************//
		void AdminMenu();
		void CreatRestaurant();			// 1.创建新餐厅
		void EnterOtherRestaurant();	// 2.进入餐厅
		void Destroy();					// 3.摧毁餐厅
			//---Restaurant--//
			void Menu();
		
		//****Show************//
		void ShowRestaurantList();
		
		//****存档，读档*****// 
		void Save();
		void Read();
		
		//****添加菜品******// 
		void AddFood();
		
	protected:
		
		int now;
		vector<Restaurant*> restaurant_list;
};

#endif
