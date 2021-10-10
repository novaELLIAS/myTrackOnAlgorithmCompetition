
// ����һ��(x,y)ʹ��a*x+b*y=gcd(a,b) 
void exgcd(int&x, int&y, int &g, int a, int b)
{
	if (b==0){x=1;y=0;g=a;}
	else {
		exgcd(y, x, g, b, a%b);
		y-=a/b*x;
	}
}

// ����x����P����Ԫ 
int inv(int x, int P)
{
	int i, j, k;
	exgcd(i, j, k, x, P);
	return (i+P)%P;
}

// ����x��k�η�����M
int pow(int x, int k, int M)
{
	if (k == 0) return 1;
	int ans = pow(x, k/2, M);
	return k%2==1 ? (ans*ans*x)%M : (ans*ans)%M;
}

// ����x����P����Ԫ 
int inv2(int x, int P)
{
	return pow(x, P-2, P);
}
