
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
int wordBreak(string A, vector<string> &B);


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++) {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        cout << wordBreak(line, dict) << "\n";
    }
}

class Node {

public:
    char ch ;
    bool isTerminal ;
    unordered_map<char, Node*> hashmap;
    Node(char c) {
        ch = c;
        isTerminal = false ;
    }
};

class Trie
{
public:
    Node* root ;
    Trie() {
        root = new Node('\0');
    }

    void insert(string str ) {
        Node* temp = root ;
        int n = str.length();
        for (int i = 0 ; i < n ; i++ ) {
            char c = str[i];
            if (temp->hashmap.find(c) == temp->hashmap.end()) {
                Node* child = new Node(c);
                temp->hashmap[c] = child;
                temp = child;
            }
            else {
                temp = temp->hashmap[c];
            }
        }
        temp->isTerminal = true ;

        return ;

    }

    bool query(string str ) {
        Node* temp = root ;
        int n = str.length();
        for (int i = 0 ; i < n ; i++ ) {
            char c = str[i];
            if (temp->hashmap.find(c) == temp->hashmap.end())
                return false ;
            else
                temp = temp->hashmap[c];
        }
        return temp->isTerminal ;
    }
};


int ifPossible(string A , Trie &t) {

    if (A.length() == 0 ) return 1 ;

    for (int i = 0 ; i < A.length() ; i++ ) {

        string sub = A.substr(0 ,  i +  1 );
        if ( t.query(sub) and ifPossible( A.substr(i + 1 , A.length() ) , t )) {

            return 1 ;
        }
    }
    return 0;
}



int wordBreak(string A, vector<string> &B) {
    //code here
    Trie t ;
    for (auto i : B ) {
        t.insert(i);
    }
    int ans = ifPossible(A , t );
    return ans ;
}