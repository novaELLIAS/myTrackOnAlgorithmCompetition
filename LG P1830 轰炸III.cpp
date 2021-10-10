#include "stdio.h"

inline int fastread ();
inline void fastwrite (int);
inline void fastwriteline (int);
inline void fastwritespace (int);

#define maxn 101
#define ll long long

int n, m, tot, ans;
ll mapp[maxn][4];

int main ()
{
	m = fastread ();
	n = fastread ();
	for (int i = 1; i <= m; i ++)
	{
		for (int j = 0; j <= 3; j ++)
		{
			mapp[i][j] = fastread ();
		}
	}
	
	int a, b;
	for (int i = 1; i <= n; i ++)
	{
		a = fastread ();
		b = fastread ();
		
		for (int j = 1; j <= m; j ++)
		{
			if (a >= mapp[j][0] && a <= mapp[j][2] && b >= mapp[j][1] && b <= mapp[j][3])
			{
				tot ++;
				ans = j;
			}
		}
		
		if (tot == 0) puts ("N");
		else {
			printf("Y ");
			fastwritespace (tot);
			fastwriteline (ans);
		}
		tot = 0;
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
