#include<cstdio>
#include<stack>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxl=105;

int t,l,w;
string o;
string code[maxl];

int sread(int &x,string c) {
	int res=0;
	int len=c.size();
	while(c[x]<'0' || c[x]>'9'&&x<c.size()) {
		if(c[x]=='n') {
			++x;
			return 1000000;
		}
		++x;
	}
	while(c[x]>='0' && c[x]<='9') {
		res*=10;
		res+=c[x]-'0';
		++x;
	}
	return res;
}

int geto() {
	int res=0,x=3;
	int len=o.size();
	if(o[2]=='n') res=sread(x,o);
	else res=0;
	return res;
}

int check() {
	int res=0,now=0;
	int a,b,x;
	stack<int> s;
	int flag=-1;
	bool ins[26]= {0};
	bool ef[26]= {0};
	for(int i=1; i<=l; i++) {
		if(code[i][0]=='F') {
			int k=code[i][2]-'a';
			if(ins[k]) return -1;
			s.push(k);
			ins[k]=true;
			x=4;
			a=sread(x,code[i]);
			b=sread(x,code[i]);
			//printf("a:%d  b:%d\n",a,b);
			if(b-a>1000) {
				//cout<<"##"<<(char)(k+'a')<<"##"<<endl;
				if(flag==-1) {
					now++;
					res=max(res,now);
					ef[k]=true;
				}
			}
			if(a>b) {
				if(flag==-1) flag=k;
			}
		}
		if(code[i][0]=='E') {
			if(s.empty()) return -1;
			int k=s.top();
			s.pop();
			ins[k]=false;
			if(flag==k) flag=-1;
			if(ef[k]) {
				ef[k]=false;
				now--;
			}
		}
	}
	if(s.size()) return -1;
	return res;
}

int main() {
	//freopen("s.txt","w",stdout);
	scanf("%d",&t);
	while(t--) {
		int ww;
		scanf("%d ",&l);
		getline(cin,o);
		w=geto();
		//printf("w:%d\n",w);
		for(int i=1; i<=l; i++) getline(cin,code[i]);
		//for(int i=1;i<=l;i++) cout<<code[i]<<"###\n";
		ww=check();
		//printf("ww:%d\n",ww);
		//cout<<o<<"##\n";
		if(ww==-1) puts("ERR");
		else {
			if(ww==w) puts("Yes");
			else puts("No");
		}
	}
}
