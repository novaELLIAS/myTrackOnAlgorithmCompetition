//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1000005;
const int INF = 23333333;
int n, m, ans = INF;
int nico;
int room[MAXN], dic[MAXN], start[MAXN], end[MAXN];
int temp[MAXN];

bool JUDGE(int mid) {
	int sum = 0;
	if(nico > mid) {
		for(int i = mid + 1; i <= nico; i++) {
			temp[start[i]] -= dic[i];
			temp[end[i] + 1] += dic[i];
		}
	} else {
		for(int i = nico + 1; i <= mid; i++) {
			temp[start[i]] += dic[i];
			temp[end[i] + 1] -= dic[i];
		}
	}
	nico = mid;
	for(int i = 1; i <= n; i++) {
		sum += temp[i];
		if(sum > room[i]) return true;
	}
	return false;
}

int main(void) {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d", &room[i]);
	for(int i=1; i<=m; i++) scanf("%d%d%d", &dic[i], &start[i], &end[i]);
	int l = 1, r = m, mid = 0;
	while(l <= r) {
		mid = (l + r) / 2;
		if(JUDGE(mid)) {
			ans = min(ans, nico);
			r = mid - 1;
		} else l = mid + 1;
	}
	if(ans != INF) printf("-1\n%d", ans);
	else printf("0");
}
