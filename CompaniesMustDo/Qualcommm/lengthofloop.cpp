// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if (position == 0) return;

    Node* walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node* head);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;

        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0 ; i < n - 1 ; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        cout << countNodesinLoop(head) << endl;
    }
    return 0;
}

Node* findLoop(Node* head ) {

    Node* slow = head;
    Node* fast = head;

    while (slow and fast and fast->next ) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast ) return slow;
    }
    return NULL;
}

int countNodesinLoop(struct Node *head)
{
    // Code here
    Node* p = findLoop(head);

    if (p == NULL ) return 0 ;

    Node* q = head;

    int count = 0 ;
    while ( p != q ) {
        count++;
        p = p->next;
        q = q->next;
    }
    return count ;
}