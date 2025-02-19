// 1. Įvesti sveiką skaičių N. Įvesti N sveikų skaičių a1, a2, ... aN. Apskaičiuoti ir išvesti sekos
// narių, didesnių už mažiausią skaičių, skaičių ir sumą.

// 2. Įterpti skaičių x po didžiausio vienkrypčio sąrašo elemento ir tą patį skaičių prieš
// mažiausią elementą.

// 3. Pašalinti iš vienkrypčio sąrašo k-ąjį elementą

// Visuose uždaviniuose reikia naudoti vienkrypčius sąrašus bei funkcijas, kuriose turi būti
// realizuoti prašomi veiksmai. Taip turi būti realizuotos įvedimo bei spausdinimo funkcijos.


#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void insertInt(Node *&head, Node *&tail, int x) {
    int smallestNum = head->data;
    int biggestNum = head->data;
    Node *smallestNode = head;
    Node *biggestNode = head;
    Node *current = head->next;
    while (current != NULL) {
        if (current->data < smallestNum) {
            smallestNum = current->data;
            smallestNode = current;
        }
        if (current->data > biggestNum) {
            biggestNum = current->data;
            biggestNode = current;
        }
        current = current->next;
    }

    Node *newNode1 = new Node;
    newNode1->data = x;
    Node *newNode2 = new Node;
    newNode2->data = x;

    if (smallestNode == head) {
        newNode1->next = head;
        head = newNode1;
    } else {
        current = head;
        while (current->next != smallestNode) {
            current = current->next;
        }
        newNode1->next = smallestNode;
        current->next = newNode1;
    }

    newNode2->next = biggestNode->next;
    biggestNode->next = newNode2;
    if (biggestNode == tail) {
        tail = newNode2;
    }

}

void deleteNode(Node *&head,Node *&tail, int k) {
    if (head == NULL) {
        cout << "sarasas tuscias" << endl;
        return;
    }
    
    if (k == 0) {
        Node *current = head;
        head = head->next;
        delete current;
    }
    
    Node *current = head;
    int index = 0;
    while (current != NULL && k > index) {
        if (k == index + 1) {
            Node *nextCurrent = current->next;
            Node *elem = nextCurrent->next;
            delete nextCurrent;
            current->next = elem;
            return;
        }
        current = current->next;
        index++;
    }
    
    if (current->next == NULL) {
        tail = current;
    }
}

void printLinkedList(Node *head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int listLength;
    cout << "iveskite saraso ilgi" << endl;
    cin >> listLength;

    Node *head = NULL;
    Node *tail = NULL;
    int smallestNum;
    int biggestNum;

    for (int i = 0; i < listLength; i++) {
        Node *newNode = new Node;
        
        cout << "iveskite duomenis lastelei " << i + 1 << ": " << endl;
        cin >> newNode->data;

        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            smallestNum = newNode->data;
            biggestNum = newNode->data;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        if (newNode->data > biggestNum) {
            biggestNum = newNode->data;
        }
        if (newNode->data < smallestNum) {
            smallestNum = newNode->data;
        }
    }

    cout << "maziausias skaicius sarase yra " << smallestNum << endl;
    cout << "didziausias skaicius sarase yra " << biggestNum << endl;
    
    int sum = 0;
    int biggerNumCount = 0;
    Node *current = head;
    while (current != NULL) {
        if (current->data > smallestNum) {
            biggerNumCount++;
            sum = sum + current->data;
        }
        current = current->next;
    }
    cout << "suma: " << sum << endl;
    cout << "didesni skaiciai: " << biggerNumCount << endl;
    int choice;
    int x;
    int k;
    do {
        cout << "ka norite daryti toliau? (iveskite pvz.: 2)" << endl;
        cout << "1. perziureti sarasa" << endl;
        cout << "2. iterpti skaiciu pries maziausia ir po didziausios lasteles" << endl;
        cout << "3. trinti lastele" << endl;
        cout << "4. baigti" << endl;
        
        cin >> choice;
        
        switch (choice) {
            case 1:
                printLinkedList(head);
                break;
            case 2:
                cout << "iveskite skaiciu, kuri norite iterpti" << endl;
                cin >> x;
                insertInt (head, tail, x);
                break;
            case 3:
                cout << "iveskite, kuria lastele norite trinti (pirmas elementas - 0)" << endl;
                cin >> k;
                deleteNode (head, tail, k);
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