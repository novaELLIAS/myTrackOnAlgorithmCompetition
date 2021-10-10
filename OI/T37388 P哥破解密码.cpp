#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma G++ target ("avx","sse2")
#pragma GCC target ("avx","sse2")

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define maxn 3
#define modn 19260817
#define rint register int
typedef long long ll;

int n, m;

struct niconi {
	ll d[maxn][maxn];
	int x,y;
	niconi (int xx=0,int yy=0):x(xx),y(yy) {
		memset(d, 0, sizeof d);
	}
	ll* operator [] (int i) {
		return d[i];
	}
	niconi operator *(niconi& a) {
		niconi r(y,a.x);
		for(int i=0; i<y; ++i)
			for(int j=0; j<a.x; ++j)
				for(int k=0; k<x; ++k) r[i][j] = (r[i][j] + d[i][k] * a[k][j]) % modn;
		return r;
	}
	niconi operator *=(niconi& a) {
		return *this=*this*a;
	}
} a(3,3), b(3,3);

inline char gc() {
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}

//#define gc() getchar ()
inline int read () {
	int x = 0;
	char c = gc();
	bool m = 0;
	while (!isdigit(c) && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	if (m) return -x;
	else return x;
}

class nico {
	private:


		inline niconi poww (niconi a,ll t) {
			niconi r(a.x,a.x);
			for(int i=0; i<r.x; ++i)r[i][i]=1;
			while(t) {
				if(t&1)r*=a;
				a *= a,t >>= 1;
			}
			return r;
		}
	public:
		inline void init () {
			b[0][1] = b[0][2] = b[1][0] = b[2][1] = b[0][0] = 1ll;
			b[1][1] = b[1][2] = b[2][0] = b[2][2] = 0;
		}
		inline void ouput () {
			a = poww (b, n + 2);
			printf ("%d\n", a[0][2]);
		}
} kiana;

int main() {
	m = read ();
	kiana.init ();
	while (m --) {
		n = read ();
		kiana.ouput ();
	}
	return 0;
}
