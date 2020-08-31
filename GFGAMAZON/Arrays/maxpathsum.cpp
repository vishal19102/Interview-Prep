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




int max_path_sum(int [], int [], int , int );

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
        int N, M;
        cin >> N >> M;
        fflush(stdin);
        int a[N], b[M];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = 0; i < M; i++)
            cin >> b[i];
        int result = max_path_sum(a, b, N, M);
        cout << result << endl;
    }
}

// } Driver Code Ends


/*You are required to complete this method*/
int max_path_sum(int A[], int B[], int l1, int l2)
{

    //Your code here
    int sum1 = 0 ;
    int sum2 = 0 ;

    int i = 0 ;
    int j = 0 ;

    int results = 0 ;
    while ( i < l1 and j < l2 ) {

        if (A[i] < B[j]) {
            sum1 += A[i];
            i++ ;
        }
        else if (A[i] > B[j]) {
            sum2 += B[j];
            j++;
        }
        else {
            results += max (sum1 , sum2 ) ;
            sum1 = 0 ;
            sum2 = 0 ;
            while (i < l1 and j < l2 and A[i] == B[j]) {
                results = results + A[i];
                i++;
                j++;
            }
        }
    }

    while (i < l1 ) {
        sum1 += A[i++];
    }
    while (j < l2 ) {
        sum2 += B[j];
        j++;
    }

    results += max(sum2 , sum1 );


    return results ;
}