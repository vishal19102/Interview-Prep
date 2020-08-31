// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << std::endl;
    //use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif
bool isKPartitionPossible(int [], int , int );


//  Driver code to test above methods
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;

        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int k;
        cin >> k;
        cout << isKPartitionPossible(a, n, k) << endl;
    }
}// } Driver Code Ends


bool isPossible(int A[] , vector<int> &sums , int pos , int N , int  K ) {

    if (pos >= N ) {
        for (auto i : sums ) cout << i << " ";
        cout << endl ;
        for (int i = 0 ; i < sums.size() - 1   ; i++ ) {
            if (sums[i] != sums[i + 1]) {
                return false ;
            }
        }
        return true;
    }
    for (int i = 0 ; i < K ; i++ ) {
        sums[i] += A[pos];
        if (isPossible(A , sums , pos + 1 , N , K ) == true )
            return true ;
        sums[i] -= A[pos];
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    vector<int>  kSubs (K, 0 ) ;

    bool ans = isPossible(A , kSubs , 0 , N , K ) ;
    return ans ;
}

/*You are required to complete this method */
bool isKPartitionPossible(int A[], int N, int K)
{
    //Your code he
    vector<int>  kSubs (K, 0 ) ;

    bool ans = isPossible(A , kSubs , 0 , N , K ) ;
    return ans ;
}