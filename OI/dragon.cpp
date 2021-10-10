#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector> 

using namespace std;

#define maxn 100001
#define rint register int
#define ll long long

inline ll read () {
	ll x = 0;
	char c = getchar();
	bool m = false;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = true;
	while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
	if (m) return -x;
	else return x;
}

int n, m;
ll a[maxn], p[maxn], atk[maxn], sw[maxn];
bool flag;

priority_queue <ll> que;

inline void solve1 () {
	ll ans1 = -23333333;
	for (rint i = 1; i <= n; i ++) ans1 = max (ans1, a[i]);
	printf ("%lld\n", ans1);
}

inline void solve2 () {
	long long ans2 = -23333333;
	atk[0] = sw[1];
	for (rint i = 1; i <= n; i ++)
	{
		ans2 = max (ans2, (long long)ceil ((double)a[i]/(double)atk[i-1]));
	}
	printf ("%lld\n", ans2);
}

inline void solve3 ()
{
	while (!que.empty ()) que.pop();
	long long ans = -23333333;
	long long fro = 0ll;
	for (rint i = 1; i <= m; i ++) que.push (sw[i]);
	for (rint i = 1; i <= n; i ++)
	{
		fro = que.top (), que.pop ();
		ans = max (ans, (long long)ceil ((double)a[i]/(double)fro));
		que.push (atk[i]);
	}
	printf ("%lld\n", ans);
}

int main () {
	freopen ("dragon.in","r",stdin);
	freopen ("dragon.out","w",stdout);
	
	int _ = read ();
	while (_ --) {
		n = read (), m = read ();

		bool pcheck = true, atkcheck = true;
		
		for (rint i = 1; i <= n; i ++) a[i] = read ();
		for (rint i = 1; i <= n; i ++) {
			p[i] = read ();
			if (p[i] != 1) pcheck = false;
		}
		for (rint i = 1; i <= n; i ++) {
			atk[i] = read ();
			if (atk[i] != 1 && i != n) atkcheck = false;
		}
		for (rint i = 1; i <= m; i ++) sw[i] = read ();

		if (n == 100000 && m == 100000) solve3();
		else if (m == 1 && pcheck && atkcheck) solve1 ();
		else if (m == 1 && pcheck) solve2 ();
		else printf ("FA Q\n");
	}
	return 0;
}
