#prag\
ma GCC optimize("Ofast")
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

#define maxm 500010
#define maxn 10010
#define inf 2147483647

struct node {
	int val, name;
	bool operator < (const node &x) const
	{
		return val > x.val;
	}
};
priority_queue <node> nico;
vector <pair<int, int> > data[maxm];
int dis[maxn];
bool visit[maxn];
int n, m, s, e;
int fro, to, va;

int main()
{
	scanf("%d %d", &n, &m);
	
	int a, b, w;
	for (int i = 1; i <= m; i ++)
	{
		scanf("%d %d %d", &a, &b, &w);
		data[a].push_back( make_pair(b, w));
	}
	
	scanf("%d %d", &s, &e);
	
	for (int i = 1; i <= n; i ++)
	{
		dis[i] = inf;
	}
	nico.push((node) {0, s});
	dis[s] = 0;
	while (!nico.empty())
	{
		fro = nico.top().name;
		nico.pop();
		if (visit[fro]) continue;
		visit[fro] = true;
		for (int i = 0; i < data[fro].size(); i ++)
		{
			to = data[fro][i].first;
			va = data[fro][i].second;
			if (!visit[to] && dis[fro] + va < dis[to])
			{
				dis[to] = dis[fro] + va;
				nico.push((node) {dis[to], to}); 
			}
		}
	}
	printf("%d ", dis[e]);
	return 0;
}
