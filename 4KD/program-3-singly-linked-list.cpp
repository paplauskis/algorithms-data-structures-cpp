//Pašalinti iš vienkrypčio sąrašo pirmąjį neigiamą elementą

/*******REQUIREMENTS IN ENGLISH*******/
// Remove the first negative element from the singly linked list.  

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

void removeFirstNegativeNode(Node *curr) {
    Node *prev = NULL;
    while (curr != NULL) {
        if (curr->data < 0) {
            if (prev == NULL) {
                Node *temp = curr;
                curr = curr->next;
                temp->next = NULL;
                delete temp;
            } else {
                prev->next = curr->next;
                delete curr;
            }
            break;
        }
        prev = curr;
        curr = curr->next;
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
    int n, num, b;
    int i = 0;
    cout << "iveskite norimu ivesti sveiku skaiciu kieki" << endl;
    cin >> n;
    while (i < n) {
        cout << i + 1 << " - iveskite sveika skaiciu" << endl;
        cin >> num;
        insertNode(num);
        i++;
    }
    removeFirstNegativeNode(head);
    printLinkedList(head);

    return 0;
}