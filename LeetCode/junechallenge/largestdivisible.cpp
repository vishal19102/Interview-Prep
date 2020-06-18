
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

 vector<int> largestDivisibleSubset(vector<int>& nums) {
       
       sort(nums.begin(), nums.end()) ;

       int* dp = new int [ nums.size() ] ;

       int* dpj = new int [ nums.size() ] ;

       int n = nums.size() ;

       dp[n-1] = 1 ;

       dpj[n-1] = n;

       for(int i = n-2 ; i >= 0 ; i-- ){
       	dp[i] =  1;
       	dpj[i] = i ;

       	for(int j = i+1 ; j < n ; j++ ) { 
       			if(nums[j] % nums[i] == 0  ) { 
       				if(dp[i] < (dp[j] + 1 )){
       					dp[i] = dp[j] + 1 ;
       					dpj[i] = j ;
       				}
       			}
       		}
       }
    

       	int maxidx = 0 ;
       	int maxlength = 0 ;
       	maxlength = dp[0];
       	for(int i = 1 ; i < n ; i++) {
       		if(dp[i] > dp[maxidx]) {
       			maxidx  = i ;
       			maxlength = dp[i];
       		}
       	}


       	vector<int>  res ; 

       	int idx =  maxidx;

       	int curlength =  0 ;
       	while(idx < n && curlength < maxlength   ) { 

       		res.push_back(nums[idx]) ;
       		//trace(idx , nums[idx]);
       		idx = dpj[idx] ;
       		curlength++;

       	}
       	for(auto i: res )
       		trace(i);

       	return res ; 

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
   	vector<int> arr ( n ) ;

   	for(int i = 0 ; i < n ; i++ )
   		cin>>arr[i];

   	largestDivisibleSubset(arr);
    return 0;
}
