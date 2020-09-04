#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

int dp_table(int wt[],int val[],int capacity,int tot_item) {
	/*
	
	1<=W<=10^9
	
	so we can't make dp table for weight due to it's large range
	instead we check for value we can reach within our knapsack capacity
	
	so dp table look like dp[tot_items][sum of value of all items]
	
	because maximum it can goes upto 10^5 and within our limit so we can make dp table
	
	*/
	
	int tot_val=0; //total value of items
	for(int i=0;i<tot_item;i++) {
		tot_val += val[i];
	}
	
	ll dp[tot_item+1][tot_val+1];
	
	for(int i=0;i<=tot_item;i++) {
		dp[i][0] = 0;
	}
	
	for(int i=0;i<=tot_val;i++) {
		if(i == 0) {
			continue;
		}
		dp[0][i] = INT_MAX;
	}
	
	
	for(int i=1;i<=tot_item;i++) {
		for(int j=1;j<=tot_val;j++) {
			if(j<val[i-1]) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = min(dp[i-1][j],wt[i-1]+dp[i-1][j-val[i-1]]); // current value with minimum weight
			}
		}
	}
	
	
	for(int i=tot_val;i>=0;i--) {
		if(dp[tot_item][i] <= capacity) {
			return i;
		}
	}
	
}

void input() {
	int tot_item,capacity;
	cin>>tot_item>>capacity;
	
	int wt[tot_item],val[tot_item];
	for(int i=0;i<tot_item;i++) {
		cin>>wt[i]>>val[i];
	}
	
	int ans = dp_table(wt,val,capacity,tot_item);
	
	cout<<ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	input();
	
	return 0;
}

