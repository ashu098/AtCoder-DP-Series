#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,w;
	cin>>n>>w;
	
	int wt[n],v[n];
	for(int i=0;i<n;i++) {
		cin>>wt[i]>>v[i];
	}
	
	ll dp[n+1][w+1];
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=w;j++) {
			if(wt[i-1]>j) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = max(dp[i-1][j],v[i-1]+dp[i-1][j-wt[i-1]]);
			}
		}
	}
	
	cout<<dp[n][w];
	
	return 0;
}

