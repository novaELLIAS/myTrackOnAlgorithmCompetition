#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[5001];
int lens;
int main(){
	cin>>s;
	lens=strlen(s);
	for(int i=lens-1;i>=0;i--){
		cout<<s[i];
	}
	return 0;
}
