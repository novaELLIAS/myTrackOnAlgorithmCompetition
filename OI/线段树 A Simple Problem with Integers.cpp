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

#define root 1,1,n
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define swap(x,y) y^=x^=y^=x
#define maxn 100001 
#define dmax 400001
#define rint register int
#define ll long long

namespace fastIO {
	const int str=1<<20;
	const char* kiana="\n";
	struct Reader {
		char buf[str],*s,*t;
		bool EOF_FLG;
		Reader():s(buf),t(buf),EOF_FLG(false) {};
		inline char gt() {
			return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);
		}
		#define gt() getchar() 
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
		#define pt(c) putchar(c)
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

struct TreeNode {
	int l, r;
	long long sum, add;
} dat[dmax];
long long in;

inline void update (int rt)
{
	dat[rt].sum = dat[rt<<1].sum + dat[rt<<1|1].sum;
}

inline void build (int rt, int l, int r)
{
	dat[rt].l = l, dat[rt].r = r;
	if (l == r) {
		cin >> in; dat[rt].sum = in; return;
	}
	register int mid = (l + r) >> 1;
	build (lson), build (rson);
	update (rt);
}

inline void pushdown (int rt)
{
	if (dat[rt].l == dat[rt].r || !dat[rt].add) return;
	register int ls = rt<<1, rs = rt<<1|1;
	dat[ls].sum += dat[rt].add * (dat[ls].r - dat[ls].l + 1);
	dat[rs].sum += dat[rt].add * (dat[rs].r - dat[rs].l + 1);
	dat[ls].add += dat[rt].add;
	dat[rs].add += dat[rt].add;
	dat[rt].add = 0;
}

inline void change (int rt, int l, int r, long long val)
{
	if (l <= dat[rt].l && dat[rt].r <= r)
	{
		dat[rt].add += val; dat[rt].sum += val * (dat[rt].r - dat[rt].l + 1);
		return;
	}
	pushdown (rt);
	register int mid = (dat[rt].l + dat[rt].r) >> 1;
	if (l <= mid) change (rt<<1, l, r, val);
	if (r >  mid) change (rt<<1|1,l,r, val);
	update (rt);
}

inline long long query (int rt, int l, int r)
{
	if (l <= dat[rt].l && dat[rt].r <= r) return dat[rt].sum;
	pushdown (rt);
	register int mid = (dat[rt].l + dat[rt].r) >> 1;
	return (l<=mid? query (rt<<1, l, r):0) + (r>mid? query (rt<<1|1, l, r):0);
}

int main ()
{
	register int n, m, x, y, v; cin >> n >> m;
	register char c;
	build (1, 1, n);
	while (m --)
	{
		c = 'A';
		while (c != 'Q' && c != 'C') c = getchar();
		cin >> x >> y;
		if (c == 'Q') cout << query (1, x, y) << kiana;
		else cin >> v, change (1, x, y, v);
	}
	return 0;
}
