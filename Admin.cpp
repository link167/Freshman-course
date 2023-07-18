#include "Admin.h"

Admin::Admin()
{
	last_file=-1;
	save_site=-1;
}
//********��������*****// 
void Admin::menu()
{
	cout<<"*********************�˵�***********************"<<endl;
	cout<<"1.����ѧ����¼    2.�鿴ѧ����¼    3.��ѯ"<<endl;
	cout<<"4.ɾ��ѧ����¼    5.��ѧ������      6.���ɼ�����"<<endl;
	cout<<"7.�޸�ѧ����¼    8.�ɼ�ͳ��        9.�ļ�����"<<endl;
	cout<<"0.�˳�����"<<endl;
	int n;
	cin>>n;
	if(save_site==-1&&n!=9&&n!=0)
	{
		cout<<"δ��ȡ�ĵ�"<<endl;
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
	 					cout<<"��ӭ�´�ʹ��"<<endl;
	 					exit(0);
					 }
			 		cout<<"�Ƿ񱣴棿/n 1.����  2.������  3.����"<<endl;
	   	            cin>>n;
	   	            if(n==1)
			        {
			 			save();
			 			cout<<"��ӭ�´�ʹ��"<<endl;
			 			exit(0);
			 		}
	   	  			else if(n==2)
			 		{
			 			cout<<"��ӭ�´�ʹ��"<<endl;
		  				exit(0);
			  		} 
		  			else if(n==3);
		 }
	 }
}

void Admin::add()
{
	
	cout<<"������ѧ����Ϣ:"<<endl;
	cout<<setw(6)<<left<<"ѧ��"<<setw(6)<<left<<"����"<<setw(6)<<left<<"����"
	    <<setw(6)<<left<<"�Ա�"<<setw(6)<<left<<"��ѧ"<<setw(6)<<left<<"Ӣ��"
		<<setw(6)<<left<<"����"<<setw(6)<<left<<"רҵ"<<endl;
		
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
	//**************����**************// 
	for(int i=0;i<s.size();++i)
	{
		if(name1==s[i]->get_name())
		{
			cout<<"ѧ�������ظ�"<<endl; 
			cout<<"����������"<<endl;
			cin>>num1>>name1>>age1>>sex1>>math1>>english1>>chinese1>>major1;
			i=0; 
		}
		if(num1==s[i]->get_num())
		{
			cout<<"ѧ��ѧ���ظ�"<<endl; 
			cout<<"����������"<<endl;
			cin>>num1>>name1>>age1>>sex1>>math1>>english1>>chinese1>>major1;
			i=0;
		}
	}
	//********************************//
	student *help=new student(num1,name1,age1,sex1,math1,english1,chinese1,major1);
	s.push_back(help);
	cout<<"��ӳɹ�"<<endl; 
	Sleep(1000);
	system("cls");
}

void Admin::view()
{
	cout<<setw(6)<<left<<"ѧ��"<<setw(6)<<left<<"����"<<setw(6)<<left<<"����"
	    <<setw(6)<<left<<"�Ա�"<<setw(6)<<left<<"��ѧ"<<setw(6)<<left<<"Ӣ��"
		<<setw(6)<<left<<"����"<<setw(6)<<left<<"�ܷ�"<<setw(6)<<left<<"רҵ"<<endl;
		
	for(int i=0;i<s.size();++i)
	s[i]->dispaly();
}

void Admin::inquire()
{
	cout<<"�������ѯѧ��ѧ��"<<endl;
	int num1;
	cin>>num1;
	int help=0;
	
	for(int i=0;i<s.size();++i)
	{
		if(s[i]->get_num()==num1)
		{
			cout<<setw(6)<<left<<"ѧ��"<<setw(6)<<left<<"����"<<setw(6)<<left<<"����"
	    	    <<setw(6)<<left<<"�Ա�"<<setw(6)<<left<<"��ѧ"<<setw(6)<<left<<"Ӣ��"
		    	<<setw(6)<<left<<"����"<<setw(6)<<left<<"�ܷ�"<<setw(6)<<left<<"רҵ"<<endl;
		    	
			s[i]->dispaly();
			help=1;
			break;
		}
	}
	
	if(help==0)cout<<"δ��ѯ��"<<endl; 
	system("pause");
	system("cls");
}

