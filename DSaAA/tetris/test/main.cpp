#include<iostream>
using namespace std;
#include "Tool.h"
#include "Frame.h"
#include "Unit.h"
#include "Diamond.h"
/*     coded by ��־     
              2018/9/18          */
int main()
{
	Tool T;
	Frame F;
	char chioce;
	bool flag=true;
	F.Draw_border();
	F.Draw_message("��־");
	
	while (flag)
	{
		Diamond diamond;
		diamond.control();
		if (diamond.get_level() < 50)
		{
			T.gotoxy(0, 0);
			cout << "�����̴ﵽ�ĵȼ���" << diamond.get_level() << endl;
			cout << "�Ƿ������ �ǣ�y)" << endl;
			cin >> chioce;
			if (chioce == 'y')
			{
				flag = true;
			}
			else flag = false;
		}
	}
	return 0;
}    

