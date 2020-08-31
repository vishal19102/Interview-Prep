// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// design the class:

class LRUCache
{
private:
    list<pair<int, int>> qu;
    int csize;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int cap)
    {
        // constructor for cache
        csize = cap;

    }

    static int get(int key)
    {
        // this function should return value corresponding to key
        if (mp.find(key) != mp.end()) {
            int ans = *mp[key];

            set()
            return ans;
        }
    }

    static void set(int key, int value)
    {
        // storing key, value pair
        if (mp.find(key) ==  mp.end()) {
            if (qu.size() > csize) {
                mp.erase(key);
                qu.pop_back();
            }
            qu.push_front({key, value});
            mp[key] = qu.begin();
        }
        else {

        }

    }
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends