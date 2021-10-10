#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define maxl 256

inline int fastread ();
inline void fastwrite (int);
inline void fastwriteline (int);
inline void fastwritespace (int);

inline int poww (int, int);
inline int workori (int, int, int);
inline int workcmp (int, int, int);
inline bool enable (int, int);
inline void get_ansori ();
inline bool cmp_anscmp ();

int n;
const int modn = 1000000007;
char in[4][2] = {{'2', '3'}, {'1', '3'}, {'1', '7'}, {'1', '1'}};
int cnt[4], ansori[4];
char ori[4][maxl], cmp[4][maxl];
bool ans[26];

int main () {
    
    for (int i = 0; i <= 3; i ++)
    {
        for (int j = 0; j <= 1; j ++)
        {
            printf ("%c ", in[i][j]);
        }
        putchar ('\n');
    }
    
    char c = getchar ();
    while (c != '\n' && c != '\r') {
        if (c != ' ') {
            if (c != 'a')
            {
                // ori1[cnt1 ++] = c;
                for (int k = 0; k <= 3; k ++) ori[k][cnt[k] ++] = c;
            }
            else {
                for (int k = 0; k <= 3; k ++)
                {
                    for (int ss = 0; ss <= 1; ss ++)
                    {
                        ori[k][cnt[k] ++] = in[k][ss];
                    }
                }
            }
        }
        c = getchar ();
    }
    /*
    for (int i = 0; i <= 3; i ++)
    {
        for (int j = 0; j < cnt[i]; j ++)
        {
            printf ("%c ", ori[i][j]);
        }
        putchar ('\n');
    }
    */
    get_ansori ();
    
    for (int i = 0; i <= 3; i ++) printf ("%d ", ansori[i]);
    putchar ('\n');
    // ansori = workori (0, cnt - 1);
    
    // printf ("\n %d\n", ansori);

    scanf ("%d", &n);

    for (int j = 0; j < n; j ++)
    {
        memset (cnt, 0, sizeof cnt);
        c = getchar ();
        while (c == '\n' || c == '\r') c = getchar ();
        while (c != '\n' && c != '\r')
        {
            if (c != ' ')
            {
                if (c != 'a')
                {
                    for (int k = 0; k <= 3; k ++) cmp[k][cnt[k] ++] = c;
                } else
                for (int k = 0; k <= 3; k ++)
                {
                    for (int ss = 0; ss <= 1; ss ++)
                    {
                        cmp[k][cnt[k] ++] = in[k][ss];
                    }
                }
            }
            c = getchar ();
        }
        // puts ("nicojudge before enable judge");
        // if (!enable (cnt)) continue;
        /*
        for (int i = 0; i <= 3; i ++)
        {
            for (int j = 0; j < cnt[i]; j ++)
            {
                printf ("%c ", cmp[i][j]);
            }
            putchar ('\n');
        }
        */
        // puts ("nicojudge before work");
        
        //cmp_anscmp ();
        
        if (cmp_anscmp ()) ans[j] = true;
        
        // judge =workcmp (0, cnt -1);
        // printf ("\n %d \n", judge);
        // if (judge == ansori) ans[j] = true;
        // puts ("nicojudge after work");
    }
    
    for (int i = 0; i < n; i ++)
    {
        if (ans[i]) printf ("%c", i+'A');
    }

    return 0;
}
/*
inline void get_ansori ()
{
    for (int i = 0; i <= 3; i ++)
    {
        ansori[i] = workori (0, cnt[i]-1, i);
        
        puts ("inline judge");
        printf (" %d ", ansori[i]);
        
    }
}
*/
inline bool cmp_anscmp ()
{
    for (int i = 0; i <= 3; i ++)
    {
        if (!enable (cnt[i], i)) return false;
        if (workcmp(0, cnt[i]-1, i) != ansori[i]) return false;
    }
    return true;
}
inline int poww (int a, int b) {
    // puts ("poww judge");
    int r = 1, base = a;
    while (b) {
        if(b & 1) r *= base;
        r %= modn;
        base *= base;
        b >>= 1;
    }
    return r;
}
/*
inline int workori (int l, int r, int sign)
{
    int ret = 0;
    int a = -1, b = -1, c = -1;
    for (int i = l; i <= r; i ++)
    {
        if (ori[sign][i] < '0' || ori[sign][i] > '9') break;
        ret = ret * 10 + ori[sign][i] - '0';
        if (i == r) return ret;
    }
    ret = 0;
    for (int i = l; i <= r; i ++)
    {
        if (ori[sign][i] == '(') ret ++;
        if (ori[sign][i] == ')') ret --;
        if (!ret)
        {
            if (ori[sign][i] == '+' || ori[sign][i] == '-') a = i;
            if (ori[sign][i] == '*') b = i;
            if (ori[sign][i] == '^') c = i;
        }
    }
    
    if (a != -1)
    {
        if (ori[sign][a] == '+') return (workori (l, a-1, sign) + workori (a+1, r, sign)) % modn;
        else return (workori (l, a-1, sign) - workori (a+1, r, sign)) % modn;
    }
    if (b != -1) return (workori (l, b-1, sign) * workori (b+1, r, sign)) % modn;
    if (c != -1) return (poww (workori (l, c-1, sign), workori (c+1, r, sign))) % modn;
    return workori (l+1, r-1, sign);
}
*/
inline int work (char *str, int l, int r, int a)
{
	prio = 0, 
}
ll calc(char *str,int l,int r,ll a)
{
    int prio=0,mnpos=MX,mn=+oo,cnt=0,p[MX],num=0;
    memset(p,0x3f,sizeof(p));
    for(int i=r;i>=l;i--)
    {
        if(str[i]==')')prio+=100;
        if(str[i]=='(')prio-=100;
        if(str[i]=='^')p[i]=prio+3,cnt++;
        if(str[i]=='*')p[i]=prio+2,cnt++;
        if(str[i]=='+')p[i]=prio+1,cnt++;
        if(str[i]=='-')p[i]=prio+1,cnt++;
        if(mn>p[i])mn=p[i],mnpos=i;
    }
    if(cnt==0)
    {
        for(int i=l;i<=r;i++)if(str[i]=='a')return a;
        for(int i=l;i<=r;i++)if(isdigit(str[i]))num=num*10+str[i]-'0';
        return num;
    }
    else
    {
        if(str[mnpos]=='^')return qpw(calc(str,l,mnpos-1,a),calc(str,mnpos+1,r,a));
        if(str[mnpos]=='*')return (calc(str,l,mnpos-1,a)*calc(str,mnpos+1,r,a))%MD;
        if(str[mnpos]=='+')return (calc(str,l,mnpos-1,a)+calc(str,mnpos+1,r,a))%MD;
        if(str[mnpos]=='-')return (calc(str,l,mnpos-1,a)-calc(str,mnpos+1,r,a))%MD;
    }
    return 0;
}
inline bool enable (int x, int sign)
{
    int ret = 0;
    for (int i = 0; i < x; i ++)
    {
        ret += cmp[sign][i]=='('? 1:(cmp[sign][i]==')'? -1:0);
        if (ret < 0) return false;
    }
    return !ret;
}
/*
inline int workcmp (int l, int r, int sign)
{
    int ret = 0, a = -1, b = -1, c = -1;
    for (int i = l; i <= r; i ++)
    {
        if (cmp[sign][i] < '0' || cmp[sign][i] > '9') break;
        ret = ret * 10 + cmp[sign][i] - '0';
        if (i == r) return puts ("retjudge"),ret;
    }
    ret = 0;
    for (int i = l; i <= r; i ++)
    {
        if (cmp[sign][i] == '(') ret ++;
        if (cmp[sign][i] == ')') ret --;
        if (!ret)
        {
            if (cmp[sign][i] == '+' || cmp[sign][i] == '-') a = i;
            if (cmp[sign][i] == '*') b = i;
            if (cmp[sign][i] == '^') c = i;
        }
    }
    if (a != -1)
    {
        if (cmp[sign][a] == '-') return ((workcmp (l, a-1, sign) - workcmp (a+1, r, sign))) % modn;
        else return ((workcmp (l, a-1, sign) + workcmp (a+1, r, sign))) % modn;
    }
    if (b != -1) return ((workcmp (l, b-1, sign) * workcmp (b+1, r, sign))) % modn;
    if (c != -1) return ((poww (workcmp (l, c-1, sign), workcmp (c+1, r, sign)))) % modn;
    return workcmp (l+1, r-1, sign);
}
*/
inline int fastread () {
    int sign = 1, n = 0;
    char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') sign = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        n = n*10 + c-'0';
        c = getchar();
    }
    return sign*n;
}
inline void fastwrite (int x) {
    if(x < 0) x = -x, putchar('-');
    if(x > 9) fastwrite(x / 10);
    putchar(x%10 + '0');
}
inline void fastwritespace (int x) {
    fastwrite(x);
    putchar(' ');
}
inline void fastwriteline (int x) {
    fastwrite(x);
    putchar('\n');
}
