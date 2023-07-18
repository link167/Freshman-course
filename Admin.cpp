#include "Admin.h"

Admin::Admin()
{
	last_file=-1;
	save_site=-1;
}
//********基本操作*****// 
void Admin::menu()
{
	cout<<"*********************菜单***********************"<<endl;
	cout<<"1.增加学生记录    2.查看学生记录    3.查询"<<endl;
	cout<<"4.删除学生记录    5.按学号排序      6.按成绩排序"<<endl;
	cout<<"7.修改学生记录    8.成绩统计        9.文件管理"<<endl;
	cout<<"0.退出程序"<<endl;
	int n;
	cin>>n;
	if(save_site==-1&&n!=9&&n!=0)
	{
		cout<<"未读取文档"<<endl;
		DDM();
	 } 
	 else
	 {
	 	switch(n)
	 	{
	 		case 1:add();break;
	 		case 2:view();break;
	 		case 3:inquire();break;
	 		case 4:Delete();break;
	 		case 5:num_sort();break;
	 		case 6:sort_menu();break;
	 		case 7:change();break;
	 		case 8:statistics_menu();break;
	 		case 9:DDM();break;
	 		case 0: 
	 				if(save_site==-1)
	 				{
	 					cout<<"欢迎下次使用"<<endl;
	 					exit(0);
					 }
			 		cout<<"是否保存？/n 1.保存  2.不保存  3.返回"<<endl;
	   	            cin>>n;
	   	            if(n==1)
			        {
			 			save();
			 			cout<<"欢迎下次使用"<<endl;
			 			exit(0);
			 		}
	   	  			else if(n==2)
			 		{
			 			cout<<"欢迎下次使用"<<endl;
		  				exit(0);
			  		} 
		  			else if(n==3);
		 }
	 }
}

void Admin::add()
{
	
	cout<<"请输入学生信息:"<<endl;
	cout<<setw(6)<<left<<"学号"<<setw(6)<<left<<"姓名"<<setw(6)<<left<<"年龄"
	    <<setw(6)<<left<<"性别"<<setw(6)<<left<<"数学"<<setw(6)<<left<<"英语"
		<<setw(6)<<left<<"语文"<<setw(6)<<left<<"专业"<<endl;
		
	    int num1;
	    string name1;
		int age1;
		string sex1;
		int math1;
		int english1;
		int chinese1;
		int score1;
		string major1;
	cin>>num1>>name1>>age1>>sex1>>math1>>english1>>chinese1>>major1;
	//**************查重**************// 
	for(int i=0;i<s.size();++i)
	{
		if(name1==s[i]->get_name())
		{
			cout<<"学生姓名重复"<<endl; 
			cout<<"请重新输入"<<endl;
			cin>>num1>>name1>>age1>>sex1>>math1>>english1>>chinese1>>major1;
			i=0; 
		}
		if(num1==s[i]->get_num())
		{
			cout<<"学生学号重复"<<endl; 
			cout<<"请重新输入"<<endl;
			cin>>num1>>name1>>age1>>sex1>>math1>>english1>>chinese1>>major1;
			i=0;
		}
	}
	//********************************//
	student *help=new student(num1,name1,age1,sex1,math1,english1,chinese1,major1);
	s.push_back(help);
	cout<<"添加成功"<<endl; 
	Sleep(1000);
	system("cls");
}

void Admin::view()
{
	cout<<setw(6)<<left<<"学号"<<setw(6)<<left<<"姓名"<<setw(6)<<left<<"年龄"
	    <<setw(6)<<left<<"性别"<<setw(6)<<left<<"数学"<<setw(6)<<left<<"英语"
		<<setw(6)<<left<<"语文"<<setw(6)<<left<<"总分"<<setw(6)<<left<<"专业"<<endl;
		
	for(int i=0;i<s.size();++i)
	s[i]->dispaly();
}

