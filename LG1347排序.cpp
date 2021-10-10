#include "stdio.h"
#include "stdlib.h"

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

#define maxn 30
#define maxm 128
#define exit exit(0);

int n, m;
int mapp[maxn][maxn];
char out[maxn];

void Floyed()
{
	for(int k = 1; k <= 26; k ++)
	{
		for(int i = 1; i <= 26; i ++)
		{
			for(int j = 1; j <= 26; j ++)
			{
				if(mapp[i][k] == 1 && mapp[k][j] == 1)
				{
					mapp[i][j] = 1;
					mapp[j][i] = -1;
				}
				if(mapp[i][k] == -1 && mapp[k][j] == -1)
				{
					mapp[i][j] = -1;
					mapp[j][i] = 1;
				}
			}
		}
	}
}
bool check()
{
	int ret = 0;
	int cou = 0, pos = 0;
	for(int i = 1; i <= 26; i ++)
	{
		cou = 0; pos = 0;
		for(int j = 1; j <= 26; j ++)
		{
			if(i!=j && (mapp[i][j]==1 || mapp[j][i]==1 || mapp[i][j]==-1 || mapp[j][i]==-1))
			{
				cou++;
				if(mapp[i][j] == -1) pos++;
			}
		}
		if(cou == n-1)
		{
			ret++;
			out[pos + 1] = i+'A'-1;
		}
	}
	if(ret == n) return 1;
	else return 0;
}
int main()
{
	n = fastread();
	m = fastread();
	for(int step = 1; step <= m ; step ++)
	{
		char in[6];
		scanf("%s", in);
		int a = in[0]-'A'+1;
		int b = in[2]-'A'+1;
		if(a == b)
		{
			printf("Inconsistency found after %d relations.", step);
			exit
		}
		if(in[1] == '>')
		{
			if(mapp[a][b] == -1 || mapp[b][a] == 1)
			{
				printf("Inconsistency found after %d relations.", step);
				exit
			}
			else
			{
				mapp[a][b] = 1;
				mapp[b][a] = -1;
			}
		}
		else
		{
			if(mapp[a][b] == 1 || mapp[b][a] == -1)
			{
				printf("Inconsistency found after %d relations.", step);
				exit
			}
			else
			{
				mapp[a][b] = -1;
				mapp[a][b] = 1;
			}
		}
		Floyed();
		if(check())
		{
			printf("Sorted sequence determined after %d relations: ", step);
			for(int i = n; i >= 1; i --) printf("%c", out[i]);
			putchar('.');
			exit
		}
	}
}
