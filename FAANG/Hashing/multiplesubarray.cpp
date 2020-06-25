
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


bool checkSubarraySum(vector<int>& nums, int k) {
    
        vector<int> prefixsum ( nums.size()); 
        
        prefixsum[0] = nums[0];
        for(int i = 1; i < nums.size() ; i++ ) {
        	prefixsum[i] = prefixsum[i-1] + nums[i];
        }

        int n = prefixsum.size();
        for(int i = 0; i < n ; i++ ) {
        	for(int j = i+1 ; j < n ; i++ ) {
        		if((prefixsum[j] - prefixsum[i]) % k == 0 ) return true;
        	}
        }
        return false ;
}

vector<int> StringInt( char* str ) {
	str++;
	str[strlen(str)-1] = 0;
	vector<int>  nums ;
	char* token = strtok(str , " ," );
	while(token != NULL ){
		nums.push_back(stoi(token));
		token = strtok(NULL ,",");
	}
	return nums;
} 


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    
    char str[200000]; 
    cin>>str;
    vector<int> nums = StringInt(str);
    int k;	
	cin>>k;
	cout<<(checkSubarraySum(nums,k))<<endl;

    return 0;
}
