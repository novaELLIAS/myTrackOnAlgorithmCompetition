#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "algorithm"

#define maxn 401
#define maxm 10001

#define rint register int

using namespace std;

inline int read()
{
    int x=0,t=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}

int fa[maxn], n, m, f, tot, cnt;
double sum;

struct node {
    int x, y;
    int c, t;
    double val;
} a[maxm << 1];

inline int get (int x)
{
    if (fa[x] != x) return get (fa[x]);
    return fa[x];
}

inline bool cmp (node aa, node bb)
{
    return aa.val < bb.val;
}

inline bool check (double x)
{
    for (rint i = 1; i <= m; i ++) a[i].val = a[i].c + (x*a[i].t);
    sort (a + 1, a + m + 1, cmp);
    sum = 0.0, cnt = 0;
    for (rint i = 1; i <= n; i ++) fa[i] = i;
    for (rint i = 1; i <= m; i ++)
    {
        if (get (a[i].x) != get (a[i].y))
        {
            fa[get (a[i].x)] = get (a[i].y);
            cnt ++;
            sum += a[i].val;
        }
        if (cnt == n-1) break;
    }
    return (cnt == n-1) && (sum <= f);
}

int main ()
{
    n = read (), m = read (), f = read ();
    for (rint i = 1; i <= m ; i ++)
    {
        a[i].x = read (), a[i].y = read (), a[i].c = read (), a[i].t = read ();
        tot += a[i].c;
    }

    double l = 0.0, r = (double)tot, mid;
    while (r > l + 0.000001)
    {
        mid = (l + r) / 2;
        if (check (mid)) l = mid;
        else r = mid;
    }

    printf ("%.4lf", l);

    return 0;
}