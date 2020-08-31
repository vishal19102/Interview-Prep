
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

int minChange(vector<int> &nums ,int amount , int pos ,int** dp ){

	if(amount < 0 ) return 0;

	if(amount == 0 ) return 1 ;

	if(pos < 0 and amount > 0 ) return 0 ;



	if(dp[pos][amount] != -1 ) return dp[pos][amount];

	int op1 = minChange(nums , amount , pos-1 ,dp);
	int op2 = minChange(nums , amount-nums[pos], pos ,dp);

	int ans = op1 + op2 ;
	return dp[pos][amount] = ans ;
}


int change(int amount, vector<int>& coins) {
        int  n = coins.size();
        int** dp = new int*[n];
        for(int i = 0 ; i < n ; i++ ){
        	dp[i] = new int[amount+1];
        	for(int j = 0 ; j <= amount ; j++) 
        		dp[i][j] = -1;
        }

		int ans = (minChange(coins , amount , n-1,dp));
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
   int n ,amount;
   cin>>amount>>n;
   vector<int> nums ( n );
   for(int i = 0 ; i < n ; i++ ) cin>>nums[i];
   trace(change(amount , nums ));
    return 0;
}
 