#pragma GCC optimize ("Ofast")

#include <stdio.h>
#include <algorithm>
#include <math.h>

#define rint register int

using namespace std;

int n, m, a[1001][2], b[1001], tot, x, y, cnt;
double ans;

struct node {
    int x, y;
    double val;
} e[2002000];

inline int read()
{
    int x=0,t=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}

inline bool cmp (node aa, node bb)
{
    return aa.val < bb.val;
}

inline int get (int u)
{
    if (b[u] != u) return get (b[u]);
    return b[u];
}

inline void work ()
{
    for (rint i = 1; i <= n; i ++) b[i] = i;
    for (rint i = 1; i <= tot; i ++)
    {
        x = get (e[i].x);
        y = get (e[i].y);
        if (x != y)
        {
            b[y] = x;
            cnt ++;
            ans += e[i].val;
        }
        if (cnt == n - 1) break;
    }
}

int main ()
{
    n = read (), m = read ();
    for (rint i = 1; i <= n; i ++) a[i][0] = read (), a[i][1] = read ();
    for (rint i = 1; i <= n; i ++)
    {
        for (rint j = i + 1; j <= n; j ++)
        {
            tot ++;
            e[tot].x = i;
            e[tot].y = j;
            e[tot].val = (double) sqrt ((double(a[i][0]-a[j][0])*(a[i][0]-a[j][0]))+((double)(a[i][1]-a[j][1])*(a[i][1]-a[j][1])));
        }
    }

    for (rint i = 1; i <= m; i ++)
    {
        tot ++;
        e[tot].x = read ();
        e[tot].y = read ();
        e[tot].val = 0;
    }

    sort (e + 1, e + tot + 1, cmp);

    work ();

    printf ("%.2lf", ans);

    return 0;
}