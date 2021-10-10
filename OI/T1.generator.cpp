#pragma G++ optimize (3)
#include <bits/stdc++.h>
using namespace std;
#define mod1 10000
#define mod2 10000000
typedef long long ll;
inline ll random ()
{
	return mod1 + 1ll*rand()*rand()%mod2;
}
int main ()
{
	freopen ("sugata.in","w",stdout);
	register ll n = 100000, k = 10000;
	printf ("%I64d %I64d\n", n, k);
	while (n --) printf ("%I64d ", random());
	puts ("");
	fclose (stdout);
	return 0;
}
