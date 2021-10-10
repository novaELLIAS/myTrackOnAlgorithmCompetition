
// 输入数据
int n, c;
int pos[];
int w[];

int sum[]; // sum[i] = w[1]+w[2]+w[3]+..+w[i];

int dp[l][r][s]
// 当前已经关闭电灯[l,r], 当前所在位置为s(s=0=>l, s=1=>r)
// 在这种情况下关闭全部的电灯最少需要再消耗多少能量

int main()
{
	dp[1][n][0] = dp[1][n][1] = 0;
	for(int len=n-1;len>=1;len--)
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			for(int s=0;s<=1;s++)
			{
				int x=s==0?l:r;
				dp[l][r][s] = 100000000;
				if (l>1) dp[l][r][s] = min(dp[l][r][s], dp[l-1][r][0] + (pos[x]-pos[l-1])*(sum[n]-sum[r]+sum[l-1]));
				if (r<n) dp[l][r][s] = min(dp[l][r][s], dp[l][r+1][1] + (pos[r+1]-pos[x])*(sum[n]-sum[r]+sum[l-1]));
			}
		}
	cout << dp[c][c][0] << endl;
	
	return 0;
}
