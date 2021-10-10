// mother-f**ker-enable-o233333333

#include <stdio.h>
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

#define maxn 500010

int n, m, s;
vector <int> e[maxn];
int father[maxn][25];
int deep[maxn];

void DFS_INIT(int root)
{
	for(int i = 0; i < e[root].size(); i++)
	{
		if(e[root][i] != father[root][0])
		{
			deep[e[root][i]] = deep[root] + 1;
			father[e[root][i]][0] = root;
			DFS_INIT(e[root][i]);
		}
	}
}
int getlca(int u, int v)
{
	if(deep[u] < deep[v]) u^=v^=u^=v;
	int delta = deep[u] - deep[v];
	for(int i = 0; (1<<i) <= n; i ++)
	{
		if((1 << i) & delta) u = father[u][i];
	}
	if(u == v) return u;
	for(int i = 19; i >= 0; i --)
	{
		if(father[u][i] != father[v][i]) u = father[u][i],v = father[v][i];
	}
	return father[u][0];
}
int main(void)
{
	n = fastread();
	m = fastread();
	s = fastread();
	for(int i = 1; i < n; i ++)
	{
		int u = fastread();
		int v = fastread();
		e[u].push_back(v);
		e[v].push_back(u); 
	}
	deep[s] = 1;
	DFS_INIT(s);
	for(int i = 1; (1 << i) <= n; i ++)
	{
		for(int j = 1; j <= n; j ++)
		{
			father[j][i] = father[father[j][i-1]][i-1];
		}
	}
	while(m--)
	{
		int u = fastread();
		int v = fastread();
		printf("%d\n", getlca(u, v));
	}
}
