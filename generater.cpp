#include <bits/stdc++.h>
using namespace std;

#define maxn 18 
#define maxk 290 
#define maxs 4182
#define modn 998244353 

int cnt, n;
long long sta[maxs], stc[maxs];
long long dp[maxn][maxs][maxk];

static void dfs (int ste, int now, int num)
{
	if (ste>=n) sta[++cnt] = now, stc[cnt] = num;
	else {
		dfs (ste + 2, now + (1<<ste), num + 1);
		dfs (ste + 1, now, num);
	}
}

signed main ()
{
	freopen ("table.txt", "w", stdout);
	n=17; dfs (0, 0, 0);
	for (register int i=0; i<=cnt; ++i) {
		printf ("%d, ", stc[i]);
	}
}
