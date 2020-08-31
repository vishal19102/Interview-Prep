// { Driver Code Starts
#include<bits/stdc++.h>
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
int maxSubarraySum(int* arr, int n) {

    int max_so_far = 0 ;
    int max_curr = 0 ;
    for (int i = 0 ; i < n ; i++ ) {

        max_curr += arr[i];
        max_so_far = max(max_so_far , max_curr);
        if (max_curr < 0 ) max_curr = 0;
    }
    return max_so_far;
}

int circularSubarraySum(int nums[], int n) {


    int max_elem = *(max_element(nums, nums + n ));
    if (max_elem < 0 ) return max_elem;

    int tot_sum = 0 ;

    int max_sb_sum = maxSubarraySum(nums , n );
    for (int i = 0 ; i < n ; i++ ) {
        nums[i] = -nums[i];
        tot_sum += nums[i];
    }

    int min_sb_sum = maxSubarraySum(nums , n );
    int ans = -(tot_sum - min_sb_sum );
    ans = max(ans , max_sb_sum);
    return ans ;
}


// { Driver Code Starts.

int main()
{
    int T;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> T;

    while (T--)
    {
        int num;
        cin >> num;
        int arr[num];
        for (int i = 0; i < num; i++)
            cin >> arr[i];


        cout << circularSubarraySum(arr, num) << endl;

    }

    return 0;
}  // } Driver Code Ends