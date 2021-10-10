#include "stdio.h"
#include "iostream"
#include <vector>
#include <queue>
#include "algorithm"

#define ll long long
#define pp pair <ll, int>
#define rint register int
#define maxn 10001
#define maxm 50001
#define inff 2147483647233ll

inline int read()
{
	register int x=0,t=1;
	register char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')
	{
		t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*t;
}

inline void write(int n)
{
	if(n<0) { putchar('-'); n = -n;}
	if(n>9) write(n/10);
	putchar((n % 10)+'0');
	return;
}

using namespace std;

int n, m, sta, end, oil;
int maxfee = -1;
vector <pair<int, int> > edge[maxn];
int fee[maxn], ord[maxn];
ll dis[maxn];
priority_queue <pp, vector <pp>, greater<pp> > q;

inline void input ()
{
	n = read ();
	m = read ();
	sta = read ();
	end = read ();
	oil = read ();

	for (rint i = 1; i <= n; i ++) fee[i] = read ();

	register int u, v, w;

	for (rint i = 1; i <= m; i ++)
	{
		u = read ();
		v = read ();
		w = read ();
		edge[u].push_back (make_pair (v, w));
		edge[v].push_back (make_pair (u, w));
	}
}

inline bool dickstra (int lim)
{
	if (fee[sta] > lim) return false;
	while (!q.empty ()) q.pop ();
	for (rint i = 1; i <= n; i ++) dis[i] = inff;
	dis[sta] = 0ll;
	pp fro (0, sta);
	q.push (fro);
	register int frof, fros, size, vv, ww;
	while (!q.empty ())
	{
		fro = q.top ();
		q.pop ();
		frof = fro.first, fros = fro.second;
		if (dis[fros] < frof) continue;
		size = edge[fros].size ();
		for (rint i = 0; i < size; i ++)
		{
			vv = edge[fros][i].first;
			if (fee[vv] > lim) continue;
			ww = edge[fros][i].second;
			ll temp = ww + dis[fros];
			if (dis[vv] > temp)
			{
				dis[vv] = temp;
				pp ppp (dis[vv], vv);
				q.push (ppp);
			}
		}
	}
	if (dis[end] > oil) return false;
	return true;
}

inline bool cmp (int x,int y)
{
	return fee[x] < fee[y];
}

int main ()
{
	
	freopen ("cost.in", "r", stdin);
	freopen ("cost.out", "w", stdout);
	
	input ();
	
	register int mid;
	register int l = 1, r = n;
	for (rint i = 1; i <= n; i ++) ord[i] = i;
	sort (ord + 1, ord + n + 1, cmp);
	if (!dickstra (fee[ord[r]]))
	{
		printf ("-1");
		return 0;
	}
	while (r > 1 + l)
	{
		mid = (l + r) >> 1;
		if (dickstra (fee[ord[mid]])) r = mid;
		else l = mid;
	}
	
	write(fee[ord[r]]);
	
	return 0;
}
