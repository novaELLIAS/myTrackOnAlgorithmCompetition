#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>

using namespace std;

#define maxn 100001

int n, m, k;
long long ri[maxn];
double wi[maxn], wians[maxn];
bool visit[maxn];
queue  <int> que;
queue  <int> frt;
vector <int> con[maxn];

signed main () {
	scanf ("%d %d %d", &n, &m, &k);
	for (register int i=1; i<=n; ++ i) scanf ("%lld", &ri[i]);
	register int fr, to;
	for (register int i=1; i<=m; ++ i) {
		scanf("%d %d", &fr, &to);
		con[fr].push_back(to); con[to].push_back(fr);
	} while (!frt.empty()) frt.pop();
	for (register int i=1; i<=k; ++ i) {
		scanf("%d %d", &fr, &to);
		frt.push(fr);
		wi[fr] = (double) to;
	}
	
	register int size, init;
	while (!frt.empty()) {
		init = frt.front(); frt.pop();
		if (visit[init]) continue;
		visit[init] = true;
		while(!que.empty()) que.pop();
		que.push(init);
		while (!que.empty()) {
			fr = que.front(); que.pop();
			size = con[fr].size();
			for (register int j=0; j<size; ++ j) {
				to = con[fr][j];
				if (!visit[to]) {
					if (abs(wi[to])>1e-4) {
						if (abs(wi[to]*ri[to] + wi[fr]*ri[fr]) > 1e-4) {
							printf("0"); exit(0);
						}
					} wi[to] = - wi[fr]*ri[fr]/ri[to];
					que.push(to); visit[to] = true;
				} else {
					if (abs(wi[to]*ri[to] + wi[fr]*ri[fr]) > 1e-4) {
						printf("0"); exit(0);
					}
				}
			}
		}
	}
	
	while (!frt.empty()) frt.pop();
	for (register int i=1; i<=n; ++ i) {
		if (!visit[i]) frt.push(i);
		wians[i] = wi[i];
	}
	
	bool isMul = true;
	while (!frt.empty()) {
		init = frt.front(); frt.pop();
		if (visit[init]) continue;
		visit[init] = true;
		wi[init] = 114514.1919;
		while(!que.empty()) que.pop();
		que.push(init);
		while (!que.empty()) {
			fr = que.front(); que.pop();
			size = con[fr].size();
			for (register int j=0; j<size; ++ j) {
				to = con[fr][j];
				if (!visit[to]) {
					wi[to] = - wi[fr]*ri[fr]/ri[to];
					que.push(to); visit[to] = true;
				} else {
					if (abs(wi[to]*ri[to] + wi[fr]*ri[fr]) > 1e-4) {
						isMul = false;
					}
				}
			}
		} if (isMul) {printf("-1"); exit(0);}
	}
	
	for (register int i=1; i<=n; ++ i) printf("%.8lf ", wians[i]);
	return 0;
}
