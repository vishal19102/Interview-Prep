
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

vector<int> getDiagonal(vector<vector<int> > &A , int sum , int flag ,  int st  ){

	vector<int>  cur ; 

	if(flag ==0  ){
		int i = 0  ; 
		int j = sum ; 
		while ( i <= sum  ){
			cur.push_back(A[i][j]);
			i++;
			j--;
		}
	}
	else{
		int i = st  ; 
		int j = sum-st ; 
		while ( i < sum  ){
			cur.push_back(A[i][j]);
			i++;
			j--;
		}
	}
	
	return cur ; 
}


vector<vector<int>> diagonal(vector<vector<int> > &A) {

	vector<vector<int> >  res ;

	int maxlength = A.size() - 1 ; 

	int i = 0 ; 

	int flag = 0 ;
	while( i <=  maxlength ){

		vector<int> currrow = getDiagonal ( A , i , flag , 0);
		res.push_back(currrow);
		i++;
	}
	flag = 1 ; 
	maxlength =2 *  (A.size() - 1);
	int j = 1 ;
	while( i <=  maxlength ){

		vector<int> currrow = getDiagonal ( A , i , flag , j);
		res.push_back(currrow);
		i++;
		j++;
	}
	for(auto i : res ) {
		for(auto  j :  i ) cout<<j<<" ";
		cout<<endl;
	}
	return res;
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
    vector<vector<int> > nums ( n );
    for(int i = 0 ; i < n ; i++ ) {
    	nums[i] = vector<int> ( n );
    	for(int j = 0 ; j < n ; j++ ){
    		cin>>nums[i][j];
    	}
    }
    diagonal(nums);
    return 0;
}
