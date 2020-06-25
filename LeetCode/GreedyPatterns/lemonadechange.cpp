
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

bool ifPossible(int bill , map<int,int> &changes ) {

	int count20 = changes[20];
	int count10 = changes[10];
	int count5 = changes[5];

	int count = 0; 
	while(bill >= 20 && count20 != 0 ) {
		count20--;
		bill -= 20 ;  
	}
	while(bill >= 10 && count10 != 0 ) {
		count10--;
		bill -= 10;
	}
	while(bill >= 5 && count5 != 0 ) {
		count5--;
		bill -= 5;
	}
	changes[5] = count5;
	changes[10] = count10;
	changes[20] = count20;

	if(bill == 0 ) return true ; 
	else return false ;
}

bool lemonadeChange(vector<int>& bills) {
        
        int change = 0 ; 

        map<int , int > changecount ; 

        int n = bills.size();
        for(int i = 0 ; i < n ; i++ ) {
        	if(bills[i] > 5 ) {
        		int returnchange = bills[i] - 5 ;

       			if(ifPossible(returnchange , changecount)){
       				changecount[bills[i]] += 1 ; 
       			}
       			else return false ;

        	}
        	else{
        		changecount[bills[i]] += 1  ;
        	}
        }
        return true ; 
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
    vector<int> nums ( n ); 
    for(int i = 0 ; i < n ; i++ ) cin>>nums[i];

    trace(lemonadeChange(nums ));

    return 0;
}
