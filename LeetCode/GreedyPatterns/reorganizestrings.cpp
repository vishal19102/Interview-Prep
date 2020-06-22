
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


string reorganizeString(string S) {
        sort(S.begin(), S.end()) ;
        int i = 0 ; 
        int j = S.length()-1 ;
        string res , res1 ; 
        while( i <= j ) {
        	res += S[i];
        	if(i!=j)
        		res += S[j];
        	res1 += S[j];
        	if(i != j)
        		res1 += S[i];
        	i++;
        	j--;
        }
        int flag = 0 , flag1 = 0 ;
        for(int i = 0 ; i < S.length()-1 ; i++ ) {
        	if(res[i] == res[j]) flag = 1 ;
        }
        for(int j = 0 ; j < S.length()-1 ; j++ ){
        	if(res1[j] == res1[j+1]) flag = 1 ;
        }
        if(!flag) return res ;
        if(!flag1) return res1;
        return "" ;
 }



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    string str ; 
    cin>>str;
    trace(reorganizeString(str));

    return 0;
}
