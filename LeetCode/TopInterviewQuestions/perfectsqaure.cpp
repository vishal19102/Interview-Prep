
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

int minnumbers(int n , int* dp ) {

	if(n < 0 ) return INT_MAX ;

	if(n == 0 ) return 0 ;

	if(n == 1 ) return 1 ;

	if(dp[n]!=-1 ) return dp[n];

	int mincurr = INT_MAX;
	for(int i = 1 ; i*i <= n ; i++ ){
		int op1 = minnumbers( (n - i*i) , dp) + 1 ;
		mincurr = min (mincurr , op1 ) ;
	}

	return dp[n] =  mincurr ; 
}


int numSquares(int n) {
        
        int* dp = new int[n+1];
        for(int i = 0 ; i <= n ;i++) dp[i] = -1;
        int ans= minnumbers( n , dp);

        return ans ; 
}




int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int n ; cin>> n ;
    trace(numSquares(n));
    return 0;
}
