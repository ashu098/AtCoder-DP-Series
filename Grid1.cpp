#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

int total_path(char c[1002][1002],int n,int m) {
	// bottom up dp
	int dp[n][m];
	
	int f=0;
	// if there is single columm than max path would be 1 if there is empty square else 0
	for(int i=n-1;i>=0;i--) {
		if(c[i][m-1] == '.' && f == 0) {
			dp[i][m-1] = 1;
		}
		else {
			dp[i][m-1] = 0;
			f = 1;
		}
	}
	
	f=0;
	// if there is single row than max path would be 1 if there is empty square else 0
	for(int i=m-2;i>=0;i--) {
		if(c[n-1][i] == '.' && f == 0) {
			dp[n-1][i] = 1;
		}
		else {
			dp[n-1][i] = 0;
			f = 1;
		}
	}
	
	for(int i=n-2;i>=0;i--) {
		for(int j=m-2;j>=0;j--) {
			if(c[i][j] == '.') {
				// calculate from right and down path
				ll temp;
				temp = (dp[i+1][j]+ dp[i][j+1])%mod;
				dp[i][j] = temp;
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	
	// return total path from position 0
	return dp[0][0];
}

void input() {
	int h,w;
	cin>>h>>w;
	
	char c[1002][1002];
	for(int i=0;i<h;i++) {
		for(int j=0;j<w;j++) {
			cin>>c[i][j];
		}
	}
	
	int ans = total_path(c,h,w);
	
	cout<<ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	input();
	
	return 0;
}

