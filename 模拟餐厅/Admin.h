#ifndef ADMIN_H
#define ADMIN_H
#include "Restaurant.h"

class Admin
{
	public:
		
		Admin();
		
		//****�˵�************//
		void AdminMenu();
		void CreatRestaurant();			// 1.�����²���
		void EnterOtherRestaurant();	// 2.�������
		void Destroy();					// 3.�ݻٲ���
			//---Restaurant--//
			void Menu();
		
		//****Show************//
		void ShowRestaurantList();
		
		//****�浵������*****// 
		void Save();
		void Read();
		
		//****��Ӳ�Ʒ******// 
		void AddFood();
		
	protected:
		
		int now;
		vector<Restaurant*> restaurant_list;
};

#endif
