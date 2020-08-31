// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


Node *compute(Node *head);

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Node *result = compute(head);
        print(result);
        cout << endl;
    }
}

Node *compute(Node *head)
{
    // your code goes here
    if (head == NULL ) return NULL ;

    Node* curPtr = head ;
    Node* nPtr = curPtr->next ;

    while (curPtr != NULL and nPtr != NULL ) {
        if (curPtr->data < nPtr->data) {
            nPtr = nPtr->next ;
        }
        else {

        }
    }
}
