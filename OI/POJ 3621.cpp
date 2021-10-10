#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx","sse2")

#include "stdio.h"
#include "string.h"

#define rint register int
#define maxn 1001

inline int read() {
	int x=0ll,t=1ll;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*t;
}

struct node {
	int en;
	double v, w;
} e[maxn * 10];

int point[maxn], next[maxn * 10], x, y, cnt;
int n, m;
bool vis[maxn], flag;
double f[maxn], v, dis[maxn];

inline void add (int x, int y, double v) {
	next [++cnt] = point [x];
	point [x] = cnt;
	e [cnt].en = y;
	e [cnt].v = e[cnt].w = v;
}

inline void build (double x) {
	for (rint i = 1; i <= n; i ++) {
		for (rint j = point[i]; j; j = next[j]) {
			e[j].v = x*e[j].w - f[e[j].en];
		}
	}
}

inline void spfa (int x) {
	vis[x] = 1;
	for (rint i = point[x]; i; i = next[i]) {
		if (dis[e[i].en] > dis[x]+e[i].v) {
			if (vis[e[i].en]) {
				flag = 1;
				return;
			} else {
				dis[e[i].en] = dis[x] + e[i].v;
				spfa (e[i].en);
			}
		}
	}
	vis[x] = false;
}

inline bool check () {
	memset (dis, 127/3, sizeof dis);
	memset (vis, 0, sizeof vis);
	flag = false;
	for (rint i = 1; i <= n; i ++) {
		spfa (i);
		if (flag ) return true;
	}
	return false;
}

int main () {
	n = read (), m = read ();
	for (rint i = 1; i <= n; i ++) scanf ("%lf", &f[i]);
	for (rint i = 1; i <= m; i ++) {
		x = read (), y = read ();
		scanf ("%lf", &v);
		add (x, y, v);
	}
	double l = 0.0, r = 10000, mid;
	while (r > 0.001 + l) {
		mid = (l + r) / 2;
		build (mid);
		if (check ()) l = mid;
		else r = mid;
	}
	printf ("%.2lf", l);
	return 0;
}
