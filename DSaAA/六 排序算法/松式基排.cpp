#pragma GCC optimize ("Ofast", 3)

#include <bits/stdc++.h>

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

#define maxn 100001

using namespace std;

const int BIT=8, U=256;

#define getd(x, y) ((x>>y*BIT)&(U-1))

signed main () {
	register int n=readu(), maxa=0;
	register int data[maxn], tmpa[maxn], cnt[U]={0};
	for (register int i=0; i^n; ++ i) data[i]=read(), maxa=data[i]>maxa? data[i]:maxa;
	
	register int top = 1;
	while (maxa >>= BIT) ++ top;
	
	for (register int base=0; base^top; ++ base) {
		//write(base), pt(' '), write(maxa>>(BIT*base)), pt('\n');
		for (register int i=0; i^U; ++ i) cnt[i] = 0;
		for (register int i=0; i^n; ++ i) ++ cnt[getd(data[i], base)];
		for (register int i=1; i^U; ++ i) cnt[i] += cnt[i-1];
		for (register int i=n-1;~i; --i) tmpa[-- cnt[getd(data[i], base)]]=data[i];
		for (register int i=0; i^n; ++ i) data[i] = tmpa[i];
	}
	
	for (register int i=0; i^n; ++ i) write(data[i]), pt(' ');
	
	return fwrite (but, 1, _p3-but, stdout), 0;
}
