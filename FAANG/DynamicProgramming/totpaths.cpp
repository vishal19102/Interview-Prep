
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



int totWays(int st ,int en , int** dp , int n  , int m ){

	if(st == (n-1 ) and en == (m-1 ) ) return 1 ; 

	if(st >= n or en >= m ) return 0;

	if(dp[st][en]!=-1 ) return dp[st][en];

	int op1 = totWays(st+1,en,dp,n , m);
	int op2 = totWays(st,en+1,dp,n , m);
	int ans = op1 + op2 ;

	return dp[st][en] = ans ;
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
   		int n , m;
   		cin>>n>>m;
   			int**dp = new int*[n] ;
   				for(int i  = 0 ; i < n ; i++ ){
   					dp[i] = new int[m];
   					for(int j = 0; j < m ;j++ )
   						dp[i][j] = -1;
   					
   		    }
   		cout<<totWays(0 , 0 , dp, n , m)<<endl;
    }
    return 0;
}
	