void Admin::Delete()
{
	cout<<"������Ҫɾ��ѧ����Ϣ��ѧ��" <<endl;
	
	int num1;
	cin>>num1;
	//*****�ж��Ƿ����******// 
	int i=0;							//���� 
	for(;i<s.size();++i)				//
	{									//��ȡλ�� 
		if(s[i]->get_num()==num1)break;	//
	}									//���� 
	if(i==s.size())
	{
		cout<<"��ѧ��������"<<endl;
		return;
	}
	
	//*****ɾ��ѧ����Ϣ******//
	for(;i<s.size();++i)				//���� 
	{									//an=an+1
		s[i]=s[i+1];					//
	}									//���� 
	
	s.pop_back();
	cout<<"ɾ���ɹ�"<<endl;
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
	cout<<"ɾ���ɹ�"<<endl;
	system("pause");
	system("cls");
}
void Admin::change()
{

	cout<<"�������дѧ����ѧ��"<<endl;
	int num1;
	cin>>num1;
	cout<<"�������д��Ϣ"<<endl;
	 
	string name1;
	int age1;
	string sex1;
	int math1;
	int english1;
	int chinese1;
	string major1;
	cout<<setw(6)<<left<<"����"<<setw(6)<<left<<"����"
	    <<setw(6)<<left<<"�Ա�"<<setw(6)<<left<<"��ѧ"
		<<setw(6)<<left<<"Ӣ��"<<setw(6)<<left<<"����"
		<<setw(6)<<left<<"רҵ"<<endl;
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
	cout<<"�������"<<endl;
	system("pause");
	system("cls"); 
}

