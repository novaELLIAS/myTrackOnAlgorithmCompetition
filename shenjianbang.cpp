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
#include <cstring>

using namespace std;

const int ELAS = 1<<14;
static char buf[ELAS],but[ELAS],*_p1=buf,*_p2=buf,*_p3=but,*_p4=but+ELAS;
static int bit[20];
#define gc() ((_p1==_p2)&&(_p2=(_p1=buf)+fread(buf,1,ELAS,stdin),_p1==_p2)?EOF:*_p1++)
inline void pt(char c) {
	(_p3==_p4)?(fwrite(_p3=but, 1, ELAS, stdout), *_p3++=c):(*_p3++=c);
}
inline long long read () {
	register long long x=0ll; register char c=gc(); register bool m=false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (!(c ^ '-')) c = gc(), m = true;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
inline long long readu () {
	register long long x=0ll; register char c=gc();
	while (c < '0' || c > '9') c = gc();
	while (c >='0' && c <='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}
inline void write (long long x) {
	if (!x) {pt('0'); return;}
	register int pos=0;
	if (x < 0) x = -x, pt ('-');
	for (; x; x/=10) bit[++ pos] = x%10;
	for (register int i=pos; i; --i) pt(bit[i]^'0');
}

#define maxn 101
#define maxa 0x3f3f3f3f3f

int head[maxn], to[201], nxt[201], cnt, all;

inline void adde (int fr, int tm) {
	nxt[++ cnt] = head[fr], to[cnt] = tm, head[fr] = cnt;
	nxt[++ cnt] = head[tm], to[cnt] = fr, head[tm] = cnt;
}

int a[maxn], w[maxn], dp[101][16384];

#define max(x, y) ((x)<(y)? (y):(x))
#define min(x, y) ((x)<(y)? (x):(y))

#define too to[i]
static void dfs (int pos, int fa)
{
	dp[pos][a[pos]? 1<<(a[pos]-1):0] = w[pos];
	for (register int i=head[pos]; i; i=nxt[i]) {
		if (too^fa) {
			dfs (too, pos);
			for (register int j=0; j<=all; ++j) {
				for (register int k=j; k; k=(k-1)&j) dp[pos][j]=min(dp[pos][j], dp[pos][j^k]+dp[too][k]);
			} for (register int j=all; j; --j) {
				if (dp[pos][j]<maxa) for (register int k=j&(j-1); k; k=(k-1)&j) {
					dp[pos][k]=min(dp[pos][j], dp[pos][k]);
				} dp[pos][0]=min(dp[pos][0], dp[pos][j]);
			}
		}
	}
}
#undef too

signed main()
{
	register int n=read()+1, i=1, f, t; all=(1<<read())-1;
	for (	; i^n; ++i) a[i]=read();
	for (i=1; i^n; ++i) w[i]=read(); n --;
	for (i=1; i^n; ++i) f=read(), t=read(), adde(f,t);
	memset (dp, 63, sizeof dp); dfs(1, 0);
	write(dp[1][all]); fwrite (but, 1, _p3-but, stdout); return 0;
}
