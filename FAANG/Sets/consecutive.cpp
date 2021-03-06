
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

int longestconsecutive(vector<int> & numbers ) { 


	int ans = 0 ; 

	set<int>  arr ( numbers.begin() , numbers.end() ) ;

	for(int i = 0; i < numbers.size() ; i++  ) { 

		int currelem = numbers[i];
		int templength = 0 ;

		while(arr.count(currelem)!=0) { 
			templength++ ;
			currelem++;

		}
		templength--;
		currelem = numbers[i];
		while(arr.count(currelem)!=0) { 
			templength++ ;
			currelem--;

		}

		ans = max ( ans , templength ) ;
		//trace(templength);

	}


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
    vector<int> numbers;

    for(int i = 0;i < n ; i++ ){
    	int a;
    	cin>>a;
    	numbers.push_back(a);
    }
   	cout<< longestconsecutive(numbers)<< endl;
    return 0;
}