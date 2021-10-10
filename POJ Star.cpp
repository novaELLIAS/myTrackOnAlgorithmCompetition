#include <stdio.h>

const int maxstar = 15000 +10;
const int maxn = 32000 + 10;
int level[maxstar], nico[maxn];
int n;

inline int lowbit(int x)
{
	return x&-x;
}
void update(int pos, int num)
{
	while(pos <= 32001)
	{
		nico[pos] += num;
		pos += lowbit(pos);
	}
}
int query(int pos)
{
	int ret = 0;
	while(pos)
	{
		ret += nico[pos];
		pos -= lowbit(pos);
	}
	return ret;
}
int main(void)
{
	scanf("%d", &n);
	int x, y;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d", &x, &y);
		x++;
		update(x, 1);
		level[query(x)]++;
	}
	for(int i = 1; i <= n; i++)
	{
		printf("%d\n", level[i]);
	}
}
