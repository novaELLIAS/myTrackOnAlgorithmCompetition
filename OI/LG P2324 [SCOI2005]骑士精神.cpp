#include <cstdio>

using namespace std;

#define rint register int
#define swap(x,y) ((y)^=(x)^=(y)^=(x))

const char fin[5][5] = {
	{'1', '1', '1', '1', '1'},
	{'0', '1', '1', '1', '1'},
	{'0', '0', '*', '1', '1'},
	{'0', '0', '0', '0', '1'},
	{'0', '0', '0', '0', '0'}
};

const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

char dat[5][5];
int ans = 0;

inline bool over_check (int x, int y)
{
	return x>=0&&x<=4&&y>=0&&y<=4;
}

inline int get_eps ()
{
	register int ret = 0;
	for (rint i = 0; i <= 4; i ++)
	{
		for (rint j = 0; j <= 4; j ++)
		{
			if (dat[i][j] != fin[i][j]) ret ++;
		}
	}
	return ret;
}

static bool dfs (int ste, int x, int y)
{
	if (ste >= ans)
	{
		if (!get_eps()) return true;
		return false;
	}
	if (ste + get_eps() > ans + 1) return false;
	register int nowx, nowy;
	for (rint i = 0; i <= 7; i ++)
	{
		nowx = x + dx[i], nowy = y + dy[i];
		if (over_check (nowx, nowy))
		{
			swap (dat[x][y], dat[nowx][nowy]);
			if (dfs(ste + 1, nowx, nowy)) return true;
			swap (dat[x][y], dat[nowx][nowy]);
		}
	}
	return false;
}

int main ()
{
	register int _; scanf ("%d", &_);
	register int gax, gay;
	while (_ --)
	{
		for (rint i = 0; i <= 4; i ++) scanf ("%s", dat[i]);
		gax = -1;
		for (rint i = 0; i <= 4 && gax == -1; i ++)
		{
			for (rint j = 0; j <= 4; j ++)
			{
				if (dat[i][j] == '*')
				{
					gax = i, gay = j; break;
				}
			}
		}
		for (ans = 0; ans <= 15; ans ++)
		{
			if (dfs(0, gax, gay)) break;
		}
		if (ans > 15) puts ("-1");
		else printf ("%d\n", ans);
	}
	return 0;
}
