
double dp[s][k];
// 已经经过的点集合为s，当前正在点k，要经过其他所有点的最优方案（最小距离之和）

int main()
{
	// read
	
	// 边界
	for(int k=0;k<n;k++)
		dp[(1<<n)-1][k]=0;
	
	for(int s=(1<<n)-1-1;s>=1;s--) // 计算顺序
		for(int k=0;k<n;k++) // 计算顺序
		{
			dp[s][k] = 10000000; // 初始化
			for(int kk=0;kk<n;kk++) // 转移方程
				if( ((s>>kk)&1) == 0 )
				{
					int ss = s | (1<<kk);
					dp[s][k] = min(dp[s][k], dp[ss][kk] + dist(k, kk));
					// s < ss, 此时dp[ss][kk]的值必须已知
				}
		}
	
	double ans = 1000000;
	for(int k=0;k<n;k++)
		ans = min(ans, dist(k) + dp[1<<k][k]);
	cout << ans << endl;
}
