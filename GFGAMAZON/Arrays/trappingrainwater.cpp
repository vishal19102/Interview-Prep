// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int trappingWater(int arr[], int n) {

    // Your code here
    vector<int> Lmax(n);
    vector<int> Rmax(n);

    int cur_max = arr[0];
    Lmax[0] = arr[0];
    for (int i = 1 ; i < n ; i++ ) {
        cur_max = max(cur_max , arr[i]);
        Lmax[i] = cur_max;
    }
    cur_max = arr[n - 1 ];
    Rmax[n - 1] = arr[n - 1];
    for (int i = n - 2 ; i >= 0 ; i-- ) {
        cur_max = max(cur_max , arr[i]);
        Rmax[i] = cur_max;
    }

    for (auto i : Lmax) cout << i << " ";
    cout << endl;
    for (auto i : Rmax ) cout << i << " ";
    cout << endl;

    int totWater = 0 ;
    for (int i = 0 ; i < n ; i++ ) {
        totWater += min(Lmax[i] , Rmax[i]) - arr[i];
    }
    return totWater;
}


int main() {

    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;

    while (t--) {
        int n;

        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << trappingWater(a, n) << endl;

    }

    return 0;
}