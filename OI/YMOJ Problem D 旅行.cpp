#prag\
ma GCC optimize("Ofast")

#include <stdio.h>

inline int fastread ();
inline void fastwrite (int);
inline void fastwriteline (int);
inline void fastwritespace (int);

#define maxn 250
#define max(a,b) a>b? a:b

int n, m, in, cnt, temp;
int ans = -0x7fffffff;
bool flag;
// int mapp[maxn][maxn];
int summ[maxn][maxn];

int main ()
{
	m = fastread ();
	n = fastread ();
	for (int i = 1; i <= m; i ++)
	{
		for (int j = 1; j <= n; j ++)
		{
			in = fastread ();
			// mapp[i][j] = fastraed ();
			summ[i][j] = summ[i-1][j] + /* summ[i][j-1] - summ[i-1][j-1] + mapp[i][j] */ in;
			if (in/* mapp[i][j] */ >= 0) flag = true;
		}
	}
	
	if (!flag)
	{
		printf ("No");
		return 0;
	}
	
	
	putchar ('\n');
	for (int i = 1; i <= m; i ++)
	{
		for (int j = 1; j <= n; j ++)
		{
			fastwritespace (summ[i][j]);
		}
		putchar ('\n');
	}
	putchar ('\n');
	
	for (int i = 0; i < m; i ++)
	{
		for (int j = i + 1; j <= m; j ++)
		{
			cnt = 0;
			for (int k = 1; k <= n; k ++)
			{
				temp = summ[j][k] - summ[i][k];
				cnt = cnt+temp<0? 0:cnt+temp;
				ans = max (ans, cnt);
			}
		}
	}
	
	fastwrite (ans);
	
	return 0;
}

inline int fastread ()
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
inline void fastwrite (int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwritespace (int x)
{
	fastwrite(x);
	putchar(' ');
}
inline void fastwriteline (int x)
{
	fastwrite(x);
	putchar('\n');
}
