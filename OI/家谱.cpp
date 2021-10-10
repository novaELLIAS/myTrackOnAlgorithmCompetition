#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

/*
struct node{
	char name[6];
};*/
map<string,string> nico;
int father[50001],tot;
node s[50001];

int locat(node a) {
	for(int i=1; i<=tot; i++) {
		if(cmp(s[i],a)) return i;
	}
	tot++;
	s[tot]=a;
	return tot;
}
int find(int x) {
	int k=x;
	while(father[x]!=x) x=father[x];
	while(father[k]!=x) {
		int temp=father[k];
		father[k]=x;
		k=temp;
	}
	return x;
}
void fastread(node read){
	for(int i=0;i<=5;i++) read.name[i]=getchar(); 
}
int main() {
	for(int i=1; i<=50000; i++) father[i]=i;
	char c;
	node s1,s2,s3;
	do {
		c=getchar();
		switch(c) {
			case '#':
				fastread(s1);
				//cin>>s1;
				break;
			case '+':
				fastread(s2);
				//cin>>s2;
				father[find(locat(s2))]=find(locat(s1));
				break;
			case '?':
				fastread(s3);
				//cin>>s3;
				cout<<s3.name<<" "<<s[find(locat(s3))].name<<endl;
				//putchar('\n');
				//printf("%s %s\n",s3.name,s[find(locat(s3))].name);
				//cout<<s3<<" "<<<<endl;
				break;
		}
		getchar();
		//getchar();
	} while(c!='$');
	return 0;
}
