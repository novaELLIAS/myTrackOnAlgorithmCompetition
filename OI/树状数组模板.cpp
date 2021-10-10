#include <stdio.h>

const int maxn = 500000 + 10;
int n, m;
int nico[maxn];

int lowbit(int x) {return x&-x;}
void update(int pos, int num)
{
	while(pos <= n)
	{
		nico[pos] += num;
		pos += lowbit(pos);
	}
}
int ask(int pos)
{
	int ret = 0;
	while(pos)
	{
		ret += nico[pos];
		pos -= lowbit(pos);
	}
	return ret;
}
void WORK()
{
	int var, x, y;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &var, &x, &y);
		if(var == 1) update(x, y);
		else printf("%d\n", ask(y)-ask(x-1));
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	int in;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &in);
		update(i, in);
	}
	WORK();
	return 0;
}
