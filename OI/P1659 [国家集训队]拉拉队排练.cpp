#include <stdio.h>
#include <string.h> 

#define min(x,y) x<y? x:y
#define max(x,y) x>y? x:y

#define ll long long
#define modn 19930726
#define maxn 1000010

inline int fastread();
inline ll fastread_l();
inline void fastwrite(int);
inline void fastwrite_l(ll);
inline void fastwriteline(int);

int n;
ll k;
char str[maxn];
int cnt[maxn], nico[maxn];

ll fastpow(int x, int y)
{
	if (x == 1) return 1;
	ll base = x, ret = 1;
	while (y)
	{
		if (y&1) ret = (ret*base)%modn;
		base = (base*base)%modn;
		y>>=1;
	}
	return ret;
}
int main()
{
	n = fastread();
	k = fastread_l();
	scanf("%s", str+1);
	str[0] = '$';
	int len = strlen(str);
	int maxx = 0;
	int pos = 0;
	int mr = 0;
	ll ans = 1;
	for (int i = 1; i <= n; i ++)
	{
		if (i < mr)
		{
			nico[i] = min(nico[2*pos-i], mr-i);
		}
		else nico[i] = 1;
		while (str[i - nico[i]] == str[i + nico[i]])
		{
			nico[i] ++;
		}
		if (mr < i+nico[i] - 1)
		{
			pos = i;
			mr = i + nico[i] - 1;
		}
		cnt[nico[i]*2-1] ++;
		maxx = max (maxx, nico[i]*2-1);
	}
	int sum = 0;
	for(int i = maxx; i >= 1; i -=2)
	{
		sum += cnt[i];
		if(k >= sum)
		{
			ans = (ans*fastpow(i,sum)) % modn;
			k -= sum;
		}
		else
		{
			ans = (ans*fastpow(i,k)) % modn;
			k -= sum;
			break;
		}
	}
	if(k > 0) puts("-1");
	else fastwrite_l(ans);
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
inline ll fastread_l()
{
	ll sign = 1, n = 0;
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
inline void fastwrite_l(ll x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite_l(x / 10);
	putchar(x%10 + '0');
}
inline void fastwriteline(int x)
{
	fastwrite(x);
	putchar('\n');
}
