//Įterpti skaičių x po visų neigiamų elementų.

/*******REQUIREMENTS IN ENGLISH*******/
// Insert the number x after all negative elements.  

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};
Node *head = NULL;
Node *tail = NULL;

void insertNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        tail->next = NULL;
        head->next = NULL;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void checkNegativeNum(int num, int x) {
    if (num < 0) {
        insertNode(x);
    }
}

void printLinkedList(Node *curr) {
    cout << "--------------------------------------------" << endl;
    while (curr != NULL) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
    cout << "--------------------------------------------" << endl;
}

int main() {
    int n, num, x;
    int i = 0;
    cout << "iveskite skaiciu x" << endl;
    cin >> x;
    cout << "iveskite norimu ivesti sveiku skaiciu kieki" << endl;
    cin >> n;
    while (i < n) {
        cout << i + 1 << " - iveskite sveika skaiciu" << endl;
        cin >> num;
        insertNode(num);
        checkNegativeNum(num, x);
        i++;
    }
    printLinkedList(head);

    return 0;
}