void Admin::inquire()
{
	cout<<"请输入查询学生学号"<<endl;
	int num1;
	cin>>num1;
	int help=0;
	
	for(int i=0;i<s.size();++i)
	{
		if(s[i]->get_num()==num1)
		{
			cout<<setw(6)<<left<<"学号"<<setw(6)<<left<<"姓名"<<setw(6)<<left<<"年龄"
	    	    <<setw(6)<<left<<"性别"<<setw(6)<<left<<"数学"<<setw(6)<<left<<"英语"
		    	<<setw(6)<<left<<"语文"<<setw(6)<<left<<"总分"<<setw(6)<<left<<"专业"<<endl;
		    	
			s[i]->dispaly();
			help=1;
			break;
		}
	}
	
	if(help==0)cout<<"未查询到"<<endl; 
	system("pause");
	system("cls");
}

void Admin::Delete()
{
	cout<<"请输入要删除学生信息的学号" <<endl;
	
	int num1;
	cin>>num1;
	//*****判断是否存在******// 
	int i=0;							//—— 
	for(;i<s.size();++i)				//
	{									//获取位置 
		if(s[i]->get_num()==num1)break;	//
	}									//—— 
	if(i==s.size())
	{
		cout<<"此学生不存在"<<endl;
		return;
	}
	
	//*****删除学生信息******//
	for(;i<s.size();++i)				//—— 
	{									//an=an+1
		s[i]=s[i+1];					//
	}									//—— 
	
	s.pop_back();
	cout<<"删除成功"<<endl;
	system("pause");
	system("cls");
}
void Admin::Delete(int num1)
{
	int i=0;
	for(;i<s.size();++i)
	{
		if(s[i]->get_num()==num1)break;
	}
	for(;i<s.size();++i)
	{
		s[i]=s[i+1];
	}
	
	s.pop_back();
	cout<<"删除成功"<<endl;
	system("pause");
	system("cls");
}
void Admin::change()
{

	cout<<"请输入改写学生的学号"<<endl;
	int num1;
	cin>>num1;
	cout<<"请输入改写信息"<<endl;
	 
	string name1;
	int age1;
	string sex1;
	int math1;
	int english1;
	int chinese1;
	string major1;
	cout<<setw(6)<<left<<"姓名"<<setw(6)<<left<<"年龄"
	    <<setw(6)<<left<<"性别"<<setw(6)<<left<<"数学"
		<<setw(6)<<left<<"英语"<<setw(6)<<left<<"语文"
		<<setw(6)<<left<<"专业"<<endl;
	cin>>name1>>age1>>sex1>>math1>>english1>>chinese1>>major1;
	
	for(int i=0;i<s.size();++i)
	{
		if(s[i]->get_num()==num1)
		{	
			s[i]->name_change(name1);
			s[i]->age_change(age1);
			s[i]->sex_change(sex1);
			s[i]->math_change(math1);
			s[i]->english_change(english1);
			s[i]->chinese_change(chinese1);
			s[i]->major_change(major1);
			break;
		}
	}
	cout<<"更改完成"<<endl;
	system("pause");
	system("cls"); 
}

