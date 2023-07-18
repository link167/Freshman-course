#ifndef ADMIN_H
#define ADMIN_H
#include "student.h" 

class Admin
{
	private:
		vector<student*>s;		//学生列表 
		char file[N][N];		//文档列表 
		int last_file;			//文档列表最后元素索引 
		int save_site;			//当前所在文档 
		
	public:
		Admin();
		
		//*****基本功能******// 
		void menu();			//菜单界面与菜单功能 
		void add();				//增
		void view();			//预览表格 
		void inquire();			//查;
		
		void Delete();			//删;
		void Delete(int num1);
		
		void change();			//改 
		void statistics_menu();	//统计菜单 
		//******统计**********//
		void math_statistics();
		void chinese_statistics();
		void english_statistics();
		
		//******sort**********//
		void sort_menu();		//排序菜单 
		void score_sort();
		void num_sort();
		void math_sort();
		void english_sort();
		void chinese_sort();
		
		//******文档管理***//
		void read(char name_save[]);
		void save();
		void newSave();
		void readSaveList();
		void DDM();
		void delete_file();
	protected:
};

#endif
