
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

	
bool ifPossible(string &str, string &pat ){

	int n = str.length();
	int m = pat.length();

	vector<bool>  pre ( m+1 , false) ,cur ( m+1 , false  ); 

	 cur[0] = true ; 

	for(int i = 1; i <= n ; i++ ){
		for(int j = 1 ; j <= m ; j++ ){
			trace(i,j);
			if(str[i]==pat[j]|| pat[j]=='.')
				cur[j] = pre[j-1] ;
			else if ( pat[j]=='*' && str[i]==pat[j-1]){
				cur[j] = pre[j] || pre[j-1];
			}
			else if(pat[j]=='*' && str[i-1]!=pat[j])
				cur[j] =  false;
		}
		fill(pre.begin(), pre.end() , false);
		swap(pre,cur);
	}
	return pre[m-1];
}	

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    string str,pat;
    cin>>str>>pat;

    trace(ifPossible(str,pat));
    return 0;
}
