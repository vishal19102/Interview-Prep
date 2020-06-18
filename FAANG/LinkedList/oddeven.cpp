
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
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif

#define output(x) cout<<x<<"\n";
#define long long int int 
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define mod 1000000007
typedef pair<string,int> pp;

class Node{

public:
	int data;
	Node* next ; 

	Node(int d )  {
		data = d ;
		next = NULL ;
	}

};

class LinkedList { 

 Node* head ; 

public: 
	LinkedList( ) { 
		head = NULL;
	}
	void addNode(int d )  { 
		Node* temp = head ; 

		Node* newNode = new Node(d);
		
		if(temp==NULL ){
			head = newNode;
		}
		else{
			while(temp->next!=NULL ) {
				temp = temp->next;
			}
			temp->next = newNode ;
		}
	}	
	void printNodes(){
		Node* temp = head ;

		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	} 
	void swapnodes() { 
		Node* temp = head ; 

		if(temp==NULL) return ; 

		Node* odd , *even ;

		odd = temp ;

		if(temp->next != NULL )
			even = temp->next;

		if(even->next)
			temp  =even->next;

		int flg = 1 ;

		Node* O  = odd , *E = even ;  
		while(temp!=NULL ){ 

			if(flg%2 == 1 ) {
				odd->next = temp;
				odd = odd->next;
			}
			else{
				even->next = temp;
				even = even->next;
			}
		}
		odd->next = E;

		head = O ;

	}

};


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
	int n ;
	cin>>n;

	LinkedList* ll = new LinkedList();

	for(int i = 0 ; i < n ; i++   ) {
		int a ; cin>> a;
		ll->addNode(a);
	}

	ll->printNodes();
	ll->swapnodes();
	ll->printNodes();

    return 0;
}
