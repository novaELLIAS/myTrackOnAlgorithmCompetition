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
    const int str = 1<<20; const char* kiana = "\n";
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

#define maxn 100001
#define dmax 400001
#define rint register int
#define ll long long

int n, m;
long long modn, in;

inline long long mod (long long x)
{
	if (x < modn) return x;
	return x - (modn * (x / modn));
}

struct node {
	int l, r;
	long long val, add, mul;
} dat[dmax];

#define lson root<<1, l, mid
#define rson root<<1|1, mid+1, r

inline long long nico_build (int root, int l, int r)
{
	dat[root] = (node) {l, r, 0, 0, 1};
	if (l == r) {
		cin >> in; return dat[root].val = mod (in);
	}
	register int mid = (l + r) >> 1;
	return dat[root].val = mod(nico_build(lson)+nico_build(rson));
}

#undef lson
#undef rson

inline void pushdown (int rt)
{
	if (dat[rt].l == dat[rt].r || (!dat[rt].add && dat[rt].mul == 1)) return;
	register int ls = rt<<1, rs = rt<<1|1;
	dat[ls].add = mod (dat[rt].add + dat[ls].add * dat[rt].mul);
	dat[rs].add = mod (dat[rt].add + dat[rs].add * dat[rt].mul);
	dat[ls].mul = mod (dat[rt].mul * dat[ls].mul);
	dat[rs].mul = mod (dat[rt].mul * dat[rs].mul);
	dat[ls].val = mod (dat[ls].val * dat[rt].mul + dat[rt].add * (dat[ls].r - dat[ls].l + 1));
	dat[rs].val = mod (dat[rs].val * dat[rt].mul + dat[rt].add * (dat[rs].r - dat[rs].l + 1));
	dat[rt].add = 0, dat[rt].mul = 1;
}

inline void update (int rt, bool opt, int l, int r, long long val)
{
	pushdown (rt);
	if (opt) {
		if (l <= dat[rt].l && dat[rt].r <= r) {
			dat[rt].add = val;
			dat[rt].val = mod (dat[rt].val + dat[rt].add * (dat[rt].r - dat[rt].l + 1));
			return;
		}
	} else {
		if (l <= dat[rt].l && dat[rt].r <= r) {
			dat[rt].mul = val;
			dat[rt].add = mod (dat[rt].add * val);
			dat[rt].val = mod (dat[rt].val * val);
			return;
		}
	}
	register int mid = (dat[rt].l + dat[rt].r) >> 1;
	if (l <= mid) update (rt << 1, opt, l, r, val);
	if (r >  mid) update (rt<<1|1, opt, l, r, val);
	dat[rt].val = mod (dat[rt<<1].val + dat[rt<<1|1].val);
}

inline long long query (int rt, int l, int r)
{
	pushdown (rt);
	if (l <= dat[rt].l && dat[rt].r <= r) return dat[rt].val;
	register int mid = (dat[rt].l + dat[rt].r) >> 1;
	return mod ((l<=mid? query (rt<<1, l, r):0) + (r>mid? query (rt<<1|1, l, r):0));
}

int main ()
{
	register int m, x, y;
	register long long v;
	register short opt;
	cin >> n >> modn;
	nico_build (1, 1, n);
	cin >> m;
	while (m --) {
		cin >> opt >> x >> y;
		if (opt == 3) cout << query (1, x, y) << kiana;
		else cin >> v, update (1, opt - 1, x, y, mod (v));
	}
	return 0;
}
