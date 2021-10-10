#pragma GCC optimize ("Ofast")

#include "stdio.h"

int n,k;

inline long long work(int n,int k)
{
	if((k==1)||(k==n))
	{
		return 1;
	}
	if((k==0)||(k==0))
	{
		return 0;
	}
	return (long long) work(n-1,k-1)+(long long)k*(long long)work(n-1,k);
}
int main()
{
	scanf("%d%d",&n,&k);
	printf("%I64d",work(n,k));
	return 0;
}