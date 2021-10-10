#pragma GCC optimize ("Ofast")

#include <stdio.h>

const int mapp[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int n, na, nb, ansa, ansb;
int a[200], b[200];

inline int read () {
	int sign = 1, n = 0;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') sign = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		n = (n*10) + c-'0';
		c = getchar();
	}
	return sign*n;
}

int main () {
	freopen ("rps.in", "r", stdin);
	freopen ("rps.out", "w", stdout);
	n = read (), na = read (), nb = read ();
	for (int i = 0; i < na; i ++) a[i] = read ();
	for (int i = 0; i < nb; i ++) b[i] = read ();
	for (int i = 0; i < n; i ++) {
		ansa += mapp[a[i%na]][b[i%nb]];
		ansb += mapp[b[i%nb]][a[i%na]];
	}
	printf ("%d %d", ansa, ansb);
	return 0;
}
