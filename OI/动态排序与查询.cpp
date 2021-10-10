#include <stdio.h>
#include <algorithm>

using namespace std;

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

#define maxn  45010

struct node
{
	int name;
	int value;
} data[maxn];
int n, nico[maxn];

int lowbit (int x)
{
	return x&-x;
}
void update (int pos)
{
	while (pos <= n)
	{
		nico[pos] ++;
		pos += lowbit(pos);
	}
}
int ask (int pos)
{
	int ret = 0;
	while (pos > 0)
	{
		ret += nico[pos];
		pos -= lowbit(pos);
	}
	return ret+1;
}
bool cmp (node a, node b)
{
	return a.value > b.value;
}

int main()
{
	n = fastread();
	for (int i = 1; i <= n; i ++)
	{
		data[i].value = fastread();
		data[i].name = i;
	}
	sort (data+1, data+n+1, cmp);
	for (int i = 1; i <= n; i ++)
	{
		nico[data[i].name] = i;
	}
	for (int i = 1; i <= n; i ++)
	{
		fastwriteline (ask (nico[i]));
		update (nico[i]);
	}
	return 0;
}
