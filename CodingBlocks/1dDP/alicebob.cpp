
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


int solve(vector<int> &nums , int pos ,int* dp ) { 

	if(pos < 0 )
		return 0 ;

	int op1 = 0 , op2 = 0 ,ans = 0;

	if((nums[pos]-1)==nums[pos-1]){
		op1 = solve(nums,pos-2,dp) + nums[pos];
		op2 = solve(nums,pos-1,dp);
		ans = max(op1,op2);
	}
	else
		ans = solve(nums,pos-1,dp) + nums[pos];

	trace(ans,pos);
	return dp[pos] = ans;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<int> nums ( n );

    for(int i = 0 ; i < n ; i++ )
    	cin>>nums[i];

    sort(nums.begin(), nums.end() , greater<int>() );
    int* dp = new int[n];

    memset(dp,-1,sizeof(dp));

    trace(solve(nums,n-1,dp));
    return 0;
}
