#pragma G++ optimize ("Ofast", 3)

#include <cstdio>

using namespace std;

inline char gc()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while (c!='-'&&(c<'0'||c>'9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {write (x); putchar ('\n');}

inline const int& max (const int& a, const int& b) {return a>b? a:b;}

#define Re register

int dp[2][4][2];

int main ()
{
	freopen ("jx.in", "r", stdin);
	freopen ("jx.out","w",stdout);
	
	register int n = read () + 1, x, las = 1, now = 0;
	for (Re int i = 1; i ^ n; ++ i)
	{
		x = read (), las = !las, now = !now;
		/****************************************************/
		dp[now][1][0] = max (dp[las][1][0], dp[las][1][1]);
		dp[now][1][1] = max (0, dp[las][1][1]) + x;
		/****************************************************/
    	if (i >= 2)
    	{
    		dp[now][2][0] = max (dp[las][2][0], dp[las][2][1]);
    		dp[now][2][1] = max (dp[las][2][1], max (dp[las][1][1], dp[las][1][0])) + x;
		}
		/****************************************************/
    	if (i >= 3)
    	{
    		dp[now][3][0] = max (dp[las][3][0], dp[las][3][1]);
    		dp[now][3][1] = max (dp[las][3][1], max (dp[las][2][1], dp[las][2][0])) + x;
		}
	}
	write (max (dp[now][3][1], dp[now][3][0]));
}
