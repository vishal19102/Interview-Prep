
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

#define printBreak() cout << "----------------------" << endl;
#define long long int int
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define mod 1000000007
typedef pair<string, int> pp;

string pat;
string text;

string smallestWindow() {

	int left = 0 ;
	int right =  0 ;
	int n = pat.size();

	unordered_map<char, int> freqtext ;
	unordered_map<char , int > freqpat;

	for (auto i : text ) {
		freqtext[i] += 1;
	}

	int characterNeeded = freqtext.size();
	int ans = INT_MAX;
	int leftB = 0 ;
	int characterCount = 0 ;
	bool found = false;
	while ( right < n ) {
		char ch = pat[right];
		if (freqtext.find(ch) != freqtext.end() ) {
			freqpat[ch] += 1;
			if (freqtext[ch] == freqpat[ch]) {
				characterCount++;
			}
			while (characterCount == characterNeeded ) {
				found = true;
				if (ans > right - left + 1  ) {
					ans = right - left + 1;
					leftB = left;
				}
				char newch = pat[left++];
				if (freqtext.find(newch) != freqtext.end()) {
					freqpat[newch]--;
					if (freqpat[newch] < freqtext[newch])
						characterCount--;
				}


			}
		}
		right++;
	}
	if (found ) return pat.substr(leftB , ans);
	else return "-1";
}





int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	cin >> t;
	while (t--) {
		cin >> pat;
		cin >> text;
		cout << smallestWindow() << endl;
	}
	return 0;
}
