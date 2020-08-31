// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void sort012(int[], int);

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort012(a, n);

        for (int i = 0; i < n; i++) {
            cout << a[i]  << " ";
        }

        cout << endl;


    }
    return 0;
}

// } Driver Code Ends
void sortColors(vector<int>& a) {
    int low = 0 ;
    int mid = 0;
    int high = n - 1;

    while (mid <= high ) {

        if (a[mid] == 0) {
            int t = a[mid];
            a[mid] = a[low];
            a[low] = t;
            low++;
            mid++;
        }
        if (a[mid] == 1) {
            mid++;
        }
        if (a[mid] == 2) {
            int t = a[mid];
            a[mid] = a[high];
            a[high] = t;
            high--;
        }
    }
}

void sort012(int a[], int n)
{
    // coode here
    int low = 0 ;
    int mid = 0;
    int high = n - 1;

    while (mid <= high ) {

        if (a[mid] == 0) {
            int t = a[mid];
            a[mid] = a[low];
            a[low] = t;
            low++;
            mid++;
        }
        if (a[mid] == 1) {
            mid++;
        }
        if (a[mid] == 2) {
            int t = a[mid];
            a[mid] = a[high];
            a[high] = t;
            high--;
        }
    }
}