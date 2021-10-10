//#ifndef TETRIS_H_  
//#define TETRIS_H_  
#include <time.h>
#include <windows.h>  
#include <iostream>
#include <conio.h>
//#define int short

using namespace std; 
//长条形  
const int A1 = 0;  
const int A2 = 7;  
//方块  
const int B = 1;  
//L 形状  
const int C11 = 2;  
const int C12 = 8;  
const int C13 = 9;  
const int C14 = 10;  
//L 的另一个形状  
const int C21 = 3;  
const int C22 = 11;  
const int C23 = 12;  
const int C24 = 13;  
//Z 形状  
const int D11 = 4;  
const int D12 = 14;  
//Z 的另一个形状  
const int D21 = 5;  
const int D22 = 15;  
  
//土字形  
const int E31 = 6;  
const int E32 = 16;  
const int E33 = 17;  
const int E34 = 18;  
  
class tetris  
{  
private:  
    int map[12][23];        //背景  
    int top;            //当前的最高点  
    int score;          //分数  
    int level;          //难度等级  
    int ID;             //当前的方块的形状  
    int hotPoint[2];        //热点，当前活动的所在点     
public:  
    tetris()  
    {  
        for (int i = 0; i < 12; i++)//<span style="white-space:pre">     </span>//初始化地图  
        for (int j = 0; j < 23; j++)  
            map[i][j] = 0;  
        top = 99;  
        score = 0;  
        level = 1;  
        ID = 0;  
        hotPoint[0] = 5;    //下落起始点的横坐标  
        hotPoint[1] = 0;    //下落起始点的纵坐标  
    }  
    void DrawMap();       //  <span style="white-space:pre">    </span>//绘制地图  
    void initInterface();           //初始化界面  
    void DrawBox(int x, int y, int id); //绘制图形  
    void ReBox(int x, int y, int id);   //擦除图形  
    int  IsJudge(int x, int y, int id); //是否可以绘制图形  
    int  TurnBlock(int id);         //旋转方块  
    void UpdateMap(int id);         //更新画面  
    void RunGame();             //运行  
};  
  
//#endif 

void tetris::initInterface(){
	
}

int sharp[19][9] =                  //每个一维数组内有8个点，每两个点是一个 形状的一个小方格，在4*4的表格中  
{  
    { 0, 0, 0, 1, 0, 2, 0, 3, FOREGROUND_RED | FOREGROUND_INTENSITY },          //长条形  
    { 0, 0, 1, 0, 0, 1, 1, 1, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY },   //方形  
    { 0, 0, 0, 1, 1, 1, 2, 1, FOREGROUND_GREEN | FOREGROUND_RED },              //L形  
    { 0, 1, 1, 1, 2, 1, 2, 0, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY },  //反L形  
    { 0, 0, 1, 0, 1, 1, 2, 1, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY },    //Z形  
    { 1, 0, 2, 0, 0, 1, 1, 1, FOREGROUND_GREEN | FOREGROUND_INTENSITY },            //反Z形  
    { 0, 0, 0, 1, 0, 2, 1, 1, FOREGROUND_BLUE | FOREGROUND_INTENSITY },     //土形  
    //下面是上面形状的变换  
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
  
int high[19] = { 4, 2, 2, 2, 2, 2, 3, 1, 3, 2, 3, 3, 2, 3, 3, 3, 2, 3, 2 };  //数组是用来保存上面每个一维数组的各个形状高度的

void setCurPos(int i, int j, int color = 1 | 2 | 4) 
{                           //<span style="white-space:pre">    </span>//color相当于自己选择颜色，没有就用默认的白色  
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);       //获得标准输出句柄  
    SetConsoleTextAttribute(out, color);//<span style="white-space:pre">            </span>//设置颜色  
    COORD pos; pos.X = i * 2, pos.Y = j;
    SetConsoleCursorPosition(out, pos);//<span style="white-space:pre">         </span>//设置位置  

}  
void tetris::DrawMap()  
{  
    //地图框架  
    for (short i = 0; i < 14; i++)     // 0 - 13  
    {  
        setCurPos(i, 0);  
        cout << "■";  
    }  
    for (short i = 0; i < 25; i++) // 0 - 24  
    {  
        setCurPos(0, i);  
        cout << "■";  
        setCurPos(13, i);  
        cout << "■";  
    }  
    for (short i = 0; i < 14; i++)  
    {  
        setCurPos(i, 24);  
        cout << "■";  
    }  
    //信息框架  
    for (short i = 15; i <= 25; i++)  
    {  
        setCurPos(i, 0);  
        cout << "■";  
        setCurPos(i, 8);  
        cout << "■";  
    }  
    for (short i = 0; i <= 8; i++)  
    {  
        setCurPos(15, i);  
        cout << "■";  
        setCurPos(25, i);  
        cout << "■";  
    }  
    setCurPos(16, 12);  
    cout << "俄罗斯方块(6D)";  
    setCurPos(16, 15);  
    cout << " 分数： " << score;  
    setCurPos(16, 16);  
    cout << " 等级： " << level;  
}  

