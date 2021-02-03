#include <bits/stdc++.h>
using namespace std;
const int maximum = 1001;

int lcs(string s1,string s2,int m,int n,int memo[][maximum]){
    
    if(memo[m][n]!=-1){
        return memo[m][n];
    }
    if(m==0 || n==0){
        memo[m][n]=0;
    }
    
    else{
    
    if(s1[m-1]==s2[n-1]){
        memo[m][n]=1+lcs(s1,s2,m-1,n-1,memo);
    }
    else{
    memo[m][n]=max(lcs(s1,s2,m,n-1,memo),lcs(s1,s2,m-1,n,memo));
    }
    }
    return memo[m][n];
}

int main() {
	// your code goes here
	
	string s1;
	cin>>s1;
	string s2;
	cin>>s2;
	
	int m=s1.length();
	int n=s2.length();
	
	int memo[maximum][maximum];
	memset(memo,-1,sizeof(memo));
	
	cout<<lcs(s1,s2,m,n,memo)<<"\n";
	
	return 0;
}
