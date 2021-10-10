#pragma G++ optimize (3)

#include <cstdio>
#include <cstring>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
inline const int& min (const int& a,const int& b) {return a<b? a:b;}
inline const int& max (const int& a,const int& b) {return a>b? a:b;}

#define Re register
#define maxn 3000010

int tr[maxn<<2];
bool vis[maxn];

static void pushdown (int rt)
{
	if (tr[rt] ^ (-1)) {
		tr[rt<<1] = tr[rt<<1|1] = tr [rt], tr[rt] = -1;
		return;
	}
}

static void update (int rt, int sta, int end, int col, int l, int r)
{
	if (sta <= l && r <= end) {tr[rt] = col; return;}
	pushdown (rt);
	register int mid = (l + r) >> 1;
	if (sta <= mid) update (rt<<1, sta, end, col, l, mid);
	if (mid <  end) update (rt<<1|1,sta,end,col,mid+1, r);
}

static void query (int rt, int l, int r)
{
	if (l == r) {if (tr[rt] ^ (-1)) vis[tr[rt]] = true; return;}
	pushdown (rt);
	register int mid = (l + r) >> 1;
	query (rt<<1,  l,  mid);
	query (rt<<1|1,mid+1,r);
}

int main ()
{
	freopen ("paper.in", "r", stdin);
	freopen ("paper.out", "w", stdout);
	
	register int n = read (), m = read (), fr, to;
	std::memset (tr, -1, sizeof tr);
	for (Re int i = 1; i <= n; ++ i)
	{
		fr = read (), to = read ();
		update (1, fr, to, i, 1, m);
	}
	query (1, 1, m);
	register int ans = 0;
	for (Re int i = 1; i <= m; ++ i) if (vis[i]) ++ ans;
	printf ("%d", ans);
	fclose (stdin), fclose (stdout);
	return 0;
}
