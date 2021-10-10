#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define maxn 2510
#define maxm 200010
#define inff 23333333

struct node {
	int val, name;
	bool operator < (const node &x) const
	{
		return val > x.val;
	}
};
priority_queue <node> nico;
vector <pair<int, int> > data[maxn];
bool visit[maxn];
int dis[maxn] = {inff};
int n, m, a, b, c;
int fro, to, va;

int main ()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++)
	{
		scanf("%d %d %d", &a, &b, &c);
		data[a].push_back(make_pair(b, c));
		data[b].push_back(make_pair(a, c));  
	}
	for (int i = 1; i <= n; i ++) dis[i] = inff;
	nico.push((node) {0, 1});
	dis[1] = 0;
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
	printf("%d", dis[n]);
	return 0;
}
