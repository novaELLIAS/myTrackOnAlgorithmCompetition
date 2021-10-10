#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"

inline int read ()
{
	int x=0,t=1;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*t;
}

int mapp[21][21][21];

inline long long w (int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	else if (a > 20 || b > 20 || c > 20) return w (20, 20, 20);
	else if (mapp[a][b][c]) return mapp[a][b][c];
	if (mapp[a][b][c]) return mapp[a][b][c];
	mapp[a][b][c] = w (a-1, b, c) + w (a-1, b-1, c) + w (a-1, b, c-1) - w (a-1, b-1, c-1);
	return mapp[a][b][c];
}

int main ()
{
	int a, b, c;
	
	while (true)
	{
		a = read (), b = read (), c = read ();
		if (a == -1 && b == -1 && c == -1) return 0;
		memset (mapp, 0, sizeof mapp);
		printf ("w(%d, %d, %d) = ", a, b, c);
		if (a > 20) a = 21;
		if (b > 20) b = 21;
		if (c > 20) c = 21;
		printf ("%d\n", w (a, b, c));
	}
	
	return 0;
}