void tetris::DrawBox(int x, int y, int id)//<span style="white-space:pre">      </span>//画方块  
{  
    short nx = 0, ny = 0;  
    int color = sharp[id][8];  
    for (int i = 0; i < 4; i++)  
    {  
        nx = x + sharp[id][i * 2];  
        ny = y + sharp[id][i * 2 + 1];  
        setCurPos(nx + 1, ny + 1, color);//<span style="white-space:pre">   </span><span style="font-family: Arial, Helvetica, sans-serif;">//玩的地图比实际的地图横纵坐标都大1(因为有一个外围)</span><span style="white-space:pre">  
       cout << "■";  
    }  
}  
void tetris::ReBox(int x, int y, int id)//<span style="white-space:pre">        </span>//消除方块  
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
        if (nx < 0 || nx >= 12 || ny < 0 || ny >= 23 || map[nx][ny] != 0)   //不能放了，返回0  
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
    int clear = 0;                          //清除了多少个行，最后积分  
    for (int i = 0; i < 4; i++)  
    {  
        nx = hotPoint[0] + sharp[id][i * 2];  
        ny = hotPoint[1] + sharp[id][i * 2 + 1];  
        map[nx][ny] = sharp[id][8];             //保存颜色值，因为颜色值不为0，所以可以和没有方格区分开  
    }  
    if (hotPoint[1] < top)//<span style="white-space:pre">           </span>//因为地图的最上面是0，最底层是22，所以当前热点的y坐标如果小于top，就是最高点变化了，更新一下top  
        top = hotPoint[1];  
    for (int j = hotPoint[1]; j < hotPoint[1] + high[id]; j++)   //从上向下进行消除，从下向上容易少消行  
    {  
        flag = 0;  
        for (int i = 0; i < 12; i++)  
        {  
            if (map[i][j] == 0)         //<span style="white-space:pre">    </span>//没有可以消除的  
            {  
                flag = 1;  
                break;  
            }  
        }  
        if (flag == 0)                      //可以消除当前行  
        {  
            for (int k = j; k >= top; k--)//<span style="white-space:pre">           </span>//将每一行的上一行下移，直到最高点所在行下移完毕  
            {  
                if (k == 0)             //消除 到了最顶行  
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
                        setCurPos(i + 1, k + 1);   //因为有两条图形框边，游戏运行过程中的坐标系相对于 真正的坐标系是x、y都加 1 的  
                        if (map[i][k] == 0)    //被删除行的 上一行是空的，所以这一行也是空的  
                            cout << " ";  
                        else                        //上一行不是空的  
                        {  
                            int tempColor = map[i][k];  
                            setCurPos(i + 1, k + 1, tempColor);  
                            cout << "■";  
                        }  
                    }  
                }  
            }  
            top++;                  //<span style="white-space:pre">    </span>//消除成功，最高点下降一个  
            clear++;  
            score += clear * 100;  
        }  
    }  
    setCurPos(16, 15);  
    cout << " 分数： " << score;  
}
void tetris::RunGame()  
{  
    initInterface();  
    system("cls");  
    DrawMap();  
  
    char x = ' ';                   //读取键盘信息  
    int i = 0;      //<span style="white-space:pre">    </span>       //计时，到时间没有获得指令，自动下降  
    int Count = 0;  
    int nextId = 0;  
    int curId = 0;  
    srand(time(0));  
    curId = rand() % 7;  
    nextId = rand() % 7;  
    DrawBox(hotPoint[0], hotPoint[1], curId);   //画当前图形  
    DrawBox(17, 3, nextId);             //画出下一个要出现的图形  
    Count = 10000 - 1000 * level;  
    while (1)  
    {  
        if (i >= Count)                                  //可以自动下移了  
        {  
            i = 0;                                  //将 i 清零，下次继续计数  
            if (IsJudge(hotPoint[0], hotPoint[1] + 1, curId) == 0)  //<span style="white-space:pre">        </span>//下个位置无效，到底了  
            {  
                UpdateMap(curId);                       //更新一下画面  
                ReBox(17, 3, nextId);               //<span style="white-space:pre">    </span>   //清除原来的下一个图形  
                curId = nextId;  
                nextId = rand() % 7;  
                hotPoint[0] = 5;                        //更新热点  
                hotPoint[1] = 0;  
                DrawBox(hotPoint[0], hotPoint[1], curId);  
                DrawBox(17, 3, nextId);                 //<span style="white-space:pre">    </span>//画上现在的下一个图形  
                if (IsJudge(hotPoint[0], hotPoint[1], curId) == 0)      //无法绘制当前图形  
                {  
                    system("cls");  
                    cout << "游戏结束！！！最终得分为：" << score << endl;  
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
        if (_kbhit())                                   //读取键盘信息  
        {  
            x = _getch();  
            if (x == 'a' || x == 'A')                       //左移  
            {  
                if (IsJudge(hotPoint[0] - 1, hotPoint[1], curId))  
                {  
                    ReBox(hotPoint[0], hotPoint[1], curId);  
                    hotPoint[0]--;  
                    DrawBox(hotPoint[0], hotPoint[1], curId);  
                }  
            }  
            else if (x == 'd' || x == 'D')              //<span style="white-space:pre">        </span>//右移  
            {//<span style="white-space:pre">           //</span>  
                if (IsJudge(hotPoint[0] + 1, hotPoint[1], curId))  
                {  
                    ReBox(hotPoint[0], hotPoint[1], curId);  
                    hotPoint[0]++;  
                    DrawBox(hotPoint[0], hotPoint[1], curId);  
                }  
            }  
            else if (x == 's' || x == 'S')              //<span style="white-space:pre">        </span>//向下加速  
            {  
                if (IsJudge(hotPoint[0], hotPoint[1] + 1, curId))  
                {  
                    ReBox(hotPoint[0], hotPoint[1], curId);  
                    hotPoint[1]++;  
                    DrawBox(hotPoint[0], hotPoint[1], curId);  
                }  
            }  
            else if (x == 'w' || x == 'W')//<span style="white-space:pre">                      </span>//变形  
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
            else if (x == ' ')                          //暂停  
            {  
                _getch();  
            }  
            while (_kbhit())                            //读取掉剩下的键盘信息s  
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
