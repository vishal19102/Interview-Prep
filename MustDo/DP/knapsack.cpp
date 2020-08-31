#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int maxPossible( int pos ,  vector<int> weights , vector<int> values,int capacity){

    if( pos < 0 ) 
        return 0;

    if(capacity < 0)
        return 0;

    if(dp[pos][capacity]!=-1)
        return dp[pos][capacity];

    int op1 = INT_MIN;

    if(capacity-weights[pos]>=0)
         op1 = values[pos]  + maxPossible(pos-1 , weights,values , capacity-weights[pos]);
    
    int op2 =  maxPossible(pos-1 , weights,values , capacity);

    int ans = max(op1,op2);

    return dp[pos][capacity] = ans ;
    
    }


int main(){
    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        int capacity;
        cin>>capacity;
        vector<int> weights ( n ) , values ( n ) ;
        
        for(int i = 0 ; i < n ;  i++ ) 
            cin>>weights[i];
        
        for(int i = 0 ; i < n ;  i++ ) 
            cin>>values[i];

        memset(dp,-1,sizeof(dp));

        cout<<maxPossible( n-1, weights ,values, capacity)<<endl;
    }
    
     
    return 0;
}
