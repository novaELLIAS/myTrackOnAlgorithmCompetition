#pragma GCC optimzie ("Ofast", 3)

#include <bits/stdc++.h>

using namespace std;

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

void __fastcall write (long long x) {
	if (!x) {pt('0'); return;}
	register int pos=0;
	if (x < 0) x = -x, pt ('-');
	for (; x; x/=10) bit[++ pos] = x%10;
	for (register int i=pos; i; --i) pt(bit[i]^'0');
}

#define MAXN 10001

int cnt[MAXN];

signed main () {
	register int n = read(), a;
	for (register int i=0; i^n; ++ i) {
		a = read();
		if (a<0 && a>=n) return printf("-1\n"), 0;
		cnt[a] ++;
	} register bool flag = true;
	for (register int i=0; i^n; ++ i) {
		if (cnt[i] >= 2) {printf("%d,%d\n", i, cnt[i]), flag = false;}
	} if (flag) printf("-1\n");
	return 0;
}
