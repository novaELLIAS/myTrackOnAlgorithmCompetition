#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"
//#include "string.h"
#include "stdlib.h"

#define maxn 27

inline int fastread ();
inline void fastwrite (int);
inline void fastwriteline (int);
inline void fastwritespace (int);

inline void getnext (int x);
inline void input ();
inline bool judge ();
inline bool cut ();
inline void dfs (int);

int n, cnt;
int ans[maxn] = {-1}, next[maxn];
int a[maxn], b[maxn], c[maxn];
bool visit [maxn];

int main ()
{	
	input ();
	
	for (int i = 0; i <= n; i ++) ans[i] = -1;
	/*
	for (int i = 0; i < n; i ++) fastwritespace (ans[i]);
	putchar ('\n');
	for (int i = 0; i < n; i ++) fastwritespace (a[i]);
	putchar ('\n');
	for (int i = 0; i < n; i ++) fastwritespace (b[i]);
	putchar ('\n');
	for (int i = 0; i < n; i ++) fastwritespace (c[i]);
	putchar ('\n');
	*/
	for (int i = n-1; i >= 0; i --)
	{
		getnext (a[i]);
		getnext (b[i]);
		getnext (c[i]);
	}
	
	for (int i = 0; i < n; i ++) visit[i] = false;
	dfs (0);
	
	return 0;
}

inline void getnext (int x)
{
	if (!visit[x])
	{
		visit[x] = true;
		next[cnt++] = x;
	}
}
inline bool cut ()
{
	if (ans[a[0]] + ans[b[0]] >= n) return true;
	for (int i = n-1; i >= 0; i --)
	{
		if (ans[a[i]] == -1 || ans[b[i]] == -1 || ans[c[i]] == -1) continue;
		if ((ans[a[i]] + ans[b[i]]) % n != ans[c[i]] && (ans[a[i]] + ans[b[i]] + 1) % n != ans[c[i]]) return true;
	}
	return false;
}
inline bool judge ()
{
	for (int i = n-1,x = 0; i >= 0; i --)
	{
		if ((ans[a[i]] + ans[b[i]] + x) % n != ans[c[i]]) return false;
		x = (ans[a[i]] + ans[b[i]] + x) / n;
	}
	return true;
}
inline void dfs (int x)
{
	if (cut ()) return;
	//puts ("lajidaoshiheheheheheeh");
	
	if (x == n)
	{
		//puts ("lajidaoshi     23333");
		if (judge ())
		{
			//puts ("lajidaoshi");
			for (int i = 0; i < n; i ++) fastwritespace (ans[i]);
			exit (0);
		}
		return;
	}
	
	for (int i = n-1; i >= 0; i --)
	{
		if (!visit[i])
		{
			ans[next[x]] = i;
			visit[i] = true;
			//puts ("nicodfs");
			dfs (x + 1);
			ans[next[x]] = -1;
			visit[i] = false;
		}
	}
}
inline void input ()
{
	n = fastread ();
	getchar ();
	for (int i = 0; i < n; i ++)
	{
		a[i] = getchar () - 'A';
	}
	getchar (); getchar ();
	for (int i = 0; i < n; i ++)
	{
		b[i] = getchar () - 'A';
	}
	getchar (); getchar ();
	for (int i = 0; i < n; i ++)
	{
		c[i] = getchar () - 'A';
	}
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
