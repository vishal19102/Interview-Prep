
// Created By Vishal Srivastava ....
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <string>
#include<cstring>
#include<unordered_map>

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

#define output(x) cout<<x<<"\n";
#define long long int int
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define mod 1000000007
typedef pair<string, int> pp;

class Node {
public:
	char ch ;
	bool isTerminal;
	unordered_map<char, Node*> hashmap;
	Node(char cc) {
		ch = cc;
		isTerminal = false;
	}
};

class Trie
{
public:
	Node* root ;
	Trie() {
		root = new Node('\0');
	}
	void insertStrings(string word ) {
		Node* temp = root;

		for (int i = 0 ; i < word.length() ; i++ ) {

			if (temp->hashmap.count(word[i]) == 0 ) {
				Node* newchild = new Node(word[i]);
				temp->hashmap[word[i]] = newchild;
				temp = temp->hashmap[word[i]];
			}
			else {
				temp = temp->hashmap[word[i]];
			}
		}
		temp->isTerminal = true ;
	}

	string longestPrefix(string word) {
		Node* temp = root ;
		int count = 0 ;
		string res;
		for (int i = 0 ; i < word.size() ; i++ ) {
			if (temp->hashmap.size() == 1  and temp->isTerminal == false) {
				temp = temp->hashmap[word[i]];
			}
			else {
				return  word.substr(0 , i);
			}

		}
		return word ;
	}

};


string longestCommonPrefix(vector<string>& arr) {
	// write your awesome code here
	Trie *t = new Trie();
	for (auto i : arr ) {
		t->insertStrings(i);
	}
	string res = t->longestPrefix(arr[0]);

	trace(res);
	return res ;
}




int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> t;
	while (t--) {
		int n ;
		cin >> n;
		vector<string> words ( n );
		for (int i = 0 ; i < n ; i++ ) cin >> words[i];
		longestCommonPrefix(words);
	}
	return 0;
}
