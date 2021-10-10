#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

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

#define maxn 1010
#define ques 10001

struct node {
	int name;
	int cost;
	bool friend operator <(node a,node b){
		return a.cost>b.cost;
	}
	
};
int n;
int make[ques];
int cost[maxn];
int ans[maxn];
priority_queue <node> nico;

int main()
{
	n = fastread();
	int x;
	for(int i = 1; i <= n; i ++){
		x = fastread();
		nico.push((node){i,x});
	}
	for(int i = 1; i <= n; i ++){
		printf("%d ", nico[i].cost);
	}/*
	memset(ans, 1, sizeof(ans));
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		a++, b++, c++;
		make[a][b] = make[b][a] = c;
	}
	*/
}
