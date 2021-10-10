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
static char buf[ELAS],but[ELAS],*p1=buf,*p2=buf,*p3=but,*p4=but+ELAS;
static int bit[20];
#define gc() ((p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++)
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
inline void write (long long x) {
	if (!x) {pt('0'); return;}
	register int pos=0;
	if (x < 0) x = -x, pt ('-');
	for (; x; x/=10) bit[++ pos] = x%10;
	for (register int i=pos; i; --i) pt(bit[i]^'0');
}
#define writelen(x) {if (x<=0){pt('0'),pt('\n');} else {write (x); pt ('\n');}}

#define maxn 100001
#define dmax 400001
#define swap(x,y) ((y)^=(x)^=(y)^=(x)) 

struct node {
	int l, r;
	long long sum, lmax, rmax, dat;
} tr[dmax], null;

inline const long long& max (const long long& x,const long long& y) {return x>y? x:y;}

inline void update (int rt) {
	register int lson = rt<<1, rson = rt<<1|1;
	tr[rt].sum = tr[lson].sum + tr[rson].sum,
	tr[rt].lmax= max (tr[lson].lmax, tr[lson].sum + tr[rson].lmax),
	tr[rt].rmax= max (tr[rson].rmax, tr[rson].sum + tr[lson].rmax),
	tr[rt].dat = max (max(tr[lson].dat, tr[rson].dat), tr[lson].rmax + tr[rson].lmax);
}

static void build (int rt, int l, int r) {
	tr[rt].l = l, tr[rt].r = r;
	if (!(l ^ r)) {tr[rt].dat = tr[rt].sum = tr[rt].lmax = tr[rt].rmax = read (); return;}
	register int mid = (l + r) >> 1;
	build (rt<<1, l, mid), build (rt<<1|1, mid + 1, r);
	update (rt);
}

static node query (int rt, int ql, int qr) {
	register int l = tr[rt].l, r = tr[rt].r;
	if (ql >  qr) return null;
	if (ql <= l && qr >= r) return tr[rt];
	register int mid = (l + r) >> 1;
	if (ql >  mid) return query (rt<<1|1,ql,qr);
	if (qr <= mid) return query (rt<<1, ql, qr);
	else {
		register node ret, a =query (rt<<1, ql, qr), b =query (rt<<1|1, ql, qr);
		ret.sum = a.sum + b.sum,
		ret.dat = max (a.dat, a.rmax + b.lmax), ret.dat = max (ret.dat, b.dat),
		ret.lmax= max (a.lmax, a.sum + b.lmax), ret.rmax= max (b.rmax, b.sum + a.rmax);
		return ret;
	}
}

static void modify (int rt, int to, long long val) {
	if (!(tr[rt].l ^ tr[rt].r)) {tr[rt].sum=tr[rt].lmax=tr[rt].rmax=tr[rt].dat=val; return;}
	register int mid = (tr[rt].l + tr[rt].r) >> 1;
	if (to <= mid) modify (rt<<1, to, val);
	else modify (rt<<1|1, to, val);
	update(rt);
}

int main()
{
	register int x1, y1, x2, y2, n = read (), m = read (); if (!m) return 0;
	register node a, b, c; register long long tmp; register char opt;
	
	build (1, 1, n);
	
	while (m --) {
		opt = 'z';
		while ((opt ^ 'C') && (opt ^ 'Q')) opt = gc();
		if (opt ^ 'C') {
			x1 = read (), y1 = read (), x2 = read (), y2 = read ();
			if (y1<x1) swap(x1,y1); if (y2<x2) swap(x2,y2); if (x1>x2) swap(x1,x2), swap(y1,y2);
			if (y1 < x2) {
				writelen (max(query(1,x1,y1-1).rmax, 0) + query(1,y1,x2).sum + max(query(1,x2+1,y2).lmax, 0));
			} else {
				a = query (1, x2, y1), b = query(1,x1,x2-1), c = query(1,y1+1,y2);
				writelen (max (max (max (a.dat, a.lmax + b.rmax), c.lmax + a.rmax), a.sum + max(0, b.rmax) + max(0, c.lmax)));
			}
		} else {x1 = read (), tmp = read (); modify (1, x1, tmp);}
	}
	
	return fwrite (but, 1, p3-but, stdout), 0;
}
