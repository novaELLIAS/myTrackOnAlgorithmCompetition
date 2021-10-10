#pragma G++ optimize ("Ofast", 3)

#include <cstdio>
#include <algorithm>

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

inline const int& max (const int& a, const int& b)
{
	return a>b? a:b;
}

#define Re register
#define maxn 100001

struct node {
	int a, b;
	friend bool operator < (node a, node b)
	{
		return a.a < b.a;
	}
} dat[maxn];

int rl[1900101], dp[1900101];

int main ()
{
	freopen ("hop.in", "r", stdin);
	freopen ("hop.out","w",stdout);
	
	register int n = read (), m = read (), pos = 0, ans = 0;
	for (Re int i = 1; i <= n; ++ i) dat[i].b = read (), dat[i].a = read (), dp[i] = -1;
	sort (dat + 1, dat + n + 1);
	dp[0] = 0;
	
	for (Re int i = 1; i <= n; ++ i)
	{
		if (dat[i].a - dat[i-1].a > 17) pos += 18, rl[pos] += dat[i].b;
		else pos += dat[i].a - dat[i-1].a, rl[pos] += dat[i].b;
	}
	
	for (Re int i = 0; i <= pos; ++ i)
	{
		if (dp[i] ^ (-1))
		{
			dp[i+7] = max (dp[i+7], dp[i] + rl[i+7]);
			dp[i+4] = max (dp[i+4], dp[i] + rl[i+4]);
		}
	}
	
	printf ("%d", dp[pos]);
	return 0;
}
