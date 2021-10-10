#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "algorithm"

#define maxn 1001
#define maxm 20001

#define rint register int

using namespace std;

inline int read()
{
    int x=0,t=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}

int n, m, fa[maxn], u, v, tot, ans;

struct node {
	int x, y, v;
} e[maxm];

inline int get (int x) { return fa[x]==x? x:fa[x]=get (fa[x]);}

inline bool cmp (node aa, node bb) {return aa.v > bb.v;}

int main ()
{
	n = read (), m = read ();
	for (rint i = 1; i <= m; i ++) e[i].x = read (), e[i].y = read (), e[i].v = read ();
	for (rint i = 1; i <= n; i ++) fa[i] = i;
	sort (e + 1, e + m + 1, cmp);
	
	for (rint i = 1; i <= m; i ++)
	{
		u = get (e[i].x), v = get (e[i].y);
		if (u != v)
		{
			fa[u] = v;
			tot ++;
			ans += e[i].v;
			if (tot == n - 1)
			{
				printf ("%d", ans);
				return 0;
			}
		}
	}
	
	putchar ('-');putchar ('1');
	
	return 0;
}
