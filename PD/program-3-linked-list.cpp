//3. Parašyti programą, kuri įterpia į sukurto sąrašo L pabaigą visus sąrašo elementus, kurie yra prieš elementą E, 
//jei toks elementas egzistuoja.

/*******REQUIREMENTS IN ENGLISH*******/
// 3. Write a program that inserts into the end of the created list L all the elements of the list 
// that are before element E, if such an element exists.

#include <iostream>
using namespace std;

struct List {
    int data;
    struct List *next;
};
List *head = NULL;
List *tail = NULL;

void insertNodeToList(int data) {
    List* newNode = new List;
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

void insertElementsToListTail(List *curr, int elem) {
    while (curr != NULL) {
        int e = curr->data;
        if (e != elem) {
            insertNodeToList(e);
        } else {
            break;
        }
        curr = curr->next;
    }
}

void printLinkedList(List *curr) {
    cout << "--------------------------------------------" << endl;
    while (curr != NULL) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
    cout << "--------------------------------------------" << endl;
}

int main() {
    int choice;
    int num;
    int elem;
    do {
        cout << "ka norite daryti toliau? (iveskite pvz.: 2)" << endl;
        cout << "1 - iterpti skaiciu i sarasa" << endl;
        cout << "2 - spausdinti sarasa" << endl;
        cout << "3 - perkelti elementus, kurie yra pries elementa E i saraso pabaiga" << endl;
        cout << "4 - baigti programa" << endl;
        
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "iveskite koki skaiciu norite iterpti" << endl;
                cin >> num;
                insertNodeToList(num);
                cout << "------------------------------" << endl;
                cout << "skaicius " << num << " iterptas" << endl;
                cout << "------------------------------" << endl;
                break;
            case 2:
                printLinkedList(head);
                break;
            case 3:
                cout << "iveskite elementa E" << endl;
                cin >> elem;
                insertElementsToListTail(head, elem);
                cout << "------------------------------" << endl;
                cout << "elementai perkelti" << endl;
                cout << "------------------------------" << endl;
                break;
            case 4:
                cout << "programa baigta" << endl;
                break;
            default:
                cout << "netinkamas pasirinkimas" << endl;
        }
    } while (choice != 4);

    return 0;
}
