// { Driver Code Starts
// C program for implementation of Merge Sort
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

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
}
void merge(int arr[], int left, int mid, int right)
{
    int* temp = new int [ right - left + 1 ] ;
    int i = left ;
    int j = mid + 1 ;
    int k = 0 ;
    while ( i <= mid and  j <= right ) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    while ( i <= mid ) temp[k++] = arr[i++];

    while (j <= right ) temp[k++] = arr[j++];

    for (int  i = left ; i <= right  ; i++ ) {
        arr[i] = temp[i - left ] ;
    }

    return ;
}