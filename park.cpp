#pragma GCC optimize ("Ofast")

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>

using namespace std;

#define maxn 100001
#define rint register int

inline int read () {
	int x = 0;
	char c = getchar();
	bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

int n, m, k, p, a, b, c, u, v, w;
vector <pair <int, int> > e[maxn];

struct node {
	int val, name;
	bool operator < (const node &x) const {
		return val > x.val;
	}
};
priority_queue <node> nico;

int dis[maxn], rcd[maxn], minlong, ans;
bool visit[maxn];

inline void solve1 () {
	int fro, to, va;
	for (int i = 1; i <= n; i ++) {
		dis[i] = 0x3f3f3f3f, rcd[i] = 0, visit[i] = false;
	}
	while (!nico.empty ()) nico.pop ();
	nico.push((node) {
		0, 1
	});
	dis[1] = 0, rcd[1] = 1;
	while (!nico.empty()) {
		fro = nico.top().name;
		nico.pop();
		if (visit[fro]) continue;
		visit[fro] = true;
		for (int i = e[fro].size () - 1; i >= 0; i --) {
			to = e[fro][i].first;
			va = e[fro][i].second;
			if (!visit[to] && dis[fro] + va < dis[to]) {
				dis[to] = dis[fro] + va;
				rcd[to] = rcd[fro];
				nico.push((node) {
					dis[to], to
				});
			} else if(dis[to] == dis[fro] + va) rcd[to] = (rcd[to] + rcd[fro]) % p;
		}
	}
	printf ("%d\n", rcd[n]);
}

inline int dijstra ()
{
	int fro, to, va;
	for (int i = 1; i <= n; i ++) {
		dis[i] = 0x3f3f3f3f, visit[i] = false;
	}
	while (!nico.empty ()) nico.pop ();
	nico.push((node) {
		0, 1
	});
	dis[1] = 0;
	while (!nico.empty()) {
		fro = nico.top().name;
		nico.pop();
		if (visit[fro]) continue;
		visit[fro] = true;
		for (int i = e[fro].size () - 1; i >= 0; i --) {
			to = e[fro][i].first;
			va = e[fro][i].second;
			if (!visit[to] && dis[fro] + va < dis[to]) {
				dis[to] = dis[fro] + va;
				nico.push((node) {
					dis[to], to
				});
			}
		}
	}
	return dis[n];
}

inline void dfs (int now, int len)
{
	//puts ("check");
	if (len > minlong) return;
	if (now == n)
	{
		//puts ("arrive");
		ans ++;
		return;
	}
	int to, va;
	for (rint i = e[now].size()-1; i >= 0; i --)
	{
		to = e[now][i].first;
		va = e[now][i].second;
		dfs(to, len + va);
	}
}

inline void solve2 ()
{
	minlong = dijstra () + k;
	dfs (1,0);
	printf ("%d\n", ans);
}

inline void solve () {
	if (k == 0) solve1 ();
	else solve2 ();
}

int main () {
	freopen ("park.in","r",stdin);
	freopen ("park.out","w",stdout);
	
	int _ = read ();
	while (_ --) {
		for (rint i = 1; i <= n; i ++) e[i].clear ();
		n = read (), m = read (), k = read (), p = read ();
		for (rint i = 1; i <= m; i ++) {
			u = read (), v = read (), w = read();
			e[u].push_back (make_pair (v, w));
		}
		solve ();
	}
	return 0;
}
