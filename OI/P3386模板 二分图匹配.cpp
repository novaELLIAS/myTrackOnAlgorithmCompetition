#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

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

#define maxn 1010

int n, m, e, ans;
vector <int> data[maxn];
bool visit[maxn];
int nico[maxn];

bool hungry(int x)
{
	for(int i = 0; i < data[x].size(); i ++)
	{
		if(!visit[data[x][i]])
		{
			visit[data[x][i]] = true;
			if(!nico[data[x][i]] || hungry(nico[data[x][i]]))
			{
				nico[data[x][i]] = x;
				return true;
			}
		}
	}
	return false;
}
int main(void)
{
	n = fastread();
	m = fastread();
	e = fastread();
	for(int i = 1; i <= e; i ++)
	{
		int u = fastread();
		int v = fastread();
		if (v > m) continue;
		data[u].push_back(v);
	}
	for(int i = 1; i <= n; i ++)
	{
		memset(visit, false, sizeof(visit));
		if(hungry(i)) ans++;
	}
	fastwrite(ans);
}
