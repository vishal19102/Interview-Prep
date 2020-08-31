//  n zeni...

// 5 3 
// 1 1 1 1 1

// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3

// 1 1 1 1 1 . ...

//  ith index ...
//  include ith coin...
//  	ways(i-1 , um -1 ) ;
//  	ways(i-1 , sum + 1 );
//  exclude ith coin... ways(i-1 , sum );


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

int totalWays(vector<int> &nums , int Sum ,int pos , int**  dp){

if (pos < 0) {
  if (Sum == 0)
    return 1;
  else
      return 0;
  }


	if(dp[pos][Sum] != -1 ) return dp[pos][Sum];

	int op2 = totalWays(nums , Sum-nums[pos] , pos-1 , dp);
	int op3 = totalWays(nums , Sum+nums[pos] , pos-1 , dp);

	int ans = op2 + op3;
	trace(pos , Sum );
	return  dp[ pos ][ Sum ] = ans; 
}



int findTargetSumWays(vector<int>& nums, int S) {
      
     int n = nums.size();
     int m = S ; 
   	  int** dp = new int*[n];
        for(int i = 0 ; i < n ; i++ ){
            dp[i] = new int[m+1];
            for(int j = 0 ; j <= m ; j++) 
                dp[i][j] = -1;
        }
       //trace(dp[0][0]);
       int ans = totalWays(nums , S, nums.size()-1 , dp) ; 
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
    int n , sum ;
    cin>>n>>sum;
    vector<int> nums ( n ) ;
    for(int i = 0 ; i < n ; i++ ) cin>>nums[i];
    trace(findTargetSumWays(nums , sum ));
    return 0;
}
