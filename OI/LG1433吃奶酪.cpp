// F**K YOUR MOTHER ONLINE JUDGE !! 
#include <bits/stdc++.h>
using namespace std;
/*
#define max(x,y) x>y? x:y
#define min(x,y) x<y? x:y
*/
inline int fastread()
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

#define maxn 20
struct point {
	double x, y;
}data[maxn];
int n;
double dis[maxn][maxn];
//double cut[maxn];
bool visit[maxn];
double ans = 233333333.0;

void DFS(int now, int step, double tot)
{
	if(tot >= ans) return;
	/*
	if(tot >= cut[now]) return;
	cut[now] = tot;
	*/
	if(step == n)
	{
		ans = min(ans, tot);
		return;
	}
	for(int i = 1; i <= n; i ++)
	{
		if(!visit[i])
		{
			visit[i] = true;
			DFS(i, step + 1, tot + dis[now][i]);
			visit[i] = false;
		}
	}
}
/*
double getdis(point a, point b)
{
	int x1 = a.x;
	int x2 = b.x;
	int y1 = a.y;
	int y2 = b.y;
	double ret = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	return ret;
}
*/
int main(void)
{
	n = fastread();
	for(int i = 1; i <= n; i ++)
	{
		/*
		data[i].x = fastread();
		data[i].y = fastread();
		*/
		scanf("%lf %lf", &data[i].x, &data[i].y);
	}
	data[0].x = data[0].y = 0;
	for(int i = 0; i <= n; i ++)
	{
		for(int j = 0; j<=n ; j ++)
		{
			//if(i == j) continue; 
			dis[i][j] = dis[j][i] = sqrt((data[i].x-data[j].x)*(data[i].x-data[j].x) + (data[i].y-data[j].y)*(data[i].y-data[j].y));
		}
	}
	/* // test dis[][] 
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= n; j ++)
		{
			printf("%lf ", dis[i][j]);
		}
		putchar('\n');
	}
	*/
	
	DFS(0, 0, 0.0); 
	printf("%.2lf", ans);
}
