#include <stdio.h>
#define lll long long
#define lowbit(x) (x&-x)

const int maxn = 200000 + 100;
int n, q;
lll sumorigin[maxn];
lll delta[maxn], deltai[maxn];

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
void update(lll *nico, int pos, int num)
{
	while(pos <= n)
	{
		nico[pos] += num;
		pos += lowbit(pos);
	}
}
lll query(lll *nico, int pos)
{
	lll ret = 0ll;
	while(pos)
	{
		ret += nico[pos];
		pos -= lowbit(pos);
	}
	return ret;
}
int main(void)
{
	n = fastread();
	//q = fastread();
	for(int i = 1; i <= n; i++)
	{
		sumorigin[i] = fastread();
		sumorigin[i] += sumorigin[i-1];
	}
	q = fastread();
	while(q--)
	{
		/*
		char flag;
		scanf("%c", &flag);*/
		int flag = fastread();
		if(flag == 1)
		{
			int l, r, x;
			l = fastread(); r = fastread(); x = fastread();
			update(delta, l, x);
			update(delta, r+1, -x);
			update(deltai, l, x*l);
			update(deltai, r+1, -x*(r+1));
		}
		else{
			lll l = fastread(), r = fastread();
			lll suml = sumorigin[l - 1] + l*query(delta, l-1) - query(deltai, l-1);
			lll sumr = sumorigin[r] + (r+1) * query(delta, r) - query(deltai, r);
			printf("%lld\n", sumr-suml);
		}
	}
}
