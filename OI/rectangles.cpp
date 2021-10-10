#pragma G++ optimize ("Ofast", 3)

#include <cstdio>

#define gc() getchar()
inline int read ()
{
	register int x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0' && c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {write(x), putchar('\n');}

inline const int& min (const int& a, const int& b) {return a<b? a:b;}

#define Re register
#define maxn 45

int ans[maxn][maxn][maxn][maxn], lin[maxn][maxn];

int main ()
{
	freopen ("rectangles.in", "r", stdin);
	freopen ("rectangles.out","w",stdout);
	
	register int n = read (), m = read (), _ = read (), nico;
	for (  int i = 1; i <= n; ++ i)
    {
        for (  int j = 1; j <= m; ++ j)
        {
            scanf ("%1d", &nico);
            if (nico) lin[i][j] = 0;
            else lin[i][j] = lin[i-1][j] + 1;
        }
    }
    
    for (  int frx = 1; frx <= n; ++ frx)
    {
        for (  int fry = 1; fry <= m; ++ fry)
        {
            for (  int tox = frx; tox <= n; ++ tox)
            {
                for (  int toy = fry; toy <= m; ++ toy)
                {
                    ans[frx][fry][tox][toy] = ans[frx][fry][tox-1][toy] + ans[frx][fry][tox][toy-1] - ans[frx][fry][tox-1][toy-1];
                    nico = tox - frx + 1;
                    for (  int k = toy; k >= fry; -- k)
                    {
                        nico = min (nico, lin[tox][k]);
                        ans[frx][fry][tox][toy] += nico;
                    }
                }
            }
        }
    }
	
	while (_ --) writelen (ans[ read()][ read()][ read()][ read()]);
	
	 return 0;
}
