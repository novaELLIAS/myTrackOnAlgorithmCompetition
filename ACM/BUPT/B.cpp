#include <cstdio>

signed main () {
	register int n, m;
	scanf ("%d %d", &n, &m);
	if (!(n%2) && !(m%2)) return printf("NO"), 0;
	printf("YES\n");
	if (n%2) {
		for (int i=2; i<=m; ++ i) printf("%d %d\n", 1, i);
		bool flag = false;
		// false: r->l
		for (int i=2; i<n; ++ i) {
			for (int j=1; j<=m; ++ j) {
				printf("%d %d\n", i, flag? j:(m-j+1));
			} flag = !flag;
		}
		for (int i=1; i<m; ++ i) printf("%d %d\n", n, i);
	} else {
		for (int i=2; i<=n; ++ i) printf("%d %d\n", i, 1);
		bool flag = false;
		// false: d->u
		for (int i=2; i<m; ++ i) {
			for (int j=1; j<=n; ++ j) {
				printf("%d %d\n", flag? j:(n-j+1), i);
			} flag = !flag;
		}
		for (int i=1; i<n; ++ i) printf("%d %d\n", i, m);
	} return 0;
}
