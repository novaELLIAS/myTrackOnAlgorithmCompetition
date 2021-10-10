int n, m;
int data[]; // 教室余量
int s[], t[], d[]; // 订单
int diff[], need[];
bool isok(int x) // 返回前x个订单是否都可以被满足
{
	memset(diff, 0, sizeof(diff));
	for(int i=1;i<=x;i++)
	{
		diff[s[i]]+=d[i];
		diff[t[i]+1]-=d[i];
	}
	need[0]=0;
	for(int i=1;i<=n;i++)
		need[i]=need[i-1]+diff[i];
	for(int i=1;i<=n;i++)
		if(need[i]>data[i])
			return false;
	return true;
}
int main()
{
	// read
	int l=1,r=m+1,mid;
	while(l<r)
	{
		mid=(l+r)/2; // [l,r] -> [l, mid]/[mid+1,r]
		if(isok(mid)/*前mid个订单可行*/)l=mid+1;
		else r=mid;
	}
	if(l==m+1)cout<<"ok"<<endl;
	else cout<<l<<endl;
}