#pragma GCC optimize ("Ofast", 3)

#include <cstdio>
#include <string.h>

#define gc() getchar()
inline int read ()
{
	register int x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}

inline const int& max (const int& a, const int& b) {return a>b? a:b;}

#define Re register
#define maxn 201

const int dx[5] = {0, -1, 1, 0, 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node {
	int id, dat;
} que[maxn];

char mp[maxn][maxn];
int dp[maxn][maxn], ans;

inline void nico (Re int x, Re int y, Re int lim, Re int ps, Re int n, Re int m)
{
	//printf ("%d %d %d %d %d %d\n", x, y, lim, ps, n, m);
	register int head = 1, tail = 0;
	for (Re int i = 1; x>=1 && x<=n && y>=1 && y<=m; ++ i, x += dx[ps], y += dy[ps])
	{
		if (mp[x][y] == 'x') tail = 0, head = 1;
		else {
			while (head <= tail && que[tail].dat + i - que[tail].id < dp[x][y]) -- tail;
			que[++ tail] = (node) {i, dp[x][y]};
			while (head<=tail && que[tail].id - que[head].id > lim) ++ head;
			dp[x][y] = que[head].dat + i - que[head].id;
			ans = max (ans, dp[x][y]);
		}
	}
}

int main ()
{
	register int n=read(),m=read(),sx=read(),sy=read(),AK=read();
	for (Re int i = 1; i <= n; ++ i) scanf ("%s", mp[i] + 1);
	//for (Re int i = 1; i <= n; ++ i) printf ("%s\n", mp[i] + 1);
	memset (dp, -0x3f3f3f3f, sizeof dp); dp[sx][sy] = 0;
	register int hd, le, fr, to;
	while (AK --)
	{
		fr = read(), to = read(), le = to - fr + 1, hd = read ();
		if (hd == 1) for (Re int i = 1; i <= m; ++ i) nico (n, i, le, hd, n, m);
		else if (hd == 2) for (Re int i = 1; i <= m; ++ i) nico (1, i, le, hd, n, m);
		else if (hd == 3) for (Re int i = 1; i <= n; ++ i) nico (i, m, le, hd, n, m);
		else for (Re int i = 1; i <= n; ++ i) nico (i, 1, le, hd, n, m);
	}
	printf ("%d", ans);
	return 0;
}
