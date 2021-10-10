#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"
#include <vector>
#include <queue>

using namespace std;

inline int fastread ();
inline void fastwrite (int);
inline void fastwriteline (int);
inline void fastwritespace (int);

inline void dfs (int, int);

#define maxn 301
#define max(a,b) a>b? a:b
#define min(a,b) a<b? a:b

struct node
{
	int father;
	int deep;
} data[maxn];
int n, p, u, v, maxdeep, fro, ans = 0x7ffffff;
int prot[maxn];
vector <int> input[maxn];
vector <int> level[maxn];
queue <int> nico;

int main ()
{
	n = fastread ();
	p = fastread ();
	for (int i = 1; i <= p; i ++)
	{
		u = fastread ();
		v = fastread ();
		input[u].push_back (v);
		input[v].push_back (u);
	}

	nico.push (1);
	data[1].deep = 1;
	level[1].push_back (1); 
	
	while (!nico.empty ())
	{
		fro = nico.front ();
		nico.pop ();
		maxdeep = max (maxdeep, data[fro].deep);
		for (int i = 0; i < input[fro].size (); i ++)
		{
			if (input[fro][i] != data[fro].father)
			{
				data[input[fro][i]].deep = data[fro].deep + 1;
				data[input[fro][i]].father = fro;
				level[data[input[fro][i]].deep].push_back (input[fro][i]);
				nico.push (input[fro][i]); 
			}
		}
	}
	
	dfs (2, 1);
	
	fastwrite (ans);
	
	return 0;
}

inline void dfs (int lev, int sum)
{
	if (sum >= ans) return;
	if (lev > maxdeep)
	{
		ans = min (ans, sum);
		return;
	}
	int cnt = 0;
	
	for (int i = 0; i < level[lev].size (); i ++)
	{
		if (prot[data[level[lev][i]].father])
		{
			cnt ++;
			prot[level[lev][i]] = lev;
		}
	}
	if (cnt == level[lev].size ())
	{
		ans = min (ans, sum);
		return;
	}
	
	for (int i = 0; i < level[lev].size (); i ++)
	{
		if (prot[level[lev][i]]) continue;
		prot[level[lev][i]] = true;
		dfs (lev + 1, sum + level[lev].size () - cnt - 1);
		prot[level[lev][i]] = false;
	}
	
	for (int i = 1; i <= n; i ++)
	{
		prot[i] = prot[i]==lev? false:prot[i];
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
