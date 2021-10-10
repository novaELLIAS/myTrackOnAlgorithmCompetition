#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"
#include "queue"
#include "vector"

using namespace std;

#define rint register int
#define maxn 501

inline int read()
{
	int x=0ll,t=1ll;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*t;
}

vector <pair <int, int> > e[maxn];
int t, n, m, M, dis[maxn];
bool visit[maxn], flag;

inline void spfa (int x)
{
	if (visit[x])
	{
		visit[x] = false;
		flag = true;
		return;
	}
	visit[x] = true;
	if (!e[x].empty ())
	{
		
		for (rint i = 0; i < e[x].size (); i ++)
		{
			if (dis[e[x][i].first] > dis[x] + e[x][i].second)
			{
				dis[e[x][i].first] = dis[x] + e[x][i].second;
				spfa (e[x][i].first);
				if (flag)
				{
					visit[x] = false;
					return;
				}
			}
		}
	}
	visit[x] = false;
}

int main ()
{
	t = read ();
	int x, y, v;
	while (t --)
	{
		n = read (), m = read (), M = read ();
		for (rint i = 1; i <= n; i ++) e[i].clear ();
		for (rint i = 1; i <= m; i ++)
		{
			x = read (), y = read (), v = read ();
			e[x].push_back (make_pair (y, v));
			e[y].push_back (make_pair (x, v));
		}
		for (rint i = 1; i <= M; i ++)
		{
			x = read (), y = read (), v = -read ();
			e[x].push_back (make_pair (y, v));
		}
		memset (dis, 0, sizeof dis);
		flag = false;
		for (rint i = 1; i <= n; i ++)
		{
			spfa (i);
			if (flag) break;
		}
		if (flag) puts ("YES");
		else puts ("NO");
	}
	return 0;
}
