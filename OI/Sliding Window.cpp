#include <stdio.h>

const int maxn = 1000000 + 10;
int n, k;
int data[maxn], quemax[maxn], quemin[maxn];
int outmin[maxn], outmax[maxn];
int posminout, posmaxout;

int main(void)
{
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &data[i]);
	int startmax, startmin, tailmax, tailmin;
	startmax = startmin = 1;
	tailmax = tailmin = 0;
	for(int i = 1; i < k ; ++ i)
	{
		while(startmax<=tailmax && data[quemax[tailmax]]<=data[i]) tailmax--;
		while(startmin<=tailmin && data[quemin[tailmin]]>=data[i]) tailmin--;
		quemax[++tailmax] = i;
		quemin[++tailmin] = i;
	}
	for(int i = k; i <= n; i++)
	{
		while(startmax<=tailmax && data[quemax[tailmax]]<=data[i]) tailmax--;
		quemax[++tailmax] = i;
		if(quemax[startmax]+k <= i) startmax++;
		outmax[++posmaxout] = data[quemax[startmax]];
		
		while(startmin<=tailmin && data[quemin[tailmin]]>=data[i]) tailmin--;
		quemin[++tailmin] = i;
		if(quemin[startmin]+k <= i) startmin++;
		outmin[++posminout] = data[quemin[startmin]];
	}
	for(int i = 1; i <= posminout; i++) printf("%d ", outmin[i]);
	putchar('\n');
	for(int i = 1; i <= posmaxout; i++) printf("%d ", outmax[i]);
}
