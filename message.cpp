#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "ctype.h"

#define maxn 200001
#define rint register int

inline int read () {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

inline int minn (int xxx, int yyy) {
	return xxx<yyy? xxx:yyy;
}

int n, t, to[maxn], de[maxn], ans = 0x7777777, cnt;
bool ni[maxn];

int main () {
	freopen ("message.in", "r", stdin);
	freopen ("message.out", "w", stdout);
	
	n = read ();
	for (rint i = 1; i <= n; i ++) to[i] = read (), de[to[i]] ++;

	for (rint i = 1; i <= n; i ++) if (!ni[i] && !de[i]) for (rint j = i; !ni[j] && !de[j]; ni[j] = true, de[to[j]] --, j = to[j]);

	register int j;
	for (rint i = 1; i <= n; i ++) if (!ni[i]) {
			for (j = to[i], ni[i] = true, cnt = 1; j != i; ni[j] = true, cnt ++, j = to[j]);
			ans = minn (ans, cnt);
		}

	printf ("%d", ans);
	return 0;
}
