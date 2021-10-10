#include <stdio.h>

inline int fastread();
inline void fastwrite(int);
inline void fastwriteline(int);
inline void fastwritespace(int x);

#define maxn 100005

int n, hig[maxn], ans[maxn];
int j;

int main ()
{
	n = fastread();
	for (int i = 1; i <= n; i ++)
	{
		hig[i] = fastread();
	}
	
	hig[0] = 233333333;
	
	for (int i = n-1; i >= 1; i --)
	{
		for (j = i+1; hig[i] >= hig[j]; j = ans[j]);
		ans[i] = j;
	}
	for (int i = 1; i <= n; i ++)
	{
		fastwriteline(ans[i]);
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
inline void fastwritespace(int x)
{
	fastwrite(x);
	putchar(' ');
}
inline void fastwriteline(int x)
{
	fastwrite(x);
	putchar('\n');
}
