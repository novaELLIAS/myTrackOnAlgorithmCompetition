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

using namespace std;

const int ELAS = 1<<14;
static char buf[ELAS],but[ELAS],*p1=buf,*p2=buf,*p3=but,*p4=but+ELAS;
static int bit[20];
inline char gc() {
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline void pt(char c) {
	(p3==p4)?(fwrite(p3=but, 1, ELAS, stdout), *p3++=c):(*p3++=c);
}
inline long long read () {
	register long long x=0; register char c=gc(); register bool m=false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (!(c ^ '-')) c = gc(), m = true;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
inline long double readdou () {
	register long double x=0.0; register char c=gc(); register bool m=false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (!(c ^ '-')) c = gc(), m = true;
	while (c>='0'&&c<='9') x = x * 10.0 + (c ^ '0'), c = gc();
	if (!(c ^ '.')) {
		register long double s=0.1; c=gc();
		while (c>='0' && c<='9') x = x + (c ^ '0') * s, s/=10.0, c=gc();
	} return m? -x : x;
}
inline void write (long long x) {
	if (!x) {pt('0'); return;}
	register int pos=0;
	if (x < 0) x = -x, pt ('-');
	for (; x; x/=10) bit[++ pos] = x%10;
	for (register int i=pos; i; --i) pt(bit[i]^'0');
}

signed main ()
{
	register int n=read(), k;
	while (n --) {
		write (read () + 1); pt (' ');
	} fwrite (but, 1, p3-but, stdout); return 0;
}
