// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}

bool isValid(int i , int j , vector<int> matrix[] , vector<vector<bool> > &visited , int M , int  N ) {

    if ((i >= 0 and i < N ) and (j >= 0 and j < M ) and (matrix[i][j] == 1)  and visited[i][j] == false )
        return true ;

    return false ;
}

int countTot = 0 ;
void dfs(int i , int j , vector<vector<bool>> &visited , vector<int> matrix[] , int M , int N ) {


    visited[i][j] = true;

    int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    countTot++;
    for (int steps = 0 ; steps < 8 ; steps++  ) {
        if (isValid(i + dx[steps] , j + dy[steps] , matrix , visited , M , N )) {
            dfs(i + dx[steps]  , j + dy[steps] , visited , matrix , M , N  );
        }
    }
}




int findIslands(vector<int> A[], int N, int M) {

    vector<vector<bool>> visited (N , vector<bool> (M , false )) ;

    int cc = 0 ;
    for (int i = 0 ; i < N ; i++ ) {
        for (int j = 0 ; j < M ; j++ ) {
            if (isValid(i , j , A , visited , M , N )) {
                dfs(i , j , visited , A , M , N );
                cc++;
            }
        }
    }
    return cc;
}
