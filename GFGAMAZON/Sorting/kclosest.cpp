// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> &a,
             const pair<int, int> &b)
{
    if (a.first == b.first)
        return (a.second < b.second);
    return a.first < b.first;
}

vector<vector<int>> kClosest(vector<vector<int>>& , int );

//User code will be pasted here

int main() {
    int t;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> p, res;

        for (int i = 0 ; i < n ; ++ i ) {
            vector<int> vec(2);
            cin >> vec[0] >> vec[1];
            p.push_back(vec);
        }

        res = kClosest(p, k);

        for (int i = 0 ; i < k ; ++ i ) {
            cout << res[i][0] << " " << res[i][1] << " ";
        }

        cout << "\n";

    }
}

long long  dist(vector<vector<long long > >  p1 ) {

    return ( (p1[0][0] * p1[0][0] ) + (p1[0][1] * p1[0][1] )) ;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    // code here
    priority_queue<pair<int, int> > pq ;

    int i = 0 ;
    for (; i < K ; i++ ) {
        pq.push({points[i][0] , points[i][1]});
    }

    while ( i < points.size() ) {
        pair<long long , long long > cur_p = pq.top();
        if (dist(cur_p) > dist(points[i++])) {
            pq.pop();
            pq.push({points[i][0] , points[i][1]});
        }
    }

    vector<vector<long long > >  res ;
    while (!pq.empty()) {
        pair<long long , long > point = pq.top();
        pq.pop();
        res.push_back({point.first , point.second});
    }
    return res ;
}