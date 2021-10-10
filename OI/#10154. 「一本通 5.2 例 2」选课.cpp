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

#define maxn 3001

int n, m;
int head[maxn], to[maxn], wei[maxn], nxt[maxn];
int dp[maxn][maxn], siz[maxn];

static void dfs (int pos) {
	siz[pos] = 1;
	for (register int i=head[pos]; i; i=nxt[i]) {
		dfs (to[i]); siz[pos] += siz[to[i]];
		for (register int j=min(m+1, siz[pos]); j; -- j) {
			for (register int k=j-1; k; -- k) {
				dp[pos][j] = max (dp[pos][j], dp[pos][j-k] + dp[to[i]][k]);
			}
		}
	}
}

signed main ()
{
	n = read (), m = read ();
	register int tm, wm, cnt = 0;
	for (register int i=1; i<=n; ++ i) {
		tm = read (), wm = read ();
		nxt[++ cnt] = head[tm], to[cnt] = i, wei[cnt] = wm,
		head[tm] = cnt, dp[i][1] = wm;
	} dfs (0); return printf ("%d", dp[0][m+1]), 0;
}
