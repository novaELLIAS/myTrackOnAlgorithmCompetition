#pragma GCC optimize ("Ofast", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")
 
#include <cstdio>
#include <queue>

using namespace std;

static char buf[1<<14],*p1=buf,*p2=buf;	
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while (c!='-'&&(c<'0'||c>'9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {if (x<0) putchar('-'), x = -x; write (x); putchar ('\n');}

inline const int& min (const int& a, const int& b) {return a<b? a:b;}
inline const int& max (const int& a, const int& b) {return a>b? a:b;}

#define Re register
#define maxn 101

deque <int> maxque, minque;
int dat[maxn][maxn][maxn];
int max1[maxn][maxn][maxn], min1[maxn][maxn][maxn], max2[maxn][maxn][maxn], min2[maxn][maxn][maxn];

int main ()
{
	//freopen ("cube.in", "r", stdin);
	//freopen ("cube.out","w",stdout);
	
	register int a=read(), b=read(), c=read(), n=read(), TOP, ans=0x3f3f3f3f;
	for (Re int i = 1; i <= a; ++ i)
	{
		for (Re int j = 1; j <= b; ++ j)
		{
			for (Re int k = 1; k <= c; ++ k) dat[i][j][k] = read ();
		}
	}
	
	TOP = n - 1;
	for (Re int i = 1; i <= a; ++ i)
	{
		for (Re int j = 1; j <= b; ++ j)
		{
			maxque.clear(), minque.clear();
			for (Re int k = 1; k < n; ++ k)
			{
				while (!maxque.empty() && dat[i][j][maxque.back()] < dat[i][j][k]) maxque.pop_back ();
				maxque.push_back (k);
				
				while (!minque.empty() && dat[i][j][minque.back()] > dat[i][j][k]) minque.pop_back ();
				minque.push_back (k);
			}
			
			for (Re int k = n; k <= c; ++ k)
			{
				while (!maxque.empty() && maxque.front() < k - TOP) maxque.pop_front();
				while (!maxque.empty() && dat[i][j][maxque.back()] < dat[i][j][k]) maxque.pop_back();
				maxque.push_back(k);
				max1[i][j][k-TOP] = dat[i][j][maxque.front()];
				
				while (!minque.empty() && minque.front() < k - TOP) minque.pop_front();
				while (!minque.empty() && dat[i][j][minque.back()] > dat[i][j][k]) minque.pop_back();
				minque.push_back(k);
				min1[i][j][k-TOP] = dat[i][j][minque.front()];
			}
		}
	}

	
/*
	for (Re int i = 1; i <= a; ++ i)
	{
		for (Re int j = 1; j <= b; ++ j)
		{
			for (Re int k = 1; k <= c; ++ k) printf ("%d ", max1[i][j][k]);
			puts ("");
		}
	}puts ("---");
	for (Re int i = 1; i <= a; ++ i)
	{
		for (Re int j = 1; j <= b; ++ j)
		{
			for (Re int k = 1; k <= c; ++ k) printf ("%d ", min1[i][j][k]);
			puts ("");
		}
	}puts ("---");
*/
	for (Re int i = 1; i <= a; ++ i)
	{
		for (Re int k = 1; k <= c - TOP; ++ k)
		{
			maxque.clear(), minque.clear();
			for (Re int j = 1; j < n; ++ j)
			{
				while (!maxque.empty() && max1[i][maxque.back()][k] < max1[i][j][k]) maxque.pop_back ();
				maxque.push_back (j);
				
				while (!minque.empty() && min1[i][minque.back()][k] > min1[i][j][k]) minque.pop_back ();
				minque.push_back (j);
			}
			
			for (Re int j = n; j <= b; ++ j)
			{
				while (!maxque.empty() && maxque.front() < j - TOP) maxque.pop_front();
				while (!maxque.empty() && max1[i][maxque.back()][k] < max1[i][j][k]) maxque.pop_back();
				maxque.push_back(j);
				max2[i][j-TOP][k] = max1[i][maxque.front()][k];
				
				while (!minque.empty() && minque.front() < j - TOP) minque.pop_front();
				while (!minque.empty() && min1[i][minque.back()][k] > min1[i][j][k]) minque.pop_back();
				minque.push_back(j);
				min2[i][j-TOP][k] = min1[i][minque.front()][k];
			}
		}
	}
	
/*
	for (Re int i = 1; i <= a; ++ i)
	{
		for (Re int j = 1; j <= b; ++ j)
		{
			for (Re int k = 1; k <= c; ++ k) printf ("%d ", max2[i][j][k]);
			puts ("");
		}
	}puts ("---");
	for (Re int i = 1; i <= a; ++ i)
	{
		for (Re int j = 1; j <= b; ++ j)
		{
			for (Re int k = 1; k <= c; ++ k) printf ("%d ", min2[i][j][k]);
			puts ("");
		}
	}puts ("---");
*/
	for (Re int k = 1; k <= c - TOP; ++ k)
	{
		for (Re int j = 1; j <= b - TOP; ++ j)
		{
			maxque.clear(), minque.clear();
			for (Re int i = 1; i <= TOP; ++ i)
			{
				while (!maxque.empty() && max2[maxque.back()][j][k] < max2[i][j][k]) maxque.pop_back ();
				maxque.push_back (i);
				
				while (!minque.empty() && min2[minque.back()][j][k] > min2[i][j][k]) minque.pop_back ();
				minque.push_back (i);
			}
			
			for (Re int i = n; i <= a; ++ i)
			{
				while (!maxque.empty() && maxque.front() < i - TOP) maxque.pop_front();
				while (!maxque.empty() && max2[maxque.back()][j][k] < max2[i][j][k]) maxque.pop_back();
				maxque.push_back(i);
				
				while (!minque.empty() && minque.front() < i - TOP) minque.pop_front();
				while (!minque.empty() && min2[minque.back()][j][k] > min2[i][j][k]) minque.pop_back();
				minque.push_back(i);
				ans = min (ans, max2[maxque.front()][j][k] - min2[minque.front()][j][k]);
			}
		}
	}
	
	printf ("%d", ans);
	return 0;
}
