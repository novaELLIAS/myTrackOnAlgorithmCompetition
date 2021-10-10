#include "stdio.h"
#include "string.h"
#include "iostream"
#include "queue"
#include "vector"

#define rint register int
#define maxn 200011
#define maxm 400011

using namespace std;

inline short read () {
	short sign = 1, n = 0;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') sign = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') n = ((n<<1)+(n<<3)) + c^'0',c = getchar();
	return sign*n;
}

struct dij {
	int val, name;
	bool operator < (const dij &x) const {
		return val > x.val;
	}
};

int dis [maxn];
bool vis[maxn];
priority_queue <dij> nico;

struct node {
	int to, w, hai;
};

bool dfscheck, descheck;
int dfscnt;
int n, m, q, k, s, vv, pp, v, p, ans, aa, bb;
vector <node> e[maxn];

inline void dijstra (int sta) {
	while (!nico.empty())nico.pop();
	memset (dis, 127/3, sizeof dis);
	memset (vis, 0, sizeof vis);
	nico.push((dij) {
		0, sta
	});
	dis[sta] = 0;
	int fro, size, to, va;
	while (!nico.empty()) {
		fro = nico.top().name;
		nico.pop();
		if (vis[fro]) continue;
		vis[fro] = true;
		size = e[fro].size ();
		for (rint i = 0; i < size; i ++) {
			to = e[fro][i].to;
			va = e[fro][i].w;
			if (!vis[to] && dis[fro] + va < dis[to]) {
				dis[to] = dis[fro] + va;
				nico.push((dij) {
					dis[to], to
				});
			}
		}
	}
	ans = dis[1];
}

inline void work1 () {
	if (p == 0) {
		ans = 0;
		return;
	} else dijstra (v);
}

inline void work2_1 (int sta/*, int ste, bool water*/,int fa,int cnt,bool fla) {
	//puts ("work2check");
	//printf ("%d %d %d %d %d \n", sta, fa, cnt, fla, dfscheck);
	
	if (dfscheck) return;
	for (rint i = 0; i < e[sta].size (); i ++) {
		if (e[sta][i].to == fa) continue;//printf ("%d\n", e[sta][i].hai);
		if(e[sta][i].hai <= p) fla = true;
		if (fla) cnt += e[sta][i].w;
		if (e[sta][i].to == 1)
		{
			dfscheck = true;
			ans = cnt;
			return;
		}
		work2_1 (e[sta][i].to, sta, cnt, fla);
	}
}

inline void work2 () {
	//puts ("work2check");
	//if (q == 2000) {
		dfscheck = false;
		//ans = 999999999;
		work2_1 (v,0,0,false);
	//}

	//else work2_2 ();
}

int main () {
	freopen ("return.in", "r", stdin);
	freopen ("return.out", "w", stdout);
	
	int _ /*= read ()*/;
	scanf ("%d", &_);
	while (_--) {
		ans = 0;
		//n = read (); m = read ();
		scanf ("%d %d", &n, &m);
		for(rint i =1; i <=m; i++) {
			scanf ("%d %d %d %d", &vv, &pp,&aa, &bb);
			//vv=read();pp=read();aa=read();bb=read();
			if (vv !=pp) {
				e[vv].push_back ((node) {
					pp, aa, bb
				});
				e[pp].push_back ((node) {
					vv, aa, bb
				});
			}
		}
		scanf ("%d %d %d", &q, &k, &s);
		//q = read (); k = read (); s = read ();
		if (!q) continue;
		while (q--) {
			scanf("%d %d", &vv, &pp);
			//vv = read (); pp = read ();
			v = ((vv + (k*ans)-1) % n) + 1;
			
			if (v==1) {
				puts ("0");
				continue;
			}
			p = (pp + (k*ans))%(s+1);//printf ("||||||%d|||||\n", p);
			if (m == n-1) work2 ();
			else work1 ();
			printf ("%d\n", ans);
		}
	}
	return 0;
}
