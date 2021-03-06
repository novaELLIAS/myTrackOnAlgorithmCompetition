#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

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
// optimize switch

#include <bits/stdc++.h>
using namespace std;

const int STR = 1 << 14; int Top; static char buf[1<<14],*p1=buf,*p2=buf;
#define gc() (p1==p2)&&(p2=(p1=buf)+fread(buf,1,STR,stdin),p1==p2)?EOF:*p1++;
#define pt(ch) (Top<STR?buf[Top++]=ch:(fwrite(buf,1,STR,stdout),buf[(Top=0)++]=ch))

class fastio {
//#define gc() getchar ()
	private:
		inline char gc() {
			static char buf[1<<14],*p1=buf,*p2=buf;
			return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
		}
	public:
		inline void getint (int &to) {
			register int x = 0; register char c = gc(); register bool m = 0;
			while (c!='-'&&(c<'0'||c>'9') && c != '-') c = gc();
			if (c == '-') c = gc(), m = 1;
			while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + c - '0', c = gc();
			if (m) return -x; else return x;
		}
		inline void getuint (int &to) {
			int x = 0;
			char c = gc();
			while (!isdigit(c)) c = gc();
			while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
			to = x;
		}
		inline void getdou (double &to) {
			double x=0;
			char ch = getchar ();
			bool m = 0;
			while (!isdigit(ch) && ch != '-') ch = gc ();
			if (ch == '-') ch = gc(), m = 1;
			while (isdigit(ch)) x = x * 10 + (ch-48), ch = gc ();
			if (ch == '.') {
				double s = 0.1;
				ch = gc ();
				while (isdigit(ch)) x = x + (ch-48)*s,s/=10,ch = gc ();
			}
			if (m) to = -x;
			else to = x;
		}
		inline void getudou (double &to) {
			double x=0;
			char ch = gc ();
			while (!isdigit(ch)) ch = gc ();
			while (isdigit(ch)) x = x * 10 + (ch-48), ch = gc ();
			if (ch == '.') {
				double s = 0.1;
				ch = gc ();
				while (isdigit(ch)) x = x + (ch-48)*s,s/=10,ch = gc ();
			}
			to = x;
		}
        inline void write (int x)
        {
	        if (x > 9) write (x / 10);
	        putchar (x % 10 + 48);
        }
} io;

namespace fastIO {
    const int str = 1<<20; const char* kiana = "\n";
    struct Reader {
        char buf[str], *s, *t;
        bool EOF_FLG;
        Reader():s(buf), t(buf), EOF_FLG(false) {};
        inline char gt() {return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);}
        template <typename T> Reader&operator >> (T&x)
		{
            if (EOF_FLG)return *this;
            register char c=0,d;
            while (c != EOF && (!isdigit(c)))d=c,c=gt();
            if(c == EOF) {EOF_FLG=true; return *this;} else x = 0;
            while(isdigit(c)) x = (x<<3) + (x<<1) + c - '0', c = gt();
            if (d == '-') x =- x;
            return *this;
        }
    } cin;
    struct Writer {
        char buf[str],*s,*t;
        Writer():s(buf),t(buf+str) {}
        ~Writer() {fwrite(buf,1,s-buf,stdout);}
        inline void pt(char c) {(s==t)?(fwrite(s=buf,1,str,stdout),*s++=c):(*s++=c);}
        template<typename T>Writer&operator<<(T x)
		{
            if(!x) return pt('0'),*this;
            if(x<0) pt('-'), x = -x;
            register char a[30],t=0;
            while(x)a[t++]=x%10,x/=10;
            while(t--)pt(a[t]+'0');
            return *this;
        }
        Writer&operator<<(const char*s) {while(*s)pt(*s++);return *this;}
    } cout;
}

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
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
static void writelen (int x) {if(x<0)x=-x,putchar('-'); write (x); putchar ('\n');}

int main () {}
