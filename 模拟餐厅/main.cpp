#include"Admin.h"

void Gotoxy(int x,int y)
{
	COORD pos={x,y};
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
}

int main(int argc, char** argv) 
{
	Admin ad;
	
	ad.Read();
	
	while(1)
	{
		ad.AdminMenu();
	}

	return 0;
}
