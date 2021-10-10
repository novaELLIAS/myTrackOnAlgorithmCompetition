#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast", 3)

#include <cstdio>
#include <stack>

using std::stack;

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline long long read ()
{
	register long long x = 0; register char c = gc(); register bool m = false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (c == '-') m = true, c = gc ();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return m? -x:x;
}
inline const int max (const int& a, const int& b) {return a>b? a:b;}
inline const int min (const int& a, const int& b) {return a<b? a:b;}

#define maxn 100001
#define Re register

int too[maxn], tim[maxn];
int vis[maxn], visid, ans;

struct node {
	int id, val;
};

stack <node> sta;

inline void solve(Re int x)
{
	register int ret = 0, fr;
	while (!sta.empty())
	{
		fr = sta.top().id, ret += sta.top().val, sta.pop();
		if (fr == x) {ans = max (ans, ret); return;}
	}
}

static void nico_dfs (Re int x)
{
	if (vis[x] == visid)
		{solve (x); return;}
	vis[x] = visid;
	sta.push({x, tim[x]});
	nico_dfs (too[x]);
}

inline void cl () {while (!sta.empty()) sta.pop();}

signed main ()
{
	register int n = read ();
	for (Re int i = 1; i <= n; ++ i) too[i] = read (), tim[i] = read ();
	
	for (Re int i = 1; i <= n; ++ i)
		if (!vis[i]) cl(), ++ visid, nico_dfs (i);
		
	printf ("%d", ans);
	return 0;
}
