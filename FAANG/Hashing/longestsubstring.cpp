
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

int findLongest(string str ) {

	map<char , int> freq ; 

	freq[str[0]] = 0 ; 

	int st = 0 ;
	int en = 1 ;

	int n = str.length();

	int maxlength = 0 ;
	while( en < n ) {
		char ch = str[en];
		if(freq.count(ch) == 0 ) {
			en++ ;
			freq[ch] = en ;
		} 
		else {
			int currmax = en - st ;
			maxlength = max(maxlength , currmax);
			st = freq[ch] + 1 ;
			freq.erase(ch);
			if(st == en )  { 
				freq[ch] = st ; 
				en = st+1 ;

			}
		}
	}
	int lastlength = 0 ;
	if(st < (n-1))
		 lastlength = en - st + 1  ;
	maxlength = max(maxlength, lastlength);
	return maxlength ;
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
   		string str;
   		cin>>str;
   		cout<<(findLongest(str))<<endl;
    }
    return 0;
}
	