#include <stdio.h>
#include <queue>

using namespace std;

inline int fastread();
inline void fastwrite(int);
inline void fastwriteline(int);

#define max(a,b) a>b? a:b
#define maxn 110

struct node {
	int name;
	int tot;
	bool operator < (node x) const
	{
		return tot<x.tot;
	}
} data[maxn], temp;
int n, t, ans, now;
int tim[maxn], delta[maxn];
priority_queue <node> nico;

int main()
{
	n = fastread();
	for (int i = 1; i <= n; i ++)
	{
		data[i].tot = fastread();
		data[i].name = i;
	}
	for (int i = 1; i <= n; i ++)
	{
		delta[i] = fastread();
	}
	for (int i = 1; i < n; i ++)
	{
		tim[i] = fastread();
	}
	t = fastread();
	for (int i = 1; i <= n; i ++)
	{
		t -= tim[i-1];
		now = 0;
		while (!nico.empty()) nico.pop();
		for (int j = 1; j <= i; j ++)
		{
			nico.push(data[j]);
		}
		for (int j = 1; j <= t; j ++)
		{
			temp = nico.top();
			nico.pop();
			if (temp.tot > 0)
			{
				now += temp.tot;
			}
			temp.tot -= delta[temp.name];
			nico.push(temp);
		}
		ans = max(ans, now);
	}
	fastwrite(ans);
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
