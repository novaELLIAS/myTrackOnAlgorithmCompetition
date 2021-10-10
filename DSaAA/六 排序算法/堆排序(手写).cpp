#pragma GCC optimize ("Ofast", 3)

#include <cstdio>

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
inline void write (int x) {
	if (!x) {pt('0'); return;}
	register int pos=0;
	if (x < 0) x = -x, pt ('-');
	for (; x; x/=10) bit[++ pos] = x%10;
	for (register int i=pos; i; --i) pt(bit[i]^'0');
}

#define swapp(x, y) {if(x^y)(x)^=(y)^=(x)^=(y);}

#define maxn 100001

int data[maxn];

inline void swift(int rt, int len) {
	register int pos=rt<<1;
	while (pos<=len) {
		if(pos<len && data[pos|1]<data[pos]) pos |= 1;
		if (data[rt]<data[pos]) return;
		swapp(data[rt], data[pos]);
		rt = pos, pos=rt<<1;
	}
}

signed main () {
	register int n = read();
	for (register int i=1; i<=n; ++ i) data[i]=read();
	for (register int i=n>>1; i; -- i) swift(i, n);
	for (register int i=n; i; -- i) {
		write(data[1]); pt(' '); swapp(data[1], data[i]); swift(1, i-1);
	} return fwrite (but, 1, _p3-but, stdout), 0;
}
