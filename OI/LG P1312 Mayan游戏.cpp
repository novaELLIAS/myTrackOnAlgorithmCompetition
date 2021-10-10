#prag\
ma GCC optimize ("Ofast")

#include "string.h"
#include "stdio.h"
#include "stdlib.h"

using namespace std;

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

int n, in;
int mapp[6][8], step[10][6], dfs_temp[6][8];
int total_inital_value, color_used_count;
bool flag[11], visit[10][10], vis[10];

inline void nico_input ()
{
	int in;
	register int j = 0;
	
	scanf ("%d", &n);
	for (register int i = 1; i <= 5; i ++)
	{
		in = fastread ();
		while (in)
		{
			mapp[i][++ j] = in;
			if (!flag[in])
			{
				flag[in] = true;
				color_used_count ++;
			}
			in = fastread ();
			total_inital_value ++;
		}
	}
}

inline void fastwrite (int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}

inline void nico_swap (int &a, int &b)
{
	int temp = a; a = b; b = temp;
}

inline bool nico_judge ()
{
	memset (vis, 0, sizeof vis);
	
	for (register int i = 1; i <= 5; i ++)
	{
		for (register int j = 1; j <= 7; j ++)
		{
			vis[mapp[i][j]] ++;
		}
	}
	
	for (register int i = 1; i <= color_used_count; i ++)
	{
		if (vis[i] >= 1 && vis[i] <= 2) return true;
	}
	return false;
}

inline void nico_clear (int i, int j)
{
	int l = i, r = j, x = j, y = j;
	while (l >= 2 && mapp[i-1][j] == mapp[i][j]) l --;
	while (r <= 3 && mapp[r+1][j] == mapp[i][j]) r ++;
	while (x >= 2 && mapp[i][x-1] == mapp[i][j]) x --;
	while (y <= 6 && mapp[i][y+1] == mapp[i][j]) y ++;
	
	if (r - l >= 2) for (register int k = l; k <= r; k ++) visit[k][j] = false;
	if (x - y >= 2) for (register int k = x; k <= y; k ++) visit[i][k] = false;
}
inline int nico_clc ()
{
	memset (visit, 1, sizeof visit);
	int ret = 0, l, r, x, y;
	bool flag = false;
	for (register int i = 1; i <= 5; i ++)
	{
		for (register int j = 1; j <= 7; j ++) if (mapp[i][j]) nico_clear (i, j);
	}
	
	for (register int i = 1; i <= 5; i ++)
	{
		for (register int j = 1; j <= 7; j ++)
		{
			if (!visit[i][j])
			{
				ret ++;
				mapp[i][j] = 0;
			}
		}
	}
	
	int cnt = 0;
	for (register int i = 1, j; i <= 5; i ++)
	{
		for (; j <= 7; j ++) if (!mapp[i][j]) break;
		x = j;
		for (; j <= 7 ; j ++) if (mapp[i][j]) break;
		if (j == 8) continue;
		y = j - 1;
		cnt = 0;
		for (j = x; j <= 7; j ++)
		{
			cnt ++;
			if (!mapp[i][y+cnt] || mapp[i][j]) break;
			mapp[i][j] = mapp[i][y+cnt];
			mapp[i][y+cnt] = 0;
			flag = true;
		}
	}
	if (flag) ret += nico_clc ();
	return ret;
}

inline void nico_dfs (int tot, int num)
{
	if (nico_judge ()) return;
	if (num >= n+1)
	{
		if (!tot)
		{
			for (register int i = 1; i <= n; i ++)
			{
				fastwrite (step[i][1] - 1); putchar (' ');
				fastwrite (step[i][2] - 1); putchar (' ');
				fastwrite (step[i][3]); putchar (' ');
			}
			exit (0);
		}
		return;
	}
	
	bool flag = false;
	
	for (register int i = 1; i <= 5; i ++)
	{
		for (register int j = 1; j <= 7; j ++)
		{
			dfs_temp[i][j] = mapp[i][j];
		}
	}
	
	for (register int i = 1; i <= 5; i ++)
	{
		for (register int j = 1; j <= 7; j ++)
		{
			if (mapp[i][j])
			{
				flag = true;
				if (i <= 4 && mapp[i][j] != mapp[i+1][j])
				{
					nico_swap (mapp[i][j], mapp[i+1][j]);
					step[num][1] = i;
					step[num][2] = j;
					step[num][3] = 1;
					nico_dfs (num + 1, tot - nico_clc());
					flag = false;
				}
				if (!flag)
				{
					for (register int ii = 1; ii <= 5; ii ++)
					{
						for (register int jj = 1; jj <= 7; jj ++)
						{
							mapp[ii][jj] = dfs_temp[ii][jj];
						}
					}
				}
			}
		}
	}
}

int main ()
{
	nico_input ();
	
	nico_dfs (total_inital_value, 1);
	
	puts ("-1");
	
	return 0;
}
