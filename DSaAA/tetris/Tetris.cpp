//#ifndef TETRIS_H_  
//#define TETRIS_H_  
#include <time.h>
#include <windows.h>  
#include <iostream>
#include <conio.h>
//#define int short

using namespace std; 
//������  
const int A1 = 0;  
const int A2 = 7;  
//����  
const int B = 1;  
//L ��״  
const int C11 = 2;  
const int C12 = 8;  
const int C13 = 9;  
const int C14 = 10;  
//L ����һ����״  
const int C21 = 3;  
const int C22 = 11;  
const int C23 = 12;  
const int C24 = 13;  
//Z ��״  
const int D11 = 4;  
const int D12 = 14;  
//Z ����һ����״  
const int D21 = 5;  
const int D22 = 15;  
  
//������  
const int E31 = 6;  
const int E32 = 16;  
const int E33 = 17;  
const int E34 = 18;  
  
class tetris  
{  
private:  
    int map[12][23];        //����  
    int top;            //��ǰ����ߵ�  
    int score;          //����  
    int level;          //�Ѷȵȼ�  
    int ID;             //��ǰ�ķ������״  
    int hotPoint[2];        //�ȵ㣬��ǰ������ڵ�     
public:  
    tetris()  
    {  
        for (int i = 0; i < 12; i++)//<span style="white-space:pre">     </span>//��ʼ����ͼ  
        for (int j = 0; j < 23; j++)  
            map[i][j] = 0;  
        top = 99;  
        score = 0;  
        level = 1;  
        ID = 0;  
        hotPoint[0] = 5;    //������ʼ��ĺ�����  
        hotPoint[1] = 0;    //������ʼ���������  
    }  
    void DrawMap();       //  <span style="white-space:pre">    </span>//���Ƶ�ͼ  
    void initInterface();           //��ʼ������  
    void DrawBox(int x, int y, int id); //����ͼ��  
    void ReBox(int x, int y, int id);   //����ͼ��  
    int  IsJudge(int x, int y, int id); //�Ƿ���Ի���ͼ��  
    int  TurnBlock(int id);         //��ת����  
    void UpdateMap(int id);         //���»���  
    void RunGame();             //����  
};  
  
//#endif 

void tetris::initInterface(){
	
}

int sharp[19][9] =                  //ÿ��һά��������8���㣬ÿ��������һ�� ��״��һ��С������4*4�ı����  
{  
    { 0, 0, 0, 1, 0, 2, 0, 3, FOREGROUND_RED | FOREGROUND_INTENSITY },          //������  
    { 0, 0, 1, 0, 0, 1, 1, 1, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY },   //����  
    { 0, 0, 0, 1, 1, 1, 2, 1, FOREGROUND_GREEN | FOREGROUND_RED },              //L��  
    { 0, 1, 1, 1, 2, 1, 2, 0, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY },  //��L��  
    { 0, 0, 1, 0, 1, 1, 2, 1, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY },    //Z��  
    { 1, 0, 2, 0, 0, 1, 1, 1, FOREGROUND_GREEN | FOREGROUND_INTENSITY },            //��Z��  
    { 0, 0, 0, 1, 0, 2, 1, 1, FOREGROUND_BLUE | FOREGROUND_INTENSITY },     //����  
    //������������״�ı任  
    { 0, 0, 1, 0, 2, 0, 3, 0, FOREGROUND_RED | FOREGROUND_INTENSITY },                        
    { 1, 0, 1, 1, 1, 2, 0, 2, FOREGROUND_GREEN | FOREGROUND_RED },  
    { 0, 0, 1, 0, 2, 0, 2, 1, FOREGROUND_GREEN | FOREGROUND_RED },  
    { 0, 0, 1, 0, 0, 1, 0, 2, FOREGROUND_GREEN | FOREGROUND_RED },  
    { 0, 0, 1, 0, 1, 1, 1, 2, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY },  
    { 0, 0, 1, 0, 2, 0, 0, 1, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY },  
    { 0, 0, 0, 1, 0, 2, 1, 2, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY },  
    { 1, 0, 0, 1, 1, 1, 0, 2, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY },  
    { 0, 0, 0, 1, 1, 1, 1, 2, FOREGROUND_GREEN | FOREGROUND_INTENSITY },  
    { 0, 0, 1, 0, 2, 0, 1, 1, FOREGROUND_BLUE | FOREGROUND_INTENSITY },  
    { 0, 1, 1, 0, 1, 1, 1, 2, FOREGROUND_BLUE | FOREGROUND_INTENSITY },  
    { 1, 0, 0, 1, 1, 1, 2, 1, FOREGROUND_BLUE | FOREGROUND_INTENSITY }  
};  
  
