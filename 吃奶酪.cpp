
double dp[s][k];
// �Ѿ������ĵ㼯��Ϊs����ǰ���ڵ�k��Ҫ�����������е�����ŷ�������С����֮�ͣ�

int main()
{
	// read
	
	// �߽�
	for(int k=0;k<n;k++)
		dp[(1<<n)-1][k]=0;
	
	for(int s=(1<<n)-1-1;s>=1;s--) // ����˳��
		for(int k=0;k<n;k++) // ����˳��
		{
			dp[s][k] = 10000000; // ��ʼ��
			for(int kk=0;kk<n;kk++) // ת�Ʒ���
				if( ((s>>kk)&1) == 0 )
				{
					int ss = s | (1<<kk);
					dp[s][k] = min(dp[s][k], dp[ss][kk] + dist(k, kk));
					// s < ss, ��ʱdp[ss][kk]��ֵ������֪
				}
		}
	
	double ans = 1000000;
	for(int k=0;k<n;k++)
		ans = min(ans, dist(k) + dp[1<<k][k]);
	cout << ans << endl;
}
