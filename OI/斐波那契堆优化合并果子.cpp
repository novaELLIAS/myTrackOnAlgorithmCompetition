#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
__gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag>nico;
int n,temp,tot;
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d",&temp);
        nico.push(temp);
    }
    while(true) {
        int k=nico.top();
        nico.pop();
        int s=nico.top();
        nico.pop();
        tot+=s+k;
        if(nico.empty()) break;
        nico.push(s+k);
    }
    printf("%d",tot);
    return 0;
} 
