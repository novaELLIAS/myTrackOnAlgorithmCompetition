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
static char buf[ELAS],but[ELAS],*_p1=buf,*_p2=buf,*_p3=but,*_p4=but+ELAS;
static int bit[20];
#define gc() ((_p1==_p2)&&(_p2=(_p1=buf)+fread(buf,1,ELAS,stdin),_p1==_p2)?EOF:*_p1++)
inline void pt(char c) {
	(_p3==_p4)?(fwrite(_p3=but, 1, ELAS, stdout), *_p3++=c):(*_p3++=c);
}
long long __fastcall read () {
	register long long x=0ll; register char c=gc(); register bool m=false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (!(c ^ '-')) c = gc(), m = true;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
long long __fastcall readu () {
	register long long x=0ll; register char c=gc();
	while (c < '0' || c > '9') c = gc();
	while (c >='0' && c <='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}
long double __fastcall readdou () {
	register long double x=0.0; register char c=gc(); register bool m=false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (!(c ^ '-')) c = gc(), m = true;
	while (c>='0'&&c<='9') x = x * 10.0 + (c ^ '0'), c = gc();
	if (!(c ^ '.')) {
		register long double s=0.1; c=gc();
		while (c>='0' && c<='9') x = x + (c ^ '0') * s, s/=10.0, c=gc();
	} return m? -x : x;
}
long double __fastcall readudou () {
	register long double x=0.0; register char c=gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0'&&c<='9') x = x * 10.0 + (c ^ '0'), c = gc();
	if (!(c ^ '.')) {
		register long double s=0.1; c=gc();
		while (c>='0' && c<='9') x = x + (c ^ '0') * s, s/=10.0, c=gc();
	} return x;
}
void __fastcall write (long long x) {
	if (!x) {pt('0'); return;}
	register int pos=0;
	if (x < 0) x = -x, pt ('-');
	for (; x; x/=10) bit[++ pos] = x%10;
	for (register int i=pos; i; --i) pt(bit[i]^'0');
}
long long __fastcall qpow (long long a, long long t) {
	register long long base = a, ret = 1ll;
	while (t) {
		if (t&1) ret = ret * base;
		base = base * base, t >>= 1;
	} return ret;
}
void __fastcall writedou (long double x, int res=9) {
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

signed main ()
{
	//主程序代码内容
	return fwrite (but, 1, _p3-but, stdout), 0;
}
