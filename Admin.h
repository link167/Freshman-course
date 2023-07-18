#ifndef ADMIN_H
#define ADMIN_H
#include "student.h" 

class Admin
{
	private:
		vector<student*>s;		//ѧ���б� 
		char file[N][N];		//�ĵ��б� 
		int last_file;			//�ĵ��б����Ԫ������ 
		int save_site;			//��ǰ�����ĵ� 
		
	public:
		Admin();
		
		//*****��������******// 
		void menu();			//�˵�������˵����� 
		void add();				//��
		void view();			//Ԥ����� 
		void inquire();			//��;
		
		void Delete();			//ɾ;
		void Delete(int num1);
		
		void change();			//�� 
		void statistics_menu();	//ͳ�Ʋ˵� 
		//******ͳ��**********//
		void math_statistics();
		void chinese_statistics();
		void english_statistics();
		
		//******sort**********//
		void sort_menu();		//����˵� 
		void score_sort();
		void num_sort();
		void math_sort();
		void english_sort();
		void chinese_sort();
		
		//******�ĵ�����***//
		void read(char name_save[]);
		void save();
		void newSave();
		void readSaveList();
		void DDM();
		void delete_file();
	protected:
};

#endif
