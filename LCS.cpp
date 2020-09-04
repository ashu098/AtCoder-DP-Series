#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

int dp[3003][3003];

string extract_string(int dp[3003][3003],int n,int m,string s) {
	
	int i=n,j=m,k = dp[n][m];
	string ans="";
	
	while(i>=0 && j>=0 && k>0) {
		for(;i>=0;i--) {
			if(dp[i][j] != k) {
				break;
			}
		}
		
		i += 1;
		
		for(;j>=0;j--) {
			if(dp[i][j] != k) {
				break;
			}
		}
		
		j += 1;
		
		ans += s[j-1];
		i -= 1;
		j -= 1;
		k = dp[i][j];
	}
	
	reverse(ans.begin(),ans.end());
	
	return ans;
}

string lcs(string s,string t) {
	
	memset(dp,0,sizeof(dp)); // initalize 2d dp array with 0
	
	for(int i=1;i<=s.size();i++) {
		for(int j=1;j<=t.size();j++) {
			if(s[i-1] == t[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	string ans = extract_string(dp,s.size(),t.size(),t); // extract common subsequence string from dp table
	
	return ans;
}

void input() {
	string s,t;
	cin>>s>>t;
	
	string k = lcs(s,t);
	cout<<k;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	input();
	
	return 0;
}

