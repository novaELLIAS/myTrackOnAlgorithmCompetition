#pragma GCC optimize ("Ofast")

//#include "iostream"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

//using namespace std;

#define rint register int
#define maxn 2001
#define maxm 2001
#define maxv 301
//#define minn min

inline int getint ()
{
	int x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	return x;
}

inline double getdou ()
{
    double x=0; char ch = getchar ();
    while (!isdigit(ch)) ch = getchar ();
    while (isdigit(ch)) x = x * 10 + (ch-48), ch = getchar ();
    if (ch == '.')
    {
		double s = 0.1;ch = getchar ();
        while (isdigit(ch)) x = x + (ch-48)*s,s/=10,ch = getchar ();
    }
    return x;
}

inline double minn (double AA, double BB) {return AA<BB? AA:BB;}

int n, m, v, e, fro, tow;
int c[maxn], d[maxn];
double k[maxn], dis[maxv][maxv], val;
double dp[maxn][maxm][2], ans = 0x3f3f3f3f;

int main ()
{
	//freopen ("classroom.in", "r", stdin);
	//freopen ("classroom.out", "w", stdout);
	
	n = getint (), m = getint (), v = getint (), e = getint ();
	
	for (rint i = 1; i <= n; i ++) c[i] = getint ();
	for (rint i = 1; i <= n; i ++) d[i] = getint ();
	for (rint i = 1; i <= n; i ++) k[i] = getdou ();
	
	for (rint i = 1; i <= v; i ++) for (rint j = 1; j < i; j ++) dis[j][i] = dis[i][j] = (double) 0x3f3f3f3f;
	for (rint i = 1; i <= n; i ++) for (rint j = 0; j <= m; j ++) dp[i][j][0] = dp[i][j][1] = (double) 0x3f3f3f3f;
	
	for (rint i = 1; i <= e; i ++)
	{
		fro = getint (), tow = getint (), val = getdou ();
		dis[fro][tow] = dis[tow][fro] = minn (dis[fro][tow], val);
	}
	
	for (rint r = 1; r <= v; r ++)
	{
		for (rint i = 1; i <= v; i ++)
		{
			for (rint j = 1; j < i; j ++)
			{
				if (dis[i][r] + dis[r][j] < dis[i][j]) dis[i][j] = dis[j][i] = dis[i][r] + dis[r][j];
			}
		}
	}
	
	dp[1][0][0] = dp[1][1][1] = 0.00;
	for (rint i = 2; i <= n; i ++)
	{
		for (rint j = 0; j <= m && j <= i; j ++)
		{
			dp[i][j][0] = minn (dp[i-1][j][0] + dis[c[i-1]][c[i]],
								dp[i-1][j][1] +
								dis[c[i-1]][c[i]]*(1.0-k[i-1]) + 
								dis[d[i-1]][c[i]]*k[i-1]);
			if (j)
			{
				dp[i][j][1] = minn (dp[i-1][j-1][0] + dis[c[i-1]][d[i]]*k[i] + dis[c[i-1]][c[i]]*(1.0-k[i]),
									dp[i-1][j-1][1] + dis[d[i-1]][d[i]]*k[i]*k[i-1] +
									dis[d[i-1]][c[i]]*k[i-1]*(1.0-k[i]) +
									dis[c[i-1]][d[i]]*(1.0-k[i-1])*k[i] +
									dis[c[i-1]][c[i]]*(1.0-k[i-1])*(1.0-k[i]));
			}
		}
	}
	
	for (rint i = 0; i <= m; i ++) ans = minn (ans, minn (dp[n][i][0], dp[n][i][1]));
	/*
	for (rint i = 0; i <= m; i ++) printf ("dp[n][%d][0]: %.2lf\n", i, dp[n][i][0]);
	for (rint i = 0; i <= m; i ++) printf ("dp[n][%d][1]: %.2lf\n", i, dp[n][i][1]);
	*/
	printf ("%.2lf", ans);
	
	return 0;
}
