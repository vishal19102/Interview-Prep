// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int minimumJumps(int[], int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << minimumJumps(arr, n) << endl;
    }
    return 0;
}

// function to find minimum number of jumps to reach end of the array
int minimumJumps(int arr[], int n) {

    // your code here
    int pos = 0 ;
    int des = 0;
    int jumps = 0 ;

    for (int i = 0 ; i < n - 1 ; i++ ) {
        des = max(des , i + arr[i]);

        if (pos == i ) {
            pos = des;
            jumps++;
        }

    }

    return jumps ;
}
