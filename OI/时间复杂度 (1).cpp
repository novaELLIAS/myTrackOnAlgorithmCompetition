#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Node
{
    char w;
    int p;
};
const int MAXN = 100 + 10;

Node S[MAXN]; // 栈 

int main()
{
    int T = 0;
    cin >> T;
    while(T--)
    {
        int top = 0; // 栈顶位置 

        int err = 0; // 编译错误标志 
        int L;
        char buf[100];
        int ans_p; // 储存输入复杂度的指数 

        cin >> L >> buf;
        if (strlen(buf) == 4) ans_p = 0;
        else {
            ans_p = 0;
            for(int i = 4; buf[i] != ')'; i ++)
                ans_p = ans_p * 10 + buf[i] - '0';
        }

        int max_p = 0; // 储存实际复杂度的指数 
        while(L--)
        {
            cin >> buf;
            if (buf[0] == 'F')
            {
                char var[10], l[10], r[10];
                cin >> var >> l >> r;

                for(int i = 1; i <= top; i ++)
                    if (S[i].w == var[0]) // 变量名已存在 
                        err = 1;
                int a = l[0] == 'n' ? 1000 : atoi(l);
                int b = r[0] == 'n' ? 1000 : atoi(r);
                int range = -1; // 当前循环的复杂度-1,0,1 
                if (b-a+1 <= 0) range = -1;
                else if (b-a+1 > 100) range = 1; // O(n)
                else range = 0;

                // if (err) continue;
                S[++top] = (Node){var[0], range};
            } else {
                if (err) continue;

                int sum = 0; // 当前栈中的复杂度 
                for(int i = 1; i <= top; i ++)
                {
                    if (S[i].p < 0) break;
                    sum += S[i].p;
                }
                max_p = max(max_p, sum);

                if (top == 0) err = 1;
                else top --; // 弹栈 
            }
        }
        if (top != 0) err = 1;

        if (err) cout << "ERR" << endl;
        else cout << (max_p == ans_p ? "Yes" : "No") << endl;
    }

    return 0;
}
