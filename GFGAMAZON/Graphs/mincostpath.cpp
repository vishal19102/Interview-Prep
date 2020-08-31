// { Driver Code Starts
// Initial template for C++

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
int shortest(vector<vector<int> > &grid , int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int> > grid(n);

        for (int i = 0; i < n; i++)
        {
            grid[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }

        cout << shortest(grid, n) << endl;
    }
    return 0;
}

bool isValid(int posX, int posY , int n ) {

    if (posX < 0 or posY < 0 ) return false;

    if (posX >= n or posY >= n ) return false;

    return true;
}

int shortest(vector<vector<int> > &grid, int n) {
    // Your code goes here
    vector<vector<int>> dist ( n , vector<int> ( n , INT_MAX));

    int dx[] = { -1 , 1, 0 , 0 };
    int dy[] = { 0 ,  0 , -1, 1};

    priority_queue < pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>> > pq;


    dist[0][0] = grid[0][0] ;
    pq.push({dist[0][0], {0, 0}});

    while (!pq.empty()) {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int cr_dist = p.first;
        int crX = p.second.first;
        int crY = p.second.second;
        trace(crX, crY, cr_dist);
        for (int i = 0 ; i < 4 ; i++ ) {
            int newX = crX + dx[i];
            int newY = crY + dy[i];
            if (!isValid(newX, newY , n )) continue;
            if (dist[newX][newY] > cr_dist + grid[newX][newY]) {
                dist[newX][newY] =  cr_dist + grid[newX][newY];
                pair<int, pair<int, int>> ps = {dist[newX][newY] , {newX , newY }};
                pq.push(ps);
            }
        }
    }



    return dist[n - 1][n - 1];
}