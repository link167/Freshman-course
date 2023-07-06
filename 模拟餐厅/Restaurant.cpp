#include "Restaurant.h"

Restaurant::Restaurant()
{
	//***********初始化餐厅对象************// 
	money=200;
	level=1;
	cout<<"请为新店起名字："<<endl;
	cin>>name;
	//---初始化菜品列表----// 
	Food* food=new Food("西红柿炒鸡蛋",8,"菜品");
	food_list.push_back(food);
	Food* food1=new Food("米饭",4.5,"主食");
	food_list.push_back(food1);
	Food* food2=new Food("牛奶燕麦粥",2.5,"饮品");
	food_list.push_back(food2);
	//---初始化桌位列表----// 
	Table* table[4];
	for(int i=0;i<4;++i)
	{
		table[i]=new Table;
		table_list.push_back(table[i]);
	}
	//---初始化统计列表----// 
	for(int i=0;i<food_list.size();++i)
	{
		stats[food_list[i]->GetName()]=0;
	}
	//************开辟餐厅存档**********// 
	char trans_name[30]="";						//
 	strcpy(trans_name,name.c_str());			//
 	int length=0;								//
 	for(;trans_name[length]!='\0';++length);	//获取存档文件名 
 	trans_name[length]='.';length++;			//
 	trans_name[length]='t';length++;			//
 	trans_name[length]='x';length++;			//
 	trans_name[length]='t';length++;			//
 	
 		//----创建文档----// 
	ofstream out;
	out.open(trans_name,ios::out);
			
			//存储餐厅基础信息 
	out<<name<<" "<<money<<" "<<level<<endl;
			
			//存储顾客列表 
	out<<Customer::GetCounst()<<endl;
			
			//存储座位列表 
	out<<table_list.size()<<endl;
	for(int i=0;i<4;++i)
	out<<table_list[i]->GetMoneyTable()<<" "<<table_list[i]->GetState()<<endl;
			
			//存储菜品列表 
	out<<3<<endl;
	for(int i=0;i<3;++i)
	out<<food_list[i]->GetName()<<" "<<food_list[i]->GetPrice()<<" "<<food_list[i]->GetType()<<endl;
			//存储记录列表
	out<<record_list.size()<<endl; 
			//存储统计信息 
	out<<stats.size()<<endl;
	map<string,int>::iterator it;
	for(it =stats.begin();it!=stats.end();++it)
	{
		out<<it->first<<" "<<it->second<<endl;
	}
	out.close();
		
		//----存入存档列表----//
	out.open("Restaurant_list.txt",ios::app);
	ifstream in;
	in.open("Restaurant_list.txt",ios::in);
	string help;
	in>>help;
	if(help == "")
	{
		out<<trans_name;
	}
	else
	{
		out<<endl<<trans_name;
	}
	
	out.close();
	in.close();
}
Restaurant::Restaurant(int)
{
	
}

