#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1000001;
const int MAXM = 10000001;
const int MOD = 1e9 + 7;

inline int read()
{
	int s = 0, f = 1;
	char ch = getchar();
	
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	
	while(ch <= '9' && ch >= '0')
	{
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	
	return s * f;
}

int n, m;
int l[MAXN], r[MAXN], L = 1e9, R = -1e9, tmp, tp = -1e9;
ll sum[MAXM], prime[MAXM], _prime;
bool check[MAXM], a[MAXM];

inline void getPrime()
{
	check[1] = 1;
	for(int i = 2; i < MAXM; i++)
	{
		if(!check[i])
			prime[++_prime]=i;
		for(int j = 1; j <= _prime && i * prime[j] < MAXM; j++)
		{
			check[i * prime[j]] = 1;
			if(!i % prime[j])
				break;
		}
	}
}

int main()
{
	freopen("prime.big.in", "r", stdin);
	//freopen("prime.out", "w", stdout);
	
	n = read(), m = read();
	
	for(int i = 1; i <= n; ++i)
		a[tmp = read()] = true, tp = max(tp, tmp);
	
	getPrime();
	
	for(int i = 1; i <= m; ++i)
		l[i] = read(), r[i] = read(), L = min(L, l[i]), R = max(R, r[i]);
		
	for(int i = L; i <= R; ++i)
	{
		if(check[i])
		{
			sum[i] = sum[i - 1];
			continue;
		}
		
		int _ = 0;
		for(int j = 1; i * j <= tp; ++j)
			if(a[i * j])
				++_;
		sum[i] += _ + sum[i - 1];
	}
	
	for(int i = 1; i <= m; ++i)
		printf("%I64d\n", (sum[r[i]] - sum[l[i] - 1]) % MOD);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
