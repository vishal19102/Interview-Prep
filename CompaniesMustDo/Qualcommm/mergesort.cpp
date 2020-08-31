// { Driver Code Starts
// C program for implementation of Merge Sort
#include <stdio.h>
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
void merge(int arr[], int l, int m, int r);

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int n, T, i;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    scanf("%d", &T);

    while (T--) {

        scanf("%d", &n);
        int arr[n + 1];
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        mergeSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}// } Driver Code Ends


/* The task is to complete merge() which is used
   in below mergeSort() */
/*   l is for left index and r is right index of the
   sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
} */

// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    // Your code here
    vector<int> arr1 ;
    vector<int> arr2 ;

    for (int i = l ; i <= m ; i++)
        arr1.push_back(arr[i]);

    for (int i = m + 1 ; i <= r ; i++ )
        arr2.push_back(arr[i]);

    vector<int> res;

    int i = 0, j = 0;
    while ( i < arr1.size() and j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            res.push_back(arr1[i]);
            i++;
        }
        else if (arr2[j] < arr1[i]) {
            res.push_back(arr2[j]);
            j++;
        }
        else {
            res.push_back(arr1[i]);
            res.push_back(arr2[j]);
            i++;
            j++;
        }
        trace(res[res.size() - 1]);
    }

    while ( i < arr1.size()) res.push_back(arr1[i++]);

    while ( j < arr2.size()) res.push_back(arr2[j++]);


    for (int i = l ; i <= r ; i++ ) {
        //trace(res[i]);
        arr[i] = res[i];
    }
}