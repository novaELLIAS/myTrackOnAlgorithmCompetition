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

#define maxn 10
#define maxk 82
#define maxs 513

int cnt, n;
int sta[maxs], stc[maxs];
long long dp[maxn][maxs][maxk];

static void dfs (int ste, int now, int num)
{
	if (ste>=n) sta[++cnt] = now, stc[cnt] = num;
	else {
		dfs (ste + 2, now + (1<<ste), num + 1);
		dfs (ste + 1, now, num);
	}
}

inline bool check (int x, int y) {
	return !(x&y||(x<<1)&y||(x>>1)&y);
}

signed main ()
{
	n=read(); register int K=read();
	if (K > (n*n)>>1) return putchar('0'), 0;
	dfs (0, 0, 0);
	for (register int i=1; i<=cnt; ++i) dp[1][i][stc[i]] = 1;
	for (register int i=2; i<=n; ++i) {
		for (register int j=1; j<=cnt; ++j) {
			for (register int k=1; k<=cnt; ++k) {
				if (check (sta[j], sta[k])) {
					for (register int m=stc[j]; m<=K; ++m) {
						dp[i][j][m] += dp[i-1][k][m-stc[j]];
					}
				}
			}
		}
	}
	register long long ans = 0ll;
	for (register int i=1; i<=cnt; ++i) ans += dp[n][i][K];
	return printf ("%lld", ans), 0;
}
