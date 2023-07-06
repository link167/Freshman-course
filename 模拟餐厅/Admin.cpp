#include "Admin.h"

bool sign=false;

Admin::Admin()
{
	now=-1;
}

//****�˵�************//
void Admin::AdminMenu()
{
	cout<<"*******ģ�����********"<<endl;
	cout<<"1.�����²���"<<endl; 
	cout<<"2.�������"<<endl;
	cout<<"3.�ݻٲ���"<<endl;
	cout<<"4.�˳�"<<endl;
	cout<<"***********************"<<endl;
	//*******�����ж�********// 
	string opt;
	int trans_opt;
	while(1)
	{
		cin>>opt;
		trans_opt=0;
		
		for(int i=0;i<opt.length();++i)
		trans_opt=trans_opt*10 + opt[i] - '0';
	
		if(trans_opt <= 0 || trans_opt >4)
		{
			cout<<"��������"<<endl;
			cout<<"����������"<<endl;
		}
		else
		break;
	}
	
	switch(trans_opt)
	{
		case 1:CreatRestaurant();break;
		case 2:EnterOtherRestaurant();
			   while(1)
			   {
			   		Menu();
			   }
		       break;
		case 3:Destroy();break;
		case 4:exit(0);break;
	}
} 
void Admin::CreatRestaurant()		// 1.�����²���
{
	Restaurant* restaurant=new Restaurant;
	restaurant_list.push_back(restaurant);
	now=restaurant_list.size()-1;
}
void Admin::EnterOtherRestaurant()	// 2.�������
{
	cout<<"��ȥ�Ǹ�����"<<endl;
	ShowRestaurantList();
	int n;
	cin>>n;
	if(n<0 || n>=restaurant_list.size())
	{
		cout<<"�ò���������"<<endl;
		system("pause");
		system("cls");
		return; 
	}
	now=n;
	system("cls");
	cout<<"��ӭ����"<<restaurant_list[n]->GetName()<<"����"<<endl; 
}
void Admin::Destroy()				// 3.�ݻٲ���
{
	//********�����б����****// 
	
	ifstream in("Restaurant_list.txt",ios::in);
	char list[50][50];
	int size=0; 
	while(1)
	{
		if(in.eof())
		break;
		
		in>>list[size];
		++size;
	}
	in.close();
	
	cout<<"������Ҫ�ݻٵĲ���"<<endl;
	for(int i=0;i<size;++i)
	cout<<i<<" " <<list[i]<<endl;
	//*********�����ж�********// 
	int trans_opt;
	string opt;
	while(1)
	{
		cin>>opt;
		trans_opt=0;
		
		for(int i=0;i<opt.length();++i)
		trans_opt=trans_opt*10+opt[i]-'0';
		
		if(trans_opt<0 || trans_opt>=size)
		{
			cout<<"������������������"<<endl;
			continue;
		}
		else
		break;
	}
	//********ɾ���浵*********//
	ofstream out("Restaurant_list.txt",ios::out);
	if(!out)
	{
		cout<<"��ȡRestaurant_list.txtʧ��"<<endl;
		cout<<GetLastError();
	}
	
	remove( list[trans_opt] );
	
	//----���´浵�б�----// 
	if(size-1 == trans_opt)			//�ĵ��е��б� 
	{
		size--;
		int i=0;
		for(;i<size-1;++i)
		{
			out<<list[i]<<endl;
		}
		out<<list[i];
	}
	else
	{
		int i=0;
		for(;i<size -1;++i)
		{
			if(i==trans_opt)continue;
			out<<list[i]<<endl;
		}
		out<<list[i]<<endl;
	}
	
	restaurant_list.erase(restaurant_list.begin()+trans_opt);  //ϵͳ�е��б� 
	
}
	//---Restaurant--//
	void Admin::Menu()
	{
		cout<<"------------ģ���������------"<<endl;
		cout<<"1.�鿴����״̬  2.��������    "<<endl;
		cout<<"3.ӭ��          4.���        "<<endl;
		cout<<"5.�鿴��ͼ�¼  6.����        "<<endl; 
		cout<<"7.����          8������       "<<endl;
		cout<<"9.����         10.��Ӳ�Ʒ    "<<endl;
		cout<<"11.ͳ�Ʒ���     0.�˳�        "<<endl; 
		cout<<"------------------------------"<<endl;
		int choice;
		cin>>choice;
		if(sign == false && choice!=0 && choice!=11)
		{	
			cout<<"û�ж���"<<endl;
			Read();
			return;
		 } 
		switch(choice)
		{
			case 1:restaurant_list[now]->Show();break;
			case 2:restaurant_list[now]->LevelUp();break;
			case 3:restaurant_list[now]->Recept();break;
			case 4:restaurant_list[now]->Order();break;
			case 5:restaurant_list[now]->ShowOrder();break;
			case 6:restaurant_list[now]->Cook();break;
			case 7:restaurant_list[now]->CheckOut();break;
			case 8:Save();break;
			case 9:Read();break;
			case 10:AddFood();break;
			case 11:restaurant_list[now]->StatisticalAnalysis();break;
			case 0:exit(0);break;
		 }
	}

