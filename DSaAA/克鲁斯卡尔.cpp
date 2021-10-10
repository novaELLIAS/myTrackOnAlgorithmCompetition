#pragma GCC optimize ("Ofast", 3)

#include <cstdio>
#include <algorithm>

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
inline long double dou () {
	register long double x=0.0; register char c=gc(); register bool m=false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (!(c ^ '-')) c = gc(), m = true;
	while (c>='0'&&c<='9') x = x * 10.0 + (c ^ '0'), c = gc();
	if (!(c ^ '.')) {
		register long double s=0.1; c=gc();
		while (c>='0' && c<='9') x = x + (c ^ '0') * s, s/=10.0, c=gc();
	} return m? -x : x;
}
inline long double udou () {
	register long double x=0.0; register char c=gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0'&&c<='9') x = x * 10.0 + (c ^ '0'), c = gc();
	if (!(c ^ '.')) {
		register long double s=0.1; c=gc();
		while (c>='0' && c<='9') x = x + (c ^ '0') * s, s/=10.0, c=gc();
	} return x;
}
inline void write (long long x) {
	if (!x) {pt('0'); return;}
	register int pos=0;
	if (x < 0) x = -x, pt ('-');
	for (; x; x/=10) bit[++ pos] = x%10;
	for (register int i=pos; i; --i) pt(bit[i]^'0');
}
inline long long qpow (long long a, long long t) {
	register long long base = a, ret = 1ll;
	while (t) {
		if (t&1) ret = ret * base;
		base = base * base, t >>= 1;
	} return ret;
}
inline void writedou (long double x, int res=9) {
	if (x == 0.0) {
		pt('0'), pt('.');
		for (register int i=0; i^res; ++i) pt ('0');
		return;
	} else {
		if (x < 0.0) x=-x, pt('-');
		register long long clf=qpow(10, res);
		register long long flt=(long long)(x * clf) % clf;
		write ((long long) x); pt ('.');
		register int pos = 0;
		for (; pos^res; flt/=10) bit[++ pos] = flt%10;
		for (register int i=pos; i; --i) pt(bit[i]^'0');
	}
}

#define MAXN 5001
#define MAXM 200001

struct edge {
	int fr, to, val;
} e[MAXM];

int fa[MAXN];

inline bool cmp (edge &a, edge &b) {
	return a.val < b.val;
}

inline int getFa (int x) {
	while (x^fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

signed main () {
	register int n = read(), m = read();
	for (register int i=0; i^m; ++ i)
		e[i].fr = read(), e[i].to = read(), e[i].val = read();
	for (register int i=1; i<=n; ++ i) fa[i] = i;
	std::sort(e, e+m, cmp);
	register int cnt = 0, ans = 0, fax, fay;
	for (register int i=0; i^m; ++ i) {
		if (cnt >= n-1) break;
		if ((fax=getFa(e[i].fr)) ^ (fay=getFa(e[i].to))) {
			ans += e[i].val; ++ cnt; fa[fax] = fay;
		}
	} write(ans);
	return fwrite (but, 1, _p3-but, stdout), 0;
}
