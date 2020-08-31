// { Driver Code Starts
//Initial Template for C++

// C program to find n'th Node in linked list
#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
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
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};


/* Function to get the middle of the linked list*/
struct Node *reverseList(struct Node *head);

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T, n, l, firstdata;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> T;

    while (T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin >> n;

        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;

        for (int i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        head = reverseList(head);

        printList(head);
        cout << endl;
    }
    return 0;
}

struct Node* revhead ;
struct Node* rList( struct Node* head ) {

    if (head == NULL ) return NULL ;

    if (head->next == NULL ) {
        revhead = head ;
        return head ;
    }
    struct Node* rev = rList(head->next);
    rev->next = head;
    head->next = NULL;
    return head ;
}

struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    rList(head);

    return revhead;
}
