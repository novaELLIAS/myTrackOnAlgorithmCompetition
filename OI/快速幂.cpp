
// 计算x的k次方求余M，k可能很大
long long pow(long long x, long long k, long long M)
{
	if(k==0)return 1;
	long long ans = pow(x, k/2, M);
	ans = (ans * ans)%M;
	if (k%2==1) ans = (ans * x)%M;
	return ans;
}

// 计算x*y求余M
long long mul(long long x, long long y, long long M)
{
	if(y==0)return 0;
	long long ans = mul(x, y/2, M);
	ans = (ans + ans) % M;
	if (k%2==1) ans = (ans + x) % M;
	return ans;
}
