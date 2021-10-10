#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "vector"

#define rint register int
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))

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

int n, rp[6001], root, dp[6001][2];
bool fa[6001];
vector <int> t [6001];

inline void solve (int bt)
{
	dp[bt][0] = 0;
	dp[bt][1] = rp[bt];
	int k;
	for (rint i = 0; i < t[bt].size(); i ++)
	{
		k = t[bt][i];
		solve (k);
		dp[bt][0] += max (dp[k][0], dp[k][1]);
		dp[bt][1] += dp[k][0];
	}
}

int main ()
{
	n = read ();
	for (rint i = 1; i <= n; i ++) rp[i] = read ();
	int u, v;
	for (rint i = 1; i < n; i ++)
	{
		u = read (), v = read ();
		t[v].push_back (u);
		fa[u] = true;
	}
	for (rint i = 1; i <= n; i ++)
	{
		if (!fa[i])
		{
			root = i;
			break;
		}
	}
	solve (root);
	printf ("%d", max (dp[root][1], dp[root][0]));
	return 0;
}
