#pragma G++ optimize (3)

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline long long read ()
{
	register long long x = 0; register char c = gc(); register bool m = 0;
	while (c!='-'&&(c<'0'||c>'9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}

inline const long long& min (const long long& a,const long long& b) {return a<b? a:b;}
inline const long long& max (const long long& a,const long long& b) {return a>b? a:b;}

typedef long long ll;
#define Re register
#define maxn 1005
#define maxe 2000005
#define maxm 500005
#define sqr(x) ((x)*(x))

struct node {
	long long val;
	int id;
};

struct cmp {
	inline bool operator () (const node& a,const node& b) {
		return a.val > b.val;
	}
};

inline bool sortcmp (long long a, long long b) {return a<b;}

int head[maxn], nxt[maxe], too[maxe];
ll xx[maxn], yy[maxn], zz[maxn], dis[maxn], wei[maxe];
ll cmax[maxm];
bool vis[maxn];
priority_queue <node, vector<node>, cmp> que;

inline int find (register ll x, register int n)
{
	register int l = 0, r = n, mid, ret;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (x >= dis[mid]) ret = mid, l = mid + 1;
		else r = mid - 1;
	}
	while (dis[ret+1]==dis[ret] && ret <= n) ++ ret;
	return ret;
}

int main ()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out","w",stdout);
	
	register int n = read (), m = read (), ecnt = 0ll;
	register int fr, to;
	register long long maxl = -1ll, va;
	for (Re int i = 1; i <= n; ++ i) xx[i]=read(),yy[i]=read(),zz[i]=read(),dis[i]=(long long)1e20;
	for (Re int i = 1; i <= m; ++ i) cmax[i]=read(),cmax[i]=cmax[i]*cmax[i], maxl=max(maxl,cmax[i]);
	/*
	puts ("cmax[]");
	for (Re int i = 1; i <= m; ++ i) printf ("%I64d ", cmax[i]);
	puts ("");
	puts ("end");
	*/
	for (Re int i = 0; i ^  n; ++ i)
		for (Re int j = i + 1; j <= n; ++ j)
		{
			va=sqr(xx[i]-xx[j])+sqr(yy[i]-yy[j])+sqr(zz[i]-zz[j]);
			if (va <= maxl)
				nxt[++ ecnt] = head[i], head[i] = ecnt, too[ecnt] = j, wei[ecnt] = va,\
				nxt[++ ecnt] = head[j], head[j] = ecnt, too[ecnt] = i, wei[ecnt] = va;
		}
	
	dis[0] = 0; que.push ((node) {0, 0});
	while (!que.empty())
	{
		
		fr = que.top().id, que.pop();
		if (!vis[fr])
		{//puts ("check");
			vis[fr] = true;
			for (Re int i = head[fr]; i; i = nxt[i])
			{
				to = too[i], va = wei[i];
				if (!vis[to] && max(dis[fr], va) < dis[to])
				{
					//printf ("------ %I64d ", dis[to]);
					dis[to] = max (dis[fr], va);
					//printf ("%I64d\n", dis[to]);
					que.push ((node) {dis[to], to});
				}
			}
		}
	}
	
	//prefix();
	//for (Re int i = 1; i <= n; ++ i) printf ("%I64d ", dis[i]); puts ("");
	sort (dis + 1, dis + n + 1, sortcmp);
	//for (Re int i = 1; i <= n; ++ i) printf ("%I64d ", dis[i]); puts ("");
	for (Re int i = 1; i <= m; ++ i) write (find (cmax[i], n)), putchar ('\n');
	return 0;
}
/*
5 5
2 0 3
0 4 4
5 1 3
3 7 6
4 0 1
2
3
4
5
6
*/
