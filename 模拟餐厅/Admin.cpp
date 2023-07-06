#include "Admin.h"

bool sign=false;

Admin::Admin()
{
	now=-1;
}

//****菜单************//
void Admin::AdminMenu()
{
	cout<<"*******模拟餐厅********"<<endl;
	cout<<"1.创建新餐厅"<<endl; 
	cout<<"2.进入餐厅"<<endl;
	cout<<"3.摧毁餐厅"<<endl;
	cout<<"4.退出"<<endl;
	cout<<"***********************"<<endl;
	//*******输入判断********// 
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
			cout<<"输入有误"<<endl;
			cout<<"请重新输入"<<endl;
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
void Admin::CreatRestaurant()		// 1.创建新餐厅
{
	Restaurant* restaurant=new Restaurant;
	restaurant_list.push_back(restaurant);
	now=restaurant_list.size()-1;
}
void Admin::EnterOtherRestaurant()	// 2.进入餐厅
{
	cout<<"想去那个餐厅"<<endl;
	ShowRestaurantList();
	int n;
	cin>>n;
	if(n<0 || n>=restaurant_list.size())
	{
		cout<<"该餐厅不存在"<<endl;
		system("pause");
		system("cls");
		return; 
	}
	now=n;
	system("cls");
	cout<<"欢迎来到"<<restaurant_list[n]->GetName()<<"餐厅"<<endl; 
}
void Admin::Destroy()				// 3.摧毁餐厅
{
	//********餐厅列表读入****// 
	
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
	
	cout<<"请输入要摧毁的餐厅"<<endl;
	for(int i=0;i<size;++i)
	cout<<i<<" " <<list[i]<<endl;
	//*********输入判断********// 
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
			cout<<"输入有误请重新输入"<<endl;
			continue;
		}
		else
		break;
	}
	//********删除存档*********//
	ofstream out("Restaurant_list.txt",ios::out);
	if(!out)
	{
		cout<<"读取Restaurant_list.txt失败"<<endl;
		cout<<GetLastError();
	}
	
	remove( list[trans_opt] );
	
	//----更新存档列表----// 
	if(size-1 == trans_opt)			//文档中的列表 
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
	
	restaurant_list.erase(restaurant_list.begin()+trans_opt);  //系统中的列表 
	
}
	//---Restaurant--//
	void Admin::Menu()
	{
		cout<<"------------模拟餐厅——------"<<endl;
		cout<<"1.查看餐厅状态  2.餐厅升级    "<<endl;
		cout<<"3.迎客          4.点菜        "<<endl;
		cout<<"5.查看点餐记录  6.做菜        "<<endl; 
		cout<<"7.结账          8，保存       "<<endl;
		cout<<"9.读档         10.添加菜品    "<<endl;
		cout<<"11.统计分析     0.退出        "<<endl; 
		cout<<"------------------------------"<<endl;
		int choice;
		cin>>choice;
		if(sign == false && choice!=0 && choice!=11)
		{	
			cout<<"没有读档"<<endl;
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
		cout<<"还没有开设餐厅"<<endl;
		return;
	}
	cout<<"序号"<<setw(6)<<"餐厅名称"<<endl;
	for(int i=0;i < restaurant_list.size();++i)
	{
		cout<<i<<setw(6)<<restaurant_list[i]->GetName()<<endl;
	}
}

//****存档，读档*****// 
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
		
		cout<<"打开Restaurant_list.txt失败"<<endl;
		switch(GetLastError())
		{
			case 2:cout<<"系统找不到指定的文件"<<endl;break;
			case 123:cout<<"文件名、目录名或卷标语法不正确。 "<<endl;break; 
			case 111:cout<<"文件名太长。"<<endl; 
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
		cout<<"加载" <<name_restaurant<<"中(☆▽☆)"<<endl;
		Restaurant *restaurant = new Restaurant(1);//创建空餐厅 
		restaurant->Read(name_restaurant);
		restaurant_list.push_back(restaurant);
	}
	cout<<"加载完成!"<<endl;
	Sleep(500);
	system("cls");
	now=0; 
	sign=true;
//	cout<<"欢迎来到"<<restaurant_list[now]->GetName()<<"餐厅"<<endl;
	in.close();
}

//****添加菜品******//  
void Admin::AddFood()
{
	if(restaurant_list[now]->GetLevel()%2==0 && restaurant_list[now]->GetFoodCount()<3+restaurant_list[now]->GetLevel()/2)
	{																	//level%2==0 且 菜品列表没有满 
		cout<<"可以添加菜品了！"<<endl;
		cout<<restaurant_list[now]->GetLevel()
		    <<"可以添加"
			<<1
			<<"个菜品。"<<endl; 
			
		string name;
		double price;
		string type;
		cout<<"菜品名称"<<setw(10)<<"菜品价格"<<setw(10)<<"菜品类型"<<endl; 
		if(cin>>name>>price>>type)
		restaurant_list[now]->AddFood(name,price,type);
		
	 }
	 else
	 {
	 	cout<<"等级还不够 w(·Д·)w"<<endl;
	 	return;
	 }
}