void Admin::statistics_menu()
{
	cout<<"1.��ѧͳ��  2.����ͳ��  3.Ӣ��ͳ��  "<<endl;
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
//*********ͳ��********//
void Admin::math_statistics()
{
	int min=999;
	int max=0;
	vector<student*>help; 
	for(int i=0;i<s.size();++i)
	{
		if(s[i]->get_math()>max)max=s[i]->get_math();
		if(s[i]->get_math()<min)min=s[i]->get_math();
		//��ȡ��������������Ϣ 
		if(s[i]->get_math()<60)
		{
			help.push_back(s[i]);
		}
	}
	cout<<"��ѧ��ͷ�:"<<min<<endl;
	cout<<"��ѧ��߷�:"<<max<<endl;
	cout<<"��ѧ����������Ϊ:"<<help.size()<<endl;
	
	cout<<"�Ƿ�鿴������ѧ����Ϣ��\n 1.��  2.��"<<endl;
	cin>>max;//max ���� 
	if(max==2)return;
	else if(max==1)
	{
		cout<<setw(6)<<left<<"ѧ��"<<setw(6)<<left<<"����"<<setw(6)<<left<<"����"
	        <<setw(6)<<left<<"�Ա�"<<setw(6)<<left<<"��ѧ"<<setw(6)<<left<<"Ӣ��"
		    <<setw(6)<<left<<"����"<<setw(6)<<left<<"�ܷ�"<<setw(6)<<left<<"רҵ"<<endl;
		    
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
		//��ȡ������������Ϣ 
		if(s[i]->get_chinese()<60)
		{
			help.push_back(s[i]);
		}
	}
	cout<<"������ͷ�:"<<min<<endl;
	cout<<"������߷�:"<<max<<endl;
	cout<<"���Ĳ���������Ϊ:"<<help.size()<<endl;
	
	cout<<"�Ƿ�鿴������ѧ����Ϣ��\n 1.��  2.��"<<endl;
	cin>>max;//max���� 
	if(max==2)return;
	else if(max==1)
	{
		cout<<setw(6)<<left<<"ѧ��"<<setw(6)<<left<<"����"<<setw(6)<<left<<"����"
	        <<setw(6)<<left<<"�Ա�"<<setw(6)<<left<<"��ѧ"<<setw(6)<<left<<"Ӣ��"
		    <<setw(6)<<left<<"����"<<setw(6)<<left<<"�ܷ�"<<setw(6)<<left<<"רҵ"<<endl;
		    
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
		//��ȡ��������Ϣ 
		if(s[i]->get_english()<60)
		{
			help.push_back(s[i]);
		}
	}
	cout<<"Ӣ����ͷ�:"<<min<<endl;
	cout<<"Ӣ����߷�:"<<max<<endl;
	cout<<"Ӣ�ﲻ��������Ϊ:"<<help.size()<<endl;
	
	cout<<"�Ƿ�鿴������ѧ����Ϣ��\n 1.��  2.��"<<endl;
	cin>>max;//max���� 
	if(max==2)return;
	else if(max==1)
	{
		cout<<setw(6)<<left<<"ѧ��"<<setw(6)<<left<<"����"<<setw(6)<<left<<"����"
	        <<setw(6)<<left<<"�Ա�"<<setw(6)<<left<<"��ѧ"<<setw(6)<<left<<"Ӣ��"
		    <<setw(6)<<left<<"����"<<setw(6)<<left<<"�ܷ�"<<setw(6)<<left<<"רҵ"<<endl;
		    
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
	cout<<"1.��ѧ  2.Ӣ��  3.����  4.�ܳɼ�"<<endl;
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

void Admin::score_sort()		//�ܳɼ����� 
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

void Admin::num_sort()			//ѧ������ 
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

void Admin::math_sort()			//��ѧ�ɼ����� 
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

void Admin::english_sort()		//Ӣ��ɼ����� 
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

void Admin::chinese_sort()		//���ĳɼ����� 
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

//********�ĵ�����*****//
void Admin::read(char name_save[])
{
	ifstream in(name_save,ios::in);
	if(!in)
	{
		cout<<"��ȡ�ļ�ʧ��"<<endl; 
		cout<<"get last error:"<<GetLastError()<<endl;
		return;
	}
	s.clear();//��ջ��� 
	
	int num1=-1;//��ǳ�״̬���ж��ļ��Ƿ�Ϊ�� 
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
			cout<<"��ȡ���"<<endl;
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
		cout<<"�洢ʧ��"<<endl;
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
		cout<<"���ĵ�Ŀ¼ʧ��"<<endl;
		cout<<"get last error:"<<GetLastError()<<endl;
		return;
	}
	cout<<"�������½��ĵ���"<<endl;
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
		cout<<"�����ļ�ʧ��"<<endl;
		cout<<"get last error:"<<GetLastError()<<endl;
		return;
	}
	string s_help="";
	fout<<s_help;
	fout.close();
	cout<<"�����ɹ�!"<<endl;
	system("pause");
	system("cls");
}
void Admin::readSaveList()	//��ȡ�ĵ��б� 
{
	ifstream in("SaveList.txt",ios::app);
	if(!in)
	{
		cout<<"��ȡ�ĵ��б�ʧ��"<<endl;
		cout<<"get last error:"<<GetLastError()<<endl;
		return;
	}
	cout<<"���   �ĵ���"<<endl; 
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
	
	cout<<"��ѡ��Ҫ��ȡ���ĵ�"<<endl;
	cout<<"���������"<<endl;
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
		cout<<"��ȡ�ĵ��б�ʧ��"<<endl;
		cout<<"get last error:"<<GetLastError()<<endl;
		return;
	}
	//********��ʾ�ĵ��б�********// 
	cout<<"���   �ĵ���"<<endl;
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
	
	//*********���ĵ��б�*********// 
	ofstream out("SaveList.txt",ios::out);
	if(!out)
	{
		cout<<"�ĵ��б����ʧ��"<<endl;
		cout<<"get last error:"<<GetLastError()<<endl;
		return;
	}
	
	cout<<"������Ҫɾ���ļ������"<<endl;
	int n;
	cin>>n;
	
	//ɾ���ĵ� 
	remove(file[n]);
	last_file--;
	if(n==0)//Ҫɾ�����Ƿ�Ϊ�����ĵ� 
	{
			for(;last_file>1;--last_file)	//
			out<<file[last_file]<<endl;		//�������Ļس��� 
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
	cout<<"1.��ȡ�ĵ�"<<endl;
	cout<<"2.�½��ĵ�"<<endl;
	cout<<"3.�����ĵ�"<<endl;
	cout<<"4.ɾ���ĵ�"<<endl; 
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
