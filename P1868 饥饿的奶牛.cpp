#include <stdio.h>
#include <algorithm>

using namespace std;

inline int fastread();
inline void fastwrite(int);
inline void fastwriteline(int);

#define min(a,b) a<b? a:b
#define max(a,b) a>b? a:b
#define maxn 150010
#define maxp 3000010

struct node {
	int x, y;
	int val;
} data[maxn];
int dp[maxn];
int n;

bool cmp (node a, node b)
{
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}
int find (int x)
{
	int l = 1, r = x, ret = -1;
	while (l <= r)
	{
		int mid = l+r >>1;
		if (data[mid].y < data[x].x)
		{
			ret = mid;
			l = mid+1;
		}
		else r = mid - 1;
	}
	return ret;
}
int main ()
{
	n = fastread();
	for (int i = 1; i <= n; i ++)
	{
		data[i].x = fastread();
		data[i].y = fastread();
		data[i].val = data[i].y - data[i].x + 1;
	}
	sort(data+1, data+n+1, cmp);
	dp[1] = data[1].val;
	for (int i = 2; i <= n; i ++)
	{
		int j = find(i);
		if (j != -1) dp[i] = max(dp[i-1], dp[j] + data[i].val);
		else dp[i] = max(dp[i-1], data[i].val);
	}
	fastwrite(dp[n]);
	return 0;
}

inline int fastread()
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
inline void fastwrite(int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwriteline(int x)
{
	fastwrite(x);
	putchar('\n');
}
