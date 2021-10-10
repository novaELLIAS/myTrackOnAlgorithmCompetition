#pragma GCC optimize ("Ofast",3)

#include <cstdio>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::stack;

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
    register int x = 0; register char c = gc(); register bool m = 0;
    while ((c < '0' || c > '9')/* && (c ^ '-')*/) c = gc();
    //if (c == '-') c = gc(), m = true;
    while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
    return x;
}
static void write (int x)
{
    if (x > 9) write (x / 10);
    putchar (x % 10 + 48);
}

#define Re register
#define maxn 5001
#define dmax 10001
#define pb push_back

vector <int> son[maxn];
int ord[maxn], pos;
bool vis[maxn];

inline bool cmp (int a, int b) {return a>b;}

static void nico_dfs (Re int x, Re int fa)
{
    register int to;
    if (!vis[x])
    {
        vis[x]=true, ord[++pos]=x;
        for (Re int i=son[x].size()-1; i>=0; --i)
        {
            to=son[x][i];
            if (to^fa) nico_dfs(to, x);
        }
    }
}

inline void solve_tree(Re int n, Re int m)
{
    register int i, fr, to;
    for (i=1; i<=m; ++ i)
    {
        fr=read(), to=read();
        son[fr].pb(to), son[to].pb(fr);
    }
    for (i=1; i<=n; ++i)
        sort (son[i].begin(), son[i].end(), cmp);
    nico_dfs (1, -1);
    for (i=1; i<=n; ++i) write(ord[i]), putchar(' ');
    fclose (stdin), fclose (stdout); exit (0);
}

int head[maxn], too[dmax], nxt[dmax], frr[dmax], ecnt;
int killfr, killto;
bool flag, genso;
int now[maxn];
//bool inc[maxn];
/*
static bool findc (int x, int fa)
{
    vis[x]=true;
    register int to, i, tp;
    for (i=head[x]; i; i=nxt[i])
    {
        if ((to=too[i])^fa)
        {
            sta.push(to);
            if (vis[to])
            {
                while (true)
                {
                    tp=sta.top(),sta.pop();
                    inc[tp]=1;
                }
            }
        }
    }
}
*/
static void jh_dfs (int x, int fa)
{
    if (!vis[x] && flag)
    {
        register int to;
        vis[x]=true, now[++pos]=x;
        if (now[pos] < ord[pos]) {genso=false;}
        if (now[pos] > ord[pos] && genso) {flag=false;return;}
        for (Re int i=son[x].size()-1; i>=0; --i)
        {
            to=son[x][i];
            if (to^fa && (to^killfr||x^killto) && (x^killfr||to^killto))
                jh_dfs (to, x);
        }
    }
}

inline bool comp (Re int n)
{
    for(Re int i=1; i<=n; ++i)
        if (now[i]<ord[i]) return true;
        else if (now[i]>ord[i]) return false;
}

inline void modify(Re int n)
{
    for (Re int i=1; i<=n; ++i) ord[i]=now[i];
}

inline void solve_jh(register int n)
{
    register int i, fr, to;
    for (i=1; i<=n; ++i)
    {
        fr=read(), to=read();
        son[fr].pb(to), son[to].pb(fr);
        nxt[++ecnt]=head[fr], head[fr]=ecnt, frr[ecnt]=fr, too[ecnt]=to;
        nxt[++ecnt]=head[to], head[to]=ecnt, frr[ecnt]=to, too[ecnt]=fr;
    }
    for (i=1; i<=n; ++i)
        sort (son[i].begin(), son[i].end(), cmp);
    nico_dfs (1, -1);
    for (i=0; i<ecnt; i+=2)
    {
        pos=0, killfr=frr[i], killto=too[i];
		genso = flag = true;
        memset (vis, 0, sizeof vis);
        jh_dfs (1, -1);
        /*
        if (pos==n)
            if (comp(n)) modify(n);
    	*/
    	if (pos == n && flag) modify(n);
	}
    for (i=1; i<=n; ++i) write(ord[i]), putchar(' ');
    fclose (stdin), fclose (stdout); exit(0);
}


signed main ()
{
    register int n=read(), m=read();
    if (m==n-1) solve_tree(n, m);
    else solve_jh(n);
    return 0;
}

