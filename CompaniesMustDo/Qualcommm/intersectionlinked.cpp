// { Driver Code Starts
#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
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

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int n = 0 ;
    Node* temp1 = head1;
    while (temp1 != NULL ) {
        n++;
        temp1 = temp1->next;
    }
    int m = 0 ;
    Node* temp2 = head2;
    while (temp2 != NULL ) {
        m++;
        temp2 = temp2->next;
    }

    if (n > m ) {
        int diff = (n - m ) ;
        while (diff--) {
            head1 = head1->next;
        }
    }
    else if ( m > n ) {
        int diff = (m - n) ;
        while (diff--) {
            head2 = head2->next;
        }
    }
    while (head1 != NULL and head2 != NULL ) {
        if (head1 == head2) return head1->data;
        else {
            head1 = head1->next;
            head2 = head2->next;
        }
    }

    return -1 ;
}