int high[19] = { 4, 2, 2, 2, 2, 2, 3, 1, 3, 2, 3, 3, 2, 3, 3, 3, 2, 3, 2 };  //������������������ÿ��һά����ĸ�����״�߶ȵ�

void setCurPos(int i, int j, int color = 1 | 2 | 4) 
{                           //<span style="white-space:pre">    </span>//color�൱���Լ�ѡ����ɫ��û�о���Ĭ�ϵİ�ɫ  
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);       //��ñ�׼������  
    SetConsoleTextAttribute(out, color);//<span style="white-space:pre">            </span>//������ɫ  
    COORD pos; pos.X = i * 2, pos.Y = j;
    SetConsoleCursorPosition(out, pos);//<span style="white-space:pre">         </span>//����λ��  

}  
void tetris::DrawMap()  
{  
    //��ͼ���  
    for (short i = 0; i < 14; i++)     // 0 - 13  
    {  
        setCurPos(i, 0);  
        cout << "��";  
    }  
    for (short i = 0; i < 25; i++) // 0 - 24  
    {  
        setCurPos(0, i);  
        cout << "��";  
        setCurPos(13, i);  
        cout << "��";  
    }  
    for (short i = 0; i < 14; i++)  
    {  
        setCurPos(i, 24);  
        cout << "��";  
    }  
    //��Ϣ���  
    for (short i = 15; i <= 25; i++)  
    {  
        setCurPos(i, 0);  
        cout << "��";  
        setCurPos(i, 8);  
        cout << "��";  
    }  
    for (short i = 0; i <= 8; i++)  
    {  
        setCurPos(15, i);  
        cout << "��";  
        setCurPos(25, i);  
        cout << "��";  
    }  
    setCurPos(16, 12);  
    cout << "����˹����(6D)";  
    setCurPos(16, 15);  
    cout << " ������ " << score;  
    setCurPos(16, 16);  
    cout << " �ȼ��� " << level;  
}  

void tetris::DrawBox(int x, int y, int id)//<span style="white-space:pre">      </span>//������  
{  
    short nx = 0, ny = 0;  
    int color = sharp[id][8];  
    for (int i = 0; i < 4; i++)  
    {  
        nx = x + sharp[id][i * 2];  
        ny = y + sharp[id][i * 2 + 1];  
        setCurPos(nx + 1, ny + 1, color);//<span style="white-space:pre">   </span><span style="font-family: Arial, Helvetica, sans-serif;">//��ĵ�ͼ��ʵ�ʵĵ�ͼ�������궼��1(��Ϊ��һ����Χ)</span><span style="white-space:pre">  
       cout << "��";  
    }  
}  
void tetris::ReBox(int x, int y, int id)//<span style="white-space:pre">        </span>//��������  
{  
    int nx = 0, ny = 0;  
    for (int i = 0; i < 4; i++)  
    {  
        nx = x + sharp[id][i * 2];  
        ny = y + sharp[id][i * 2 + 1];  
        setCurPos(nx + 1, ny + 1);//<span style="white-space:pre">      </span>  
        cout << " ";  
    }  
}  

