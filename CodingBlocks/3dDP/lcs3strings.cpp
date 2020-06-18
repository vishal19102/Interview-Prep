
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

string st1 ,st2 ,st3 ;

int dp[201][201][201];

int maxlength(int i , int j , int k ) {


	if( i < 0 || j < 0 || k < 0 )
		return 0 ;
	
	int ans = 0 ;	

	if( dp[i][j][k]!=-1 )  return dp[i][j][k];


	if(st1[i]==st2[j] && st1[i]==st3[k]){
		ans = maxlength(i-1,j-1,k-1) +  1;
	}
	else
		ans = max ( maxlength(i-1,j,k) , max(maxlength(i,j-1,k )  , maxlength(i,j,k-1) ));
	
	return dp[i][j][k] =  ans ;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif

	cin>>st1>>st2>>st3;
	memset(dp , -1, sizeof dp );

	cout<< maxlength( st1.length()-1 , st2.length()-1 , st3.length()-1 )<<endl ; 

    return 0;
}