//****Show************//
void Admin::ShowRestaurantList()
{
	if(restaurant_list.size() == 0)
	{
		cout<<"��û�п������"<<endl;
		return;
	}
	cout<<"���"<<setw(6)<<"��������"<<endl;
	for(int i=0;i < restaurant_list.size();++i)
	{
		cout<<i<<setw(6)<<restaurant_list[i]->GetName()<<endl;
	}
}

//****�浵������*****// 
void Admin::Save()
{
	for(int i=0;i<restaurant_list.size();++i)
	restaurant_list[now]->Save();
}
void Admin::Read()
{
	ifstream in("Restaurant_list.txt",ios::in);
	if(!in)
	{
		
		cout<<"��Restaurant_list.txtʧ��"<<endl;
		switch(GetLastError())
		{
			case 2:cout<<"ϵͳ�Ҳ���ָ�����ļ�"<<endl;break;
			case 123:cout<<"�ļ�����Ŀ¼�������﷨����ȷ�� "<<endl;break; 
			case 111:cout<<"�ļ���̫����"<<endl; 
		}
		exit(0);
	}
	restaurant_list.clear();
	char name_restaurant[50];
	while(1)
	{
		if(in.eof())
		{
			break;
		}
		in>>name_restaurant;
		Gotoxy(0,0); 
		cout<<"����" <<name_restaurant<<"��(���)"<<endl;
		Restaurant *restaurant = new Restaurant(1);//�����ղ��� 
		restaurant->Read(name_restaurant);
		restaurant_list.push_back(restaurant);
	}
	cout<<"�������!"<<endl;
	Sleep(500);
	system("cls");
	now=0; 
	sign=true;
//	cout<<"��ӭ����"<<restaurant_list[now]->GetName()<<"����"<<endl;
	in.close();
}

//****��Ӳ�Ʒ******//  
void Admin::AddFood()
{
	if(restaurant_list[now]->GetLevel()%2==0 && restaurant_list[now]->GetFoodCount()<3+restaurant_list[now]->GetLevel()/2)
	{																	//level%2==0 �� ��Ʒ�б�û���� 
		cout<<"������Ӳ�Ʒ�ˣ�"<<endl;
		cout<<restaurant_list[now]->GetLevel()
		    <<"�������"
			<<1
			<<"����Ʒ��"<<endl; 
			
		string name;
		double price;
		string type;
		cout<<"��Ʒ����"<<setw(10)<<"��Ʒ�۸�"<<setw(10)<<"��Ʒ����"<<endl; 
		if(cin>>name>>price>>type)
		restaurant_list[now]->AddFood(name,price,type);
		
	 }
	 else
	 {
	 	cout<<"�ȼ������� w(������)w"<<endl;
	 	return;
	 }
}
