#pragma GCC optimize ("Ofast")

#include "iostream"
#include "stdio.h"
#include "vector"

#define rint register int

using namespace std;

inline int read()
{
    int x=0ll,t=1ll;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}

bool check[10001];
int n, fa[10001], ans, mxdp;
vector <int> mp[10001], fl[10001];

inline void dfs (int u, int de)
{
	mxdp = max (mxdp, de);
	fl[de].push_back (u);
	int v;
	for (rint i = 0; i < mp[u].size (); i ++)
	{
		v = mp[u][i];
		if (v == fa[u]) continue;
		fa[v] = u;
		dfs (v, de + 1);
	}
}

inline void work (int u)
{
	check[u] = true;
	for (rint i = 0; i < mp[u].size (); i ++) check[mp[u][i]] = true;
}

int main ()
{
	n = read ();
	int u, v;
	for (rint i = 1; i < n; i ++)
	{
		u = read (), v = read ();
		mp[u].push_back (v);
		mp[v].push_back (u);
	}
	
	dfs (1, 0);
	
	for (rint i = mxdp; i >= 0; i --)
	{
		for (rint j = 0; j < fl[i].size (); j ++)
		{
			u = fl[i][j], v = fa[u];
			if (check[u]) continue;
			ans ++;
			work (v);
		}
	}
	printf ("%d", ans);
}