void Admin::statistics_menu()
{
	cout<<"1.数学统计  2.语文统计  3.英语统计  "<<endl;
	int n;
	cin>>n;
	switch(n)
	{
		case 1:math_statistics();break;
		case 2:chinese_statistics();break;
		case 3:english_statistics();break;
	}
	system("cls");
}
//*********统计********//
void Admin::math_statistics()
{
	int min=999;
	int max=0;
	vector<student*>help; 
	for(int i=0;i<s.size();++i)
	{
		if(s[i]->get_math()>max)max=s[i]->get_math();
		if(s[i]->get_math()<min)min=s[i]->get_math();
		//获取不及格人数的信息 
		if(s[i]->get_math()<60)
		{
			help.push_back(s[i]);
		}
	}
	cout<<"数学最低分:"<<min<<endl;
	cout<<"数学最高分:"<<max<<endl;
	cout<<"数学不及格人数为:"<<help.size()<<endl;
	
	cout<<"是否查看不及格学生信息？\n 1.是  2.否"<<endl;
	cin>>max;//max 复用 
	if(max==2)return;
	else if(max==1)
	{
		cout<<setw(6)<<left<<"学号"<<setw(6)<<left<<"姓名"<<setw(6)<<left<<"年龄"
	        <<setw(6)<<left<<"性别"<<setw(6)<<left<<"数学"<<setw(6)<<left<<"英语"
		    <<setw(6)<<left<<"语文"<<setw(6)<<left<<"总分"<<setw(6)<<left<<"专业"<<endl;
		    
		for(int i=0;i<help.size();++i)
		{
			help[i]->dispaly();
		}
	}
	system("pause");
	system("cls");
}

void Admin::chinese_statistics()
{
	int min=999;
	int max=0;
	vector<student*>help;
	for(int i=0;i<help.size();++i)
	{
		if(s[i]->get_chinese()>max)max=s[i]->get_chinese();
		if(s[i]->get_chinese()<min)min=s[i]->get_chinese();
		//获取不及格人数信息 
		if(s[i]->get_chinese()<60)
		{
			help.push_back(s[i]);
		}
	}
	cout<<"语文最低分:"<<min<<endl;
	cout<<"语文最高分:"<<max<<endl;
	cout<<"语文不及格人数为:"<<help.size()<<endl;
	
	cout<<"是否查看不及格学生信息？\n 1.是  2.否"<<endl;
	cin>>max;//max复用 
	if(max==2)return;
	else if(max==1)
	{
		cout<<setw(6)<<left<<"学号"<<setw(6)<<left<<"姓名"<<setw(6)<<left<<"年龄"
	        <<setw(6)<<left<<"性别"<<setw(6)<<left<<"数学"<<setw(6)<<left<<"英语"
		    <<setw(6)<<left<<"语文"<<setw(6)<<left<<"总分"<<setw(6)<<left<<"专业"<<endl;
		    
		for(int i=0;i<help.size();++i)
		{
			help[i]->dispaly();
		}
	}
	system("pause");
	system("cls");
}
void Admin::english_statistics()
{
	int min=999;
	int max=0;
	vector<student*>help;
	for(int i=0;i<help.size();++i)
	{
		if(s[i]->get_english()>max)max=s[i]->get_english();
		if(s[i]->get_english()<min)min=s[i]->get_english();
		//获取不及格信息 
		if(s[i]->get_english()<60)
		{
			help.push_back(s[i]);
		}
	}
	cout<<"英语最低分:"<<min<<endl;
	cout<<"英语最高分:"<<max<<endl;
	cout<<"英语不及格人数为:"<<help.size()<<endl;
	
	cout<<"是否查看不及格学生信息？\n 1.是  2.否"<<endl;
	cin>>max;//max复用 
	if(max==2)return;
	else if(max==1)
	{
		cout<<setw(6)<<left<<"学号"<<setw(6)<<left<<"姓名"<<setw(6)<<left<<"年龄"
	        <<setw(6)<<left<<"性别"<<setw(6)<<left<<"数学"<<setw(6)<<left<<"英语"
		    <<setw(6)<<left<<"语文"<<setw(6)<<left<<"总分"<<setw(6)<<left<<"专业"<<endl;
		    
		for(int i=0;i<help.size();++i)
		{
			help[i]->dispaly();
		}
	}
	system("pause");
	system("cls");
}

//*********sort********//
void Admin::sort_menu()	
{
	cout<<"1.数学  2.英语  3.语文  4.总成绩"<<endl;
	int n;
	cin>>n;
	system("cls");
	switch(n)
	{
		case 1:math_sort();break;
		case 2:english_sort();break;
		case 3:chinese_sort();break;
		case 4:score_sort();break;
	}
	
}