//*******菜单功能*******//
void Restaurant::Show()					// 1.查看餐厅状态
{
	cout<<"餐厅名称"<<name<<setw(8)
		<<"等级"<<level<<setw(6)
		<<"     金钱"<<money<<endl;
	
	for(int i=0;i<food_list.size();++i)  //菜品列表打印 
	{
		food_list[i]->Show();
	}
	
	for(int i=0;i<table_list.size();++i) //桌位列表打印 
	{
		table_list[i]->Show();
	}
}
void Restaurant::LevelUp()				// 2.餐厅升级
{
	if(money-200*level < 0)
	{
		cout<<"钱还不够/(ㄒoㄒ)/~~"<<endl; 
		cout<<"需要"<< 200*level<<endl;
	}
	else
	{
		money=money-200*level;
		level++;
		
		cout<<"升级成功"<<endl;
	}
}
void Restaurant::Recept()				// 3.迎客
{
	Customer* customer=new Customer;
	bool flag=true;
	cout<<customer->GetNum()<<"号客人，请问你想坐在哪里？"<<endl;
	for(int i=0;i<table_list.size();++i)
	{
		table_list[i]->Show();
		if(table_list[i]->GetState() == 0)
		flag=false;
		
	}
	if(flag)
	{
		cout<<"已经没有空闲的桌位了"<<endl;
		system("pause"); 
		system("cls");
		return; 
	}
	
	
	string opt;
	int trans_opt;
	while(1)
	{
		//*******将字符串转换*********//
		trans_opt=0;							//为避免输 
		cin>>opt;								//入字符陷
		for(int i=0;i<opt.length();++i)			//入死循环
		{										
			trans_opt= trans_opt*10+opt[i]-'0';
		}										
		
		//******判断选择是否正确*****// 
		if(trans_opt<0 || trans_opt>table_list.size())
		{
			cout<<"该座位号不存在"<<endl;
			cout<<"请重新输入"<<endl;
			continue;
		}
		if(table_list[trans_opt]->GetState() != 0)
		{
			cout<<"该位置有客人了"<<endl;
			cout<<"请重新输入"<<endl;
			continue;
		}
		
		break;
	}
	
	table_list[trans_opt]->Seated(customer);
	cout<<"入座成功"<<endl;
	
	Sleep(500);
	system("cls"); 
	
}
void Restaurant::Order()				// 4.点菜
{
	vector<Table*>tableList;
	int flag=1;
	
	//********录入临时列表***********// 
	for(int i=0;i<table_list.size();++i)			//----
	{												//
		if(table_list[i]->GetState() == 1)			//将带点餐的记
			{										//录录入临时列表
				tableList.push_back(table_list[i]);	// 
				flag=0;								//
			}										//----
	}												
	if(flag)										//----
	{												//判断是否没有点餐的人
		cout<<"没有要点餐的客人"<<endl;				//
		return;										//----
	}
	
	
	cout<<"请选择桌位号进行点餐："<<endl;
	for(int i=0;i<tableList.size();++i)
	{
		tableList[i]->Show();
	}
	
	//*********输入转换******************//
	string num;
	int trans_num;
	while(1)
	{
		cin>>num;
		trans_num=0;						//为避免输
		for(int i=0;i<num.length();++i)		//入字符陷
		trans_num=trans_num*10+num[i]-'0';	//入死循环
		
		//----判断输入是否正确----// 
		if(trans_num >= table_list.size() || trans_num<0)
		{
			cout<<"该记录不存在"<<endl;
			cout<<"请重新输入"<<endl;
			continue;
		}
		if(table_list[trans_num]->GetState() < 1)
		{
			cout<<"该顾客还没有点餐"<<endl;
			cout<<"请重新输入"<<endl; 
			continue;
		}
		if(table_list[trans_num]->GetState() >1)
		{
			cout<<"该顾客点过菜了"<<endl; 
			cout<<"请重新输入"<<endl; 
			continue;
		}
		
		break;
	}
	
	//************创建记录***********// 
	Record* re=new Record;					//创建记录 
	re->InTable(table_list[trans_num]);		//初始化桌位 
	
		//----显示菜品列表----// 
	for(int i=0;i<food_list.size();++i)
	{
		cout<<i+1<<"  ";
		food_list[i]->Show();
	 }
	 	
		 //----点餐----// 
	 while(1)
	 {
	 		//输入转换 
		 cout<<"请问您想吃什么？(0退出点餐)"<<endl;
		 string opt;
		 int trans_opt;
		 cin>>opt;
		 trans_opt=0;
		 for(int i=0;i<opt.length();++i)
		 trans_opt=trans_opt*10+opt[i]-'0';
		 	
			 //加入记录列表 
		 if(trans_opt == 0)break;
		 re->AddFood(food_list[trans_opt-1]);//由于输入零退，所以要加零 
		 
		 	//记录统计
		stats[food_list[trans_opt-1]->GetName()]++;
	 }
	 
	 
	 re->SetState(2);
	 record_list.push_back(re);
	 cout<<"点餐结束"<<endl;
	
}
void Restaurant::ShowOrder()			// 5.查看点餐记录
{
	for(int i=0;i<record_list.size();++i)
	{
		record_list[i]->Show();
	}
}
void Restaurant::Cook()					// 6.做菜
{
	//********筛选订单*********// 
	vector<Record*>record;
	for(int i=0;i<record_list.size();++i)
	{
		if(record_list[i]->GetState() == 2)
		record.push_back(record_list[i]);
	}
	
	if(record.size() == 0)//判断筛选结果是否为空 
	{
		cout<<"目前没有订单"<<endl;
		return;
	}
	//********展示筛选的订单*****// 
	cout<<"*******请选择订单的编号******"<<endl;
	for(int i=0;i<record.size();++i)
	{
		cout<<i<<"   ";
		record[i]->Show();
	 }
	cout<<"*****************************"<<endl; 
	 //*******输入判断**********// 
	 int opt;
	 cin>>opt;
	 while(1)
	 {
	 	if(opt<0 || opt>table_list.size())
	 	{
	 		cout<<"该桌位不存在"<<endl;
	 		cin>>opt;
	 		continue;
		 }
	 	
	 	if(table_list[opt]->GetState() != 2)
	 	{
	 		cout<<"该桌位没有点餐或已经上菜"<<endl;
	 		cin>>opt;
	 		continue;
		 }
		 
	 	break;
	 }
	 //************做菜**********// 
	 cout<<"请选择要做的菜"<<endl;//选择 
	 record[opt]->ShowFood();
	 int choice;
	 cin>>choice;
	 
	 record[opt]->MinusFood(choice);//做菜 
	 if(record[opt]->GetFoodCount() == 0)
	 {
	 	
	 	record[opt]->SetState(3);
	 }
 } 