int tetris::IsJudge(int x, int y, int id)  
{  
    int nx = 0, ny = 0;  
    for (int i = 0; i < 4; i++)  
    {  
        nx = x + sharp[id][i * 2];  
        ny = y + sharp[id][i * 2 + 1];  
        if (nx < 0 || nx >= 12 || ny < 0 || ny >= 23 || map[nx][ny] != 0)   //���ܷ��ˣ�����0  
            return 0;  
    }  
    return 1;  
}  

int tetris::TurnBlock(int id)  
{  
    switch (id)  
    {  
    case A1: id = A2;  break;  
    case A2: id = A1;  break;  
  
    case B:  id = B;   break;  
  
    case C11:id = C12; break;  
    case C12:id = C13; break;  
    case C13:id = C14; break;  
    case C14:id = C11; break;  
  
    case C21:id = C22; break;  
    case C22:id = C23; break;  
    case C23:id = C24; break;  
    case C24:id = C21; break;  
  
    case D11:id = D12; break;  
    case D12:id = D11; break;  
  
    case D21:id = D22; break;  
    case D22:id = D21; break;  
  
    case E31:id = E32; break;  
    case E32:id = E33; break;  
    case E33:id = E34; break;  
    case E34:id = E31; break;  
    }  
    return id;  
}  

