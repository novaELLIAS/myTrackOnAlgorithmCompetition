#pragma G++ optimize (3)

#include <cstdio>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); //register bool m = false;
	while ((c < '0' || c > '9')/* && (c ^ '-')*/) c = gc();
	//if (c == '-') m = true, c = gc ();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return /*m? -x:*/x;
}

inline const int max (const int& a, const int& b) {return a>b? a:b;}
inline const int min (const int& a, const int& b) {return a<b? a:b;}

#define Re register

int dp[1001][101];
int su[1001];

signed main ()
{
	register int n = read (), m = read (), nm;
	for (Re int i = 1; i <= n; ++ i) su[i] = read()^su[i-1], dp[i][1] = su[i];
	for (Re int i = 1; i <= n; ++ i)
	{
		nm = min (m, i);
		for (Re int j = 2; j <= nm; ++ j)
			for (Re int k = i; k >= j; -- k)
				dp[i][j] = max (dp[i][j], dp[k-1][j-1] + (su[i]^su[k-1]));
	}
	
	printf ("%d", dp[n][m]);
	
	return 0;
}
