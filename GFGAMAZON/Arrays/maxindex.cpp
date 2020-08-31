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
int maxIndexDiff(int arr[], int n)
{

    // Your code here
    vector<int> Lmin( n );
    vector<int> Rmax(n);

    int cur_min = arr[0];
    Lmin[0] = cur_min;
    for (int i = 1 ; i < n ; i++ ) {
        cur_min = min(cur_min , arr[i]);
        Lmin[i] = cur_min;
    }
    int cur_max = arr[n - 1];
    Rmax[n - 1] = cur_max;
    for (int i = n - 2 ; i >= 0; i-- ) {
        cur_max = max(cur_max , arr[i]);
        Rmax[i] = cur_max;
    }
    int i = 0;
    int j = 0 ;

    int max_difference = 0 ;
    while ( i < n and j < n ) {

        if (Lmin[i] <= Rmax[j]) {
            trace(Lmin[i] , Rmax[j]);
            max_difference = max(max_difference , j - i ) ;
            j++;
        }
        else {
            i++;
        }
    }

    return max_difference ;
}

int main()
{
    int T;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> T;
    while (T--) {
        int num;
        cin >> num;
        int arr[num];
        for (int i = 0; i < num; i++)
            cin >> arr[i];

        if (num == 1 ) {
            cout << 0 << endl;
            continue;
        }
        cout << maxIndexDiff(arr, num) << endl;

    }
    return 0;
}   // } Driver Code Eds