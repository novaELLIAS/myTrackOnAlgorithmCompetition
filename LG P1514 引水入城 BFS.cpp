#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"
#include <queue>
#include <algorithm>

using namespace std;

inline int fastread ();
inline void fastwrite (int);
inline void fastwriteline (int);
inline void fastwritespace (int);
inline void nico_bfs (int);
inline void nico_work ();

#define max(a,b) a>b? a:b
#define min(a,b) a<b? a:b
#define maxn 502
#define af a.first
#define as a.second
#define tf t.first
#define ts t.second

struct node {
	int name, h;
	bool visit;
} s[maxn];
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, ans, mapp[maxn][maxn], cnt[maxn];
queue <int> desert [maxn];
pair <int, int> t, a;

inline bool cmp (node a, node b)
{
	return a.h > b.h;
}

int main ()
{
	// freopen ("1514.in", "r", stdin);
	// freopen ("1514.out", "w", stdout);
	n = fastread ();
	m = fastread ();
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			mapp[i][j] = fastread ();
		}
	}
	
	for (int i = 1; i <= m; i ++)
	{
		s[i] = (node) {i, mapp[1][i], false};
	}
	sort (s+1, s+m+1, cmp);
	
	for (int i = 1; i <= m; i ++)
	{
		if (!s[s[i].name].visit) nico_bfs (s[i].name);
	}
	
	for (int i = 1; i <= m; i ++)
	{
		if (desert [i].empty ()) ans ++;
	}
	if (ans != 0)
	{
		puts ("0");
		fastwrite (ans);
		return 0;
	}
	
	nico_work ();
	
	puts ("1");
	fastwrite (ans);
	
	return 0;
}

inline void nico_bfs (int x)
{
	bool vis[maxn][maxn] = {0};
	queue <pair <int, int> > nico;
	nico.push (make_pair (1, x));
	if (n == 1)
	{
		desert[x].push (x);
		cnt[x] ++;
	}
	while (!nico.empty ())
	{
		t = nico.front ();
		nico.pop ();
		for (int i = 0; i < 4; i ++)
		{
			a = make_pair (tf + dir[i][0], ts + dir[i][1]);
			if (af >=1 && af <= n && as >= 1 && as <= m && !vis[af][as] && mapp[af][as] < mapp[tf][ts])
			{
				nico.push (a);
				if (!af) s[as].visit = true;
				if (af == n)
				{
					desert[as].push (x);
					cnt[x] ++; 
				}
				vis[af][as] = true;
			}
		}
	}
}
inline void nico_work ()
{
	int i = 1;
	int maxx = 0, mann;
	while (i <= m)
	{
		maxx = 0;
		while (!desert[i].empty ())
		{
			cnt[desert[i].front ()] --;
			if (cnt[desert[i].front()] >= maxx)
			{
				maxx = cnt[desert[i].front()];
				mann = desert[i].front();
			}
			desert[i].pop();
		}
		i ++;
		while (cnt[mann] > 0)
		{
			while (!desert[i].empty())
			{
				cnt[desert[i].front()] --;
				desert[i].pop();
			}
			i ++;
		}
		ans ++;
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
