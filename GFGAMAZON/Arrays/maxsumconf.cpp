// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[], int N);

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
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        cout << max_sum(A, N) << endl;

    }
}

/*You are required to complete this method*/
int max_sum(int A[], int N)
{
//Your code here
    int cum_sum = 0 ;
    for (int i = 0 ; i < N ; i++ )
        cum_sum += A[i];

    int cur_conf_sum =  0 ;

    for (int i = 0 ; i < N ; i++ )
        cur_conf_sum += i * A[i];

    int max_so_far = cur_conf_sum  ;
    for (int i = 1 ; i < N ; i++ ) {
        int new_sum = cur_conf_sum - (cum_sum - A[i - 1]) + (N - 1) * A[i - 1 ];
        cur_conf_sum = new_sum ;
        max_so_far = max(max_so_far , new_sum ) ;
    }
    return max_so_far;
}