void Admin::score_sort()		//总成绩排序 
{
	student *help=NULL;
	for(int i=0;i<s.size()-1;++i)
	{
		for(int g=0;g<s.size()-1-i;++g)
		{
			if(s[g]->get_score()>s[g+1]->get_score())
			{
				help=s[g];
				s[g]=s[g+1];
				s[g+1]=help;
			}
		}
	}
	view();
}

void Admin::num_sort()			//学号排序 
{
	student *help=NULL;
	for(int i=0;i<s.size()-1;++i)
	{
		for(int g=0;g<s.size()-1-i;++g)
		{
			if(s[g]->get_num()>s[g+1]->get_num())
			{
				help=s[g];
				s[g]=s[g+1];
				s[g+1]=help;
			}
		}
	}
	view();
}

void Admin::math_sort()			//数学成绩排序 
{
	student *help=NULL;
	for(int i=0;i<s.size()-1;++i)
	{
		for(int g=0;g<s.size()-1-i;++g)
		{
			if(s[g]->get_math()>s[g+1]->get_math())
			{
				help=s[g];
				s[g]=s[g+1];
				s[g+1]=help;
			}
		}
	}
	view();
}

void Admin::english_sort()		//英语成绩排序 
{
	student *help=NULL;
	for(int i=0;i<s.size()-1;++i)
	{
		for(int g=0;g<s.size()-1-i;++g)
		{
			if(s[g]->get_english()>s[g+1]->get_english())
			{
				help=s[g];
				s[g]=s[g+1];
				s[g+1]=help;
			}
		}
	}
	view();
}

void Admin::chinese_sort()		//语文成绩排序 
{
	student *help=NULL;
	for(int i=0;i<s.size()-1;++i)
	{
		for(int g=0;g<s.size()-1-i;++g)
		{
			if(s[g]->get_chinese()>s[g+1]->get_chinese())
			{
				help=s[g];
				s[g]=s[g+1];
				s[g+1]=help;
			}
		}
	}
	view();
}

//********文档管理*****//
void Admin::read(char name_save[])
{
	ifstream in(name_save,ios::in);
	if(!in)
	{
		cout<<"读取文件失败"<<endl; 
		cout<<"get last error:"<<GetLastError()<<endl;
		return;
	}
	s.clear();//清空缓存 
	
	int num1=-1;//标记出状态，判断文件是否为空 
	string name1;
	int age1;
	string sex1;
	int math1;
	int english1;
	int chinese1;
	string major1;
	
	for(int i=0;i<N;++i)
	{
		if(in.eof())
		{
			cout<<"读取完成"<<endl;
			break;
		}
		
		in>>num1>>name1>>age1>>sex1>>math1>>english1>>chinese1>>major1;
		student *help;
		help=new student(num1,name1,age1,sex1,math1,english1,chinese1,major1);
		s.push_back(help);
		
	}
	if(num1==-1)Delete(num1);
	in.close();
}

