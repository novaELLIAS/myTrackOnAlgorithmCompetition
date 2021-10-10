#include <stdio.h>
#include <stdlib.h>
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

#define maxn 2000

int n, outpos;
int degree[maxn], out[maxn];
bool edge[maxn][maxn];

int exinit(char x)
{
	if(x<='z' && x>='a') return x-'a'+27;
	else return x-'A'+1;
}
char reinit(int x)
{
	if(x <= 26) return x+'A'-1;
	else return x+'a'-27;
}
void DFS(int pos)
{
	for(int i = 1; i <= 52; i ++)
	{
		if(edge[pos][i])
		{
			edge[pos][i] = edge[i][pos] = 0;
			DFS(i);
		}
	}
	out[++outpos] = pos;
}

#include <iostream>

using namespace std;

int main()
{
	n = fastread();
	for(int i = 1; i <= n; i ++)
	{
		char a, b;
		//scanf("%c%c", &a, &b);
		cin >> a >> b;
		int aa = exinit(a);
		int bb = exinit(b);
		degree[aa]++, degree[bb]++;
		edge[aa][bb] = edge[bb][aa] = 1;
	}
	int start, cnt = 0;
	bool first = true;
	for(int i = 1; i <= 52; i ++)
	{
		if(degree[i]%2 == 1)
		{
			cnt++;
			if(first)
			{
				start = i;
				first = 0;
			}
		}
	}
	if(cnt!=0 && cnt!=2)
	{
		puts("No Solution");
		exit(0);
	}
	if(cnt == 0)
	{
		for(int i = 1; i <= 52; i ++)
		{
			if(degree[i])
			{
				start = i;
				break;
			}
		}
	}
	DFS(start);
	for(int i = outpos; i >= 1; i --)
	{
		printf("%c", reinit(out[i]));
	}
	return 0;
}
