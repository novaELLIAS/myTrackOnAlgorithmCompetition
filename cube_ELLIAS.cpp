#pragma GCC optimize (2)
#pragma G++ optimize (2)
#pragma GCC optimize (3)
#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("inline")
#pragma GCC optimize ("-fgcse")
#pragma GCC optimize ("-fgcse-lm")
#pragma GCC optimize ("-fipa-sra")
#pragma GCC optimize ("-ftree-pre")
#pragma GCC optimize ("-ftree-vrp")
#pragma GCC optimize ("-fpeephole2")
#pragma GCC optimize ("-ffast-math")
#pragma GCC optimize ("-fsched-spec")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("-falign-jumps")
#pragma GCC optimize ("-falign-loops")
#pragma GCC optimize ("-falign-labels")
#pragma GCC optimize ("-fdevirtualize")
#pragma GCC optimize ("-fcaller-saves")
#pragma GCC optimize ("-fcrossjumping")
#pragma GCC optimize ("-fthread-jumps")
#pragma GCC optimize ("-funroll-loops")
#pragma GCC optimize ("-fwhole-program")
#pragma GCC optimize ("-freorder-blocks")
#pragma GCC optimize ("-fschedule-insns")
#pragma GCC optimize ("inline-functions")
#pragma GCC optimize ("-ftree-tail-merge")
#pragma GCC optimize ("-fschedule-insns2")
#pragma GCC optimize ("-fstrict-aliasing")
#pragma GCC optimize ("-fstrict-overflow")
#pragma GCC optimize ("-falign-functions")
#pragma GCC optimize ("-fcse-skip-blocks")
#pragma GCC optimize ("-fcse-follow-jumps")
#pragma GCC optimize ("-fsched-interblock")
#pragma GCC optimize ("-fpartial-inlining")
#pragma GCC optimize ("no-stack-protector")
#pragma GCC optimize ("-freorder-functions")
#pragma GCC optimize ("-findirect-inlining")
#pragma GCC optimize ("-fhoist-adjacent-loads")
#pragma GCC optimize ("-frerun-cse-after-loop")
#pragma GCC optimize ("inline-small-functions")
#pragma GCC optimize ("-finline-small-functions")
#pragma GCC optimize ("-ftree-switch-conversion")
#pragma GCC optimize ("-foptimize-sibling-calls")
#pragma GCC optimize ("-fexpensive-optimizations")
#pragma GCC optimize ("-funsafe-loop-optimizations")
#pragma GCC optimize ("inline-functions-called-once")
#pragma GCC optimize ("-fdelete-null-pointer-checks")
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>

const int ELAS = 1<<14;
static char buf[ELAS], *p1 = buf, *p2 = buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while ((c < '0' || c > '9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (long long x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (long long x) {write (x); putchar ('\n');}

inline const int& min (const int& a, const int& b) {return a<b? a:b;}

#define Re register
#define maxn 101

struct QueNode {
	int val, id;
} que[1000001];

int a, b, c, n;
int dat[maxn][maxn][maxn];
int g[maxn][maxn][maxn];
int f[maxn][maxn][maxn][2];

inline void nico_work (register int p)
{
	register int l = 1, r = 0;
	for (Re int i = 1; i <= a; ++ i)
	{
		for (Re int j = 1; j <= b; ++ j)
		{
			l = 1, r = 0;
			for (Re int k = 1; k <= c; ++ k)
			{
				while (r && r >= l && dat[i][j][k] <= que[r].val) -- r;
				while (l && l <= r && que[l].id <= k - n) ++ l;
				que[++ r].val = dat[i][j][k], que[r].id = k, g[i][j][k] = que[l].val;
			}
		}
	}
		for (Re int k = n; k <= c; ++ k)
		{
			l = 1, r = 0;
			for (Re int j = n; j <= b; ++ j)
			{
				while (r && r >= l && g[i][j][k] <= que[r].val) -- r;
				while (l && l <= r && que[l].id <= k - n) ++ l;
				que[++ r].val = g[i][j][k], que[r].id = k, f[i][j][k][p] = que[l].val;
			}
		}
	
	
	for (Re int j = 1; j <= b; ++ j)
	{
		for (Re int i = 1; i <= a; ++ i)
		{
			l = 1, r = 0;
			for (Re int k = 1; k <= c; ++ k)
			{
				while (r && r >= l && dat[i][j][k] <= que[r].val) -- r;
				while (l && l <= r && que[l].id <= k - n) ++ l;
				que[++ r].val = dat[i][j][k], que[r].id = k, g[i][j][k] = que[l].val;
			}
		}
		for (Re int k = n; k <= c; ++ k)
		{
			l = 1, r = 0;
			for (Re int i = n; i <= a; ++ i)
			{
				while (r && r >= l && g[i][j][k] <= que[r].val) -- r;
				while (l && l <= r && que[l].id <= k - n) ++ l;
				que[++ r].val = g[i][j][k], que[r].id = k, f[i][j][k][p] = que[l].val;
			}
		}
	}
}

{
    for (int j=1;j<=i_wide;j++)
    {
        int l=1,r=0;
        for (int i=1;i<=i_long;i++)
        {
            while (r&&r>=l&&t[i][j]<=q[r].i_value) r--;
            while (l&&l<=r&&q[l].p<=i-i_side) l++;
            
            q[++r].i_value=t[i][j];
            q[r].p=i;
            g[i][j]=q[l].i_value;
        }
    }
    for (int i=i_side;i<=i_long;i++)
    {
        int l=1,r=0;
        for (int j=1;j<=i_wide;j++)
        {
            while (r&&r>=l&&g[i][j]<=q[r].i_value) r--;
            while (l&&l<=r&&q[l].p<=j-i_side) l++;
            
            q[++r].i_value=g[i][j];
            q[r].p=j;
            f[i][j][k]=q[l].i_value;
        }
    }
}

inline void nico_read ()
{
	a = read (), b = read (), c = read (), n = read ();
	for (Re int i = 1; i <= a; ++ i)
	{
		for (Re int j = 1; j <= b; ++ j)
		{
			for (Re int k = 1; k <= c; ++ k) dat[i][j][k] = read ();
		}
	}
}

inline void nico_chan ()
{
	for (Re int i = 1; i <= a; ++ i)
	{
		for (Re int j = 1; j <= b; ++ j)
		{
			for (Re int k = 1; k <= c; ++ k) dat[i][j][k] = -dat[i][j][k];
		}
	}
}

inline void nico_geta ()
{
	register int ans = 0x3f3f3f3f;
	for (Re int i = 1; i <= a; ++ i)
	{
		for (Re int j = 1; j <= b; ++ j)
		{
			for (Re int k = 1; k <= c; ++ k)
			{
				ans = min (ans, -f[i][j][k][1] - f[i][j][k][0]);
			}
		}
	}
	printf ("%d", ans);
}

int main ()
{
	//freopen ("cube.in", "r", stdin);
	//freopen ("cube.out","w",stdout);
	
	nico_read ( );
	nico_work (0);
	nico_chan ( );
	nico_work (1);
	nico_geta ( );
	return 0;
}
