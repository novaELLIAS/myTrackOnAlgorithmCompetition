#pragma GCC optimize ("Ofast")

#include "stdio.h"

#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))

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

int n, d, mapp[130][130], cnt, ans, temp;
int x1, y1, x2, y2;

int main ()
{
	d = fastread ();
	n = fastread ();
	while (n --) mapp[fastread ()+1][fastread ()+1] = fastread ();
	
	for (register int i = 1; i <= 129; i ++)
	{
		for (register int j = 1; j <= 129; j ++)
		{
			mapp[i][j] += mapp[i-1][j] + mapp[i][j-1] - mapp[i-1][j-1];
		}
	}
	
	for (register int i = 1; i <= 129; i ++)
	{
		for (register int j = 1; j <= 129; j ++)
		{
			x1 = max (1, i - d) - 1;
			y1 = max (1, j - d) - 1;
			x2 = min (129, i + d);
			y2 = min (129, j + d);
			temp = mapp[x2][y2] - mapp[x1][y2] - mapp[x2][y1] + mapp[x1][y1];
			if (temp > ans) cnt = 1, ans = temp;
			else if (temp == ans) cnt ++;
		}
	}
	
	printf ("%d %d", cnt, ans);
	
	return 0;
}
