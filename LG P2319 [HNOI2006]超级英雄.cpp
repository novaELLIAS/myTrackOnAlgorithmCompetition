#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <vector>

using namespace std;

class nico {
	#define maxn 1002
	#define maxm 1002
	#define rint register int
	private:
		int n, m, ans, mat[maxn], x, y, out[maxn];
		vector <int> e[maxn];
		bool vis[maxn];
		
		inline char gc()
		{
    		static char buf[1<<14],*p1=buf,*p2=buf;
    		return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
		}
		
		inline int read ()
		{
	    	int x = 0;char c = gc();bool m = 0;
    		while (!isdigit(c) && c != '-') c = gc();
   			if (c == '-') c = gc(), m = 1;
    		while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
    		if (m) return -x;
    		else return x;
		}
		
		inline bool hungry (int x)
		{
			int to;
			for (rint i = e[x].size()-1; i >= 0; i --)
			{
				to = e[x][i];
				if (vis[to]) continue;
				vis[to] = true;
				if (!mat[to] || hungry (mat[to]))
				{
					mat[to] = x, out[x] = to;
					return true;
				}
			}
			return false;
		}
	#undef maxn
	#undef maxm
	public:
		inline void input ()
		{
			n = read (), m = read ();
			for (rint i = 1; i <= m; i ++)
			{
				e[i].push_back(read()), e[i].push_back(read());
			}
		}
		
		inline void query ()
		{
			for (rint i = 1; i <= m; i ++)
			{
				memset (vis, 0, sizeof vis);
				if (hungry(i)) ans ++;
				else break;
			}
		}
		
		inline void ouput ()
		{
			printf ("%d\n", ans);
			for (rint i = 1; i <= ans; i ++) printf ("%d\n", out[i]);
		}
	#undef rint
} kiana;

int main ()
{
	kiana.input ();
	kiana.query ();
	kiana.ouput ();
	return 0;
}
