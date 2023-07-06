#include "Restaurant.h"

Restaurant::Restaurant()
{
	//***********��ʼ����������************// 
	money=200;
	level=1;
	cout<<"��Ϊ�µ������֣�"<<endl;
	cin>>name;
	//---��ʼ����Ʒ�б�----// 
	Food* food=new Food("������������",8,"��Ʒ");
	food_list.push_back(food);
	Food* food1=new Food("�׷�",4.5,"��ʳ");
	food_list.push_back(food1);
	Food* food2=new Food("ţ��������",2.5,"��Ʒ");
	food_list.push_back(food2);
	//---��ʼ����λ�б�----// 
	Table* table[4];
	for(int i=0;i<4;++i)
	{
		table[i]=new Table;
		table_list.push_back(table[i]);
	}
	//---��ʼ��ͳ���б�----// 
	for(int i=0;i<food_list.size();++i)
	{
		stats[food_list[i]->GetName()]=0;
	}
	//************���ٲ����浵**********// 
	char trans_name[30]="";						//
 	strcpy(trans_name,name.c_str());			//
 	int length=0;								//
 	for(;trans_name[length]!='\0';++length);	//��ȡ�浵�ļ��� 
 	trans_name[length]='.';length++;			//
 	trans_name[length]='t';length++;			//
 	trans_name[length]='x';length++;			//
 	trans_name[length]='t';length++;			//
 	
 		//----�����ĵ�----// 
	ofstream out;
	out.open(trans_name,ios::out);
			
			//�洢����������Ϣ 
	out<<name<<" "<<money<<" "<<level<<endl;
			
			//�洢�˿��б� 
	out<<Customer::GetCounst()<<endl;
			
			//�洢��λ�б� 
	out<<table_list.size()<<endl;
	for(int i=0;i<4;++i)
	out<<table_list[i]->GetMoneyTable()<<" "<<table_list[i]->GetState()<<endl;
			
			//�洢��Ʒ�б� 
	out<<3<<endl;
	for(int i=0;i<3;++i)
	out<<food_list[i]->GetName()<<" "<<food_list[i]->GetPrice()<<" "<<food_list[i]->GetType()<<endl;
			//�洢��¼�б�
	out<<record_list.size()<<endl; 
			//�洢ͳ����Ϣ 
	out<<stats.size()<<endl;
	map<string,int>::iterator it;
	for(it =stats.begin();it!=stats.end();++it)
	{
		out<<it->first<<" "<<it->second<<endl;
	}
	out.close();
		
		//----����浵�б�----//
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

//*******�˵�����*******//
void Restaurant::Show()					// 1.�鿴����״̬
{
	cout<<"��������"<<name<<setw(8)
		<<"�ȼ�"<<level<<setw(6)
		<<"     ��Ǯ"<<money<<endl;
	
	for(int i=0;i<food_list.size();++i)  //��Ʒ�б��ӡ 
	{
		food_list[i]->Show();
	}
	
	for(int i=0;i<table_list.size();++i) //��λ�б��ӡ 
	{
		table_list[i]->Show();
	}
}
void Restaurant::LevelUp()				// 2.��������
{
	if(money-200*level < 0)
	{
		cout<<"Ǯ������/(��o��)/~~"<<endl; 
		cout<<"��Ҫ"<< 200*level<<endl;
	}
	else
	{
		money=money-200*level;
		level++;
		
		cout<<"�����ɹ�"<<endl;
	}
}
void Restaurant::Recept()				// 3.ӭ��
{
	Customer* customer=new Customer;
	bool flag=true;
	cout<<customer->GetNum()<<"�ſ��ˣ����������������"<<endl;
	for(int i=0;i<table_list.size();++i)
	{
		table_list[i]->Show();
		if(table_list[i]->GetState() == 0)
		flag=false;
		
	}
	if(flag)
	{
		cout<<"�Ѿ�û�п��е���λ��"<<endl;
		system("pause"); 
		system("cls");
		return; 
	}
	
	
	string opt;
	int trans_opt;
	while(1)
	{
		//*******���ַ���ת��*********//
		trans_opt=0;							//Ϊ������ 
		cin>>opt;								//���ַ���
		for(int i=0;i<opt.length();++i)			//����ѭ��
		{										
			trans_opt= trans_opt*10+opt[i]-'0';
		}										
		
		//******�ж�ѡ���Ƿ���ȷ*****// 
		if(trans_opt<0 || trans_opt>table_list.size())
		{
			cout<<"����λ�Ų�����"<<endl;
			cout<<"����������"<<endl;
			continue;
		}
		if(table_list[trans_opt]->GetState() != 0)
		{
			cout<<"��λ���п�����"<<endl;
			cout<<"����������"<<endl;
			continue;
		}
		
		break;
	}
	
	table_list[trans_opt]->Seated(customer);
	cout<<"�����ɹ�"<<endl;
	
	Sleep(500);
	system("cls"); 
	
}
void Restaurant::Order()				// 4.���
{
	vector<Table*>tableList;
	int flag=1;
	
	//********¼����ʱ�б�***********// 
	for(int i=0;i<table_list.size();++i)			//----
	{												//
		if(table_list[i]->GetState() == 1)			//������͵ļ�
			{										//¼¼����ʱ�б�
				tableList.push_back(table_list[i]);	// 
				flag=0;								//
			}										//----
	}												
	if(flag)										//----
	{												//�ж��Ƿ�û�е�͵���
		cout<<"û��Ҫ��͵Ŀ���"<<endl;				//
		return;										//----
	}
	
	
	cout<<"��ѡ����λ�Ž��е�ͣ�"<<endl;
	for(int i=0;i<tableList.size();++i)
	{
		tableList[i]->Show();
	}
	
	//*********����ת��******************//
	string num;
	int trans_num;
	while(1)
	{
		cin>>num;
		trans_num=0;						//Ϊ������
		for(int i=0;i<num.length();++i)		//���ַ���
		trans_num=trans_num*10+num[i]-'0';	//����ѭ��
		
		//----�ж������Ƿ���ȷ----// 
		if(trans_num >= table_list.size() || trans_num<0)
		{
			cout<<"�ü�¼������"<<endl;
			cout<<"����������"<<endl;
			continue;
		}
		if(table_list[trans_num]->GetState() < 1)
		{
			cout<<"�ù˿ͻ�û�е��"<<endl;
			cout<<"����������"<<endl; 
			continue;
		}
		if(table_list[trans_num]->GetState() >1)
		{
			cout<<"�ù˿͵������"<<endl; 
			cout<<"����������"<<endl; 
			continue;
		}
		
		break;
	}
	
	//************������¼***********// 
	Record* re=new Record;					//������¼ 
	re->InTable(table_list[trans_num]);		//��ʼ����λ 
	
		//----��ʾ��Ʒ�б�----// 
	for(int i=0;i<food_list.size();++i)
	{
		cout<<i+1<<"  ";
		food_list[i]->Show();
	 }
	 	
		 //----���----// 
	 while(1)
	 {
	 		//����ת�� 
		 cout<<"���������ʲô��(0�˳����)"<<endl;
		 string opt;
		 int trans_opt;
		 cin>>opt;
		 trans_opt=0;
		 for(int i=0;i<opt.length();++i)
		 trans_opt=trans_opt*10+opt[i]-'0';
		 	
			 //�����¼�б� 
		 if(trans_opt == 0)break;
		 re->AddFood(food_list[trans_opt-1]);//�����������ˣ�����Ҫ���� 
		 
		 	//��¼ͳ��
		stats[food_list[trans_opt-1]->GetName()]++;
	 }
	 
	 
	 re->SetState(2);
	 record_list.push_back(re);
	 cout<<"��ͽ���"<<endl;
	
}
void Restaurant::ShowOrder()			// 5.�鿴��ͼ�¼
{
	for(int i=0;i<record_list.size();++i)
	{
		record_list[i]->Show();
	}
}
void Restaurant::Cook()					// 6.����
{
	//********ɸѡ����*********// 
	vector<Record*>record;
	for(int i=0;i<record_list.size();++i)
	{
		if(record_list[i]->GetState() == 2)
		record.push_back(record_list[i]);
	}
	
	if(record.size() == 0)//�ж�ɸѡ����Ƿ�Ϊ�� 
	{
		cout<<"Ŀǰû�ж���"<<endl;
		return;
	}
	//********չʾɸѡ�Ķ���*****// 
	cout<<"*******��ѡ�񶩵��ı��******"<<endl;
	for(int i=0;i<record.size();++i)
	{
		cout<<i<<"   ";
		record[i]->Show();
	 }
	cout<<"*****************************"<<endl; 
	 //*******�����ж�**********// 
	 int opt;
	 cin>>opt;
	 while(1)
	 {
	 	if(opt<0 || opt>table_list.size())
	 	{
	 		cout<<"����λ������"<<endl;
	 		cin>>opt;
	 		continue;
		 }
	 	
	 	if(table_list[opt]->GetState() != 2)
	 	{
	 		cout<<"����λû�е�ͻ��Ѿ��ϲ�"<<endl;
	 		cin>>opt;
	 		continue;
		 }
		 
	 	break;
	 }
	 //************����**********// 
	 cout<<"��ѡ��Ҫ���Ĳ�"<<endl;//ѡ�� 
	 record[opt]->ShowFood();
	 int choice;
	 cin>>choice;
	 
	 record[opt]->MinusFood(choice);//���� 
	 if(record[opt]->GetFoodCount() == 0)
	 {
	 	
	 	record[opt]->SetState(3);
	 }
 } 
void Restaurant::CheckOut()				// 7.����
{
	//******¼����ʱ�б�*******//
 	vector<Record*>recordList;
 	for(int i=0;i<record_list.size();++i)			//
 	{												//���ȴ����� 
 		if(record_list[i]->GetState() == 3)			//�ļ�¼¼��
 		{											//��ʱ�б�
 			recordList.push_back(record_list[i]);	//
		 }
	 }
	 
	 //******��ʾ�����˵ļ�¼*****// 
	 cout<<"δ���˵���λ�У�"<<endl; 				
	 for(int i=0;i<recordList.size();++i)			
	 {												
	 	cout<<recordList[i]->GetTableNum()<<endl;	
	 }												
	 
	 cout<<"��ѡ��Ҫ���˵���λ"<<endl;
	 int opt;
	 cin>>opt;
	 
	 table_list[opt]->SetState(0);
	 money=money+table_list[opt]->TakeAwayMoney();
}
void Restaurant::Save()					// 8.����
{
 	//***************ת����������***********// 
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
 	
 	//***************���ļ�**************// 
 	ofstream out_file;
 	out_file.open(trans_name,ios::out);
 	if(!out_file)
 	{
 		cout<<"��"<< trans_name<<"ʧ��"<<endl; 
	 }
 	if(GetLastError() != 183)
	 {
	 	cout<<"δ���ҵ�"<<trans_name<<"�ļ�"<<endl;
	  } 
	  
     //***************����������Ϣ*********//
	 out_file<<name<<" "<<money<<" "<<level<<endl;
	 
	 //***************�˿��б�************// 
	 out_file<<Customer::GetCounst()<<endl;
	 
	 
	 //***************�����б�***********// 
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
	 
	 //***************ʳ���б�**********// 
	 out_file<<food_list.size()<<endl;
	 
	 for(i=0;i<food_list.size();++i)
	 {
	 	out_file<<food_list[i]->GetName()<<" "
	 	   		<<food_list[i]->GetPrice()<<" "
	 	   		<<food_list[i]->GetType()<<endl;
	 }
	 
	 //**************��¼�б�**********// 
	 if(record_list.size()==0)return;
	          //��¼���� 
	 out_file<<record_list.size()<<endl;
	 
	 
	         //��ӡ��¼
	 		 //��λ��� ʳ������
	 		 //ʳ������ 
	 for(i=0;i<record_list.size();++i)
	 {
	 	out_file<<record_list[i]->GetTableNum()<<" "<<record_list[i]->GetFoodCount()<<endl;
	 	for(int g=0;g < record_list[i]->GetFoodCount();++g)
	 	{
	 		out_file<<record_list[i]->GetFood(g)<<endl;
		 }
	 }
	 //*********ͳ�Ƽ�¼*************//
	 out_file<<food_list.size()<<endl;
	 
	 map<string,int>::iterator it;
	 for(it=stats.begin();it!=stats.end();++it)
	 {
	 	out_file<<it->first<<" "<<it->second<<endl;
	 }
	 //*************************//
	 out_file.close();
}
void Restaurant::Read(char save_name[]) // 9.���� 
{
 	
 	
 	ifstream in(save_name,ios::in);
 	//*********���ز���������Ϣ*********//
 	Gotoxy(0,1);
 	cout<<"���ز���������Ϣ"<<endl;
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
 	
 	//*********���ع˿��б�********//
 	 Gotoxy(0,1);
	 cout<<"���ع˿��б�"<<endl;
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
	 
	 
	 //********���������б�*********//
	 Gotoxy(0,1);
	 cout<<"���������б�"<<endl; 
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
	 
	 //*******����ʳ��*************//
	 Gotoxy(0,1);
	 cout<<"����ʳ��"<<endl;
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
	 
	 //*******�����˵�************//
	  Gotoxy(0,1);
	  cout<<"�����˵�"<<endl;
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
			
	 		//***********ʳ���б��ѯ************// 
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
	  cout<<"����ͳ����Ϣ"<<endl;
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
										// 10.��Ӳ�Ʒ
void Restaurant::StatisticalAnalysis()	// 11.ͳ�Ʒ��� 
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
