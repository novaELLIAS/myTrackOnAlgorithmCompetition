#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <stdio.h>
#include <ctype.h>

namespace fastIO {
    const int str=1<<20;
    const char* endl="\n";
    struct Reader {
        char buf[str],*s,*t;
        bool EOF_FLG;
        Reader():s(buf),t(buf),EOF_FLG(false) {};
        inline char gt() {
            return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);
        }
        template<typename T>Reader&operator>>(T&x) {
            if(EOF_FLG)return *this;
            register char c=0,d;
            while(c!=EOF&&!isdigit(c))d=c,c=gt();
            if(c==EOF) {
                EOF_FLG=true;
                return *this;
            } else x=0;
            while(isdigit(c))x=(x<<3)+(x<<1)+c-'0',c=gt();
            if(d=='-')x=-x;
            return *this;
        }
    } cin;
    struct Writer {
        char buf[str],*s,*t;
        Writer():s(buf),t(buf+str) {}
        ~Writer() {
            fwrite(buf,1,s-buf,stdout);
        }
        inline void pt(char c) {
            (s==t)?(fwrite(s=buf,1,str,stdout),*s++=c):(*s++=c);
        }
        template<typename T>Writer&operator<<(T x) {
            if(!x)return pt('0'),*this;
            if(x<0)pt('-'),x=-x;
            register char a[30],t=0;
            while(x)a[t++]=x%10,x/=10;
            while(t--)pt(a[t]+'0');
            return *this;
        }
        Writer&operator<<(const char*s) {
            while(*s)pt(*s++);
            return *this;
        }
    } cout;
}

#define rint register int

class heap {
	#define maxn 1000001
	public:
		int a[maxn], pt;
		inline void push (int x)
		{
			register int now = ++ pt, next = pt >> 1;
			while (next) {
				if (x < a[next]) a[now] = a[next], now = next, next >>= 1;
				else break;
			}
			a[now] = x;
		}
		inline void pop ()
		{
			register int now = 1, next = 2, x = a[pt --];
			while (next <= pt) {
				if (next < pt && a[next|1] < a[next]) next |= 1;
				if (a[next] < x) a[now] = a[next], now = next, next <<= 1;
				else break;
			}
			a[now] = x;
		}
} kiana;

using namespace fastIO;

int main ()
{
	//freopen ("nico.in","r",stdin);
	register int n, x, o;
	cin >> n;
	while (n --) {
		cin >> o;
		if (o == 1) {
			cin >> x; kiana.push(x);
		} else if (o == 2) fastIO::cout << kiana.a[1] << endl;
		else kiana.pop ();
	}
	return 0;
}
