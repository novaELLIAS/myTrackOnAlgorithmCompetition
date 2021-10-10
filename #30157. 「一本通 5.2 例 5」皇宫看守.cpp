#pragma GCC optimize (2)
#pragma G++ optimize (2)
#pragma GCC optimize (3)
#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>
#include <iostream>

using namespace std;

const int ELAS = 1<<14;
static char buf[ELAS], *p1 = buf, *p2 = buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline long long read ()
{
	register long long x = 0; register char c = gc(); register bool m = 0;
	while (c < '0' || c > '9') {if (c == '-') m = true; c = gc();}
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (long long x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (long long x)
{
	if (x < 0ll) {putchar('0'), putchar('\n'); return;}
	write (x), putchar ('\n');
}

#define maxn 1501
#define dmax 3001

int head[dmax], to[dmax], nxt[dmax], cnt;
int dp[maxn][3];
const int ma = 0x7fffffff>>1;

inline void adde (int fr, int tm) {
	nxt[++ cnt] = head[fr], to[cnt] = tm, head[fr] = cnt;
}

static void dfs (int pos, int fa)
{
	register int tm, va = ma;
	for (register int i=head[pos]; i; i=nxt[i]) {
		tm = to[i]; if (tm ^ fa) {
			dfs (tm, pos);
			dp[pos][0] += min (dp[tm][0], min (dp[tm][1], dp[tm][2])),
			dp[pos][1] += min (dp[tm][0], dp[tm][2]),
			dp[pos][2] += min (dp[tm][0], dp[tm][2]),
			va = min (va, dp[tm][0] - min (dp[tm][0], dp[tm][2]));
		}
	} dp[pos][2] += va;
}

signed main ()
{
	register int n = read (), sta = max (n>>1, 1);
	register int na, tm, ss;
	for (register int i=1; i<=n; ++ i) {
		na = read (), dp[na][0] = read (), ss = read ();
		for (register int j=1; j<=ss; ++ j) {
			tm = read (); adde (na, tm), adde (tm, na);
		}
	} dfs (sta, 0);
	return printf ("%d", min (dp[sta][0], dp[sta][2])), 0;
}
