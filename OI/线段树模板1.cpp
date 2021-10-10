#include <stdio.h>
#define ROOT 1,1,n
#define LCHILD bt<<1,l,mid
#define RCHILD bt<<1|1,mid+1,r
#define max(x,y) x>y? x:y
#define min(x,y) x<y? x:y

inline long long fastread()
{
	long long sign = 1, n = 0ll;
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

const int maxn = 100000 + 10;
long long n, m;
struct node
{
	long long sum, flag;
} nico[maxn<<2];
long long data[maxn];

void update(int bt, int l, int r)
{
	nico[bt].sum = nico[bt<<1].sum + nico[bt<<1|1].sum  + nico[bt].flag * (r-l+1);
}
long long query(int ll, int rr, int bt, int l, int r)
{
	if(ll<=l && r<=rr) return nico[bt].sum;
	else
	{
		long long mid = (l+r)/2;
		long long ret = 0ll;
		if(ll <= mid) ret += query(ll, rr, LCHILD);
		if(rr > mid) ret += query(ll, rr, RCHILD);
		ret += nico[bt].flag*(min(r,rr) - max(ll, l) + 1);
		return ret;
	}
}
void grow(int bt, int l, int r)
{
	if(r == l)
	{
		nico[bt].sum = data[l];
	}
	else
	{
		int mid = (l+r)/2;
		grow(LCHILD);
		grow(RCHILD);
		update(bt, l, r);
	}
}
void change(int ll, int rr, int num, int bt, int l, int r)
{
	if(ll <=l && r <= rr)
	{
		nico[bt].flag += num;
		nico[bt].sum += num * (r-l+1);
	}
	else
	{
		int mid = (l+r)/2;
		if(ll <= mid) change(ll, rr, num, LCHILD);
		if(mid < rr) change(ll, rr, num, RCHILD);
		update(bt, l, r);
	}
}
int main(void)
{
	n = fastread();
	m = fastread();
	for(int i = 1; i <= n; i++) data[i] = fastread();
	grow(ROOT);
	while(m--)
	{
		long long var = fastread();
		if(var == 1)
		{
			long long ll = fastread();
			long long rr = fastread();
			long long num = fastread();
			change(ll, rr, num, ROOT);
		}
		else
		{
			long long ll = fastread();
			long long rr = fastread();
			printf("%lld\n", query(ll, rr, ROOT));
		}
	}
}
