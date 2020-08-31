
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


int LCS(string str1,string str2 , int i , int j ,int** dp){

	if( i == 0 and j == 0 ){
		return str1[i] ==str2[j];
	}

	if(i < 0 or j < 0 ) return 0 ;	

	if(dp[i][j] != -1 ) return dp[i][j];

	int ans = 0 ; 

	if(str1[i] == str2[j]){
		ans = LCS(str1,str2,i-1,j-1 ,dp ) + 1;
	}
	else{
		ans = max(LCS(str1,str2,i-1,j , dp) , LCS(str1,str2,i,j-1 , dp )  );
	}
	return dp[i][j] = ans ;
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    string str1,str2;
    cin>>str1>>str2;
    int n = str1.length();
    int m =str2.length();
	int** dp = new int*[n];
        for(int i = 0 ; i < n ; i++ ){
            dp[i] = new int[m];
            for(int j = 0 ; j < m ; j++) 
                dp[i][j] = -1;
        }
    cout<<(LCS(str1,str2 , n-1, m-1 ,dp))<<endl;

    return 0;
}
