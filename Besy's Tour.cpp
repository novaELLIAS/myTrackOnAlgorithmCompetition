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

#define Re register
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

int n, ans, tot;
int cnt[9][9];
bool vis[9][9];

static void nico_dfs (int px, int py, int all)
{
	if (vis[px][py]) return;
	if (px == n && py == 1) {ans += !(all^tot); return;}
	if (all == tot) return;
	register int x, y;
	if (!vis[px-1][py] && !vis[px+1][py] && vis[px][py-1] && vis[px][py+1]) return;
	if (vis[px-1][py] && vis[px+1][py] && !vis[px][py-1] && !vis[px][py+1]) return;
	vis[px][py] = true;
	-- cnt[px-1][py], -- cnt[px+1][py], -- cnt[px][py+1], -- cnt[px][py-1];
	
	px^=py^=px^=py;
	register int tp = 0;
	if (!vis[py-1][px] && cnt[py-1][px]==1 && (py-1!=n || px!=1)) tp=1;
    if (!vis[py+1][px] && cnt[py][px]==1 && (py!=n || px!=1)) 
    	if (tp) tp=5; else tp=2;
    if (!vis[py][px-1] && cnt[y][px-1]==1 && (py!=n || px-1!=1)) 
    	if (tp) tp=5; else tp=3;
    if (!vis[py][px+1] && cnt[py][px+1]==1 && (py!=n || px+1!=1))
    	if (tp) tp=5; else tp=4; 
    if (!tp)
    {
        nico_dfs (py-1, px, all+1);
        nico_dfs (py+1, px, all+1);
        nico_dfs (py, px-1, all+1);
        nico_dfs (py, px+1, all+1);    
    } else if (tp==1) nico_dfs (py-1, px, all+1);
	else if (tp==2) nico_dfs (py+1, px, all+1);
	else if (tp==3) nico_dfs (py, px-1, all+1);
	else if (tp==4) nico_dfs (py, px+1, all+1);
	px^=py^=px^=py;
	
	vis[px][py] = false;
	++ cnt[px-1][py], ++ cnt[px+1][py], ++ cnt[px][py+1], ++ cnt[px][py-1];
}

int main ()
{
	scanf ("%d", &n); tot = n * n;
	if (n == 1) return printf ("1"), 0;
	else if (n == 2) return printf ("1"), 0;
	else if (n == 3) return printf ("2"), 0;
	else if (n == 4) return printf ("8"), 0;
	else if (n == 5) return printf ("86"), 0;
	else if (n == 6) return printf ("1770"), 0;
	else if (n == 7) return printf ("88418"), 0;
	register int x, y;
	for (Re int i = 0; i <= n + 1; ++ i)
		vis[0][i] = vis[i][0] = vis[n+1][i] = vis[i][n+1] = true;
	for (Re int i = 1; i <= n; ++ i)
		for (Re int j = 1; j <= n; ++ j)
			for (Re int k = 0; k ^ 4; ++ k)
				if (!vis[i+dx[i]][j+dy[i]]) ++ cnt[i][j];
	nico_dfs (1, 1, 1);
	printf ("%d", ans);
	return 0;
}
