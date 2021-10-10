#pragma GCC optimize ("Ofast")

#include "stdio.h"

#define maxn 100010
#define rint register int

inline int read()
{
    register int x = 0, t = 1;
    register char ch = getchar();
    while ((ch<'0'||ch>'9')&&ch!='-') ch = getchar();
    if (ch=='-') t =-1, ch = getchar();
    while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    return x*t;
}

struct node {
    int fa, ch[2];
    int size, val;
    bool mark;
    inline void in (int x, int ff)
    {
        size = 1, val = x, fa = ff, ch[1] = ch[0] = 0;
    }
} data[maxn];

int n, m, root, tot;

#define swap(x,y) y^=x^=y^=x

inline void update (int u)
{
    data[u].size = data[data[u].ch[0]].size + data[data[u].ch[1]].size + 1;
}

inline void markdown (int u)
{
    if (data[u].mark)
    {
        data[data[u].ch[0]].mark ^= 1;
        data[data[u].ch[1]].mark ^= 1;
        data[u].mark = false;
        swap (data[u].ch[0], data[u].ch[1]);
    }
}

inline void rotate (int u)
{
    rint y = data[u].fa;
    rint z = data[y].fa;
    rint k = data[y].ch[1] == u;
    data[z].ch[data[z].ch[1] == y] = u;
    data[u].fa = z;
    data[y].ch[k] = data[u].ch[k^1];
    data[data[u].ch[k^1]].fa = y;
    data[u].ch[k^1] = y;
    data[y].fa = u;
    update (y);
    update (u);
}

inline void splay (int x, int to)
{
    rint y, z;
    while (data[x].fa != to)
    {
        y = data[x].fa;
        z = data[y].fa;
        if (z != to) (data[z].ch[1] == y)^(data[y].ch[1] == x)? rotate (x):rotate (y);
        rotate (x);
    }
    if (to == 0) root = x;
}

inline void insert (int x)
{
    rint ff = 0, u = root;
    while (u) ff = u, u = data[u].ch[x > data[u].val];
    u = ++ tot;
    if (ff) data[ff].ch[x > data[ff].val] = u;
    data[u].in (x, ff);
    splay (u, 0);
}

inline int query_th (int k)
{
    rint u = root;
    while (true)
    {
        markdown (u);
        if (data[data[u].ch[0]].size >= k) u = data[u].ch[0];
        else if (data[data[u].ch[0]].size + 1 == k) return u;
        else k -= data[data[u].ch[0]].size + 1, u = data[u].ch[1];
    }
}

inline void output (int u)
{
    markdown (u);
    if (data[u].ch[0]) output (data[u].ch[0]);
    if (data[u].val > 1 && data[u].val < n + 2) printf ("%d ", data[u].val - 1);
    if (data[u].ch[1]) output (data[u].ch[1]);
}

int main ()
{
    n = read (), m = read ();
    for (rint i = 1; i <= n + 2; i ++) insert (i);
    rint l, r, mid;
    while (m --)
    {
        l = query_th(read ()), r = query_th(read () + 2);
        splay (l, 0);
        splay (r, l);
        data[data[data[root].ch[1]].ch[0]].mark ^= 1;	
    }
    output (root);
    
    return 0;
}
