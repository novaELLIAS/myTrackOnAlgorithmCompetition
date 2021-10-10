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
static char buf[ELAS],but[ELAS],*_p1=buf,*_p2=buf,*_p3=but,*_p4=but+ELAS;
static int bit[20];
#define gc() ((_p1==_p2)&&(_p2=(_p1=buf)+fread(buf,1,ELAS,stdin),_p1==_p2)?EOF:*_p1++)
inline void pt(char c) {
	(_p3==_p4)?(fwrite(_p3=but, 1, ELAS, stdout), *_p3++=c):(*_p3++=c);
}
inline int read () {
	register int x=0; register char c=gc(); register bool m=false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (!(c ^ '-')) c = gc(), m = true;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
inline unsigned int readu () {
	register unsigned int x=0; register char c=gc();
	while (c < '0' || c > '9') c = gc();
	while (c >='0' && c <='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}
inline void write (int x) {
	if (!x) {putchar('0'); return;}
	register int pos=0;
	if (x < 0) x = -x, pt ('-');
	for (; x; x/=10) bit[++ pos] = x%10;
	for (register int i=pos; i; --i) pt(bit[i]^'0');
}

#define maxn 100001
#define swapp(x,y) x^=y^=x^=y

int tr[maxn][2], val[maxn], dis[maxn], fa[maxn];

inline int merge (int x, int y) {
	if (!x || !y) return x^y;
	if (val[x] > val[y] || (x>y && !(val[x]^val[y]))) swapp(x, y);
	tr[x][1] = merge (tr[x][1], y), fa[tr[x][1]] = x;
	if (dis[tr[x][0]] < dis[tr[x][1]]) swapp(tr[x][0], tr[x][1]);
	dis[x] = dis[tr[x][1]] + 1;
	return x;
}

inline int find (int x) {
	while (fa[x]) x = fa[x]; return x;
}

inline void pop (int x) {
	val[x] = -1, fa[tr[x][0]] = fa[tr[x][1]] = 0;
	merge (tr[x][0], tr[x][1]);
}

signed main ()
{
	register int n=readu()+1, m=readu(), opt, x, y;
	for (register int i = 1; i ^ n; ++ i) val[i] = read();
	dis[0] = -1;
	while (m --) {
		opt = readu(), x = readu();
		if (opt^2) {
			y = readu();
			if (val[x]==-1 || val[y]==-1 || !((x=find(x))^(y=find(y)))) continue;
			merge(x, y);
		} else {
			if (val[x] == -1) pt('-'), pt('1'), pt('\n');
			else {write(val[y=find(x)]), pt('\n'), pop(y);}
		}
	}
	return fwrite (but, 1, _p3-but, stdout), 0;
}
