
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


// vector<vector<int> >  dp(1000);

// int maxPossible(vector<int>  &nums , int pos , int sum ) { 

// 	if(pos < 0 ){
// 		if(sum==0)
// 			return 1 ;
// 		else
// 			return 0 ;
// 	}

// 	if(dp[pos][sum] !=-1){
// 		return dp[pos][sum];
// 	}

// 	int op1 =0 , op2=0;

// 	if(sum-nums[pos] >= 0)
// 		op1 = maxPossible(nums , pos-1 , sum - nums[pos]);
// 	op2 = maxPossible(nums , pos-1 , sum);
// 	int ans = op1 + op2 ;

// 	return dp[pos][sum] =  ans;
// }

int maxPossibleDP(vector<int>  &nums , int sum ) { 

	int n = nums.size();


	int dp[3][sum+1];

	for(int i = 0 ; i <= 2 ; i++ )
		dp[i][0]  = 1;

	for(int i = 0; i <=sum ; i++ )
		dp[0][i] = 0 ;


	for(int i =1 ; i <= n ; i++ ){
		for(int j = 1 ; j <=sum ; j++ ) {
			if((sum-nums[i]) >= 0 ) 
				dp[i%2][j] = dp[(i-1)%2][j-nums[i]] || dp[(i-1)%2][j];
			else
				dp[i%2][j] = dp[(i-1)%2][j];

		}
	}

	if(dp[n%2][sum] > 0 )
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

	return dp[n%2][sum];
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int n ;
    cin>>n;
    int sum ;
    cin>>sum;
    vector<int> nums ( n+1 );

    nums[0] = 0 ;

    for(int i  = 1 ; i <= n ; i++ )
    	cin>>nums[i];

    (maxPossibleDP(nums,sum));
    return 0;
}
