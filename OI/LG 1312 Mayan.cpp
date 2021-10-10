#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int n, nicocnt;
int mapp[5][7], ans[5][3], rec[5][5][7];
bool map_clear[5][7];

inline int fastread ();
inline void fastwrite (int);

inline void nico_input ()
{
	scanf ("%d", &n);
	int in;
	register int j = 0;
	for (register int i = 0; i < 5; i ++)
	{
		in = fastread ();
		while (in)
		{
			mapp[i][j ++] = in;
			in = fastread ();
		}
		j = 0;
	}
}

inline bool all_cleared_check ()
{
	for (register int i = 0; i < 5; i ++)
	{
		for (register int j = 0; j < 7; j ++)
		{
			if (mapp[i][j]) return false;
		}
	}
	return true;
}

inline void nico_exit ()
{
	for (register int i = 0; i < n; i ++)
	{
		for (register int j = 0; j < 3; j ++)
		{
			fastwrite (ans[i][j]);
			putchar (' ');
		}
		putchar ('\n');
	}
	
	exit (0);
}

inline void map_saver (int step)
{
	for (register int i = 0; i < 5; i ++)
	{
		for (register int j = 0; j < 7; j ++)
		{
			rec[step][i][j] = mapp[i][j];
		}
	}
}

inline void map_reset (int step)
{
	for (register int i = 0; i < 5; i ++)
	{
		for (register int j = 0; j < 7; j ++)
		{
			mapp[i][j] = rec[step][i][j];
		}
	}
	for (register int i = 0; i < 3; i ++)
	{
		ans[step][i] = -1;
	}
}

inline void map_fall_check ()
{
	for (register int i = 0; i < 5; i ++)
	{
		nicocnt = 0;
		for (register int j = 0; j < 7; j ++)
		{
			if (!mapp[i][j]) nicocnt ++;
			else {
				if (!nicocnt) continue;
				mapp[i][j-nicocnt] = mapp[i][j];
				mapp[i][j] = 0;
			}
		}
	}
}

inline bool map_clear_check ()
{
	bool flag = false;
	memset (map_clear, 0, sizeof map_clear);
	
	for (register int i = 0; i < 5; i ++)
	{
		for (int j = 0; j < 7; j ++)
		{
			if(i > 0 && i <= 4 && mapp[i][j] && mapp[i][j] == mapp[i-1][j] && mapp[i+1][j] == mapp[i][j])
			{
				map_clear[i][j] = map_clear[i+1][j] = map_clear[i-1][j] = flag = true;
			}
			if(j > 0 && j <= 6 && mapp[i][j] && mapp[i][j] == mapp[i][j-1] && mapp[i][j] == mapp[i][j+1])
			{
				map_clear[i][j] = map_clear[i][j+1] = map_clear[i][j-1] = flag = true;
			}
		}
	}
	if (!flag) return false;
	for (register int i = 0; i < 5; i ++)
	{
		for (register int j = 0; j < 7; j ++)
		{
			if (map_clear[i][j]) mapp[i][j] = 0;
		}
	}
	return true;
}

inline void map_move (int x, int y, int flag)
{
	if (mapp[x][y] == mapp[x+flag][y]) return;
	int temp = mapp[x][y];
	mapp[x][y] = mapp[x+flag][y];
	mapp[x+flag][y] = temp;
	map_fall_check ();
	while (map_clear_check ()) map_fall_check ();
}

inline void nico_dfs (int step)
{
	if (step == n)
	{
		if (all_cleared_check ()) nico_exit ();
		return;
	}
	map_saver (step);
	for (register int i = 0; i < 5; i ++)
	{
		for (register int j = 0; j < 7; j ++)
		{
			if (mapp[i][j])
			{
				if (i < 4 && mapp[i+1][j] != mapp[i][j])
				{
					map_move (i, j, 1);
					ans[step][0] = i;
					ans[step][1] = j;
					ans[step][2] = 1;
					nico_dfs (step + 1);
					map_reset (step);
				}
				if (i > 0 && mapp[i-1][j] == 0)
				{
					map_move (i, j, -1);
					ans[step][0] = i;
					ans[step][1] = j;
					ans[step][2] = -1;
					nico_dfs (step + 1);
					map_reset (step);
				}
			}
		}
	}
}

int main ()
{
	nico_input ();
	nico_dfs (0);
	puts ("-1");
	return 0;
}

inline void fastwrite (int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
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
