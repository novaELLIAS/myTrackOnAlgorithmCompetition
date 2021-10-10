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

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc() {
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline long long read () {
	register long long x = 0; register char c = gc(); register bool m = 0;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (!(c ^ '-')) c = gc(), m = true;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (long long x) {
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (long long x) {
	if (x < 0ll) {putchar('0'), putchar('\n'); return;}
	write (x), putchar ('\n');
}

#define maxn 300001
typedef long long ll;

long long t[maxn], c[maxn], dp[maxn], que[maxn];

signed main ()
{
	register int n=read(), s=read(), N=n+1;
	for (register int i=1; i^N; ++i) t[i] = read() + t[i-1], c[i] = read () + c[i-1];
	
	register int fro=0, enf=0, l, r, mid, pos;
	for (register int i=1; i^N; ++i) {
		l=fro, r=pos=enf;
		while (l<=r) {
			mid = (l+r)>>1;
			if (dp[que[mid+1]]-dp[que[mid]] <= (s+t[i])*(c[que[mid+1]]-c[que[mid]])) l=mid+1;
			else r = mid-1, pos=mid;
		}
		dp[i] = dp[que[pos]] + t[i]*c[i] + s*c[n] - c[que[pos]]*(s+t[i]);
		while (fro<enf && (dp[i]-dp[que[enf]])*(c[que[enf]]-c[que[enf-1]]) <= (dp[que[enf]]-dp[que[enf-1]])*(c[i]-c[que[enf]])) -- enf;
		que[++ enf] = i;
	} return printf ("%lld", dp[n]), 0;
}
