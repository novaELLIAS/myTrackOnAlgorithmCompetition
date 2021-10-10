#pragma GCC optimize ("Ofast", 3)

#include <cstdio>
#include <iostream>

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
template <typename T>
inline void write (T x) {
	if (!x) {pt('0'); return;}
	register int pos=0;
	if (x < 0) x = -x, pt ('-');
	for (; x; x/=10) bit[++ pos] = x%10;
	for (register int i=pos; i; --i) pt(bit[i]^'0');
}

#define swapp(x, y) ((x)^=(y)^=(x)^=(y))

#define maxn 10001

int data[maxn];

using namespace std;

inline void qsort (register int L, register int R)
{
	register int l=L, r=R, mid=data[(L+R)>>1];
	while (l < r) {
		while (data[l] < mid) ++ l;
		while (data[r] > mid) -- r;
		if (l <= r) swap(data[l ++], data[r --]);
	}
	if (l < R) qsort (l, R);
	if (r > L) qsort (L, r);
}

signed main ()
{
	register int n=readu();
	for (register int i=0; i^n; ++ i) data[i]=read();
	
	qsort (0, n-1);
	
	for (register int i=0; i^n; ++ i) write(data[i]), pt(' ');
	
	return fwrite (but, 1, _p3-but, stdout), 0;
}
