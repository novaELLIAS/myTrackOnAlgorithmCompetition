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
#include <algorithm>

#define dmax 800001
#define maxn 200001
#define rint register int

namespace fastIO {
    const int str = 1<<20; const char* endl = "\n";
    struct Reader {
        char buf[str], *s, *t;
        bool EOF_FLG;
        Reader():s(buf), t(buf), EOF_FLG(false) {};
        inline char gt() {
            return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);
        }
        template <typename T> Reader&operator >> (T&x) {
            if (EOF_FLG)return *this;
            register char c=0,d;
            while (c != EOF && (!isdigit(c)))d=c,c=gt();
            if(c == EOF) {
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

using namespace fastIO;
using namespace std;

struct node {
	int l, r, dat;
} tr[dmax];

struct asks {
	int l, r, nam;
} qu[maxn];

inline bool cmp (asks aa, asks bb) {return aa.l<bb.l;}

int n, m, cnt;
int next[maxn], last[maxn], data[maxn], anss[maxn], in[maxn];
bool mark[maxn];

#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define inff 0x3f3f3f3f

inline void build (int rt, int l, int r)
{
	tr[rt].l = l, tr[rt].r = r;
	if (l == r) {
		tr[rt].dat = in[l]; return;
	}
	tr[rt].dat = inff;
	static int mid = (l+r)>>1;
	build(lson); build(rson);
}

int main ()
{
	fastIO::cin >> n >> m;
	for (rint i = 1; i <= n; i ++) fastIO::cin >> data[i];
	for (rint i = 1; i <= n; i ++) {
		mark[data[i]] = true;
		while (mark[cnt]) cnt ++;
		in[i] = cnt;
	}
	build(1, 1, n);
	for (rint i = n; i >= 1; i --) {
		next[i] = last[data[i]];
		last[a[i]] = i;
	}
	for (rint i = 1; i <= m; i ++) {
		fastIO::cin >> qu[i].l >> qu[i].r;
		qu[i].nam = i;
	}
	std::sort(qu+1, qu+m+1, cmp);
	for (rint i = 1; i <= m; i ++) {
		while ()
	}
	F(i,1,m) {
		while (now<b[i].l) {
			if (!next[now]) next[now]=n+1;
			change(1,now,next[now]-1,a[now]);
			now++;
		}
		ans[b[i].num]=query(1,b[i].r);
	}
}
