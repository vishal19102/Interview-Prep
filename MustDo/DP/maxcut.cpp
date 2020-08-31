
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


int maxCut(int n , int* dp ,vector<int> &nums){

	if(n== 0 ) return 0;

	if( n < 0 ) return INT_MIN;


	if(dp[n] != -1 ) return dp[n];

	
	int op1 = maxCut(n-nums[0] , dp , nums );
	int op2 = maxCut(n-nums[1] , dp , nums );
	int op3 = maxCut(n-nums[2] , dp , nums );

	int ans = max(op1,max(op2,op3)) + 1 ;

	return dp[n] = ans;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    cin>>t;
    while(t--){
   		int nn ;
   		cin>>nn ;
   		int n = 3 ;
   		vector<int> nums ( n );
   		for(int i = 0 ; i < n ; i++ ) cin>>nums[i];
   		int* dp = new int[nn+1];
   		for(int i = 0 ; i <= nn ; i++ ) dp[i] = -1;
   		cout<<maxCut( nn ,dp ,nums)<<endl;
    }
    return 0;
}
 