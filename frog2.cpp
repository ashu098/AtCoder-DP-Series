#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,k;
	cin>>n>>k;
	
	int h[n];
	for(int i=0;i<n;i++) {
		cin>>h[i];
	}
	
	if(n<=k) {
		int ans = abs(h[0]-h[n-1]);
		cout<<ans;
		return 0;
	}
	
	int dp[n];
	for(int i=0;i<=k;i++) {
		if(!i) {
			dp[i] = 0;
		}
		else {
			dp[i] = abs(h[i]-h[0]);
		}
	}
	
	for(int i=k+1;i<n;i++) {
		dp[i] = INT_MAX;
		for(int j=i-1;j>=(i-k);j--) {
			dp[i] = min(dp[i],(dp[j]+abs(h[i]-h[j])));
		}
	}
	
	cout<<dp[n-1];
	
	return 0;
}

