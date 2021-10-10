/*#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")
*/ 
#include <stdio.h>
#include <ctype.h>
#include <vector>

using namespace std;
/*
namespace fastIO {
    const int str = 1<<20; const char* kiana = "\n";
    struct Reader {
        char buf[str], *s, *t;
        bool EOF_FLG;
        Reader():s(buf), t(buf), EOF_FLG(false) {};
        inline char gt() {
            return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);
        }
        //#define gt() getchar()
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
*/
//using namespace fastIO;

#define maxn 100101
#define dmax 400101

#define rint register int
#define swap(x,y) y^=x^=y^=x

struct node {
	int l, r;
	long long sum, laz;
} dat[dmax];

long long fa[maxn], id[maxn], son[maxn], dep[maxn], siz[maxn], top[maxn];
long long twei[maxn], wei[maxn], id_cnt;
std::vector <int> e[maxn];
//
int cnt = 0;
//
void dfs1 (int pt)
{
	siz[pt] = 1;
	int maxx = -1, to;
	for (int i = e[pt].size() - 1; i >= 0; i --)
	{
		to = e[pt][i];
		if (dep[to]) continue;
		dep[to] = dep[pt] + 1, fa[to] = pt;
		dfs1 (to);
		siz[pt] += siz[to];
		if (siz[to] > maxx) maxx = siz[to], son[pt] = to;
	}
	//cout << "--niconi " << pt  << " niconi " << ++ cnt << kiana;
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
	if (l == r) {dat[rt].sum = wei[l]; return;}
	register int mid = (l + r) >> 1;
	build (rt<<1, l, mid); build (rt<<1|1, mid+1, r);
	dat[rt].sum = (dat[rt<<1].sum + dat[rt<<1|1].sum);
}

#define lson rt<<1
#define rson rt<<1|1

inline void pushdown (int rt)
{
	if (!dat[rt].laz || dat[rt].l == dat[rt].r) return;
	dat[lson].laz = (dat[lson].laz + dat[rt].laz);
	dat[rson].laz = (dat[rson].laz + dat[rt].laz);
	dat[lson].sum = (dat[lson].sum + dat[rt].laz * (dat[lson].r - dat[lson].l + 1));
	dat[rson].sum = (dat[rson].sum + dat[rt].laz * (dat[rson].r - dat[rson].l + 1));
	dat[rt].laz = 0;
}

#undef lson
#undef rson

inline void update (int rt, int ql, int qr, int val)
{
	if (ql <= dat[rt].l && dat[rt].r <= qr)
	{
		dat[rt].laz = (dat[rt].laz + val);
		dat[rt].sum = (dat[rt].sum + val * (dat[rt].r - dat[rt].l + 1));
		return;
	}
	pushdown (rt); register int mid = (dat[rt].l + dat[rt].r) >> 1;
	if (ql <= mid) update (rt<<1, ql, qr, val);
	if (qr >  mid) update (rt<<1|1,ql,qr, val);
	dat[rt].sum = (dat[rt<<1].sum + dat[rt<<1|1].sum);
}

inline long long tree_query (int rt, int ql, int qr)
{
	if (ql <= dat[rt].l && dat[rt].r <= qr) return dat[rt].sum;
	pushdown (rt);
	register int mid = (dat[rt].l + dat[rt].r) >> 1;
	register long long ret = 0ll;
	if (ql <= mid) ret =  tree_query (rt<<1, ql, qr);
	if (qr >  mid) ret += tree_query (rt<<1|1,ql,qr);
	return ret;
}

inline long long range_query (int x, int y)
{
	register long long ret = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap (x, y);
		ret = (ret + tree_query (1, id[top[x]], id[x]));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap (x, y);
	return (ret + tree_query (1, id[x], id[y]));
}

inline void range_update (int x, int y, int val)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap (x, y);
		update (1, id[top[x]], id[x], val);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap (x, y);
	update (1, id[x], id[y], val);
}

inline long long son_query (int rt) {return tree_query (1, id[rt], id[rt] + siz[rt] - 1);}

inline void son_update (int rt, int val) {update (1, id[rt], id[rt] + siz[rt] - 1, val);}

int main ()
{
	freopen ("nico.in","r",stdin);
	freopen ("nico.out","w",stdout);
	register int n, m;
	//cin >> n >> m;
	scanf ("%d %d", &n, &m);
	for (rint i = 1; i <= n; i ++) scanf ("%lld", &twei[i]);//cin >> twei[i];
	//puts ("niconi 1");
	register int x, y;
	for (rint i = 1; i <  n; i ++)
	{
		scanf ("%d %d", &x, &y);
		//cin >> x >> y;
		e[x].push_back (y), e[y].push_back (x);
	}
	//puts ("niconi addedge");
	dep[1]=1;
	dfs1 (1);
	//puts ("niconi dfs1");
	dfs2 (1, 1);
	//puts ("niconi dfs2");
	build (1, 1, n);
	//puts ("niconi build");
	register int z, opt;
	while (m --)
	{
		scanf ("%d %d", &opt, &x);
		//cin >> opt >> x;
		if (opt == 1) scanf ("%d", &y), range_update (x, x, y);
		else if (opt == 2) scanf ("%d", &y), son_update (x, y);
		else printf ("%lld\n", range_query (1, x));
	}
	return 0;
}
