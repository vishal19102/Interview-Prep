
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



 int minAddToMakeValid(string S) {	
      
      int count = 0 ;
      int i = 0 , j = 1;

      int length = S.length();

      while( i < length and j < length) {
      	char a = S[i];
      	char b = S[j];
      	if( a == '(' and b == ')' ){
      		i+= 2 ;
      		j = i + 1;
      	}
      	else if ( a == '(' and b == '(' ){
      		count++;
      		i = i + 1;
      		j = j + 1 ;
      	}
      	else if ( a == ')' and S[i-1] == ')' ) {
      		i++;
      		j = i + 1 ;
      		count++;
      	}
      }
      if(j == length ){
      	if(S[j-1] == '(') count++;
      	else if (S[j-1] == ')' and S[j-2] != '(' ) count++;
      }
      return count ;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    
    string str; 
    cin>>str;
    trace(minAddToMakeValid(str));
    return 0;
}
