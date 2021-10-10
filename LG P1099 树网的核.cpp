#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"

using namespace std;

#define max(a,b) a>b? a:b
#define min(a,b) a<b? a:b
#define maxn 1001

inline int fastread ();
inline void fastwrite (int);
inline void fastwriteline (int);
inline void fastwritespace (int);

int mapp[maxn][maxn];
int n, s, u, v, w;

int main ()
{
    n = fastread ();
    s = fastread ();
    memset (mapp, 127/3, sizeof mapp);
    for (int i = 1; i <= n; i ++) mapp[i][i] = 0;
    for (int i = 1; i < n; i ++)
    {
        u = fastread ();
        v = fastread ();
        w = fastread ();
        mapp[u][v] = mapp[v][u] = w;
    }
    
    for (int k = 1; k <= n; k ++)
    {
        for (int i = 1; i <= n; i ++)
        {
        	if (i != k)
            for (int j = 1; j <= n; j ++)
            {
                if (i != j && j != k)
                {
                    mapp[i][j] = min (mapp[i][j], mapp[i][k] + mapp[k][j]);
                }
            }
        }
    }
    /*
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            fastwritespace (mapp[i][j]);
        }
        putchar ('\n');
    }
    */
    /*
    int minn = 0x7ffffff, maxx = -23333333;
    
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            maxx = max (maxx, mapp[i][j]);
        }
    }
    */
    // fastwriteline (maxx);
    /*
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if (mapp[i][j] == maxx)
            {
                nico.push_back (make_pair (i, j));
            }
        }
    }
    */
    // putchar ('\n');
    
    int ans = 233333333, maxx = -23333333;
    
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            maxx = 0;
			mapp[i][i] = 0;
            if (mapp[i][j] <= s || i == j)
            
            {
            	for (int k = 1; k <= n; k ++)
        		{
            		if (k != i && k != j)
            		maxx = max (maxx, (mapp[k][i] + mapp[k][j] - mapp[i][j]) / 2);
				}
				ans = min (ans, maxx);
			}
        }
    }
    
    fastwrite (ans);
    
    return 0;
}

inline int fastread ()
{
    int sign = 1, n = 0;
    char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-') sign = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        n = n*10 + c-'0';
        c = getchar();
    }
    return sign*n;
}
inline void fastwrite (int x)
{
    if(x < 0) x = -x, putchar('-');
    if(x > 9) fastwrite(x / 10);
    putchar(x%10 + '0');
}
inline void fastwritespace (int x)
{
    fastwrite(x);
    putchar(' ');
}
inline void fastwriteline (int x)
{
    fastwrite(x);
    putchar('\n');
}
