
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


int solve(vector<string> &A) {
	double mi1 = INT_MAX, mi2 = INT_MAX , mi3 = INT_MAX ;

z
	for(int i  = 0 ;  i < A.size() ; i++ ){
		if(stod(A[i]) < mi1 ){
			mi3 = mi2 ;
			mi2 = mi1 ;
			mi1 = stod(A[i]);
		}
		else if (stod(A[i]) < mi2 ){
			mi3 = mi2;
			mi2 = stod(A[i]);
		}
		else if (stod(A[i]) < mi3 ){
			mi3 = stod(A[i]);
		}
	}
	double summ = mi1+mi2+mi3 ;
	if(summ > 1 and summ < 2) return 1;
	else return 0 ; 
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
  	vector<string> nums ( n );
  	for(int i = 0 ; i < n ; i++ ) cin>>nums[i];
  	solve(nums);
    return 0;
}
