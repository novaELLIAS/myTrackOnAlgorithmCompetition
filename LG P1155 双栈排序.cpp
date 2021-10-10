#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"
#include <stack>

using namespace std;

#define maxn 1001
#define max(a,b) a>b? a:b
#define min(a,b) a<b? a:b

inline int fastread ();
inline void fastwrite (int);
inline void fastwriteline (int);
inline void fastwritespace (int);
inline bool judge (int);

const char s[4] = {'a', 'b', 'c', 'd'};
stack <int> s1, s2;
int data[maxn], n, pos = 1, now = 1;
int ans[maxn<<1], top;
int maxx[maxn];
bool flag = true;

int main ()
{
	n = fastread ();
	for (int i = 1; i <= n; i ++) data[i] = fastread ();
	for (int i = n; i >= 1; i --) maxx[i] = max (maxx[i+1], data[i]);
	
	while (pos <= n)
	{
		switch (1)
		{
			case 1:
				// puts ("case 1");
				if ((s1.empty () || s1.top () > data[pos]) && judge (pos))
				{
					s1.push (data[pos ++]);
					ans[++ top] = 0;
					break;
				}
			case 2:
				// puts ("case 2");
				
				if (!s1.empty () && s1.top () == now)
				{
					ans[++ top] = 1;
					now ++;
					s1.pop ();
					break;
				}
			case 3:
				// puts ("case 3");
				if ((s2.empty () || s2.top () > data[pos]))
				{
					s2.push (data[pos]);
					ans[++ top] = 2;
					pos ++;
					break;
				}
			case 4:
				// puts ("case 4");
				if (!s2.empty() && s2.top() == now)
				{
					ans[++ top] = 3;
					now ++;
					s2.pop ();
					break;
				}
				flag = false;
		}
		if (!flag) break;
	}
	
	while ((!s1.empty () || !s2.empty ()) && flag)
	{
		if (!s1.empty () && s1.top () == now)
		{
			ans[++ top] = 1;
			now ++;
			s1.pop ();
		}
		if (!s2.empty () && s2.top () == now)
		{
			ans[++ top] = 3;
			now ++;
			s2.pop ();
		}
	}

	if (!flag) putchar ('0');
	else {
		for (int i = 1; i <= top; i ++)
		{
			putchar (s[ans[i]]);
			putchar (' ');
		}
	}
	
	return 0;
}

inline bool judge (int x)
{
	if (s2.empty ()) return true;
	int tem;
	for (tem = x+1; tem <= n && (data[tem] < data[x] || data[tem] < s2.top ()); tem ++);
	for (int i = tem+1; i <= n; i ++) if (data[i] < data[x]) return false;
	return true;
}
inline int fastread ()
{
    int sign = 1, n = 0;
    char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-') sign = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        n = n*10 + c-'0';
        c = getchar();
    }
    return sign*n;
}
inline void fastwrite (int x)
{
    if(x < 0) x = -x, putchar('-');
    if(x > 9) fastwrite(x / 10);
    putchar(x%10 + '0');
}
inline void fastwritespace (int x)
{
    fastwrite(x);
    putchar(' ');
}
inline void fastwriteline (int x)
{
    fastwrite(x);
    putchar('\n');
}
