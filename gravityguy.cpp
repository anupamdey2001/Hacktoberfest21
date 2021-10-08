#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    string l1,l2;
	    cin>>l1>>l2;
	    int n=l1.length();
	    vector<vector<int>> dp(2,vector<int>(n+1,INT_MAX));
	    dp[0][0]=0;
	    dp[1][0]=0;
	    if(l1[0]=='.')
	    dp[0][1]=0;
	    if(l2[0]=='.')
	    dp[1][1]=0;
	    for(int i=2;i<=n;i++){
	        if(dp[0][i-1]==INT_MAX&&dp[1][i-1]==INT_MAX)
	        break;
	        if(l1[i-1]=='.'){
	            if(dp[0][i-1]!=INT_MAX)
	            dp[0][i]=dp[0][i-1];
	            else
	            dp[0][i]=dp[1][i-1]+1;
	        }else{
	            dp[0][i]=INT_MAX;
	        }
	        if(l2[i-1]=='.'){
	            if(dp[1][i-1]!=INT_MAX)
	            dp[1][i]=dp[1][i-1];
	            else
	            dp[1][i]=dp[0][i-1]+1;
	        }else{
	            dp[1][i]=INT_MAX;
	        }
	    }
	    if(dp[0][n]==INT_MAX&&dp[1][n]==INT_MAX)
	       cout<<"No";
	   else
	   cout<<"Yes"<<"\n"<<min(dp[0][n],dp[1][n]);
	   cout<<"\n";
	}
	return 0;
}
