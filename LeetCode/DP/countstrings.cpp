
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


int totnumbers(int pos , int** dp , int num  , int n ) {

        //trace(num , pos );
        if(pos < 0 ) return 1 ;
        
        if(pos == 0 ) {
            if( num < n ) 
                return 2  ;
            else 
                return 1 ;
        }
        
        if(dp[pos][num] !=-1) return dp[pos][num];
        
        int op1 = totnumbers(pos-1 , dp , num , n ) ;
        
        num = num +pow(2,pos);
        int op2 = totnumbers(pos-2 , dp , num , n ) ;
        
        int ans = op1 + op2 ;
        return dp[pos][num] = ans;
    }
    int findIntegers(int num) {
        
        
        int bits = (int)log2(num)+1;
        int** dp = new int*[ bits ] ;
        for(int i = 0 ; i< bits ; i++ ) {
            int s = pow(2 , i+1 );
            dp[i] = new int[ s ];
            for(int j = 0 ; j < s ; j++ ) dp[i][j] = -1 ;
        }

        //memset(dp , -1 , sizeof(dp)); 
        //trace(bits);
        int ans = totnumbers(bits-1 , dp , 0 , num );

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
    int n ;
    cin>>n;
    trace(findIntegers(n));
    return 0;
}