void tetris::UpdateMap(int id)  
{  
    int nx = 0, ny = 0;  
    int flag;  
    int clear = 0;                          //����˶��ٸ��У�������  
    for (int i = 0; i < 4; i++)  
    {  
        nx = hotPoint[0] + sharp[id][i * 2];  
        ny = hotPoint[1] + sharp[id][i * 2 + 1];  
        map[nx][ny] = sharp[id][8];             //������ɫֵ����Ϊ��ɫֵ��Ϊ0�����Կ��Ժ�û�з������ֿ�  
    }  
    if (hotPoint[1] < top)//<span style="white-space:pre">           </span>//��Ϊ��ͼ����������0����ײ���22�����Ե�ǰ�ȵ��y�������С��top��������ߵ�仯�ˣ�����һ��top  
        top = hotPoint[1];  
    for (int j = hotPoint[1]; j < hotPoint[1] + high[id]; j++)   //�������½���������������������������  
    {  
        flag = 0;  
        for (int i = 0; i < 12; i++)  
        {  
            if (map[i][j] == 0)         //<span style="white-space:pre">    </span>//û�п���������  
            {  
                flag = 1;  
                break;  
            }  
        }  
        if (flag == 0)                      //����������ǰ��  
        {  
            for (int k = j; k >= top; k--)//<span style="white-space:pre">           </span>//��ÿһ�е���һ�����ƣ�ֱ����ߵ��������������  
            {  
                if (k == 0)             //���� �������  
                {  
                    for (int i = 0; i < 12; i++)  
                    {  
                        map[i][k] = 0;  
                        setCurPos(i + 1, k + 1);  
                        cout << " ";  
                    }  
                }  
                else  
                {  
                    for (int i = 0; i < 12; i++)  
                    {  
                        map[i][k] = map[i][k - 1];  
                        setCurPos(i + 1, k + 1);   //��Ϊ������ͼ�ο�ߣ���Ϸ���й����е�����ϵ����� ����������ϵ��x��y���� 1 ��  
                        if (map[i][k] == 0)    //��ɾ���е� ��һ���ǿյģ�������һ��Ҳ�ǿյ�  
                            cout << " ";  
                        else                        //��һ�в��ǿյ�  
                        {  
                            int tempColor = map[i][k];  
                            setCurPos(i + 1, k + 1, tempColor);  
                            cout << "��";  
                        }  
                    }  
                }  
            }  
            top++;                  //<span style="white-space:pre">    </span>//�����ɹ�����ߵ��½�һ��  
            clear++;  
            score += clear * 100;  
        }  
    }  
    setCurPos(16, 15);  
    cout << " ������ " << score;  
}
void tetris::RunGame()  
{  
    initInterface();  
    system("cls");  
    DrawMap();  
  
    char x = ' ';                   //��ȡ������Ϣ  
    int i = 0;      //<span style="white-space:pre">    </span>       //��ʱ����ʱ��û�л��ָ��Զ��½�  
    int Count = 0;  
    int nextId = 0;  
    int curId = 0;  
    srand(time(0));  
    curId = rand() % 7;  
    nextId = rand() % 7;  
    DrawBox(hotPoint[0], hotPoint[1], curId);   //����ǰͼ��  
    DrawBox(17, 3, nextId);             //������һ��Ҫ���ֵ�ͼ��  
    Count = 10000 - 1000 * level;  
    while (1)  
    {  
        if (i >= Count)                                  //�����Զ�������  
        {  
            i = 0;                                  //�� i ���㣬�´μ�������  
            if (IsJudge(hotPoint[0], hotPoint[1] + 1, curId) == 0)  //<span style="white-space:pre">        </span>//�¸�λ����Ч��������  
            {  
                UpdateMap(curId);                       //����һ�»���  
                ReBox(17, 3, nextId);               //<span style="white-space:pre">    </span>   //���ԭ������һ��ͼ��  
                curId = nextId;  
                nextId = rand() % 7;  
                hotPoint[0] = 5;                        //�����ȵ�  
                hotPoint[1] = 0;  
                DrawBox(hotPoint[0], hotPoint[1], curId);  
                DrawBox(17, 3, nextId);                 //<span style="white-space:pre">    </span>//�������ڵ���һ��ͼ��  
                if (IsJudge(hotPoint[0], hotPoint[1], curId) == 0)      //�޷����Ƶ�ǰͼ��  
                {  
                    system("cls");  
                    cout << "��Ϸ�������������յ÷�Ϊ��" << score << endl;  
                    system("pause");  
                    exit(0);  
                }  
            }  
            else  
            {  
                ReBox(hotPoint[0], hotPoint[1], curId);  
                hotPoint[1]++;  
                DrawBox(hotPoint[0], hotPoint[1], curId);  
            }  
        }  
        if (_kbhit())                                   //��ȡ������Ϣ  
        {  
            x = _getch();  
            if (x == 'a' || x == 'A')                       //����  
            {  
                if (IsJudge(hotPoint[0] - 1, hotPoint[1], curId))  
                {  
                    ReBox(hotPoint[0], hotPoint[1], curId);  
                    hotPoint[0]--;  
                    DrawBox(hotPoint[0], hotPoint[1], curId);  
                }  
            }  
            else if (x == 'd' || x == 'D')              //<span style="white-space:pre">        </span>//����  
            {//<span style="white-space:pre">           //</span>  
                if (IsJudge(hotPoint[0] + 1, hotPoint[1], curId))  
                {  
                    ReBox(hotPoint[0], hotPoint[1], curId);  
                    hotPoint[0]++;  
                    DrawBox(hotPoint[0], hotPoint[1], curId);  
                }  
            }  
            else if (x == 's' || x == 'S')              //<span style="white-space:pre">        </span>//���¼���  
            {  
                if (IsJudge(hotPoint[0], hotPoint[1] + 1, curId))  
                {  
                    ReBox(hotPoint[0], hotPoint[1], curId);  
                    hotPoint[1]++;  
                    DrawBox(hotPoint[0], hotPoint[1], curId);  
                }  
            }  
            else if (x == 'w' || x == 'W')//<span style="white-space:pre">                      </span>//����  
            {  
                int temp = curId;  
                curId = TurnBlock(curId);  
                if (IsJudge(hotPoint[0], hotPoint[1], curId))  
                {  
                    ReBox(hotPoint[0], hotPoint[1], temp);  
                    DrawBox(hotPoint[0], hotPoint[1], curId);  
                }  
                else  
                    curId = temp;  
            }  
            else if (x == ' ')                          //��ͣ  
            {  
                _getch();  
            }  
            while (_kbhit())                            //��ȡ��ʣ�µļ�����Ϣs  
                _getch();  
        }  
        i++;  
    }  
}  
int main()  
{
    tetris ter;  
    ter.RunGame();  
    return (int)0;
}
