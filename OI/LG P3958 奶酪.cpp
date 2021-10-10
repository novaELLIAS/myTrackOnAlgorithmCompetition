#pragma GCC optimize ("Ofast")

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

#define rint register int
#define maxn 1001

inline int read () {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

int n, xx[maxn], yy[maxn], zz[maxn];
int sta, top, dr;
bool flag, visit[maxn];
double h, r;
vector <int> e[maxn];
queue <int> ground;

inline double dis (double x1, double y1, double z1, double x2, double y2, double z2)
{
	return sqrt ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
}

inline void dfs (int x)
{
	if (flag || visit[x]) return;
	visit[x] = true;
	if (zz[x] >= top)
	{
		flag = true;
		return;
	}
	for (rint i = e[x].size () - 1; i >= 0; i --) dfs (e[x][i]);
}

int main ()
{
	int _ = read ();
	while (_ --)
	{
		n = read (), h = read (), r = read ();
		top = h - r, dr = r * 2;
		
		while (!ground.empty()) ground.pop ();
		memset (visit, 0, sizeof visit);
		for (rint i = 1; i <= n; i ++) e[i].clear ();
		flag = false;
		
		for (rint i = 1; i <= n; i ++)
		{
			xx[i] = read (); yy[i] = read (); zz[i] = read ();
			if (zz[i] <= r) ground.push (i); 
		}
		
		for (rint i = 1; i <= n; i ++)
		{
			for (rint j = 1; j <= n; j ++)
			{
				if (i != j && dis (xx[i], yy[i], zz[i], xx[j], yy[j], zz[j]) <= dr)
				{
					e[i].push_back (j), e[j].push_back (i);
				}
			}
		}
		
		while (!ground.empty())
		{
			sta = ground.front(), ground.pop();
			dfs (sta);
		}
		
		if (flag) puts ("Yes");
		else puts ("No");
	}
	
	return 0;
}
