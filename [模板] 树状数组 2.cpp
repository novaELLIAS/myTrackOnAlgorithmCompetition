#include <stdio.h>

const int maxn = 500000 + 10;
int n, m, pre;
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
	int var, x, y, k;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d", &var);
		if(var == 1)
		{
			scanf("%d %d %d", &x, &y, &k);
			update(x, k);
			update(y+1, -1*k);
		}
		else{
			scanf("%d", &x);
			printf("%d\n", ask(x));
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	int in;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &in);
		update(i, in-pre);
		pre = in;
	}
	WORK();
	return 0;
}
