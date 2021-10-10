#pragma GCC optimzie ("Ofast", 3)

#include <bits/stdc++.h>

using namespace std;

struct node {
	int data, id;
} a[10001];

struct Link {
	int id;
	node *nxt;
} link[10001];

inline bool cmp (node c, node b) {
	return c.data>b.data;
}

signed main () {
	register int n; scanf("%d", &n);
	register int dat;
	for (register int i=0; i^n; ++ i) {
		scanf ("%d", &dat); a[i] = node{dat, i};
	} std::sort(a, a+n, cmp);
	for (register int i=0; i^n; ++ i) printf("%d %d\n", a[i].id, a[i].data);
	for (register int i=0; i^n; ++ i) {
		link[i] = Link{a[i].id, &a[i+1]};
	} return 0;
}
