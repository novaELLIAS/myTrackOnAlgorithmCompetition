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
#include <vector>

using namespace std;

namespace fastIO {
    const int str = 1<<20; const char* kiana = "\n";
    struct Reader {
        char buf[str], *s, *t;
        bool EOF_FLG;
        Reader():s(buf), t(buf), EOF_FLG(false) {};
        inline char gt() {
            return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);
        }
        #define gt() getchar()
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
        #define pt(c) putchar (c)
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
#define swap(x,y) y^=x^=y^=x

struct node {
	int l, r;
	int sum, max;
}dat[dmax];

int fa[maxn], id[maxn], son[maxn], dep[maxn], siz[maxn], top[maxn];
int twei[maxn], wei[maxn], id_cnt;
int modn, root;
char in[11]; 
std::vector <int> e[maxn];

inline const int& max (const int& a, const int& b) {return a>b? a:b;}

inline void dfs1 (int pt, int fath, int deep)
{
	dep[pt] = deep, fa[pt] = fath, siz[pt] = 1;
	register int maxx = -1, to;
	for (rint i = e[pt].size()-1; i >= 0; i --)
	{
		to = e[pt][i];
		if (to == fath) continue;
		dfs1 (to, pt, deep + 1);
		siz[pt] += siz[to];
		if (siz[to] > maxx) maxx = siz[to], son[pt] = to;
	}
}

inline void dfs2 (int pt, int fr)
{
	id[pt] = ++ id_cnt, wei[id_cnt] = twei[pt], top[pt] = fr;
	if (!son[pt]) return;
	dfs2 (son[pt], fr);
	register int to;
	for (rint i = e[pt].size()-1; i >= 0; i --)
	{
		to = e[pt][i];
		if (to == fa[pt] || to == son[pt]) continue;
		dfs2 (to, to);
	}
}

inline void build (int rt, int l, int r)
{
	dat[rt].l = l, dat[rt].r = r;
	if (l == r) {dat[rt].sum = dat[rt].max =  wei[l]; return;}
	register int mid = (l + r) >> 1;
	build (rt<<1, l, mid); build (rt<<1|1, mid+1, r);
	dat[rt].sum = (dat[rt<<1].sum + dat[rt<<1|1].sum);
	dat[rt].max = max (dat[rt<<1].max, dat[rt<<1|1].max);
}

inline void update (int rt, int ql, int qr, int val)
{
	if (dat[rt].l > qr || dat[rt].r < ql) return;
	if (dat[rt].l == dat[rt].r) {dat[rt].max = dat[rt].sum = val; return;}
	update (rt<<1, ql, qr, val); update (rt<<1|1, ql, qr, val);
	dat[rt].sum = dat[rt<<1].sum + dat[rt<<1|1].sum;
	dat[rt].max = max (dat[rt<<1].max, dat[rt<<1|1].max);
}

inline int tree_query (int rt, int ql, int qr)
{
	if (ql <= dat[rt].l && dat[rt].r <= qr) return dat[rt].sum;
	register int mid = (dat[rt].l + dat[rt].r) >> 1, ret = 0;
	if (ql <= mid) ret =  tree_query (rt<<1, ql, qr);
	if (qr >  mid) ret += tree_query (rt<<1|1,ql,qr);
	return ret;
}

inline int tree_max_query (int rt, int ql, int qr)
{
	if (ql <= dat[rt].l && dat[rt].r <= qr) return dat[rt].max;
	register int mid = (dat[rt].l + dat[rt].r) >> 1, ret = -0x3f3f3f3f;
	if (ql <= mid) ret = max (ret, tree_max_query (rt<<1, ql, qr));
	if (qr >  mid) ret = max (ret, tree_max_query (rt<<1|1, ql, qr));
	return ret;
}

inline int range_query (int x, int y)
{
	register int ret = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap (x, y);
		ret = (ret + tree_query (1, id[top[x]], id[x]));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap (x, y);
	return (ret + tree_query (1, id[x], id[y]));
}

inline int range_max_query (int x, int y)
{
	register int ret = -0x3f3f3f3f;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap (x, y);
		ret = max (ret, tree_max_query (1, id[top[x]], id[x]));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap (x, y);
	return max (ret, tree_max_query (1, id[x], id[y]));
}

int main ()
{
	register int n, m;
	cin >> n;
	register int x, y;
	for (rint i = 1; i <  n; i ++)
	{
		cin >> x >> y;
		e[x].push_back (y), e[y].push_back (x);
	}
	for (rint i = 1; i <= n; i ++) cin >> twei[i];//puts ("nicocheck");
	dfs1 (1, 0, 1); dfs2 (1, 1);
	
	build (1, 1, n);
	register int z, opt;
	cin >> m;
	while (m --)
	{
		scanf ("%s", in);
		cin >> x;
		/*
		if (opt == 1) cin >> y >> z, range_update (x, y, z);
		else if (opt == 2) cin >> y, cout << range_query (x, y) << kiana;
		else if (opt == 3) cin >> y, son_update (x, y);
		else cout << son_query (x) << kiana;
		*/
		if (in[0] == 'C') cin >> y, update (1, id[x], id[x], y);
		else if (in[1] == 'S') cin >> y, cout << range_query (x, y) << kiana;
		else cin >> y, cout << range_max_query (x, y) << kiana;
	}
	return 0;
}
