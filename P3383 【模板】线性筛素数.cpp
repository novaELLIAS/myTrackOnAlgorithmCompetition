#include <stdio.h>

#define maxn 10000010

int n, m, q;
bool nico[maxn];
int prime[maxn];
int pos;

inline int fastread();
inline void fastwrite(int);
inline void fastwriteline(int);

int main()
{
	n = fastread();
	m = fastread();
	nico[1] = true;
	for (int i = 2; i <= n; i ++)
	{
		if (!nico[i]) prime[++ pos] = i;
		for (int j = 1; j<=pos && i*prime[j]<=n; j ++)
		{
			nico[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
	while (m --)
	{
		q = fastread();
		if (nico[q]) puts("No");
		else puts("Yes");
	}
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
