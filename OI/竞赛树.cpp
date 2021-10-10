
const int INF = 0x7fffffff/2;
// 竞赛树
struct HH
{
	int data[MAXN*2];
	int n;
	HH(int n)
	{
		this->n=n;
		for(int i=1;i<=2*n-1;i++)data[i]=-INF;
	}
	void Update(int pos, int value) // 将第pos个值修改为value
	{
		pos=pos+n-1;
		data[pos]=value;
		while(pos/=2) data[pos]=max(data[pos*2], data[pos*2+1]);
	}
	int Top() { return data[1]; } // 返回最大值
	int TopPos() // 返回最大值的位置
	{
		int pos=1;
		while(pos<n)//非叶节点
		{
			if(data[pos]==data[pos*2])pos=pos*2;
			else pos=pos*2+1;
		}
		return pos-n+1;
	}
};
