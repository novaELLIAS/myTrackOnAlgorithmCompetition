#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"
#include "stdlib.h"
#include <algorithm>

using namespace std;

#define max(a,b) a>b? a:b

inline int fastread ();
inline void fastwrite (int);
inline void fastwritelonglong (long long);
inline void fastwriteline (int);
inline void fastwritespace (int);

inline void nico_dfs (int, int, int);
inline void nico_out ();

struct node {
	int name;
	int num;
} s[10];
const int val[10][10] =
{
	{6,6,6,6,6,6,6,6,6},
	{6,7,7,7,7,7,7,7,6},
	{6,7,8,8,8,8,8,7,6},
	{6,7,8,9,9,9,8,7,6},
	{6,7,8,9,10,9,8,7,6},
	{6,7,8,9,9,9,8,7,6},
	{6,7,8,8,8,8,8,7,6},
	{6,7,7,7,7,7,7,7,6},
	{6,6,6,6,6,6,6,6,6}
};
int mapp[10][10];
bool ha[10][10], li[10][10], ge[10][10];
long long ans = -1, cnt;

inline bool cmp (node a, node b)
{
	return a.num<b.num;
}

int main ()
{
	for (int i = 1; i <= 9 ; i ++)
	{
		s[i].name = i;
		for (int j = 1; j <= 9; j ++)
		{
			mapp[i][j] = fastread ();
			if (mapp[i][j] > 0)
			{
				ha[i][mapp[i][j]] = li[j][mapp[i][j]] = ge[(i-1)/3*3+(j-1)/3+1][mapp[i][j]] = true;
			} else s[i].num ++;
		}
	}

	sort (s+1, s+10, cmp);

	nico_dfs (s[1].name, 1, 1);

	// putchar ('\n');
	fastwritelonglong (ans);

	return 0;
}

inline void nico_dfs (int x, int y, int name)
{
	if (mapp[x][y] != 0)
	{
		if (name == 9 && y == 9) nico_out ();
		if (y == 9) nico_dfs (/*x+1*/s[name+1].name, 1, name+1);
		else nico_dfs (x, y+1, name);
	}
	if (mapp[x][y] == 0)
	{
		for (int i = 1; i <= 9; i ++)
		{
			if (!ha[x][i] && !li[y][i] && !ge[(x-1)/3*3+(y-1)/3+1][i])
			{
				mapp[x][y] = i;
				ha[x][i] = li[y][i] = ge[(x-1)/3*3+(y-1)/3+1][i] = true;
				if (name == 9 && y == 9) nico_out ();
				if (y == 9) nico_dfs (/*x+1*/s[name+1].name, 1, name+1);
				else nico_dfs (x, y+1, name);
				mapp[x][y] = 0;
				ha[x][i] = li[y][i] = ge[(x-1)/3*3 + (y-1)/3+1][i] = false;
			}
		}
	}
}
inline void nico_out ()
{
	// putchar ('\n');
	cnt = 0ll;
	for (int i = 1; i <= 9; i ++)
	{
		for (int j = 1; j <= 9; j ++)
		{
			// fastwritespace (mapp[i][j]);
			cnt += ((long long) mapp[i][j] * (long long) val[i-1][j-1]);
		}
		// putchar ('\n');
	}
	ans = max (ans, cnt);
	// fastwritelonglong (cnt);
	// exit (0);
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
inline void fastwritelonglong (long long x)
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
