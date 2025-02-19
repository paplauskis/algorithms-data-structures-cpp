//Įvesti sveiką skaičių N. Įvesti N sveikų skaičių a1, a2, ... aN ir skaičių b. Sekoje a1, a2, ...
//aN visus narius, didesnius už skaičių b, pakeisti skaičiumi b. Išvesti gautą seką.

/*******REQUIREMENTS IN ENGLISH*******/
// Enter an integer N. Enter N integers a1, a2, ... aN and a number b.  
// In the sequence a1, a2, ... aN, replace all elements greater than b with b.  
// Output the resulting sequence.  

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

void changeBiggerNums(Node *curr, int b) {
    if (curr->data > b) {
        curr->data = b;
    }
}

void printLinkedList(Node *curr, int b) {
    cout << "--------------------------------------------" << endl;
    while (curr != NULL) {
        changeBiggerNums(curr, b);
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
    cout << "iveskite skaiciu b" << endl;
    cin >> b;
    printLinkedList(head, b);

    return 0;
}