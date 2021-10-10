#prag\
ma GCC optimize("Ofast")

#include "stdio.h"
#include "string.h"

inline int fastread ();
inline void fastwrite (int);
inline void fastwriteline (int);
inline void fastwritespace (int);

#define max(a,b) a>b? a:b
#define maxn 102

int n, ans, tem;
char c;
const int nico[maxn] = {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,200,202};
const int summ[maxn] = {0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676,729,784,841,900,961,1024,1089,1156,1225,1296,1369,1444,1521,1600,1681,1764,1849,1936,2025,2116,2209,2304,2401,2500,2601,2704,2809,2916,3025,3136,3249,3364,3481,3600,3721,3844,3969,4096,4225,4356,4489,4624,4761,4900,5041,5184,5329,5476,5625,5776,5929,6084,6241,6400,6561,6724,6889,7056,7225,7396,7569,7744,7921,8100,8281,8464,8649,8836,9025,9216,9409,9604,9801,10000,10201};
char mapp[maxn][maxn];
int sum1[maxn][maxn], sum2[maxn][maxn];

int main ()
{
	while (n = fastread ())
	{
		if (n == 0) return 0;
		
		for (int i = 1; i <= n; i ++)
		{
			scanf ("%s", mapp[i]);
			for (int j = nico[n-i], cnt = 0; j >= 0; j --)
			{
				if (mapp[i][j] == '-') sum1[i][j] = ++ cnt;
				else sum1[i][j] = cnt = 0;
			}
			for (int j = 0, cnt = 0; j <= nico[n-i]; j ++)
			{
				if (mapp[i][j] == '-') sum2[i][j] = ++ cnt;
				else sum2[i][j] = cnt = 0;
			}
		}
		
		for (int j = 0; j <= nico[n-1]; j ++)
		{
			tem = 0;
			if (j % 2 != 0)
			{
				for (int i = 1;i < n-(j>>1); i ++)
				{
					if (sum2[i][j] >= nico[tem]+1) tem ++;
					else {
						ans = max (ans, tem);
						tem = (sum2[i][j] + 1) >>1;
					}
				}
			} else {
				for (int i = n-(j>>1); i ; i --)
				{
					if (sum1[i][j] >= nico[tem]+1) tem ++;
					else {
						ans = max (ans, tem);
						tem = (sum1[i][j] + 1) >>1;
					}
				}
			}
			ans = max (ans, tem);
		}
		/*
		if (n == 0) return 0;
		getchar ();
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 1; j <= nico[n-i+1]; j ++)
			{
				c = ' ';
				while (c == ' ') c = getchar ();
				switch (c)
				{
					case '#':
						mapp[i][j] = 0;
						break;
					case '-':
						mapp[i][j] = 1;
						break;
				}
				getchar ();
				sum1[i][j] = sum2[i-1][j] + mapp[i][j];
				// memset (mapp, 0, sizeof mapp);
			}
			for (int j = nico[n-i+2]; j >= 1; j --)
			{
				sum2[i][j] = sum2[i+1][j] + mapp[i][j];
			}
		}
		tem = 1;
		for (int i = 2; i <= nico[n-i+1]; i += 2, tem ++)
		{
			for (int j = 1; j <= n - tem; j ++)
			{
				if (mapp[i][j] != 1) continue;
				for (int k = j; k <= n - tem; k ++)
				{
					cnt ++;
					if (mapp[i][k] != nico[cnt])
					{
						ans = cnt > ans? cnt:ans;
						break;
					}
				}
				cnt = 0;
			}
		}
		tem = cnt = 0;
		for (int i = 1; i <= nico[n-i+1]; i += 2, tem ++)
		{
			for (int j = n - tem; j >= 1; j --)
			{
				if (mapp[i][j] != 1) continue;
				for (int k = j; k >= 1; k --)
				{
					cnt ++;
					if (mapp[i][k] != nico[cnt])
					{
						ans = cnt > ans? cnt:ans;
						break;
					}
				}
				cnt = 0;
			}
		}
		*/
		fastwriteline (summ[ans]);
		ans = tem = 0;
		memset (mapp, 0, sizeof mapp);
		memset (sum1, 0, sizeof sum1);
		memset (sum2, 0, sizeof sum2);
	}
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
