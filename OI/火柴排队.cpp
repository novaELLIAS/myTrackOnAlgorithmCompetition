#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
const int modn = 99999997;
struct node {
	int data, loc;
} a[maxn], b[maxn];
int nico[maxn];
int temp[maxn];
int n, ans;

int lowbit(int x)
{
	return x&-x;
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
void update(int pos, int num)
{
	while(pos <= n)
	{
		nico[pos] += num;
		nico[pos] %= modn;
		pos += lowbit(pos);
	}
}
int query(int pos)
{
	int ret = 0;
	while(pos)
	{
		ret += nico[pos];
		nico[pos] %= modn;
		pos -= lowbit(pos);
	}
	return ret;
}
bool cmp(node x, node y)
{
	return x.data < y.data;
}
int main(void)
{
	n = fastread();
	for(int i = 1; i <= n; i++)
	{
		a[i].data = fastread();
		a[i].loc = i;
	}
	for(int i = 1; i <= n; i++)
	{
		b[i].data = fastread();
		b[i].loc = i;
	}
	sort(a+1, a+n+1, cmp);
	sort(b+1, b+n+1, cmp);
	for (int i = 1; i <= n; i++)
	{
		temp[a[i].loc] = b[i].loc;
	}
	for(int i = 1; i <= n; i++)
	{
		update(temp[i], 1);
		ans += i - query(temp[i]);
		ans %= modn;
	}
	printf("%d", ans);
}
