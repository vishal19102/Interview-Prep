
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
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define mod 1000000007
#define MAX 1000001
typedef pair<string, int> pp;

vector<int> primes;
void sieve() {
	vector<bool> isPrimes(MAX , true );

	isPrimes[1] = false ;
	isPrimes[0] = false ;
	for (int i = 2 ; i < MAX ; i++ ) {
		if (isPrimes[i] == true ) {
			for (int j =  2 * i ; j < MAX ; j += i ) {
				isPrimes[j] = false ;
			}
		}
	}
	for (int i = 2 ; i < MAX ; i++ ) {
		if (isPrimes[i])
			primes.push_back(i);
	}
	// for (auto i : primes ) trace(i);
}

int segsieve(int left, int right ) {

	vector<bool> primeranges(right - left + 1 , true ) ;

	for (int i = 0 ; primes[i] <= right ; i++ ) {

		int cur_prime = primes[i];
		int base = (left / cur_prime ) * cur_prime ;
		if (base < left )
			base = base + cur_prime;

		for (int j = base ; j <= right ; j += cur_prime ) {
			primeranges[j - left] = false ;
		}
		if (base == cur_prime) primeranges[base - left ] = true ;
	}

	long long int product  = 1 ;
	for (int i = 0 ; i < right - left + 1 ; i++ ) {
		if (primeranges[i] == true ) {
			//cout << i + left << endl ;
			product = ( (product % mod ) * (i + left ) % mod ) % mod  ;
		}
	}
	return product % mod ;
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
	sieve();
	while (t--) {
		int  l , r ;
		cin >> l >> r;
		cout << segsieve(l , r ) << endl;
	}
	return 0;
}