void Admin::save()
{
	ofstream out(file[save_site],ios::out);
	if(!out)
	{
		cout<<"存储失败"<<endl;
		cout<<"get last error:"<<GetLastError()<<endl;
		return;
	}
	int last=s.size()-1;
	for(;last>0;--last)
	{
		out<<s[last]->get_num()<<" "<<s[last]->get_name()<<" "
		   <<s[last]->get_age()<<" "<<s[last]->get_sex()<<" "
		   <<s[last]->get_math()<<" "<<s[last]->get_english()<<" "
		   <<s[last]->get_chinese()<<" "<<s[last]->get_major()<<endl;
	}
	out<<s[last]->get_num()<<" "<<s[last]->get_name()<<" "
	   <<s[last]->get_age()<<" "<<s[last]->get_sex()<<" "
	   <<s[last]->get_math()<<" "<<s[last]->get_english()<<" "
	   <<s[last]->get_chinese()<<" "<<s[last]->get_major();
	out.close();
}
void Admin::newSave()
{
	ofstream out("SaveList.txt",ios::app);
	ifstream in("SaveList.txt",ios::in);
	if(!out||!in)
	{
		cout<<"打开文档目录失败"<<endl;
		cout<<"get last error:"<<GetLastError()<<endl;
		return;
	}
	cout<<"请输入新建文档名"<<endl;
	char name_save[N];
	
	cin>>name_save;
	char help;
	in>>help;
	if(help==NULL)
	{
		out<<name_save;
		out<<".txt";
		out.close();
		in.close();
	}
	else
	{
		out<<endl<<name_save<<".txt";
		out.close();
		in.close();
	}
	
	int length=0;
	for(;name_save[length]!=NULL;++length);
	name_save[length]='.';length++;
	name_save[length]='t';length++;
	name_save[length]='x';length++;
	name_save[length]='t';length++;
	
	ofstream fout(name_save,ios::out);
	if(!fout)
	{
		cout<<"生成文件失败"<<endl;
		cout<<"get last error:"<<GetLastError()<<endl;
		return;
	}
	string s_help="";
	fout<<s_help;
	fout.close();
	cout<<"创建成功!"<<endl;
	system("pause");
	system("cls");
}
void Admin::readSaveList()	//读取文档列表 
{
	ifstream in("SaveList.txt",ios::app);
	if(!in)
	{
		cout<<"读取文档列表失败"<<endl;
		cout<<"get last error:"<<GetLastError()<<endl;
		return;
	}
	cout<<"序号   文档名"<<endl; 
	last_file=-1; 
	for(int i=0;1;++i)
	{
		if(in.eof())
		{
			break;
		}
		in>>file[i];
		cout<<i<<"      ";
		cout<<file[i]<<endl;
		++last_file;
	}
	
	cout<<"请选择要读取的文档"<<endl;
	cout<<"请输入序号"<<endl;
	int n;
	cin>>n;
	save_site=n;
	read(file[n]);
	in.close();
	system("pause");
	system("cls");
}
void Admin::delete_file()	//
{
	ifstream in("SaveList.txt",ios::app);
	if(!in)
	{
		cout<<"读取文档列表失败"<<endl;
		cout<<"get last error:"<<GetLastError()<<endl;
		return;
	}
	//********显示文档列表********// 
	cout<<"序号   文档名"<<endl;
	last_file=-1;  
	for(int i=0;1;++i)
	{
		if(in.eof())
		{
			break;
		}
		in>>file[i];
		cout<<i<<"      ";
		cout<<file[i]<<endl;
		++last_file;
	}
	in.close();
	
	//*********打开文档列表*********// 
	ofstream out("SaveList.txt",ios::out);
	if(!out)
	{
		cout<<"文档列表更新失败"<<endl;
		cout<<"get last error:"<<GetLastError()<<endl;
		return;
	}
	
	cout<<"请输入要删除文件的序号"<<endl;
	int n;
	cin>>n;
	
	//删除文档 
	remove(file[n]);
	last_file--;
	if(n==0)//要删除的是否为最后的文档 
	{
			for(;last_file>1;--last_file)	//
			out<<file[last_file]<<endl;		//消除最后的回车符 
											//
			out<<file[last_file];			//
	}
	else
	{
			for(;last_file>0;--last_file)
			{
			if(last_file!=n)out<<file[last_file]<<endl;
			}	
			out<<file[last_file];
	}
	
	out.close();
	system("pause");
	system("cls");
}
void Admin::DDM()
{
	cout<<"1.读取文档"<<endl;
	cout<<"2.新建文档"<<endl;
	cout<<"3.保存文档"<<endl;
	cout<<"4.删除文档"<<endl; 
	int n;
	cin>>n;
	switch(n)
	{
		case 1:readSaveList();break;
		case 2:newSave();break;
		case 3:save();break;
		case 4:delete_file();break;
	}
}
