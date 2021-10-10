#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>
#include <queue>

using namespace std;

class fastio {
#define gc() getchar ()
/*	private:
		inline char gc() {
			static char buf[1<<14],*p1=buf,*p2=buf;
			return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
		}
*/	public:
		inline void getint (int &to) {
			int x = 0;char c = gc();bool m = 0;
			while (!isdigit(c) && c != '-') c = gc();
			if (c == '-') c = gc(), m = 1;
			while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
			if (m) to = -x;
			else to = x;
		}
} io;

class niconi {
	#define rint register int
	#define maxa 1001
	#define maxn 101
	private:
		
		inline int maxx (int aa, int bb) {return aa>bb? aa:bb;}
		inline int minn (int aa, int bb) {return aa<bb? aa:bb;}
		int a, b, n, ans;
		int mapp[maxa][maxa];
		struct node {
			
		};
	#undef maxa
	#undef maxn
	public:
		inline void init ()
		{
			io.getint(a), io.getint(b), io.getint(n);
			for (rint i = 1; i <= a; i ++)
			{
				for (rint j = 1; j <= b; j ++) io.getint(mapp[i][j]);
			}
			
		}
	#undef rint
} kiana;

int main ()
{
	
	return 0;
}
