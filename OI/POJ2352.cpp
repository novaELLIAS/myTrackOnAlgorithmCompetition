#include <iostream>

#include <algorithm>

#include <stdio.h>

using namespace std;

pair<int, int>p[1000000];

int work[100000], a, b, c, d, ans[100000], bucket[1000000];

int lowbit(int x)
{
	return x&-x;
}

void update(int k, int x)
{
	while(k<100000)
	{
		work[k] += x;
		k += lowbit(k);
	}
}

int query(int k)
{
	int ans = 0;
	while(k>=1)
	{
		ans += work[k];
		k -= lowbit(k);
	}
	return ans;
}

int main()

{
	scanf( "%d", &a );

	for ( int i = 1; i <= a; i++ )

		scanf( "%d%d", &p[i].first, &p[i].second ), p[i].first ++, p[i].second ++;

	sort( p + 1, p + 1 + a );

	for ( int i = 1; i <= a; i++ )

	{
		ans[i] = query( p[i].second );

		update(p[i].second, 1);
	}

	for ( int i = 1; i <= a; i++ )

		bucket[ans[i]]++;

	for ( int i = 0; i <= a - 1; i++ )

		printf( "%d\n", bucket[i] );
}

/*
#include <iostream>

#include <algorithm>

#include <stdio.h>

using namespace std;

pair<int, int>p[1000000];

int work[100000], a, b, c, d, ans[100000], bucket[1000000];

int sum( int x )

{
	int temp = 0;

	for ( int i = 1; i <= x; i++ )

		temp += work[i];

	return(temp);
}


int main()

{
	scanf( "%d", &a );

	for ( int i = 1; i <= a; i++ )

		scanf( "%d%d", &p[i].first, &p[i].second ), p[i].first ++, p[i].second ++;

	sort( p + 1, p + 1 + a );

	for ( int i = 1; i <= a; i++ )

	{
		ans[i] = sum( p[i].second );

		work[p[i].second]++;
	}

	for ( int i = 1; i <= a; i++ )

		bucket[ans[i]]++;

	for ( int i = 0; i <= a - 1; i++ )

		printf( "%d\n", bucket[i] );
}
*/

