#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned long long ll;

const int MAXT = 10001;
const int MAXN = 100001;

ll t, query[MAXT], phi[MAXN], fukfr[MAXN], ans[MAXN], lastest;

void getPhi()
{
	for(int i = 0; i < MAXN; ++i)
		phi[i] = i;
		
	for(int i = 1; i < MAXN; ++i)
		for(int j = i * 2; j < MAXN; j += i)
			phi[j] -= phi[i];
}

void solve()
{
	for(int i = 1; i < MAXN; ++i)
		for(int j = i; j < MAXN; j += i)
			fukfr[j] += phi[i] * i;
}

ll getAns(ll a)
{
	if(a <= lastest)
		return ans[a];
	
	for(int i = lastest + 1; i <= a; ++i)
		ans[i] = ans[i - 1] + i * (fukfr[i] + 1) - i;
		
	lastest = a;
		
	return ans[a];
}

int main()
{
	freopen("lcm.in", "r", stdin);
	freopen("lcm.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	getPhi();
	solve();
	
	cin >> t;
	
	for(int i = 1; i <= t; ++i)
	{
		ll query;
		cin >> query;
		cout << getAns(query) << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
