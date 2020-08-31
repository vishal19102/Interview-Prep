
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
#include<numeric>

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


//int ans =INT_MAX ;

int minSum(int pos ,int S1,int S2 ,vector<int> &nums , int** dp ){

	if(pos >= nums.size()){
		return abs(S1-S2) ; 
	}
	if(dp[pos][S1] != -1 ) return dp[pos][S1]; 

	int op1 = minSum(pos+1, S1 + nums[pos] , S2 , nums ,dp);
	int op2 = minSum(pos+1, S1  , S2 + nums[pos], nums ,dp);

	int ans = min(op1 , op2 ) ; 

	return dp[pos][S1] = ans ; 
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
   	int n ;
   	cin>>n;
   	vector<int> nums ( n );
   	for(int i = 0 ; i < n ; i++ ) cin>>nums[i];
	int**dp = new int*[n] ;
	int m = accumulate(nums.begin(), nums.end(), 0);
		for(int i  = 0 ; i < n ; i++ ){
			dp[i] = new int[m];
			for(int j = 0; j < m ;j++ )
				dp[i][j] = -1;
			
    }
   	cout<<(minSum( 0 , 0 , 0 , nums ,dp))<<endl;
   	}
    return 0;
}
