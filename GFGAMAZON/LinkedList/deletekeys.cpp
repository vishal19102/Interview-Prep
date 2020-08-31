// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
  int data;
  struct Node* next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
  struct Node* new_node = new Node(new_data);
  if (*head_ref == NULL)
    *head_ref = new_node;
  else
    (*tail_ref)->next = new_node;
  *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node* deleteAllOccurances(struct Node *head, int );

void printList(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << "\n";
}

/* Driver program to test above function*/
int main()
{
  int T, i, n, l;
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  // TO BE REMOVED
  for (int i = 0; i < 2000; i++);

  cin >> T;

  while (T--) {
    struct Node *head = NULL,  *tail = NULL;

    cin >> n;
    for (i = 1; i <= n; i++)
    {
      cin >> l;
      append(&head, &tail, l);
    }

    int kk;
    cin >> kk;
    head = deleteAllOccurances(head, kk);
    printList(head);
  }
  return 0;
}

// } Driver Code Ends


/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};*/
/*You are required to complete below method*/
Node* deleteAllOccurances(Node *head, int x)
{
  //Your code here

  if (head == NULL or head->data == x ) return NULL ;

  if (head->next == NULL ) return head ;

  Node* slow = head ;
  Node* fast = head->next ;

  while (fast != NULL ) {
    if (fast->data == x ) {
      slow->next = fast->next;
    }
    else {
      slow = slow->next;
    }
    fast = fast->next;
  }
  return head ;
}
