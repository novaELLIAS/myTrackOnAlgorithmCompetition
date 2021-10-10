
int n, m;
int head[MAXN], next[MAXM], to[MAXM], op;
int color[MAXN];

bool dfs(int u)
{
	for(int pos=head[u];pos;pos=next[pos])
	{
		// to[pos]��ʾһ����u�����Ķ��� 
		if(color[to[pos]] == 2)
		{
			color[to[pos]]=1-color[u];
			if(!dfs(to[pos])) return false;
		} else if (color[to[pos]] == color[u]) return false;
	}
	return true;
}

int main()
{
	// init,2��ʾû�б�Ⱦɫ��0��1��ʾ������ɫ 
	for(int i=1;i<=n;i++)
		color[i]=2;
	for(int i=1;i<=n;i++)
		if(color[i]==2)
		{
			color[i]=0;
			if(!dfs(i)){cout<<"NO"<<endl;return 0;}
		}
	cout<<"YES"<<endl;
}
