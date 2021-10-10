#pragma G++ optimize ("Ofast", 3)

#include <cstdio>

using namespace std;

const int ELAS = 1<<14;
static char buf[ELAS], *p1 = buf, *p2 = buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while ((c < '0' || c > '9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x)
{
	if (x < 0) putchar('-'), x = -x;
	write (x); putchar ('\n');
}

#define Re register
#define maxn 100001
#define maxe 400001

struct edge {
	int nex, to, wei;
} e[maxn << 1];
int head[maxn], ecnt;

int n, m, mapp[2001][2001];
long long ptcnt[maxn];

inline void solve2 ()
{
	puts ("QwQ");
}

int main ()
{
	freopen ("warehouse.in", "r", stdin);
	freopen ("warehouse.out","w",stdout);
	
	n = read (), m = read ();
	if (n >= 100000) return puts ("QwQ"), 0;
	//if (n >= 2000) {solve2(); return 0;}
	register int u, v, w;
	register long long ans = 0ll;
	for (Re int i = 1; i <= n; ++ i) 
		for (Re int j = 1; j <= n; ++ j) mapp[i][j] = 233333333;
	
	for (Re int i = 1; i ^ n; ++ i)
	{
		u = read (), v = read (), w = read ();
		mapp[u][v] = mapp[v][u] = w;
	}
	
	for (Re int k = 1; k <= n; ++ k)
		for (Re int i = 1; i <= n; ++ i)
			for (Re int j = 1; j <= n; ++ j)
				if (i ^ j && mapp[i][j] > mapp[i][k] + mapp[k][j])
					mapp[i][j] = mapp[i][k] + mapp[k][j];

	/*
	for (Re int i = 1; i <= n; ++ i) {
		for (Re int j = 1; j <= n; ++ j) {
			printf ("%d ", mapp[i][j]);
		} putchar ('\n');
	}
	*/
	
	for (Re int i = 1; i <= n; ++ i)
		for (Re int j = 1; j <= n; ++ j)
			if (i ^ j) ptcnt[i] += mapp[i][j] ^ m;
			
	for (Re int i = 1; i <= n; ++ i) writelen (ptcnt[i]);
	goto EXIT;
	
	
	EXIT:
		return 0;
}
