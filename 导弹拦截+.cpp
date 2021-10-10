#include <stdio.h>
#include <string.h>

#define maxn 100010
#define maxint 2147483647

int data[maxn], nico[maxn];
int n, l, r, mid;

int main(void)
{
	while(scanf("%d", &data[++n]) != EOF);
	n--;
	int ans1 = 0;
	nico[0] = maxint;
	//memset(nico, maxint, sizeof(nico));
	for(int i = 1; i <= n; i ++)
	{
		if(nico[ans1] >= data[i]) nico[++ ans1] = data[i];
		else
		{
			l = 0;
			r = ans1;
			while(l < r)
			{
				mid = (l+r)/2;
				if(nico[mid] >= data[i]) l = mid+1;
				else
				{
					r = mid;
				}
			}
			if(l != 0) nico[l] = data[i];
		}
	}
	printf("%d\n", ans1);

	int ans2 = 0;
	//nico[0] = -maxnint;
	memset(nico, -1, sizeof(nico));
	for(int i = 1; i <= n; i ++)
	{
		if(nico[ans2] < data[i]) nico[++ ans2] = data[i];
		else
		{
			l = 0;
			r = ans2;
			while(l < r)
			{
				mid = (l+r)/2;
				if(nico[mid] >= data[i]) r = mid;
				else
				{
					l = mid+1;
				}
			}
			nico[l] = data[i];
		}
	}
	printf("%d", ans2);
}
