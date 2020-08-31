// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [], int );

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        petrolPump p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        cout << tour(p, n) << endl;
    }
}

int tour(petrolPump p[], int n)
{
    //Your code here
    int sur_pls = 0 ;
    for (int i = 0 ; i < n ; i++  ) {
        int cur_ = cur_ + p.petrol + p.distance ;

        if (cur_ < 0) {
            start = i + 1 ;
            deficit = sur_plsl
        }
    }
}

