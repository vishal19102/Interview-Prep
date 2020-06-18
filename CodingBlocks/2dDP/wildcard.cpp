
// Created By Vishal Srivastava .... 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <string>
#include<cstring>
#include<unordered_map>

using namespace std;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif
#define output(x) cout<<x<<"\n";
#define long long int int 
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define mod 1000000007
typedef pair<string,int> pp;


int maxPossible(string &str , string &pat ,int i , int j ,int **dp) {

	if(i == 0 && j == 0 )
		return ((str[i]==pat[j])|| pat[j]=='?'||pat[j]=='*');

	if(j < 0 )
		return 0 ;

	if(i < 0 ){
		for(int l = j ; l >= 0 ;  l-- )
			if(pat[l]!='*')
				return 0;
		return 1;
	}

	if(dp[i][j]!=-1)
		return dp[i][j];

	int op1 = 0 ,op2=0,op3=0,ans=0;
	if(str[i]==pat[j] || pat[j] == '?')	{
		op1 = maxPossible(str,pat,i-1,j-1,dp);
		ans =op1;
	}
	else if (pat[j]=='*'){
		op2 = maxPossible(str,pat,i,j-1,dp);
		op3 = maxPossible(str,pat,i-1,j,dp);
		ans = op2 || op3 ;
	}
	else
		ans = 0;

	dp[i][j] = ans;

	return dp[i][j];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    string str,pat;
    cin>>str>>pat;
    int n = str.length();
    int m = pat.length();

   int** dp = new int*[n];

    for(int i = 0; i < n ; i++ ){
    	dp[i] = new int[m];
    	for(int j = 0 ; j < m ; j++ )
    		dp[i][j] = -1;
    }

    //memset(dp,-1,sizeof(dp));


    // for(int i = 0 ; i < n ; i++ ){
    // 	for(int j = 0 ; j < m ; j++ )
    // 		cout<<dp[i][j]<<" ";
    // 	cout<<endl;
    // }
    cout<<maxPossible(str,pat,n-1,m-1 ,dp)<<endl;
    return 0;
}
