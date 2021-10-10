const int MAXN = 100000 + 10;
int diff[MAXN], data[MAXN];

int main()
{
	int L, m;
	cin >> L >> m;
	while(m--)
	{
		int l, r;
		cin >> l >> r;
		diff[l]++;
		diff[r+1]--;
	}
	data[0]=diff[0];
	for(int i=1;i<=L;i++)
		data[i]=data[i-1]+diff[i];
	int ans=0;
	for(int i=0;i<=L;i++)
		ans+=data[i]==0;
	cout<<ans<<endl;
}

