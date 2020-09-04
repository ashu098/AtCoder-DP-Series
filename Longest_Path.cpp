#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

int dfs(vector<int> g[],int dp[], int x) {
	//if value of node in dp array is -1 than perform dfs
	if(dp[x] != -1) {
		return dp[x];
	}
	
	int temp = 0;
	for(auto it:g[x]) {
		temp = max(temp,dfs(g,dp,it)+1);
	}
	
	dp[x] = temp;
	return temp;
}

int longest_path(vector<int> g[],int n) {
	
	int dp[n];
	for(int i=0;i<n;i++) {
		dp[i] = -1;
	}
	
	// check for all nodes if value of node in dp array is -1 than perform dfs
	for(int i=0;i<n;i++) {
		if(dp[i] == -1) {
			dfs(g,dp,i);
		}
	}
	
	int ans=0;
	for(int i=0;i<n;i++) {
		ans = max(ans,dp[i]);// return longest path from dp array
	}
	
	return ans;
}

void input() {
	int n,m;
	cin>>n>>m;
	
	vector<int> g[n];
	
	for(int i=0;i<m;i++) {
		int x,y;	
		cin>>x>>y;
		
		x -= 1;
		y -= 1;
		
		g[x].push_back(y);
	}
	
	int ans = longest_path(g,n);
	
	cout<<ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	input();
	
	return 0;
}