void Restaurant::CheckOut()				// 7.结账
{
	//******录入临时列表*******//
 	vector<Record*>recordList;
 	for(int i=0;i<record_list.size();++i)			//
 	{												//将等待结账 
 		if(record_list[i]->GetState() == 3)			//的记录录入
 		{											//临时列表
 			recordList.push_back(record_list[i]);	//
		 }
	 }
	 
	 //******显示待结账的记录*****// 
	 cout<<"未结账的桌位有："<<endl; 				
	 for(int i=0;i<recordList.size();++i)			
	 {												
	 	cout<<recordList[i]->GetTableNum()<<endl;	
	 }												
	 
	 cout<<"请选择要结账的桌位"<<endl;
	 int opt;
	 cin>>opt;
	 
	 table_list[opt]->SetState(0);
	 money=money+table_list[opt]->TakeAwayMoney();
}
void Restaurant::Save()					// 8.保存
{
 	//***************转换餐厅名称***********// 
 	char trans_name[30]="";
 	int length=0;
 	for(;length<name.length();++length)
 	{
 		trans_name[length]=name[length];
	 }
 	trans_name[length]='.';length++;
 	trans_name[length]='t';length++;
 	trans_name[length]='x';length++;
 	trans_name[length]='t';
 	
 	//***************打开文件**************// 
 	ofstream out_file;
 	out_file.open(trans_name,ios::out);
 	if(!out_file)
 	{
 		cout<<"打开"<< trans_name<<"失败"<<endl; 
	 }
 	if(GetLastError() != 183)
	 {
	 	cout<<"未查找到"<<trans_name<<"文件"<<endl;
	  } 
	  
     //***************餐厅基本信息*********//
	 out_file<<name<<" "<<money<<" "<<level<<endl;
	 
	 //***************顾客列表************// 
	 out_file<<Customer::GetCounst()<<endl;
	 
	 
	 //***************桌子列表***********// 
	 int i;
	 out_file<<table_list.size()<<endl;
	 for(i=0;i<table_list.size();++i)
	 {
	 	
	 	out_file<<table_list[i]->GetMoneyTable()<<" "
	 	   		<<table_list[i]->GetState()<<" ";
	 	   if(table_list[i]->GetState() == 0)
	 	   {
	 	   		out_file<<endl;
			}
		   else
		   {
		   		out_file<<table_list[i]->GetCustomerNum()<<endl;
		   }
	 }
	 
	 //***************食物列表**********// 
	 out_file<<food_list.size()<<endl;
	 
	 for(i=0;i<food_list.size();++i)
	 {
	 	out_file<<food_list[i]->GetName()<<" "
	 	   		<<food_list[i]->GetPrice()<<" "
	 	   		<<food_list[i]->GetType()<<endl;
	 }
	 
	 //**************记录列表**********// 
	 if(record_list.size()==0)return;
	          //记录条数 
	 out_file<<record_list.size()<<endl;
	 
	 
	         //打印记录
	 		 //桌位编号 食物数量
	 		 //食物名称 
	 for(i=0;i<record_list.size();++i)
	 {
	 	out_file<<record_list[i]->GetTableNum()<<" "<<record_list[i]->GetFoodCount()<<endl;
	 	for(int g=0;g < record_list[i]->GetFoodCount();++g)
	 	{
	 		out_file<<record_list[i]->GetFood(g)<<endl;
		 }
	 }
	 //*********统计记录*************//
	 out_file<<food_list.size()<<endl;
	 
	 map<string,int>::iterator it;
	 for(it=stats.begin();it!=stats.end();++it)
	 {
	 	out_file<<it->first<<" "<<it->second<<endl;
	 }
	 //*************************//
	 out_file.close();
}
void Restaurant::Read(char save_name[]) // 9.读档 
{
 	
 	
 	ifstream in(save_name,ios::in);
 	//*********加载餐厅基础信息*********//
 	Gotoxy(0,1);
 	cout<<"加载餐厅基础信息"<<endl;
 	cout<<" ---------------- "<<endl;
 	cout<<"|***             |"<<endl;
 	cout<<" ---------------- "<<endl;
	Sleep(400); 
 	string name;
 	double money;
 	int level;
 	in>>name>>money>>level;
 	this->name=name;
 	this->money=money;
 	this->level=level;
 	
 	//*********加载顾客列表********//
 	 Gotoxy(0,1);
	 cout<<"加载顾客列表"<<endl;
	 cout<<" ---------------- "<<endl;
 	 cout<<"|******          |"<<endl;
 	 cout<<" ---------------- "<<endl;
 	 Sleep(400); 
 	Customer::ChangeCounst(0);
 	vector<Customer*>customer_list;
 	int count_customer=0;
 	in>>count_customer;
 	for(int i=0;i<count_customer;++i)
 	{
 		Customer*customer=new Customer;
 		customer_list.push_back(customer);
	 }
	 
	 
	 //********加载桌子列表*********//
	 Gotoxy(0,1);
	 cout<<"加载桌子列表"<<endl; 
	 cout<<" ---------------- "<<endl;
 	 cout<<"|*********       |"<<endl;
 	 cout<<" ---------------- "<<endl;
 	 Sleep(400);
	 table_list.clear();
	 Table::SetCount(-1);
	 int count_table=0;
	 in>>count_table;

	 for(int i=0;i<count_table;++i)
	 {
	 	double money_table;
	 	int customer_num;
	 	int state;
	 	
	 	in>>money_table>>state;
	 	if(state != 0)
	 	{
	 		in>>customer_num;
	 		Table* table=new Table(money_table,state,customer_list[customer_num]);
	 		table_list.push_back(table);
		 }
	 	else
	 	{
	 		Table* table=new Table();
	 		table_list.push_back(table);
		 }
	 }
	 
	 //*******加载食物*************//
	 Gotoxy(0,1);
	 cout<<"加载食物"<<endl;
	 cout<<" ---------------- "<<endl;
 	 cout<<"|************    |"<<endl;
 	 cout<<" ---------------- "<<endl;
 	 Sleep(400);
	 food_list.clear();
	 int count_food=0;
	 in>>count_food;
	 for(int i=0;i<count_food;++i)
	 {
	 	string name;
	 	double price;
	 	string type;
	 	in>>name>>price>>type;
	 	Food* food=new Food(name,price,type);
	 	food_list.push_back(food);
	 }
	 
	 //*******加载账单************//
	  Gotoxy(0,1);
	  cout<<"加载账单"<<endl;
	  cout<<" ---------------- "<<endl;
 	  cout<<"|*************** |"<<endl;
 	  cout<<" ---------------- "<<endl;
 	  Sleep(400);
	 record_list.clear();
	 
	 int count_record=0;
	 in>>count_record;
	 for(int i=0;i<count_record;++i)
	 {
	 	int table_num;
		int count_food;
		in>>table_num>>count_food;
		
		vector<Food*>foods;
	 	for(int i=0;i<count_food;++i)
	 	{
	 		string name;
	 		in>>name;
			
	 		//***********食物列表查询************// 
	 		int g;
	 		for(g=0;g<food_list.size();++g)
	 		{
	 			if(name == food_list[g]->GetName())
				 break;
			 }
			 foods.push_back(food_list[g]);
			 
		 }
		 
		 Record* record=new Record(table_list[table_num],foods);
		 cout<<table_num<<endl;
		 record_list.push_back(record);
	  }
	  //************//
	  Gotoxy(0,1);
	  cout<<"加载统计信息"<<endl;
	  cout<<" ---------------- "<<endl;
 	  cout<<"|****************|"<<endl;
 	  cout<<" ---------------- "<<endl;
 	  Sleep(400);
 	  
	  int help;
	  in>>help;
	  for(int i=0;i<help;++i)
	  {
	  	string name;
	  	int n;
	  	in>>name>>n;
	  	stats[name]=n;
	  }
	 in.close();
}
void Restaurant::AddFood(string name,double price,string type)
{
	Food*food=new Food(name,price,type);
	food_list.push_back(food);
	stats[food->GetName()]=0;
}
										// 10.添加菜品
void Restaurant::StatisticalAnalysis()	// 11.统计分析 
{
	map<string,int>::iterator it;
	for(it=stats.begin();it!=stats.end();++it)
	{
		cout<<setw(14)<<left<<it->first<<setw(14)<<left<<it->second<<endl;
	}
	system("pause"); 
	system("cls");
}
//*******Get******//
int Restaurant::GetLevel()
{
	return level;
}
string Restaurant::GetName()
{
	return name;
}
int Restaurant::GetFoodCount()
{
	return food_list.size();
}
