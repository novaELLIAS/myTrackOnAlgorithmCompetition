#include "Frame.h"



Frame::Frame()
{
}
Frame::~Frame()
{
}
void Frame::Draw_border()
{
Tool T;
	for (int i = LEFT; i <= RIGHT3; ++i)
	{
		T.gotoxy(i, UP);
		cout << "*";                                                  //�߽��������õ�*��
		T.gotoxy(i, BUTTOM);
		cout << "*";
	}
	for (int i = RIGHT; i <= RIGHT3; ++i)
	{
		T.gotoxy(i, MIDDLE1);
		cout << "*";
		T.gotoxy(i, MIDDLE2);
		cout << "*";
	}
	for (int i = UP; i <= BUTTOM; ++i)
	{
		T.gotoxy(LEFT, i);  cout << "*";
		T.gotoxy(RIGHT, i); cout << "*";
		T.gotoxy(RIGHT3, i); cout << "*";
	}
	for (int i = UP; i <= MIDDLE2; ++i)
	{
		T.gotoxy(RIGHT2, i); cout << "*";
	}
	T.gotoxy(0, 0);
}

void Frame::Draw_message(string name)
{
	Tool T;
	T.gotoxy(RIGHT2 + 1, UP + 2);
	cout << "��Ϸ���ƣ�";
	T.gotoxy(RIGHT2 + 1, UP + 3);
	cout << "����˹����";
	T.gotoxy(RIGHT2 + 1, UP + 4);
	cout << "�����ߣ�";
	T.gotoxy(RIGHT2 + 1, UP + 5);
	cout << "��־";
	T.gotoxy(RIGHT + 1, MIDDLE2 + 1);
	cout << "ͨ��AD�����Ʒ���";
	T.gotoxy(RIGHT + 1, MIDDLE2 + 2);
	cout <<"ͨ��R����ת��S���ٽ�";
	T.gotoxy(RIGHT2 + 1, MIDDLE1 + 2);
	cout << "������ƣ�";
	T.gotoxy(RIGHT2 + 1, MIDDLE1 + 3);
	cout << name;
}

void Frame::Draw_score(int score, int level)
{
	Tool T;
	T.gotoxy(RIGHT + 1, MIDDLE1 + 1);  cout << "��ǰ�÷֣�";
	T.gotoxy(RIGHT + 1, MIDDLE1 + 2); cout << "   ";
	T.gotoxy(RIGHT + 1, MIDDLE1 + 2); cout << score;
	T.gotoxy(RIGHT + 1, MIDDLE1 + 3); cout << "��ǰ�ؿ���";
	T.gotoxy(RIGHT + 1, MIDDLE1 + 4); cout << "   ";
	T.gotoxy(RIGHT + 1, MIDDLE1 + 4); cout << level;
}
