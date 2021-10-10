/*
#prag\
ma GCC optimize ("Ofast")
*/
#include "stdio.h"
#include "string.h"
#include <algorithm>

using namespace std;

inline int fastread ();
inline void fastwrite (int);
inline void fastwriteline (int);
inline void fastwritespace (int);

#define max(a,b) a>b? a:b
#define min(a,b) a<b? a:b
#define maxn 501

inline void nico_dfs (int, int);

struct node {
	int y;
	int h;
} s[maxn];
int n, m, cnt, l = 1, maxr;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int mapp[maxn][maxn], ll[maxn][maxn], rr[maxn][maxn];
bool visit[maxn][maxn], flag;

inline bool cmp (node a, node b)
{
	return a.h > b.h;
}

int main ()
{
	 freopen ("1514.in", "r", stdin);
	 freopen ("1514.out", "w", stdout);
	memset (ll, 0x3f, sizeof ll);

	n = fastread ();
	m = fastread ();
	
	for (int i = 1; i <= m; i ++) ll[n][i] = rr[n][i] = i;
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			mapp[i][j] = fastread ();
		}
	}
	
	for (int i = 1; i <= m; i ++) s[i] = (node) {i, mapp[i][1]};
	sort (s+1, s+n+1, cmp);
	
	for (int i = 1; i <= m; i ++) if (!visit[1][s[i].y]) nico_dfs (1, s[i].y);
	// puts ("nicojudge 0");
	for (int i = 1; i <= m; i ++)
	{
		if (!visit[n][i])
		{
			flag = true;
			cnt ++;
		}
	}
	if (flag)
	{
		putchar ('0'); putchar ('\n');
		fastwrite (cnt);
		return 0;
	}
	// puts ("nicojudge 1");
	int maxxx = -1;
	for (int i = 1; i <= m ; i ++)
	{
		if (ll[1][i] == 1 && rr[1][i] > maxxx)
		{
			l = i;
			maxxx = rr[1][i];
		}
	}
	// puts ("nicojudge 2");
	while (l <= m)
	{
		maxr = 0;
		for (int i = 1; i <= m; i ++)
		{
			if (ll[1][i] <= l) maxr = max (maxr, rr[1][i]);
		}
		cnt ++;
		l = maxr + 1;
	}
	
	putchar ('1'); putchar ('\n');
	fastwrite (cnt);
	
	return 0;
}
inline void nico_dfs (int x, int y)
{
	// puts ("nico_dfs");
	visit[x][y] = true;
	int xx, yy;
	for (int i = 0; i <= 3; i ++)
	{
		xx = x + dx[i], yy = y + dy[i];
		if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
		if (mapp[xx][yy] >= mapp[x][y]) continue;
		if (!visit[xx][yy]) nico_dfs (xx, yy);
		ll[x][y] = min (ll[x][y], ll[xx][yy]);
		rr[x][y] = max (rr[x][y], rr[xx][yy]);
	}
}

inline int fastread ()
{
	int sign = 1, n = 0;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-') sign = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		n = n*10 + c-'0';
		c = getchar();
	}
	return sign*n;
}
inline void fastwrite (int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwritespace (int x)
{
	fastwrite(x);
	putchar(' ');
}
inline void fastwriteline (int x)
{
	fastwrite(x);
	putchar('\n');
}
