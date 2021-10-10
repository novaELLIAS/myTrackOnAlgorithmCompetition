#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define maxn 7
#define rint register int
const double pi = 3.141592653589;

int n, pt[maxn][2];
bool vis[maxn];
double r[maxn], ans = -1;
int x1, yx, x2, y2;

inline const double& maxx (const double& x,const double& y) {return x>y? x:y;}
inline const double& minn (const double& x,const double& y) {return x<y? x:y;}
inline double abss (double x) {return x<0? -x:x;}
inline int aabs (int x) {return x<0? -x:x;}

inline double dis (int x1, int y1, int x2, int y2)
{
	return sqrt ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

inline double nic (int x)
{
	for (rint i = 1; i <= n; i ++)
	{
		if (i != x && vis[i])
		{
			if (r[i] > dis (pt[x][1], pt[x][0], pt[i][1], pt[i][0])) return 0;
		}
	}
	register double ret = minn (minn (abss(pt[x][0]-x1), abss (pt[x][0]-x2)), minn (abss (pt[x][1]-yx), abss (pt[x][1]-y2)));
	for (rint i = 1; i <= n; i ++)
	{
		if (i != x && vis[i])
		{
			ret = minn (ret, dis (pt[x][0], pt[x][1], pt[i][0], pt[i][1])-r[i]);
		}
	}
	return ret;
}

inline void nico_dfs (int x, double s)
{
	if (x == n) {ans = maxx (ans, s); return;}
	for (rint i = 1; i <= n; i ++)
	{
		if (!vis[i])
		{
			r[i] = nic (i); vis[i] = true;
			nico_dfs (x + 1, s + pi*r[i]*r[i]);
			r[i] = vis[i] = 0; 
		}
	}
}

int main ()
{
	scanf ("%d%d %d %d %d", &n, &x1, &yx, &x2, &y2);
	for (rint i = 1; i <= n; i ++) scanf ("%d %d", &pt[i][0], &pt[i][1]);
	nico_dfs (0, 0);
	printf ("%d", (int)(aabs (x1-x2) * aabs (yx-y2) - ans + 0.5));
	return 0;
}
