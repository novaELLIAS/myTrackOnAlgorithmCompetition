#pragma G++ optimize ("Ofast", 3)

#include <cstdio>
#include <string.h>

static char buf[1<<14],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}
inline const int& max (const int& a, const int& b) {return a>b? a:b;}

#define Re register
#define maxn 16

int dat[maxn], n, ans;
int can[1<<maxn], dp[1<<maxn];

inline void DP_init (int now, int sum)
{
	if (!now || (sum&1)) return;
	memset (dp, 0, sizeof dp);
	register int j;
	dp[0] = true;
	for (Re int i = 1; i <= n; ++ i)
	{
		if (now & (1<<i))
		{
			for (j = (sum>>1); j >= dat[i]; -- j)
			{
				dp[j] = dp[j] | dp[j-dat[i]];
			}
		}
	}
	if (dp[sum>>1]) can[now] = true;
}

static void generator (int ste, int now, int sum)
{
	if (ste ^ n)
	{
		generator (ste + 1, now, sum);
		generator (ste + 1, now + (1<<ste), sum + dat[ste]);
	} else {DP_init (now, sum); return;}
}

static void nico_dfs (int ste, int nl, int sl, int ns, int ss)
{
	if (ste ^ n)
	{
		nico_dfs (ste + 1, nl, sl, ns, ss);
		nico_dfs (ste + 1, nl + (1<<ste), sl + dat[ste], ns, ss);
		nico_dfs (ste + 1, nl, sl, ns + (1<<ste), ss + dat[ste]);
	} else {
		if (can[nl] && can[ns]) ans = max (ans, (sl * ss) >> 2);
		return;
	}
}

int main ()
{
	freopen ("concert.in", "r", stdin);
	freopen ("concert.out","w",stdout);
	
	n = read ();
	for (Re int i = 0; i ^ n; ++ i) dat[i] = read ();
	generator (0, 0, 0);
	nico_dfs (0, 0, 0, 0, 0);
	
	if (ans) printf ("%d", ans);
	else puts ("No Solution");
	
	fclose (stdin), fclose (stdout);
	return 0;
}
