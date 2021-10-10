#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

string in;
bool ans;
int lenin;

int main(void){
	cin>>in;
	lenin=in.size();
	if(lenin%2==0){
		printf("No");
		exit(0);
	}
	for(int i=1;i<lenin;i+=2){
		if((in[i]=='#' and in[i+1]!='#') or (in[i+1]=='#' and in[i]!='#')){
			printf("No");
			exit(0);
		}
	}
	printf("Yes");
} 
