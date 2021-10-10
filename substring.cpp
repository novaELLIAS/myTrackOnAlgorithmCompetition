#pragma GCC optimize ("Ofast")

#include <stdio.h>
#include <ctype.h>

inline int read () {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

#define maxn 1001
#define maxm 201
#define rint register int
#define modn 1000000007

int n, m, K;
bool pos, ex;
char a[maxn], b[maxm];
int dp[2][maxm][maxm][2];

int main ()
{
	freopen ("substring.in","r",stdin);
	freopen ("substring.out","w",stdout);
	
	n = read (), m = read (), K = read ();
	scanf ("%s%s", a+1, b+1);
	dp[0][0][0][0] = dp[1][0][0][0] = 1;
	for (rint i = 1; i <= n; i ++)
	{
		pos = i&1, ex = !pos;
		for (rint j = 1; j <= i && j <= m; j ++)
		{
			for (rint k = 1; k <= j && k <= K; k ++)
			{
				dp[pos][j][k][0] = (dp[ex][j][k][0] + dp[ex][j][k][1]) % modn;
				if (a[i] == b[j])
				{
					dp[pos][j][k][1] = (dp[ex][j-1][k][1]) % modn; // combo continue
					dp[pos][j][k][1] = (dp[pos][j][k][1] + dp[ex][j-1][k-1][1]) % modn; // new trem
					dp[pos][j][k][1] = (dp[pos][j][k][1] + dp[ex][j-1][k-1][0]) % modn; // last no
				} else {
					dp[pos][j][k][1] = 0;
				}
			}
		}
	}

	printf ("%d", (dp[n&1][m][K][0] + dp[n&1][m][K][1]) % modn);
	return 0;
}
