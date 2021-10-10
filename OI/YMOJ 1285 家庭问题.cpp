#include <stdio.h>

inline int fastread();
inline void fastwrite(int);
inline void fastwriteline(int);

#define maxn 101

int n, m;
int a, b;
int father[maxn];
int family[maxn];

int find(int x)
{
	if (father[x] == 0) return x;
	father[x] = find(father[x]);
	return father[x];
}
void unionn(int x, int y)
{
	if (find(x) != find(y))
	{
		father[find(x)] = find(y);
	}
}
int main()
{
	n = fastread();
	m = fastread();
	for (int i = 1; i <= m; i ++)
	{
		a = fastread();
		b = fastread();
		unionn(a, b);
	}
	for (int i = 1; i <= n; i ++) find(i);
	int ans = 0;
	for (int i = 1; i <= n; i ++)
	{
		if (father[i] == 0) father[i] = i;
		if (family[father[i]] == 0) ans ++;
		family[father[i]] ++;
	}
	int t = 0;
	for (int i = 1; i <= n; i ++)
	{
		if (family[i] > t) t = family[i];
	}
	fastwrite(ans);
	putchar(' ');
	fastwrite(t);
	return 0;
}

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
inline void fastwrite(int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwriteline(int x)
{
	fastwrite(x);
	putchar('\n');
}
