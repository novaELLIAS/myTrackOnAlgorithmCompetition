#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "queue"
#include "vector"
#include "string.h"

#define rint register int

using namespace std;

int n, m, a[1001], totha, ans;
vector <pair <int, int> > e[1001];

inline int read()
{
    int x=0,t=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}

inline void input ()
{
	n = read (), m = read ();
	for (rint i = 1; i <= n; i ++) a[i] = read (), totha += a[i];
	for (rint i = 1; i <= m; i ++)
	{
		e[read ()].push_back (make_pair (read (), read ()));
	}
}

queue <int> nico;
bool vis[1001];
double dis[1001];
int cnt[1001];

inline bool spfa (double s)
{
	while (!nico.empty ()) nico.pop ();
	memset (cnt, 0, sizeof cnt);
	memset (vis, 0, sizeof vis);
	memset (dis, 127/3, sizeof dis);
	
	nico.push (1);
    dis[1] = 0;
    vis[1] = true;
    int fro, to, size, va;
    double k;
    while (!nico.empty ())
    {
    	fro = nico.front ();
    	nico.pop ();
    	size = e[fro].size ();
    	for (rint i = 0; i < size; i ++)
    	{
    		to = e[fro][i].first, va = e[fro][i].second;
    		k = s*va - a[fro];
    		if (dis[to] > dis[fro] + k)
    		{
    			dis[to] = dis[fro] + k;
    			if (!vis[to])
    			{
    				vis[to] = true;
    				cnt [to] = cnt[fro] + 1;
    				nico.push (to);
				}
				if (cnt[to] >= n) return true;
			}
		}
		vis[fro] = false;
	}
	return false;
}
/*
bool spfa(double k)
{
	for (int i=1; i<=maxn; i++)
	{
		dis[i]=inf;
		cnt[i]=0;
		vis[i]=0;
	}
	while (!q.empty()) q.pop();
	q.push(1);
	vis[1]=1;
	dis[1]=0;
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		for (int i=ls[x]; i>0; i=g[i].next)
		{
			int y=g[i].y;
			double w=k*g[i].w-a[x];
			if (dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				cnt[y]=cnt[x]+1;
				if (!vis[y])
				{
					vis[y]=1;
					q.push(y);
				}
				if (cnt[y]>=n) return true;
			}
		}
		vis[x]=0;
	}
	return false;
}
*/
int main ()
{
	input ();
	
	rint l = 1, r = 0x3f3f3f3f, mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (spfa ((double) mid / 10000)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	
	printf ("%.2lf", (double) ans / 10000);
	
	return 0;
}
