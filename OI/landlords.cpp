#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"
//#include "iostream"
#include "ctype.h"
#define rint register int
#define maxn 30
#define cardkind 16
#define cardmax 60

//using namespace std;

inline int read () {
	int x = 0;
	char c = getchar();
	bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}
inline int maxx (int xxx, int yyy) {
	return xxx>yyy? xxx:yyy;
}
inline int minn (int xxx, int yyy) {
	return xxx<yyy? xxx:yyy;
}
const short outmax[4] = {0, 5, 3, 2};
int t, n, ans, x, y, temp;
int table[maxn][maxn][maxn][maxn], now[7];
/*单打 双打 三打 炸*/
int card[cardkind];

inline void init () {
	memset (table, 70, sizeof table);
	table[0][0][0][0] = 1;
	for (rint i = 0; i <= n; i ++) {
		for (rint j = 0; j <= n; j ++) {
			for (rint k = 0; k <= n; k ++) {
				for (rint w = 0; w <= n; w ++) {
					if (i + 2*j + 3*k + 4*w <= n) {
						table[i][j][k][w] = i + j + k + w;
						if (i) table[i][j][k][w] = minn (table[i][j][k][w], table[i-1][j][k][w] + 1);
						/* one */
						if (j) table[i][j][k][w] = minn (table[i][j][k][w], table[i][j-1][k][w] + 1);
						/* double */
						if (k) {
							table[i][j][k][w] = minn (table[i][j][k][w], table[i][j][k-1][w] + 1);
							/* triple */
							if (i) table[i][j][k][w] = minn (table[i][j][k][w], table[i-1][j][k-1][w] + 1);
							/* triple + one */
							if (j) table[i][j][k][w] = minn (table[i][j][k][w], table[i][j-1][k-1][w] + 1);
							/* triple + double */
						}
						if (w) {
							table[i][j][k][w] = minn (table[i][j][k][w], table[i][j][k][w-1] + 1);
							/* boom */
							if (i >= 2) table[i][j][k][w] = minn (table[i][j][k][w], table[i-2][j][k][w] + 1);
							/* boom + double one */
							if (j >= 2) table[i][j][k][w] = minn (table[i][j][k][w], table[i][j-2][k][w] + 1);
							/* boom + double double */
						}
					}
				}
			}
		}
	}
}

inline int king_judge (int aa, int bb, int cc, int dd, int kk) {
	if (kk == 0) return table[aa][bb][cc][dd];
	else if (kk == 1) return table[aa+1][bb][cc][dd];
	else return minn (table[aa][bb][cc][dd] + 1, table[aa+2][bb][cc][dd]);
}

inline void dfs (int ste) {
	if (ste >= ans) return;
	memset (now, 0, sizeof now);
	for (rint i = 2; i <= 14; i ++) now[card[i]] ++;
	temp = ste + king_judge (now[1], now[2], now[3], now[4], card[0]);
	ans = minn (ans, temp);
	register int k;
	for (rint i = 1; i <= 3; i ++) {
		for (rint j = 3; j <= 14; j ++) {
			for (k = j; k <= 14 && card[k] >= i; k ++) {
				card[k] -= i;
				if (k - j >= outmax[i] - 1) dfs (ste + 1);
			}
			k --;
			for (; k >= j; k --) card[k] += i;
		}
	}
}

int main () {
	freopen ("landlords.in", "r", stdin);
	freopen ("landlords.out", "w", stdout);
	
	t = read (), n = read ();
	init ();
	while (t --) {
		memset (card, 0, sizeof card);
		for (rint j = 1; j <= n; j ++) {
			x = read ();read ();
			if (x == 1) x = 14;
			card [x] ++;
		}
		ans = n << 1;
		dfs (0);
		printf ("%d\n", ans);
	}
	return 0;
}
